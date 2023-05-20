/*
 * DIO.c
 *
 * Created: 5/9/2023 2:26:55 PM
 *  Author: COMPUMARTS
 */ 


#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include <DIO_Private.h>

/* The following function will loop through an array of 32 element each corresponding to a pin
each value in the array is a value from the enum DIO_PinStatus_type which has 3 values
either OUTPUT, INFREE, OR INPULL*/
void DIO_Init(void)
{
	DIO_Pin_type i;   // pin type (PINA0,A1,A2) enum declared in the DIO_interface.h
	for(i=PINA0;i<TOTAL_PINS;i++)   //i=A0=0
	{
		DIO_InitPin(i,PinsStatusArray[i]); //for pin A0 initialize the pin with the value in index PINA0"0" in the PinStatusArray
	}
	
}

// The following function takes port and pin to initialize
void DIO_InitPortPin(DIO_Port_type port,u8 pin_num,DIO_PinStatus_type status)
{
	switch(status)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;			
			case PD:
			SET_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;			
		}
		break;
		
		case INFREE:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		
		case INPULL:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
		}		
		break;
	}
}

// The following function takes pin name to initialize

static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status)
{
	DIO_Port_type port= pin/8;
	u8 pin_num=pin%8;
	switch(status)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		
		case INFREE:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		
		case INPULL:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
	}
}

// The following function takes pin name to write a value on an output pin

void DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt)
{
	DIO_Port_type port= pin/8;
	u8 pin_num=pin%8;
	switch(volt)
	{
		
		case HIGH:
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
		
	case LOW:
	switch(port)
	{
		case PA:
		CLR_BIT(PORTA,pin_num);
		break;
		case PB:
		CLR_BIT(PORTB,pin_num);
		break;
		case PC:
		CLR_BIT(PORTC,pin_num);
		break;
		case PD:
		CLR_BIT(PORTD,pin_num);
		break;
	}
	break;
	}
}


void DIO_WritePortPin(DIO_Port_type port,u8 pin_num,DIO_PinVoltage_type volt)
{
	switch(volt)
	{
		
		case HIGH:
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
		
		case LOW:
		switch(port)
		{
			case PA:
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
	}
}

// The following function takes pin name to read a value on an input pin
//notice the type returned from the function it is a value from HIGH,LOW from enum in DIO_interface


DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin)
{
	DIO_Port_type port= pin/8;
	u8 pin_num=pin%8;
	DIO_PinVoltage_type volt=LOW;
	switch(port)
	{
		case PA:
		volt=READ_BIT(PINA,pin_num);
		break;
		case PB:
		volt=READ_BIT(PINB,pin_num);
		break;
		case PC:
		volt=READ_BIT(PINC,pin_num);
		break;
		case PD:
		volt=READ_BIT(PIND,pin_num);
		break;
	}
	
	return volt;

}


//the next function toggles a pin
void DIO_TogglePin(DIO_Pin_type pin)
{
	DIO_Port_type port= pin/8;
	u8 pin_num=pin%8;
	switch(port)
	{
		case PA:
		TOG_BIT(PORTA,pin_num);
		break;
		case PB:
		TOG_BIT(PORTB,pin_num);
		break;
		case PC:
		TOG_BIT(PORTC,pin_num);
		break;
		case PD:
		TOG_BIT(PORTD,pin_num);
		break;
	}
}
void DIO_WritePort(DIO_Port_type port,u8 value)
{
	switch(port)
	{
		case PA:
		PORTA=value;
		
		break;
		case PB:
		PORTB=value;
		break;
		case PC:
		PORTC=value;
		break;
		case PD:
		PORTD=value;
		break;
	}
	
	
	
}





// Error_t DIO_ReadPin(DIO_Port_type port, u8 pin_num,DIO_PinVoltage_type* Pvolt)
// {
// 	if(Pvolt==NULLPTR)
// 	{
// 		return NULL_PTR_ERROR
// 	}
// 	else if ((port>PD)||(pin_num>7))
// 	{
// 		return OUT_OF_RANGE;
// 	}
// 	else
// 	{
// 		switch(port)
// 		{
// 			case PA:
// 			*Pvolt=READ_BIT(PINA,pin_num);
// 			break;
// 			case PB:
// 			*Pvolt=READ_BIT(PINB,pin_num);
// 			break;
// 			case PC:
// 			*Pvolt=READ_BIT(PINC,pin_num);
// 			break;
// 			case PD:
// 			*Pvolt=READ_BIT(PIND,pin_num);
// 			break;
// 		}
// 		return OK;
// 	}
// }