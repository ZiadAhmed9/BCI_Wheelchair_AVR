/*
 * BCI_Wheelchair_AVR.c
 *
 * Created: 5/20/2023 9:03:25 PM
 * Author : COMPUMARTS
 */ 
#define F_CPU 8000000
#include <util/delay.h>
#include "StdTypes.h"
#include "MemMap.h"
#include "MOTOR.h"
#include "DIO_Interface.h"
#include "Utils.h"
#include "EX_Interrupt.h"
#include "Move.h"
#include "SPI.h"
#include "UART.h"
#include "UART_Services.h"
#include "Timers_Services.h"
#include "Encoder.h"
#include "PID.h"
#include "UART_Services.h"
#include "I2C.h"



// void GET_Reading(void)
// {
// 	received_data=UART_ReceiveNoBlock();
// 	flag=1;
// }


int main(void)
{
	DIO_Init();
	UART_init();
	MOTOR_Init();
// 	MOTOR_Init();
// 	I2C_Init();
// 	ENCODER_Init();
	sei();
	UART_RX_InterruptEnable();
	UART_RX_SetCallBack(GET_BCIReading);
	
	while(1)
	{
		TEST_BCI();
		


	}
}

