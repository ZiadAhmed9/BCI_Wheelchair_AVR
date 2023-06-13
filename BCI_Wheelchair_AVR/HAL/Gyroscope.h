/*
 * Gyroscope.h
 *
 * Created: 6/1/2023 2:04:00 AM
 *  Author: COMPUMARTS
 */ 


#ifndef GYROSCOPE_H_
#define GYROSCOPE_H_

#define GYRO_ADDRESS 0xD0

void GYRO_Init(void);
s32 GYRO_ReadRawValue(u8 reg);
s32 GYRO_ReadTemperature(void);

#endif /* GYROSCOPE_H_ */