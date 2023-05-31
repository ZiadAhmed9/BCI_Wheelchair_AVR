/*
 * Encoder.c
 *
 * Created: 5/22/2023 12:50:31 AM
 *  Author: COMPUMARTS
 */ 
#include "MemMap.h"
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "EX_Interrupt.h"
#include "Encoder.h"


void ENCODER_Init(void)
{
	EXI_Enable(EX_INT0);
	EXI_Enable(EX_INT1);
	EXI_TriggerEdge(EX_INT0,RISING_EDGE);
	EXI_TriggerEdge(EX_INT1,RISING_EDGE);	
	EXI_SetCallBack(EX_INT0,ENCODER1_Read);
	EXI_SetCallBack(EX_INT1,ENCODER2_Read);
}
void ENCODER1_Read(void)
{
	if(DIO_ReadPin(PINA1))
	pos_i++;
	else
	pos_i--;
}

void ENCODER2_Read(void)
{
	if(DIO_ReadPin(PINA1))
	pos_ii++;
	else
	pos_ii--;
}