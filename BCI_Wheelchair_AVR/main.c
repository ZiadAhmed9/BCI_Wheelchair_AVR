/*
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
#include "Timers_Services.h"
int main(void)
{
/* Replace with your application code */
DIO_Init();
sei();
MOTOR_Init();

// EXI_Init();
// SPI_Init(SLAVE);

MOTOR_Backward(speed1);
TIMER1_Pwm_Duty(50,Timer1A);
TIMER1_Pwm_Duty(50,Timer1B);

while (1)
{
// 	while(DIO_ReadPin(PINB7))
// 	{
// 
// 	}
// 					MOTOR_Stop(M1);
// 					MOTOR_Stop(M2);
// 	}
}
}
