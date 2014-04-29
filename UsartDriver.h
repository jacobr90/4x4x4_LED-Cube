// UsartDriver.h
#ifndef UsartDriver_h
#define UsartDriver_h

#include <stm32f4xx.h>


// Send a char out USART3 as soon as it is ready to accept it
void Usart3_Transmit(unsigned char chr)
{
	while (!(USART3->SR & USART_SR_TXE));  // wait until empty
	USART3->DR = chr;
} // End of Usart_Transmit

// Send a char out USART2 as soon as it is ready to accept it
void Usart2_Transmit(unsigned char chr)
{
	while (!(USART2->SR & USART_SR_TXE));  // wait until empty
	USART2->DR = chr;
} // End of Usart_Transmit


void Usart3_RcvInterruptEnable( void )
{
	USART3->CR1 |= USART_CR1_RXNEIE; //Rcv Interrupt enable.
} // End of Usart_RcvIEnable


void Usart2_RcvInterruptEnable( void )
{
	USART2->CR1 |= USART_CR1_RXNEIE; //Rcv Interrupt enable.
} // End of Usart_RcvIEnable

// The following is the interrupt service routine for
// USART3.
volatile unsigned char NewChr3=0;
void USART3_IRQHandler( void )
{
	// Check for data coming in.
	if( USART3->SR & USART_SR_RXNE ) // Receive 
	{
		 NewChr3 = USART3->DR;
	} // End of Receive data test.
} // end of USART3_IRQHandler

// The following is the interrupt service routine for
// USART2.
volatile unsigned char NewChr2=0;
void USART2_IRQHandler( void )
{
	// Check for data coming in.
	if( USART2->SR & USART_SR_RXNE ) // Receive 
	{
		 NewChr2 = USART2->DR;
	} // End of Receive data test.
} // end of USART2_IRQHandler

// This function is called by the main program at the start  to properly configure all the registers in the USART3 system
// and establish the interrupt system.
void Usart3_Init( int SystemClock, int BaudRate )
{
// Clock enable for Usart3
	RCC->APB1ENR  |= RCC_APB1ENR_USART3EN;
	RCC->AHB1ENR  |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER  |=  0x000a0000;     // PD 9, 8 to 
	GPIOD->MODER  &=  0xFFFAFFFF;     // Alternate Function
	GPIOD->AFR[1] |=  0x00000077;     // Set PD 9 and 8's Alternate
	GPIOD->AFR[1] &=  0xFFFFFF77;     // Function to Usart3 (AF7).

	// Set CR1 for USART3 
	USART3->CR1 |= 0x200c;	// 16 oversample, Usart Enabled, 
							// Transmitter and Receiver enabled.

	// Set CR2 for USART3   Comment the following line for 1 stop bit
	// USART3->CR2 |= 0x2000; // 2 stop bits, 

	NVIC_EnableIRQ( USART3_IRQn );  // Enable USART3 interrupts.

	{ // Scope for computing Baud Rate values.
		float Divisor;
		int IntDivisor, FracDivisor;
		Divisor = (float) ( SystemClock ) / (float) ( 64 * BaudRate);
		IntDivisor = (int) Divisor;
		Divisor -= (float)IntDivisor;
		FracDivisor = (int)( 16.0F * Divisor + 0.5F );
		USART3->BRR = ( IntDivisor << 4 ) + FracDivisor ;
	}
	// Start up interrupts for receive,	
  Usart3_RcvInterruptEnable();

} // End of Usart3_Init

