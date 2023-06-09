/*
 * Gyroscope.c
 *
 * Created: 6/1/2023 2:04:11 AM
 *  Author: COMPUMARTS
 */ 

#include "MemMap.h"
#include "StdTypes.h"
#include "I2C.h"
#include "Gyroscope.h"
#include "GYROSCOPE_Cfg.h"
#include <util/delay.h>
// extern float  Acc_x,Acc_y,Acc_z,Temperature,Gyro_x,Gyro_y,Gyro_z;
void GYRO_Init()			/* Gyro initialization function */
{
	_delay_ms(150);			/* Power up time >100ms */
	I2C_Start_Wait(0xD0);	/* Start with device write address */
	I2C_Write(SMPLRT_DIV);	/* Write to sample rate register */
	I2C_Write(0x07);		/* 1KHz sample rate */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(PWR_MGMT_1);	/* Write to power management register */
	I2C_Write(0x01);		/* X axis gyroscope reference frequency */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(CONFIG);		/* Write to Configuration register */
	I2C_Write(0x00);		/* Fs = 8KHz */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(GYRO_CONFIG);	/* Write to Gyro configuration register */
	I2C_Write(0x18);		/* Full scale range +/- 2000 degree/C */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(INT_ENABLE);	/* Write to interrupt enable register */
	I2C_Write(0x01);
	I2C_Stop();
}

void MPU_Start_Loc()
{
	I2C_Start_Wait(0xD0);		/* I2C start with device write address */
	I2C_Write(ACCEL_XOUT_H);	/* Write start location address from where to read */
	I2C_Repeated_Start(0xD1);	/* I2C start with device read address */
}

void Read_RawValue(float* Acc_x,float* Acc_y,float* Acc_z,float* Gyro_x,float* Gyro_y,float* Gyro_z,float* Temperature)
{
	MPU_Start_Loc();			/* Read Gyro values */
	*Acc_x = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	*Acc_y = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	*Acc_z = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	*Temperature = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
 	Gyro_x = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
 	Gyro_y = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
 	Gyro_z = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Nack());
	I2C_Stop();
}

void Read_RawValue2(float** Acc_x,float** Acc_y,float** Acc_z,float** Gyro_x,float** Gyro_y,float** Gyro_z,float** Temperature)
{
	MPU_Start_Loc();			/* Read Gyro values */
	*(*Acc_x) = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	*(*Acc_y)= (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	*(*Acc_z) = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	*(*Temperature) = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Gyro_x = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Gyro_y = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Gyro_z = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Nack());
	I2C_Stop();
}