/*
 * I2C.h
 *
 * Created: 6/1/2023 1:18:01 AM
 *  Author: COMPUMARTS
 */ 


#ifndef I2C_H_
#define I2C_H_

#define F_CPU 16000000
#define SCL_CLK 100000L							/* Define SCL clock frequency */
#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1))))) /* Define bit rate */

void I2C_Init();								/* I2C initialize function */
u8  I2C_Start(char);						/* I2C start function */
u8  I2C_Repeated_Start(char);				/* I2C repeated start function */
void I2C_Stop();								/* I2C stop function */
void I2C_Start_Wait(char);						/* I2C start wait function */
u8  I2C_Write(char);						/* I2C write function */
char I2C_Read_Ack();							/* I2C read ack function */
char I2C_Read_Nack();							/* I2C read nack function */



#endif /* I2C_H_ */