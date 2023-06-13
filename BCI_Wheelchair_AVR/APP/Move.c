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

u8 received_data='0',Data_received_flag=0;

extern void GET_BCIReading(void)
{
	received_data=UART_ReceiveNoBlock();
	Data_received_flag=1;
}
// This function will decide the direction and speed of the vehicle depending on received data from SPI (master)
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
// void MOVE(void)
// {
// 	static u8 direction_speed;
// 	if(SPI_ReceivePeriodic(&direction_speed))
// 	{
// 		switch(direction_speed)
// 		{
// 			case STOP:
// 			RESET();
// 			return;
// 			case FORWARD_SPEED1:
// 			PID_Result(50);
// 			return;
// 			case FORWARD_SPEED2:
// 			PID_Result(100);
// 			return;
// 			case BACKWARD_SPEED1:
// 			MOTOR_Backward(M1,speed1);
// 			MOTOR_Backward(M2,speed1);
// 			return;
// 			case BACKWARD_SPEED2:
// 			MOTOR_Backward(M1,speed2);
// 			MOTOR_Backward(M2,speed2);
// 			return;
// 			case RIGHT:
// 			MOTOR_Stop(M1);
// 			MOTOR_Forward(M2,speed2);
// 			return;
// 			case LEFT:
// 			MOTOR_Forward(M1,speed2);
// 			MOTOR_Stop(M2);
// 			return;
// 		}
// 	}
// }

void TEST_FORWARD(void)
{
	MOTOR_Forward(M1,speed1);
	
}
void TEST_BCI(void)
{
	static u8 change_state_flag=0;
			if(Data_received_flag==1&&received_data=='f')
			{
				if (change_state_flag==0)
				{
					MOTOR_Forward_Pwm(M1,50);
					MOTOR_Forward_Pwm(M2,50);
					Data_received_flag=0;
					change_state_flag=1;
				}
				else
				{
					MOTOR_Stop(M1);
					MOTOR_Stop(M2);
					Data_received_flag=0;
					change_state_flag=0;					
				}
			}
			else if(Data_received_flag==1&&received_data=='r')
			{
				MOTOR_Forward_Pwm(M2,50);
				MOTOR_Backward_Pwm(M1,50);
			}
			else if(Data_received_flag==1&&received_data=='l')
			{
				MOTOR_Forward_Pwm(M1,50);
				MOTOR_Backward_Pwm(M2,50);
			}
// 			else if (Data_received_flag==1&&received_data=='0')
// 			{
// 				MOTOR_Stop(M1);
// 				Data_received_flag=0;
// 			}
}

void TEST_Backward(void)
{
	MOTOR_Backward(M1,speed1);
	MOTOR_Backward(M2,speed1);
}
