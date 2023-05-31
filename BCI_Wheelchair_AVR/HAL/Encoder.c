/*
 * Encoder.c
 *
 * Created: 5/22/2023 12:50:31 AM
 *  Author: COMPUMARTS
 */ 
#include "MemMap.h"
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "Encoder.h"

void ENCODER_Read(Encoder_type encoder)
{
	switch(encoder)
	{
	case Encoder1:
		if(DIO_ReadPin(PINA0))
		pos_i++;
		else
		pos_i--;
	break;
	
	case Encoder2:
		if(DIO_ReadPin(PINA1))
		pos_ii++;
		else
		pos_ii--;
	break;
	}
}