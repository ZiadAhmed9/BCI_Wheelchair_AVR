/*
 * Move.c
 *
 * Created: 5/21/2023 12:23:50 AM
 *  Author: COMPUMARTS
 */ 
#include "StdTypes.h"
#include "MemMap.h"
#include "MOTOR.h"
#include "Move.h"
#include "SPI.h"
#include "Encoder.h"
#include "PID.h"

//This function will decide the direction and speed of the vehicle depending on received data from SPI (master)
// void MOVE(void)
// {
// 	static u8 direction_speed;
// 	if(SPI_ReceivePeriodic(&direction_speed))
// 	{
// 		switch(direction_speed)
// 		{	
// 		case STOP:
// 		MOTOR_Stop(M1);
// 		MOTOR_Stop(M2);
// 		return;
// 		case FORWARD_SPEED1:
// 		MOTOR_Forward(M1,speed1);
// 		MOTOR_Forward(M2,speed1);
// 		return;
// 		case FORWARD_SPEED2:
// 		MOTOR_Forward(M1,speed2);
// 		MOTOR_Forward(M2,speed2);
// 		return;
// 		case BACKWARD_SPEED1:
// 		MOTOR_Backward(M1,speed1);
// 		MOTOR_Backward(M2,speed1);	
// 		return;
// 		case BACKWARD_SPEED2:
// 		MOTOR_Backward(M1,speed2);
// 		MOTOR_Backward(M2,speed2);
// 		return;
// 		case RIGHT:
// 		MOTOR_Stop(M1);
// 		MOTOR_Forward(M2,speed2);
// 		return;
// 		case LEFT:
// 		MOTOR_Forward(M1,speed2);
// 		MOTOR_Stop(M2);
// 		return;
// 		}
// 	}
// }
void MOVE(void)
{
	static u8 direction_speed;
	if(SPI_ReceivePeriodic(&direction_speed))
	{
		switch(direction_speed)
		{
			case STOP:
			RESET();
			return;
			case FORWARD_SPEED1:
			PID_Result(50);
			return;
			case FORWARD_SPEED2:
			PID_Result(100);
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

void TEST_FORWARD(void)
{
	MOTOR_Forward(M1,speed1);
	MOTOR_Forward(M2,speed1);
}

void TEST_Backward(void)
{
	MOTOR_Backward(M1,speed1);
	MOTOR_Backward(M2,speed1);
}
