/*----------------------------------------------------------------------------
 * Name:    Pin.c
 * Purpose: functions and masks to use our LED cube with a set of pins
 * Note(s):
 *----------------------------------------------------------------------------
 *----------------------------------------------------------------------------*/

#include "STM32F4xx.h"
#include "Pin.h"

/*----------------------------------------------------------------------------
 *----------------------------------------------------------------------------*/
//Pin masking						//(Row, Col)
Pin  C6 = {'C', 6};			//K	Row 3
Pin  C7 = {'C', 7};			//A	Row 2
Pin  C8 = {'C', 8};			//J	Row 1
Pin  C9 = {'C', 9};			//9	Row 0
Pin  A8 = {'A', 8};			//B	(3,0)
Pin  A9 = {'A', 9};			//1	(3,1)
Pin A10 = {'A', 10};		//C	(3,2)
Pin A13 = {'A', 13};		//2	(3,3)
Pin A14 = {'A', 14};		//3	(2,0)
Pin A15 = {'A', 15};		//D	(2,1)
Pin C12 = {'C', 12};		//E	(2,2)
Pin  D0 = {'D', 0};			//4	(2,3)
Pin  D1 = {'D', 1};			//F	(1,0)
Pin  D2 = {'D', 2};			//G	(1,1)
Pin  D3 = {'D', 3};			//5	(1,2)
Pin  D4 = {'D', 4};			//6	(1,3)
Pin  D5 = {'D', 5};			//H	(0,0)
Pin  D6 = {'D', 6};			//7	(0,1)
Pin C10 = {'C', 10};
Pin C11 = {'C', 11};

/*--------------------------------------------------------------
   initialize PORT A
 *----------------------------------------------------------------*/
void PortA_Init(void)
{
	//Enable GIOA clock
	RCC->AHB1ENR   |= ((1UL << 0) );   

	/*Pins 8-15 Port A----------------------------------*/
	GPIOA->MODER  &=  ~((3UL << 2*8)  |
									   (3UL << 2*9)   |
									   (3UL << 2*10)  |
										 (3UL << 2*13)  |
									   (3UL << 2*14)  |
									   (3UL << 2*15)   );  
	GPIOA->MODER  |=  ((1UL << 2*8)  |
     (1UL << 2*9)  |
     (1UL << 2*10)  |
     (1UL << 2*13)  |
     (1UL << 2*14)  |
     (1UL << 2*15)   );  /* PA 8-15 is output  */
	GPIOA->OTYPER  &=  ~((1UL << 2*8)  |
     (1UL << 9)     |
     (1UL << 10)    |
     (1UL << 13)    |
     (1UL << 14)    |
     (1UL << 15)     ); /*output Push-Pull*/
	GPIOA->OSPEEDR  &=  ~((3UL << 2*8)  |
     (3UL << 2*9)   |
     (3UL << 2*10)  |
     (3UL << 2*13)  |
     (3UL << 2*14)  |
     (3UL << 2*15)   ); 
	GPIOA->OSPEEDR  |=  ((1UL << 2*8)  |
     (2UL << 2*9)  |
     (2UL << 2*10)  |
     (2UL << 2*13)  |
     (2UL << 2*14)  |
     (2UL << 2*15)  ); /*50Mhz Fast*/
	GPIOA->PUPDR  &=  ~((3UL << 2*8)  |
     (3UL << 2*9)  |
     (3UL << 2*10)  |
     (3UL << 2*13)  |
     (3UL << 2*14)  |
     (3UL << 2*15)  ); 
	GPIOA->PUPDR  |=  ((1UL << 2*8)  |
     (1UL << 2*9)  |
     (1UL << 2*10)  |
     (1UL << 2*13)  |
     (1UL << 2*14)  |
     (1UL << 2*15)  );/*Pull Up*/
 }

/*-----------------------------------------------------------
   initialize port C
 *------------------------------------------------------------*/
