/*
 * Move.c
 *
 * Created: 5/21/2023 12:23:50 AM
 *  Author: COMPUMARTS
 */ 
#include "Motor.h"
#include "MemMap.h"


void STOP(void)
{
	MOTOR_Stop(M1);
	MOTOR_Stop(M2);
}

void MoveForward(void)
{
	MOTOR_Forward(M1,speed1);
	MOTOR_Forward(M2,speed1);
}