/*
 * Move.c
 *
 * Created: 5/21/2023 12:23:50 AM
 *  Author: COMPUMARTS
 */ 
#include "MemMap.h"
#include "StdTypes.h"
#include "MOTOR.h"
#include "Move.h"
#include "SPI.h"

void MOVE(void)
{
	static u8 direction_speed;
	if(SPI_ReceivePeriodic(&direction_speed))
	{
		switch(direction_speed)
		{
			
		case STOP:
			MOTOR_Stop(M1);
			MOTOR_Stop(M2);
		return;
		case FORWARD_SPEED1:
			MOTOR_Forward(M1,speed1);
			MOTOR_Forward(M2,speed1);
		return;
		case FORWARD_SPEED2:
		MOTOR_Forward(M1,speed2);
		MOTOR_Forward(M2,speed2);
		return;
		case BACKWARD_SPEED1:
		MOTOR_Backward(M1,speed1);
		MOTOR_Backward(M2,speed1);	
		return;
		case BACKWARD_SPEED2:
		MOTOR_Backward(M1,speed2);
		MOTOR_Backward(M2,speed2);
		return;
		case RIGHT:
		MOTOR_Stop(M1);
		MOTOR_Forward(M2,speed2);
		return;
		case LEFT:
		MOTOR_Forward(M1,speed2);
		MOTOR_Stop(M2);
		return;
		}
	}
}