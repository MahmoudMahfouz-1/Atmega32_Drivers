/*
 * USART.c
 *
 * Created: 2/8/2023 5:18:28 PM
 *  Author: Mahmoud Essam
 */ 

//-----------------------------
//INFO
//-----------------------------

//• TXD – Port D, Bit 1
//TXD, Transmit Data (Data output pin for the USART). When the USART Transmitter is enabled,
//this pin is configured as an output regardless of the value of DDD1.
//• RXD – Port D, Bit 0
//RXD, Receive Data (Data input pin for the USART). When the USART Receiver is enabled this
//pin is configured as an input regardless of the value of DDD0. When the USART forces this pin
//to be an input, the pull-up can still be controlled by the PORTD0 bit.


//-----------------------------
//Includes
//-----------------------------

#include "USART.h"

//-----------------------------
// Global Variables
//-----------------------------

USART_pinConfig Global_pinCfg ;

// ==================================

// Asynchronous Mode ONLY 
// 9Bit Mode Isn't Supported
void MCAL_USART_init(USART_pinConfig* pinCfg) 
{
	Global_pinCfg = *pinCfg ;
	
	//The URSEL must be one when writing the UCSRC
	UCSRC |= (1 << URSEL) ;

	UCSRC |= pinCfg->USART_Parity_Mode | pinCfg->USART_StopBits | pinCfg->USART_Mode | pinCfg->USART_ClockPolarity ;
	
	// Data Bits
	if(pinCfg->USART_DataBits != USART_DataBits_9)
		{	
			UCSRC |= pinCfg->USART_DataBits ;
		}
	else
		{
			UCSRC |= (uint8_t)((1 << 1) | (1 << 2)) ;
			UCSRB |= (uint8_t)(1 << 2) ;
		}
			
	//UCSRC &= ~(1 << URSEL) ;
	
	// Baud Rate
	// Only Normal Mode Supported 
	// Fast Asynchronous Mode isn't supported yet
	UBRRL = pinCfg->USART_BaudRate ; 

	UCSRB |= pinCfg->USART_TX_RX ;
	
}


void MCAL_USART_DeInit(void) 
{
	UCSRC = 0;
	UCSRB = 0;
}


void MCAL_USART_SendData(uint8_t data) 
{
	while( !(UCSRA & (1 << UDRE)) ) ;
	UDR = data ;
	
}

uint8_t MCAL_USART_ReciveData(void) 
{
	while ( !(UCSRA & (1<<RXC)) ) ;
	return UDR;
}
