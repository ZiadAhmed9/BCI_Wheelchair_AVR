/*
 * SPI.c
 *
 * Created: 5/20/2023 12:42:13 AM
 *  Author: COMPUMARTS
 */ 
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"
#include "SPI.h"
/*Most significant figure transfer first in case of 
master rising edge is first
frequency is fosc\4 by default
by default Leading edge is the rising edge and 
trailing edge is the falling
by default the rising edge is sample, falling edge is setup*/
void SPI_Init(SPIMODE_type mode)
{
	if(mode==MASTER)
	{
	SET_BIT(SPCR,MSTR);
		
		//clock
	}
	else if(mode==SLAVE)
	{
	CLR_BIT(SPCR,MSTR);
		
	}
	SET_BIT(SPCR,SPE);
}


u8 SPI_SendReceive(u8 data)
{
	SPDR=data;
	while(!READ_BIT(SPSR,SPIF));
	return SPDR;
}


u8 SPI_ReceivePeriodic(u8* pdata)
{
	if(READ_BIT(SPSR,SPIF))
	{
		*pdata=SPDR;
		return 1;
	}
	return 0;
}

void SPI_SendNoBlock(u8 data)
{
	SPDR=data;
}