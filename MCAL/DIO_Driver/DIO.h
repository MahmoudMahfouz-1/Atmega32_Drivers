/*
 * DIO.h
 *
 * Created: 2/4/2023 5:38:32 PM
 *  Author: Mahmoud Essam
 */ 


#ifndef DIO_H_
#define DIO_H_

//-----------------------------
//Includes
//-----------------------------
#include "avr/io.h"
#include "stdlib.h"
#include "stdint.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct 
{
	uint8_t DIO_PinNumber ;		// Specifies Pin Number
								// The parameter can be a value of @ref DIO_PinNumber_define
								
	uint8_t DIO_Mode ;			// Specifies the DIO pin Mode to be configured
								// The parameter can be a value of @ref DIO_Mode_define
								
}DIO_PinConfig;






//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref DIO_PinNumber_define
#define DIO_PinNumber_0		((uint8_t)0)
#define DIO_PinNumber_1		((uint8_t)1)
#define DIO_PinNumber_2		((uint8_t)2)
#define DIO_PinNumber_3		((uint8_t)3)
#define DIO_PinNumber_4		((uint8_t)4)
#define DIO_PinNumber_5		((uint8_t)5)
#define DIO_PinNumber_6		((uint8_t)6)
#define DIO_PinNumber_7		((uint8_t)7)

//@ref DIO_Mode_define
#define DIO_Mode_Input_FLO			((uint8_t)0) // Tri-state (Hi-Z)
#define DIO_Mode_Input_With_PU		((uint8_t)1) // (Input with pull up Resistance)Pxn will source current if ext. pulled low.
#define DIO_Mode_Output_Low 		((uint8_t)2) // Output Low (Sink)
#define DIO_Mode_Output_High		((uint8_t)3) // Output High (Source)


//@ref DIO_PORT_define
#define DIOA 1	// PORTA	
#define DIOB 2	// PORTB
#define DIOC 3	// PORTC	
#define DIOD 4	// PORTD


//-----------------------------
//			APIs
//-----------------------------

void MCAL_DIO_Init(DIO_PinConfig* pinCfg, uint8_t PORTx);
void MCAL_DIO_DeInit(uint8_t PORTx);

void MCAL_DIO_WritePin(uint8_t PORTx, uint8_t pinNuber, uint8_t Value);
void MCAL_DIO_WritePort(uint8_t PORTx, uint8_t Value);

uint8_t MCAL_DIO_ReadPin(uint8_t PORTx, uint8_t pinNuber);
uint8_t MCAL_DIO_ReadPort(uint8_t PORTx);
#endif /* DIO_H_ */