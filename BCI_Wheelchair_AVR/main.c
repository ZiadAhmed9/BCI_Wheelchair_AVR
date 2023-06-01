/*
 * BCI_Wheelchair_AVR.c
 *
 * Created: 5/20/2023 9:03:25 PM
 * Author : COMPUMARTS
 */ 
#define F_CPU 16000000
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
#include "UART_Services.h"
#include "I2C.h"

int main(void)
{
	float temperature,gyroX, gyroY, gyroZ;
	DIO_Init();
	sei();
// 	MOTOR_Init();
// 	EXI_Init();
// 	SPI_Init(SLAVE);
// 	Timer1_SetInterruptTime_ms(1,millis);
// 	ENCODER_Init();
	I2C_Init();
	UART_init();
	GYRO_Init();
		float Xa,Ya,Za,t;
	while(1) 
    {
		gyroX = GYRO_ReadRawValue(0x43);
		gyroY = GYRO_ReadRawValue(0x45);
		gyroZ = GYRO_ReadRawValue(0x47);
 		temperature = GYRO_ReadRawValue(0x41);
		_delay_ms(1000);
/*		UART_SendString("Gyroscope X: ");*/
Xa = gyroY/16384.0;
		UART_SendData(Xa);
// 		UART_SendString("  Y: ");
// 		UART_SendData(gyroY >> 8);
// 		UART_SendData(gyroY);
// 		UART_SendString("  Z: ");
// 		UART_SendData(gyroZ >> 8);
// 		UART_SendData(gyroZ);
// 		UART_SendString("  Temperature: ");
// 		UART_SendData(temperature >> 8);
// 		UART_SendData(temperature);
// 		UART_SendData('\n');
    }
}

