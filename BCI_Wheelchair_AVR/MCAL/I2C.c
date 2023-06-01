/*
 * I2C.c
 *
 * Created: 6/1/2023 1:18:11 AM
 *  Author: COMPUMARTS
 */ 

#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"
#include "I2C.h"


void I2C_Init(void)
{
	/*we need 400 khz Sck*/
	TWBR=0x02;
	TWSR=0x00;
	/* Two Wire Bus address my address if any master device want to call me: 0x1 (used in case this MC is a slave device)
	       General Call Recognition: Off */
	TWAR=0b00000010;
	SET_BIT(TWCR,TWEN);   //TWI enable bit
}

void I2C_Start(void)
{
    /*
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR|=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	/* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
	    while(BIT_IS_CLEAR(TWCR,TWINT));
    }

void I2C_Stop(void)
{
    /*
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void I2C_Write(u8 data)
{
    /* Put data On TWI data Register */
    TWDR = data;
    /*
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
}

u8 I2C_Read_ACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}

u8 I2C_Read_NO_ACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}

u8 I2C_Status(void)
{
    u8 status;
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    status = TWSR & 0xF8;
    return status;
}