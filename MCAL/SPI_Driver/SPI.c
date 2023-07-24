/*
 * SPI.c
 *
 * Created: 3/2/2023 9:19:41 PM
 *  Author: Mahmoud Essam
 */ 

//-----------------------------
//Includes
//-----------------------------

#include "SPI.h"

//-----------------------------
// Global Variables
//-----------------------------


//-----------------------------
// Local Macros
//-----------------------------
#define SPI_DDR DDRB
#define SPI_PORT PORTB

//-----------------------------
// Generic Functions
//-----------------------------

void SPI_Master_Init(SPI_Config* SPI_Cfg_t)
{
	//PB7 SCK (SPI Bus Serial Clock)
	//PB6 MISO (SPI Bus Master Input/Slave Output)
	//PB5 MOSI (SPI Bus Master Output/Slave Input)
	//PB4 SS (SPI Slave Select Input)
	SPI_DDR |= (1 << PB5) |  (1 << PB4) | (1 << PB7) ;
	
	SPCR |= (SPI_Cfg_t->SPI_IRQ) | (SPI_Cfg_t->SPI_Enable) | (SPI_Cfg_t->SPI_DataOrder) | (SPI_Cfg_t->SPI_Mode) | (SPI_Cfg_t->SPI_CPOL) | (SPI_Cfg_t->SPI_CPHA) | (SPI_Cfg_t->SPI_Clock_Rate) ;

	SPSR |= SPI_Cfg_t ->SPI_Double_Speed ;
}

void SPI_Slave_Init(SPI_Config* SPI_Cfg_t)
{
	//PB7 SCK (SPI Bus Serial Clock)
	//PB6 MISO (SPI Bus Master Input/Slave Output)
	//PB5 MOSI (SPI Bus Master Output/Slave Input)
	//PB4 SS (SPI Slave Select Input)
	SPI_DDR |= (1 << PB6) ;
	
	SPCR |= (SPI_Cfg_t->SPI_IRQ) | (SPI_Cfg_t->SPI_Enable) | (SPI_Cfg_t->SPI_DataOrder) | (SPI_Cfg_t->SPI_Mode) | (SPI_Cfg_t->SPI_CPOL) | (SPI_Cfg_t->SPI_CPHA) | (SPI_Cfg_t->SPI_Clock_Rate) ;

	SPSR |= SPI_Cfg_t ->SPI_Double_Speed ;
}


void SPI_Transmit(uint8_t data) 
{
	SPDR = data ;
	
	while(!(SPSR & (1<<SPIF))) ;
}


uint8_t SPI_Receive(void)
{
	while(!(SPSR & (1<<SPIF))) ;
	
	return SPDR;
}

