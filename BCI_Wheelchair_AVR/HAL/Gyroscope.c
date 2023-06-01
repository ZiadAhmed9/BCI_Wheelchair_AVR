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


void GYRO_Init(void){
	_delay_ms(150);	
    I2C_Start();
    I2C_Write(GYRO_ADDRESS);
    I2C_Write(0x6B);  // Power management register
    I2C_Write(0x00);  // Wake up MPU6050
    I2C_Stop();
}

u16 GYRO_ReadRawValue(u8 reg)
{
	    u16 value;

	    I2C_Start();
	    I2C_Write(GYRO_ADDRESS);
	    I2C_Write(reg);
	    I2C_Start();
	    I2C_Write(GYRO_ADDRESS | 0x01);
	    value = (I2C_Read_ACK() << 8);
	    value |= I2C_Read_NO_ACK();
	    I2C_Stop();

	    return value;
}


u16 GYRO_ReadTemperature(void)
{
    u16 temperature;
    
    I2C_Start();
    I2C_Write(GYRO_ADDRESS);
    I2C_Write(0x41);  // Temperature register
    I2C_Start();
    I2C_Write(GYRO_ADDRESS | 0x01);
    temperature = (I2C_Read_ACK() << 8);
    temperature |= I2C_Read_NO_ACK();
    I2C_Stop();
    
    return temperature;	
}