/*----------------------------------------------------------------------------
 * Name: Nick Stanley, Jacob Ryan
 * File: Blinky.c
 * Description: 
 *----------------------------------------------------------------------------*/

//#include <stdio.h>
#include "STM32F4xx.h"
#include "Pin.h"
#include "UsartDriver.h"
#include "Letters.h"
//Cycle through layers at a "framerate" of at least 60Hz (167) or 120Hz (83)
#define FRAMERATE 167
#define LETTERRATE 4000
//Delay variables
volatile uint32_t frameDelay = 0;
volatile uint32_t letterDelay = 0;

Pin testTactular[20];
//
volatile uint32_t currentLayer = 0;
volatile uint32_t letterBase = 9;

volatile uint32_t sysTicks = 0;
void testAll(void)
{
	testTactular[0] = A8;
	testTactular[1] = A9;
	testTactular[2] = A10;
	testTactular[3] = A13;
	testTactular[4] = A14;
	testTactular[5] = A15;
	testTactular[6] = C10;
	testTactular[7] = C11;
	testTactular[8] = C12;
	testTactular[9] = D0;
	testTactular[10] = D1;
	testTactular[11] = D2;
	testTactular[12] = D3;
	testTactular[13] = D4;
	testTactular[14] = D5;
	testTactular[15] = D6;
}
 /*----------------------------------------------------------------------------
  SysTick_Handler
 *----------------------------------------------------------------------------*/
int x = 0;
void SysTick_Handler(void) 
{
	
  sysTicks++;
	//At the frame rate, turn off layer and turn on next layer 
	if(frameDelay == sysTicks)
	{		
		frameDelay += FRAMERATE;			//Delay till next frame
		PinOff(LayerChecker(currentLayer));	//Turn off current layer
		++currentLayer;
		if(currentLayer == 5)				//Check overflow
			currentLayer = 0;
		if(currentLayer != 4)
			PinOn(LayerChecker(currentLayer));		//Turn on new layer
	}
	//Move letter over 
	if(letterDelay == sysTicks)
	{
		letterDelay += LETTERRATE;
		if(letterBase == -1)
			letterBase = 9;
		else
			--letterBase;
// 		PinOff(testTactular[x]);
// 		++x;
// 		if(x == 16)
// 			x = 0;
// 		PinOn(testTactular[x]);
	}
}
/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/
int main (void) 
{
	letter lK;//, lS, lU;
	int i, j;
  SystemCoreClockUpdate();                      /* Get Core Clock Frequency   */
  if (SysTick_Config(SystemCoreClock / 10000))  /* SysTick 10000/s interrupts  */
	{ 
    while (1);                                  /* Capture error              */
  }
	//Prepare framerate
	frameDelay = sysTicks + FRAMERATE;
	letterDelay = sysTicks + LETTERRATE;
	testAll();
	Pin_Init(); 
	buildScrollBase();
	
	for(i = 0; i < 4; ++i)
	{
		for(j = 0; j < 3; ++j)
		{
			lK.rep[i][j] = letterL[i][j];
// 			lS.rep[i][j] = letterS[i][j];			
// 			lU.rep[i][j] = letterU[i][j];
		}
	}
	while(1)
	{
		lK.basePin = letterBase;
// 		lS.basePin = letterBase + 6;
// 		lU.basePin = letterBase + 12;
		drawLetter(lK, currentLayer);
	}//end while(1)
}//end Main
