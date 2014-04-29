#include "Letters.h"
#include "Pin.h"

Pin ScrollBase[10];
void buildScrollBase(void)
{
	ScrollBase[0] = D5;//B3;
	ScrollBase[1] = D1;//D7;
	ScrollBase[2] = C10;//D6;
	ScrollBase[3] = A10;//D6;
	ScrollBase[4] = A13; //D1;
	ScrollBase[5] = A8; //A14;
	ScrollBase[6] = A9; //A8;
	ScrollBase[7] = A15; //A9;
	ScrollBase[8] = D0; //A10;
	ScrollBase[9] = D3; //A13;
}
void drawLetter(letter l, int frame)
{
	int i;
	Pin pin;
	//This might be what we're looking for
	if(frame == 0)
	{
		for(i = 2; i >= 0; --i)
		{
			int x = l.basePin + i;
			if(x < 10)
			{
				pin = ScrollBase[x];
				if(l.rep[3][i] == 1)
					PinOn(pin);
				else
					PinOff(pin);
			}
		}
	}
	if(frame == 1)
	{
		for(i = 2; i >= 0; --i)
		{
			int x = l.basePin + i;
			if(x < 10)
			{
				pin = ScrollBase[x];
				if(l.rep[2][i] == 1)
					PinOn(pin);
				else
					PinOff(pin);
			}
		}
	}
	if(frame == 2)
	{
		for(i = 2; i >= 0; --i)
		{
			int x = l.basePin + i;
			if(x < 10)
			{
				pin = ScrollBase[x];
				if(l.rep[1][i] == 1)
					PinOn(pin);
				else
					PinOff(pin);
			}
		}
	}
	if(frame == 3)
	{
		for(i = 2; i >= 0; --i) //was i = 0; i < 3; ++i
		{
			int x = l.basePin + i;
			if(x < 10)
			{
				pin = ScrollBase[x];
				if(l.rep[0][i] == 1)
					PinOn(pin);
				else
					PinOff(pin);
			}
		}
	}

}//End drawLetter

//Letters A-Z represented as 0s and 1s (for LED off and on) as 4x3 matricies
int letterA[4][3] = { {0, 1, 0},
                      {1, 0, 1},
											{1, 1, 1},
											{1, 0, 1} };
					  
int letterB[4][3] = { {1, 0, 0},
                      {1, 1, 0},
											{1, 0, 1},
											{1, 1, 0} };
					  
int letterC[4][3] = { {1, 1, 1},
                      {1, 0, 0},
											{1, 0, 0},
											{1, 1, 1} };
					  
int letterD[4][3] = { {1, 1, 0},
                      {1, 0, 1},
											{1, 0, 1},
											{1, 1, 0} };
					  
int letterE[4][3] = { {1, 1, 1},
                      {1, 0, 1},
											{1, 1, 0},
											{0, 1, 1} };
					  
int letterF[4][3] = { {1, 1, 1},
                      {1, 0, 0},
											{1, 1, 0},
											{1, 0, 0} };
					  
int letterG[4][3] = { {1, 1, 1},
                      {1, 0, 0},
											{1, 0, 1},
											{1, 1, 1} };
					  
int letterH[4][3] = { {1, 0, 0},
                      {1, 0, 0},
											{1, 1, 1},
											{1, 0, 1} };
					  
int letterI[4][3] = { {1, 1, 1},
                      {0, 1, 0},
											{0, 1, 0},
											{1, 1, 1} };
					  
int letterJ[4][3] = { {1, 1, 1},
                      {0, 1, 0},
											{0, 1, 0},
											{1, 1, 0} };
					  
int letterK[4][3] = { {1, 0, 1},
                      {1, 0, 1},
											{1, 1, 0},
											{1, 0, 1} };
					  
int letterL[4][3] = { {1, 0, 0},
                      {1, 0, 0},
											{1, 0, 0},
											{1, 1, 1} };
					  
int letterM[4][3] = { {1, 0, 1},
                      {1, 1, 1},
											{1, 0, 1},
											{1, 0, 1} };
					  
int letterN[4][3] = { {0, 0, 0},
                      {1, 1, 1},
											{1, 0, 1},
											{1, 0, 1} };
					  
int letterO[4][3] = { {1, 1, 1},
                      {1, 0, 1},
											{1, 0, 1},
											{1, 1, 1} };
					  
int letterP[4][3] = { {1, 1, 1},
                      {1, 0, 1},
											{1, 1, 1},
											{1, 0, 0} };
					  
int letterQ[4][3] = { {1, 1, 1},
                      {1, 0, 1},
											{1, 1, 1},
											{0, 0, 1} };
					  
int letterR[4][3] = { {1, 1, 1},
                      {1, 0, 1},
											{1, 1, 0},
											{1, 0, 1} };
					  
int letterS[4][3] = { {1, 1, 1},
                      {1, 1, 0},
											{0, 0, 1},
											{1, 1, 1} };
					  
int letterT[4][3] = { {1, 1, 1},
                      {0, 1, 0},
											{0, 1, 0},
											{0, 1, 0} };
					  
int letterU[4][3] = { {1, 0, 1},
                      {1, 0, 1},
											{1, 0, 1},
											{1, 1, 1} };
					  
int letterV[4][3] = { {1, 0, 1},
                      {1, 0, 1},
											{1, 0, 1},
											{0, 1, 0} };
					  
int letterW[4][3] = { {1, 0, 1},
                      {1, 0, 1},
											{1, 1, 1},
											{1, 0, 1} };
					  
int letterX[4][3] = { {0, 0, 0},
                      {1, 0, 1},
											{0, 1, 0},
											{1, 0, 1} };
					  
int letterY[4][3] = { {1, 0, 1},
                      {1, 0, 1},
											{0, 1, 0},
											{0, 1, 0} };
					  
int letterZ[4][3] = { {1, 1, 1},
                      {0, 1, 1},
											{1, 0, 0},
											{1, 1, 1} };
											
//This is a new line
											