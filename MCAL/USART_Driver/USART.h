/*
 * USART.h
 *
 * Created: 2/8/2023 5:18:40 PM
 *  Author: Mahmoud Essam
 */ 


#ifndef USART_H_
#define USART_H_

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
	uint8_t USART_Mode ;			// selects between Asynchronous and Synchronous mode of operation.
									// Can be defined as a value of @ref USART_Mode_define
								
	uint8_t USART_Parity_Mode ;		// selects the parity mode
									// Can be defined as a value of @ref USART_Parity_Mode_define
									
	uint8_t USART_StopBits ;		// selects the number of Stop Bits to be inserted by the Transmitter
									// Can be defined as a value of @ref USART_StopBits_define
									
	uint8_t USART_DataBits ;		// sets the number of data bits (Character Size) in a frame the Receiver and Transmitter use.
									// Can be defined as a value of @ref USART_DataBits_define
									
	uint8_t USART_ClockPolarity ;	// This bit is used for Synchronous mode only. Write this bit to zero in Asynchronous mode									// Can be defined as a value of @ref USART_ClockPolarity_define
									
	uint8_t USART_BaudRate ;		// Specify BuadRate For the USART
									// Can be defined as a value of @ref USART_BaudRate_define
	
	uint8_t USART_TX_RX ;		    // selects which is enabled TX or RX or BOTH
									// Can be defined as a value of @ref USART_TX_RX_define
	
}USART_pinConfig;



//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref USART_Mode_define
//• Bit 6 – UMSEL: USART Mode Select  --> UCSRC 
//This bit selects between Asynchronous and Synchronous mode of operation.
#define USART_Mode_Async	(uint8_t)(0)
#define USART_Mode_Sync		(uint8_t)(1 << 6)


//@ref USART_Parity_Mode_define
//• Bit 5:4 – UPM1:0: Parity Mode  --> UCSRC 
#define USART_Parity_Mode_disabled		(uint8_t)(0)
#define USART_Parity_Mode_reversed		(uint8_t)(1 << 4)
#define USART_Parity_Mode_Even			(uint8_t)(1 << UPM1)
#define USART_Parity_Mode_Odd			(uint8_t)( (1 << 4) | (1 << 5) )


//@ref USART_StopBits_define
//• Bit 3 – USBS: Stop Bit Select  --> UCSRC 
#define USART_StopBits_1Bit				(uint8_t)(0)
#define USART_StopBits_2Bits			(uint8_t)(1 << 3)


//@ref USART_DataBits_define
// 9Bit Mode Isn't Supported
//• Bit 2:1 – UCSZ1:0: Character Size --> UCSRC , UCSZ2 --> UCSRB
#define USART_DataBits_5				(uint8_t)(0)
#define USART_DataBits_6				(uint8_t)(1 << 1)
#define USART_DataBits_7				(uint8_t)(1 << 2)
#define USART_DataBits_8				(uint8_t)((1 << 1) | (1 << 2))
#define USART_DataBits_9				(uint8_t)(9)		// this case (uint8_t)((1 << 1) | (1 << 2)) and put 1 in UCSZ2 --> UCSRB


//@ref USART_ClockPolarity_define
//• Bit 0 – UCPOL: Clock Polarity
#define USART_ClockPolarity_Rising_TR		(uint8_t)(0)
#define USART_ClockPolarity_Falling_TR		(uint8_t)(1 << 0)


//@ref USART_BaudRate_define
// At Fcpu = 8Mhz
#define USART_BaudRate_2400		207
#define USART_BaudRate_4800		103
#define USART_BaudRate_9600		51
#define USART_BaudRate_14_4k	34
#define USART_BaudRate_19_2k	25
#define USART_BaudRate_28_8k	16


//@ref USART_TX_RX_define 
//• Bit 4 – RXEN: Receiver Enable  --> UCSRB
//• Bit 3 – TXEN: Transmitter Enable  --> UCSRB
#define USART_TX_EN			(uint8_t)(1 << 3)
#define USART_RX_EN			(uint8_t)(1 << 4)
#define USART_TX_RX_EN		(uint8_t)((1 << 3) | (1 << 4) )



//-----------------------------
//			APIs
//-----------------------------

void MCAL_USART_init(USART_pinConfig* pinCfg) ;
void MCAL_USART_DeInit(void) ;

void MCAL_USART_SendData(uint8_t data) ;
uint8_t MCAL_USART_ReciveData(void) ;




#endif /* USART_H_ */