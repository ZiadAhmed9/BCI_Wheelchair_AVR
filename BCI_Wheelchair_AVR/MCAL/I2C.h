/*
 * I2C.h
 *
 * Created: 6/1/2023 1:18:01 AM
 *  Author: COMPUMARTS
 */ 


#ifndef I2C_H_
#define I2C_H_


#define I2C_START         0x08
#define I2C_REP_START     0x10
#define I2C_MT_SLA_W_ACK  0x18
#define I2C_MT_SLA_R_ACK  0x40
#define I2C_MT_DATA_ACK   0x28
#define I2C_MR_DATA_ACK   0x50
#define I2C_MR_DATA_NACK  0x58


void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(u8 data);
u8 I2C_Read_ACK(void);
u8 I2C_Read_NO_ACK(void);
u8 I2C_Status(void);



#endif /* I2C_H_ */