void PortC_Init(void)
{
	//Enable GIOC clock
	RCC->AHB1ENR   |= ((1UL << 2) ); 
  /*Pins 6-9, 12 Port C----------------------------------*/
	GPIOC->MODER  &=  ~((3UL << 2*6)  |
     (3UL << 2*7)  |
     (3UL << 2*8)  |
     (3UL << 2*9)  |
			(3UL << 2*11)  |
	(3UL << 2*10)  |
     (3UL << 2*12)  );  
	GPIOC->MODER  |=  ((1UL << 2*6)  |
     (1UL << 2*7)  |
     (1UL << 2*8)  |
     (1UL << 2*9)  | (1UL << 2*10)  | (1UL << 2*11)  |
     (1UL << 2*12)  );/* PC 6-9,12 is output  */
	GPIOC->OTYPER  &=  ~((1UL << 2*6) |
     (1UL << 7)   |
     (1UL << 8)   |
     (1UL << 9)   |(1UL << 2*10)  |(1UL << 2*11)  |
     (1UL << 12)   );/*output Push-Pull*/
	GPIOC->OSPEEDR &=  ~((3UL << 2*6) |
     (3UL << 2*7)   |
     (3UL << 2*8)   |
     (3UL << 2*9)   |
			(3UL << 2*11)  |
	(3UL << 2*10)  |
     (3UL << 2*12)   );
	GPIOC->OSPEEDR  |=  ((2UL << 2*6) |
     (2UL << 2*7)   |
     (2UL << 2*8)   |
     (2UL << 2*9)   |
			(2UL << 2*11)  |
	(2UL << 2*10)  |
     (2UL << 2*12)   );/*50Mhz Fast*/
	GPIOC->PUPDR  &=  ~((3UL << 2*6) |
     (3UL << 2*7)   |
     (3UL << 2*8)   |
     (3UL << 2*9)   |
			(3UL << 2*11)  |
	(3UL << 2*10)  |
     (3UL << 2*12)   );
	GPIOC->PUPDR  |=  ((1UL << 2*6) |
     (1UL << 2*7)   |
     (1UL << 2*8)   |
     (1UL << 2*9)   |
			(1UL << 2*11)  |
	(1UL << 2*10)  |
     (1UL << 2*12)   );/*Pull Up*/
}

/*-----------------------------------------------------------------
   initialize port D
 *------------------------------------------------------------------*/
void PortD_Init(void)
{
	//Enable GIOD clock
	RCC->AHB1ENR   	  |=  ((1UL << 3) ); 
	GPIOD->MODER &=		~((3UL << 2*0)  |
											(3UL << 2*1)  |
											(3UL << 2*2)  |
											(3UL << 2*3)  |
											(3UL << 2*4)  |
											(3UL << 2*5)  |
											(3UL << 2*6));  
	GPIOD->MODER |= 	 ((1UL << 2*0)  |
											(1UL << 2*1)  |
											(1UL << 2*2)  |
											(1UL << 2*3)  |
											(1UL << 2*4)  |
											(1UL << 2*5)  |
											(1UL << 2*6));//PD 0-7 is output
	GPIOD->OTYPER &=    ~((1UL << 0)  |
											  (1UL << 1)  |
											  (1UL << 2)  |
											  (1UL << 3)  |
												(1UL << 4)  |
												(1UL << 5)  |
												(1UL << 6));//output Push-Pull
	GPIOD->OSPEEDR &= ~((3UL << 2*0)  |
									 	  (3UL << 2*1)  |
										  (3UL << 2*2)  |
										  (3UL << 2*3)  |
										  (3UL << 2*4)  |
										  (3UL << 2*5)  |
										  (3UL << 2*6));
	GPIOD->OSPEEDR |=  ((2UL << 2*0)  |
										  (2UL << 2*1)  |
										  (2UL << 2*2)  |
										  (2UL << 2*3)  |
										  (2UL << 2*4)  |
										  (2UL << 2*5)  |
										  (2UL << 2*6));//50MHz Fast
	GPIOD->PUPDR &=   ~((3UL << 2*0)  |
											(3UL << 2*1)  |
											(3UL << 2*2)  |
											(3UL << 2*3)  |
											(3UL << 2*4)  |
											(3UL << 2*5)  |
											(3UL << 2*6)); 
	GPIOD->PUPDR |= 	 ((1UL << 2*0)  |
									    (1UL << 2*1)  |
											(1UL << 2*2)  |
											(1UL << 2*3)  |
											(1UL << 2*4)  |
											(1UL << 2*5)  |
											(1UL << 2*6)); //Pull Up
}
/*----------------------------------------------------------------------------
*----------------------------------------------------------------------------*/
void Pin_Init(void) 
{
	PortA_Init();
	PortC_Init();
	PortD_Init();
}

/*----------------------------------------------------------------------------
  Turns on a pin based on Pin struct: Port x, pin y
 *----------------------------------------------------------------------------*/
void PinOn(Pin in)
{
	if (in.port == 'A')
	{
		GPIOA->BSRRL = 1UL << in.num;
	}
	else if (in.port == 'B')
	{
		GPIOB->BSRRL = 1UL << in.num;
	}
	else if (in.port == 'C')
	{
		GPIOC->BSRRL = 1UL << in.num;
	}
	else 
	{
		GPIOD->BSRRL = 1UL << in.num;
	}
}

/*----------------------------------------------------------------------------
  Turns off a pin based on Pin struct: Port x, pin y
 *----------------------------------------------------------------------------*/
void PinOff(Pin in)
{
	if (in.port == 'A')
	{
		GPIOA->BSRRH = 1UL << in.num;
	}
	else if (in.port == 'B')
	{
		GPIOB->BSRRH = 1UL << in.num;
	}
	else if (in.port == 'C')
	{
		GPIOC->BSRRH = 1UL << in.num;
	}
	else 
	{
		GPIOD->BSRRH = 1UL << in.num;
	}
}

Pin LayerChecker(int i)
{
	switch(i)
	{
		case 0:
			return C9;
		case 1:
			return C8;
		case 2:
			return C7;
		default:
			return C6;		
	}
}