// This function is called by the main program at the start  to properly configure all the registers in the USART2 system
// and establish the interrupt system.
void Usart2_Init( int SystemClock, int BaudRate )
{
//old comment	// Clock enabled for SPI2 and GPIOB.
// Clock enable for Usart2
	RCC->APB1ENR  |= RCC_APB1ENR_USART2EN;
//	RCC->AHB1ENR  |= RCC_AHB1ENR_GPIOAEN;
//	GPIOA->MODER  |=  0x000000A0;     // PA 3, 2 to 
//	GPIOA->MODER  &=  0xFFFFFFAF;     // Alternate Function
//	GPIOA->AFR[0] |=  0x00007700;     // Set PA 3 and 2's Alternate
//	GPIOA->AFR[0] &=  0xFFFF77FF;     // Function to Usart2 (AF7).
	RCC->AHB1ENR  |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER  |=  0x00002800;     // PD 6, 5 to 
	GPIOD->MODER  &=  0xFFFF28FF;     // Alternate Function
	GPIOD->AFR[0] |=  0x07700000;     // Set PD 6 and 5's Alternate
	GPIOD->AFR[0] &=  0xF77FFFFF;     // Function to Usart3 (AF7).

	// Set CR1 for USART3 
	USART2->CR1 |= 0x200c;	// 16 oversample, Usart Enabled, 
							// Transmitter and Receiver enabled.

	// Set CR2 for USART3   Comment the following line for 1 stop bit
	// USART3->CR2 |= 0x2000; // 2 stop bits, 

	NVIC_EnableIRQ( USART2_IRQn );  // Enable USART3 interrupts.

	{ // Scope for computing Baud Rate values.
		float Divisor;
		int IntDivisor, FracDivisor;
		Divisor = (float) ( SystemClock ) / (float) ( 64 * BaudRate);
		IntDivisor = (int) Divisor;
		Divisor -= (float)IntDivisor;
		FracDivisor = (int)( 16.0F * Divisor + 0.5F );
		USART2->BRR = ( IntDivisor << 4 ) + FracDivisor ;
	}
	// Start up interrupts for receive,	
  Usart2_RcvInterruptEnable();

} // End of Usart2_Init


// The following three functions support sending data out to a terminal.
// This first simply transmit a string of characters.
void Usart3_Send_String( unsigned char *out )
{
    // loop until reaching a null character.
    while( *out )
	    Usart3_Transmit( *out++ ); // Send character and move to next 
} // End of Usart_Send_String

// Transmits a number as a string of ascii characters in a decimal format.
void Usart3_Send_Decimal( int number )
{
    // if greater than 0 to 9. 
    if( number > 9 )
	   Usart3_Send_Decimal( number/10 ); // move to next character.
	// Send out last digit as ascii character.
	Usart3_Transmit( '0' + number % 10 );
	
} // End of Usart_Send_Decimal

// Transmits a number as a string of ascii characters in a hexadecimal format.
void Usart3_Send_Hexadecimal( int number )
{
    // if greater than 0 to F
    if( number > 15 )
	   Usart3_Send_Decimal( number / 16 ); // move to next character.
    // Pull out bottom digit.
	number = number % 16;
	// if in the range of A to F
	if( number > 9 )
	   Usart3_Transmit( 'A' + number - 10 );
	else // if in the range 0 to 9
	   Usart3_Transmit( '0' + number );
	   
} // End of Usart_Send_Hexadecimal

// The following three functions support sending data out to a terminal.
// This first simply transmit a string of characters.
void Usart2_Send_String( unsigned char *out )
{
    // loop until reaching a null character.
    while( *out )
	    Usart2_Transmit( *out++ ); // Send character and move to next 
} // End of Usart_Send_String

// Transmits a number as a string of ascii characters in a decimal format.
void Usart2_Send_Decimal( int number )
{
    // if greater than 0 to 9. 
    if( number > 9 )
	   Usart2_Send_Decimal( number/10 ); // move to next character.
	// Send out last digit as ascii character.
	Usart2_Transmit( '0' + number % 10 );
	
} // End of Usart_Send_Decimal

// Transmits a number as a string of ascii characters in a hexadecimal format.
void Usart2_Send_Hexadecimal( int number )
{
    // if greater than 0 to F
    if( number > 15 )
	   Usart2_Send_Decimal( number / 16 ); // move to next character.
    // Pull out bottom digit.
	number = number % 16;
	// if in the range of A to F
	if( number > 9 )
	   Usart2_Transmit( 'A' + number - 10 );
	else // if in the range 0 to 9
	   Usart2_Transmit( '0' + number );
	   
} // End of Usart_Send_Hexadecimal

#endif
