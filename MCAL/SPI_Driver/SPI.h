/*
 * SPI.h
 *
 * Created: 3/2/2023 9:19:56 PM
 *  Author: Mahmoud Essam
 */ 


#ifndef SPI_H_
#define SPI_H_


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
	uint8_t SPI_IRQ ;				// Specifies weather to enable or disable the interrupt in the SPI
									// Can be a value of @ref SPI_IRQ_deifne
							
	uint8_t SPI_DataOrder ;			// Specifies weather LSB or MSB will be transmitted first
									// Can be a value of @ref SPI_DataOrder_define
							
	uint8_t SPI_Mode ;				// Specifies weather the SPI will act as MASTER or SLAVE
									// Can be a value of @ref SPI_Mode_define
							
	uint8_t SPI_CPOL ;				// Specifies SPI Clock Polarity weather Leading Edge is Rising or falling
									// Can be a value of @ref SPI_CPOL_define

	uint8_t SPI_CPHA;				// Specifies SPI Clock Phase weather Leading Edge is Sample or Setup
									// Can be a value of @ref SPI_CPHA_define
							
	uint8_t SPI_Clock_Rate;			// These two bits control the SCK rate of the device configured as a Master.
									// Can be a value of @ref SPI_Clock_Rate_define
							
	uint8_t SPI_Double_Speed;		// Double the Speed of the SPI
									// Can be a value of @ref SPI_Double_Speed_define
									
	uint8_t SPI_Enable;				// Enable the SPI Peripheral 
									// Can be a value of @ref SPI_Enable_define

}SPI_Config;


//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref SPI_IRQ_deifne
//SPCR Register
#define SPI_IRQ_Enable		(uint8_t)(1 << SPIE)
#define SPI_IRQ_Disable		(uint8_t)(0)

//@ref SPI_DataOrder_define
//• Bit 5 – DORD: Data Order --> SPCR Register
#define SPI_DataOrder_LSB	(uint8_t)(1 << DORD)
#define SPI_DataOrder_MSB	(uint8_t)(0)

//@ref SPI_Mode_define
//• Bit 4 – MSTR: Master/Slave Select --> SPCR Register
#define SPI_Mode_Master		(uint8_t)(1 << MSTR)
#define SPI_Mode_Slave		(uint8_t)(0)

//@ref SPI_CPOL_define
//• Bit 3 – CPOL: Clock Polarity --> SPCR register
#define SPI_CPOL_Rising		(uint8_t)(0)
#define SPI_CPOL_Falling	(uint8_t)(1 << CPOL)

//@ref SPI_CPHA_define
//• Bit 2 – CPHA: Clock Phase --> SPCR register
#define SPI_CPHA_Sample		(uint8_t)(0)
#define SPI_CPHA_Setup		(uint8_t)(1 << CPHA)


//@ref SPI_Clock_Rate_define
//• Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0  --> SPCR register
#define SPI_Clock_Rate_Prescaler_4		(uint8_t)(0)
#define SPI_Clock_Rate_Prescaler_16		(uint8_t)(1 << SPR0)
#define SPI_Clock_Rate_Prescaler_64		(uint8_t)(1 << SPR1)
#define SPI_Clock_Rate_Prescaler_128	(uint8_t)( (1 << SPR1) | (1 << SPR0) )

//@ref SPI_Double_Speed_define
//• Bit 0 – SPI2X: Double SPI Speed Bit --> SPSR Register
#define SPI_Double_Speed_Enable		(uint8_t)(1 << SPI2X)
#define SPI_Double_Speed_Disable	(uint8_t)(0)

//@ref SPI_Enable_define
//• Bit 6 – SPE: SPI Enable --SPCR 
#define SPI_Enable_ENABLE			(uint8_t)(1 << SPE)
#define SPI_Enable_DISABLE			(uint8_t)(0)
//-----------------------------
//			APIs
//-----------------------------

void SPI_Master_Init(SPI_Config* SPI_Cfg_t);
void SPI_Slave_Init(SPI_Config* SPI_Cfg_t);

void SPI_Transmit(uint8_t data) ;
uint8_t SPI_Receive(void) ;
 


#endif /* SPI_H_ */