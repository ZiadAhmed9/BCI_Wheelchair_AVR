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
void Read_RawValue(float* Acc_x,float* Acc_y,float* Acc_z,float* Gyro_x,float* Gyro_y,float* Gyro_z,float* Temperature);
void Read_RawValue2(float** Acc_x,float** Acc_y,float** Acc_z,float** Gyro_x,float** Gyro_y,float** Gyro_z,float** Temperature);
// s32 GYRO_ReadTemperature(void);

#endif /* GYROSCOPE_H_ */