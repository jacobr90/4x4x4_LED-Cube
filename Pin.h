/*----------------------------------------------------------------------------
 * Name:    Pin.h
 * Purpose: 
 * Note(s):
 *----------------------------------------------------------------------------
 *----------------------------------------------------------------------------*/

#ifndef __PIN_H
#define __PIN_H

//Pin representation by Port and Number
typedef struct
{
	char port;
	int num;
} Pin;

//Block of pins, lower right of Discovery board
extern Pin  A8,A9,A10,A13,A14,A15,
						C6,C7,C8,C9,C10,C11,C12,
						D0,D1,D2,D3,D4,D5,D6;

//Functions
extern void PortA_Init(void);
extern void PortB_Init(void);
extern void PortC_Init(void);
extern void PortD_Init(void);
extern void Pin_Init (void);
extern void PinOn  (Pin p);
extern void PinOff (Pin p);
extern Pin LayerChecker(int i);

#endif
