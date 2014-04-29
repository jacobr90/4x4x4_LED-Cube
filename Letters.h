#ifndef __LETTERS_H
#define __LETTERS_H

typedef struct 
{
	//letter represented as 1s and 0s in a 4x3 Matrix
	int rep[4][3];
	//Start "drawing" from bottom left corner
	int basePin;
}letter;

extern void buildScrollBase(void);
extern void drawLetter(letter l, int i);

extern int letterA[4][3];					  
extern int letterB[4][3];					  
extern int letterC[4][3];					  
extern int letterD[4][3];					  
extern int letterE[4][3];					  
extern int letterF[4][3];					  
extern int letterG[4][3];					  
extern int letterH[4][3];					  
extern int letterI[4][3];					  
extern int letterJ[4][3];					  
extern int letterK[4][3];					  
extern int letterL[4][3];					  
extern int letterM[4][3];					  
extern int letterN[4][3];					  
extern int letterO[4][3];					  
extern int letterP[4][3];					  
extern int letterQ[4][3];					  
extern int letterR[4][3];					  
extern int letterS[4][3];					  
extern int letterT[4][3];					  
extern int letterU[4][3];					  
extern int letterV[4][3];					  
extern int letterW[4][3];					  
extern int letterX[4][3];					  
extern int letterY[4][3];					  
extern int letterZ[4][3];

#endif
