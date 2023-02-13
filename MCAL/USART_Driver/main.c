/*
 * Atmega32_Drivers.c
 *
 * Created: 2/4/2023 5:37:15 PM
 * Author : Mahmoud Essam
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000UL
#include "MCAL/DIO_Driver/DIO.h"
#include "MCAL/USART_Driver/USART.h"
int main(void)
{
	char data ;
	
	USART_pinConfig pinCfg ;
	pinCfg.USART_BaudRate = USART_BaudRate_9600 ;
	pinCfg.USART_ClockPolarity = USART_ClockPolarity_Rising_TR ;
	pinCfg.USART_DataBits = USART_DataBits_8;
	pinCfg.USART_Mode = USART_Mode_Async ;
	pinCfg.USART_Parity_Mode = USART_Parity_Mode_disabled ;
	pinCfg.USART_StopBits = USART_StopBits_1Bit ;
	pinCfg.USART_TX_RX = USART_TX_RX_EN ;
	
	MCAL_USART_init(&pinCfg) ;

	MCAL_USART_SendData('M');
	MCAL_USART_SendData('Y');
	

    /* Replace with your application code */
    while (1) 
    {
		data = MCAL_USART_ReciveData();
		MCAL_USART_SendData(data);
    }
}

