/*
 * DIO.c
 *
 * Created: 2/4/2023 5:38:17 PM
 *  Author: Mahmoud Essam
 */ 

//-----------------------------
//Includes
//-----------------------------
#include "DIO.h"


//-----------------------------
// Global Variables
//-----------------------------
DIO_PinConfig Global_pinCfg = {0};


uint8_t Get_PinNumber()
{
	switch (Global_pinCfg.DIO_PinNumber)
	{
		case 0:	return DIO_PinNumber_0;
		case 1:	return DIO_PinNumber_1;
		case 2:	return DIO_PinNumber_2;
		case 3:	return DIO_PinNumber_3;
		case 4:	return DIO_PinNumber_4;
		case 5:	return DIO_PinNumber_5;
		case 6:	return DIO_PinNumber_6;
		case 7:	return DIO_PinNumber_7;
	}
	return 0;
}

void MCAL_DIO_Init(DIO_PinConfig* pinCfg, uint8_t PORTx)
{
	Global_pinCfg = *pinCfg;
	uint8_t pinNumber = Get_PinNumber();
	if(PORTx == DIOA)
	{
		// If Pin is Output
		if(pinCfg->DIO_Mode == DIO_Mode_Output_Low)
		{
			DDRA |= (1<<pinNumber);
			PORTA &= ~(1<<pinNumber);
		}
		if(pinCfg->DIO_Mode == DIO_Mode_Output_High)
		{
			DDRA |= (1<<pinNumber);
			PORTA |= (1<<pinNumber);
		}
		if(pinCfg->DIO_Mode == DIO_Mode_Input_FLO)
		{
			PORTA &= ~(1<<pinNumber);
			DDRA &= ~(1<<pinNumber);
		}
		if(pinCfg->DIO_Mode == DIO_Mode_Input_With_PU)
		{
			PORTA |= (1<<pinNumber);
			DDRA &= ~(1<<pinNumber);
		}
	}
	else if (PORTx == DIOB)
	{
		if(pinCfg->DIO_Mode == DIO_Mode_Output_Low)
		{
			DDRB |= (1<<pinNumber);
			PORTB &= ~(1<<pinNumber);
		}
		if(pinCfg->DIO_Mode == DIO_Mode_Output_High)
		{
			DDRB |= (1<<pinNumber);
			PORTB |= (1<<pinNumber);
		}
		if(pinCfg->DIO_Mode == DIO_Mode_Input_FLO)
		{
			PORTB &= ~(1<<pinNumber);
			DDRB &= ~(1<<pinNumber);
		}
		if(pinCfg->DIO_Mode == DIO_Mode_Input_With_PU)
		{
			PORTB |= (1<<pinNumber);
			DDRB &= ~(1<<pinNumber);
		}
	}
	else if (PORTx == DIOC)
	{
		if(pinCfg->DIO_Mode == DIO_Mode_Output_Low)
		{
			DDRC |= (1<<pinNumber);
			PORTC &= ~(1<<pinNumber);
		}
		if(pinCfg->DIO_Mode == DIO_Mode_Output_High)
		{
			DDRC |= (1<<pinNumber);
			PORTC |= (1<<pinNumber);
		}
		if(pinCfg->DIO_Mode == DIO_Mode_Input_FLO)
		{
			PORTC &= ~(1<<pinNumber);
			DDRC &= ~(1<<pinNumber);
		}
		if(pinCfg->DIO_Mode == DIO_Mode_Input_With_PU)
		{
			PORTC |= (1<<pinNumber);
			DDRC &= ~(1<<pinNumber);
		}
	}
	else if (PORTx == DIOD)
	{
		if(pinCfg->DIO_Mode == DIO_Mode_Output_Low)
		{
			DDRD |= (1<<pinNumber);
			PORTD &= ~(1<<pinNumber);
		}
		if(pinCfg->DIO_Mode == DIO_Mode_Output_High)
		{
			DDRD |= (1<<pinNumber);
			PORTD |= (1<<pinNumber);
		}
		if(pinCfg->DIO_Mode == DIO_Mode_Input_FLO)
		{
			PORTD &= ~(1<<pinNumber);
			DDRD &= ~(1<<pinNumber);
		}
		if(pinCfg->DIO_Mode == DIO_Mode_Input_With_PU)
		{
			PORTD |= (1<<pinNumber);
			DDRD &= ~(1<<pinNumber);
		}
	}
	
}
void MCAL_DIO_DeInit(uint8_t PORTx)
{
	if(PORTx == DIOA)
	{
		PORTA = 0;
		DDRA = 0;
	}
	if(PORTx == DIOB)
	{
		PORTB = 0;
		DDRB = 0;
	}
	if(PORTx == DIOC)
	{
		PORTC = 0;
		DDRC = 0;
	}
	if(PORTx == DIOD)
	{
		PORTD = 0;
		DDRD = 0;
	}
}



void MCAL_DIO_WritePin(uint8_t PORTx, uint8_t pinNuber, uint8_t Value)
{
	if(PORTx == DIOA)
	{
		PORTA |= (Value << pinNuber);
	}
	if(PORTx == DIOB)
	{
		PORTB |= (Value << pinNuber);
	}
	if(PORTx == DIOC)
	{
		PORTC |= (Value << pinNuber);
	}
	if(PORTx == DIOD)
	{
		PORTD |= (Value << pinNuber);
	}
}
void MCAL_DIO_WritePort(uint8_t PORTx, uint8_t Value)
{
	if(PORTx == DIOA)
	{
		PORTA = (Value);
	}
	if(PORTx == DIOB)
	{
		PORTB = (Value);
	}
	if(PORTx == DIOC)
	{
		PORTC = (Value);
	}
	if(PORTx == DIOD)
	{
		PORTD = (Value);
	}
}


uint8_t MCAL_DIO_ReadPin(uint8_t PORTx, uint8_t pinNuber)
{
	uint8_t value = 0;
	if(PORTx == DIOA)
	{
		value = (PINA & (1 << pinNuber) );
	}
	if(PORTx == DIOB)
	{
		value = (PINB & (1 << pinNuber) );
	}
	if(PORTx == DIOC)
	{
		value = (PINC & (1 << pinNuber) );
	}
	if(PORTx == DIOD)
	{
		value = (PIND & (1 << pinNuber) );
	}
	return value ;
}
uint8_t MCAL_DIO_ReadPort(uint8_t PORTx)
{
	int value = 0;
	if(PORTx == DIOA)
	{
		value = PINA;
	}
	if(PORTx == DIOB)
	{
		value = PINB;
	}
	if(PORTx == DIOC)
	{
		value = PINC;
	}
	if(PORTx == DIOD)
	{
		value = PIND;
	}
	return value ;
}





