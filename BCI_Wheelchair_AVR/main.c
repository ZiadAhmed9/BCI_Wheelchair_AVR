/*
 * BCI_Wheelchair_AVR.c
 *
 * Created: 5/20/2023 9:03:25 PM
 * Author : COMPUMARTS
 */ 
#define F_CPU 8000000
#include "StdTypes.h"
#include "MemMap.h"
#include "Motor.h"
#include "DIO_Interface.h"
#include "Utils.h"
#include "EX_Interrupt.h"
#include "Move.h"
#include "SPI.h"

int main(void)
{
	DIO_Init();
	sei();
	MOTOR_Init();
	EXI_Init();
	SPI_Init(SLAVE);
    while (1) 
    {
		MOVE();
    }
}

