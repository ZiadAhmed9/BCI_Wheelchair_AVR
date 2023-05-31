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
#include "Timers_Services.h"
#include "Encoder.h"
#include "PID.h"

int main(void)
{
	DIO_Init();
	sei();
	MOTOR_Init();
	EXI_Init();
	SPI_Init(SLAVE);
	Timer1_SetInterruptTime_ms(1,millis);
	ENCODER_Init();
	while(1) 
    {
		PID_Result(128);
    }
}

