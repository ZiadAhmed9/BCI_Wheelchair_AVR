/*
 * MOTOR.c
 *
 * Created: 5/20/2023 9:54:31 PM
 *  Author: COMPUMARTS
 */ 
//This Driver is intended for motors that demand 2 PWM signals to move

#include "StdTypes.h"
#include "MemMap.h"
#include "DIO_Interface.h"
#include "Timers.h"
#include "Timers_Services.h"
#include "MOTOR.h"
#include "MOTOR_Cfg.h"

void MOTOR_Init(void)
{
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_64);
	TIMER0_OC0Mode(OC0_NON_INVERTING);
	TIMER2_Init(TIMER2_FASTPWM_MODE,TIMER2_SCALER_64);
	TIMER2_OC0Mode(OC2_NON_INVERTING);
	TIMER0_Pwm_Duty(0);
	TIMER2_Pwm_Duty(0);
}

void MOTOR_Forward(MOTOR_type motor,MotorSpeed_type speed)
{
	switch(motor)
	{
		case M1:
		switch(speed)
		{
			case speed1:
				TIMER0_Pwm_Duty(50);
				DIO_WritePin(M1_Direction,FORWARD);
			break;
			case speed2:
				TIMER0_Pwm_Duty(75);
				DIO_WritePin(M1_Direction,FORWARD);	
			break;
			break;
		}
		case M2:
			switch(speed)
			{
				case speed1:
				TIMER2_Pwm_Duty(50);
				DIO_WritePin(M2_Direction,FORWARD);
				break;
				case speed2:
				TIMER2_Pwm_Duty(75);
				DIO_WritePin(M2_Direction,FORWARD);
				break;	
			}
	}
}


void MOTOR_Backward(MOTOR_type motor,MotorSpeed_type speed)
{
	switch(motor)
	{
		case M1:
		switch(speed)
		{
			case speed1:
				TIMER0_Pwm_Duty(50);
				DIO_WritePin(M1_Direction,BACKWARD);
			break;
			case speed2:
				TIMER0_Pwm_Duty(75);
				DIO_WritePin(M1_Direction,BACKWARD);
			break;
			break;
		}
		case M2:
		switch(speed)
		{
			case speed1:
				TIMER2_Pwm_Duty(50);
				DIO_WritePin(M2_Direction,BACKWARD);
			break;
			case speed2:
				TIMER2_Pwm_Duty(75);
				DIO_WritePin(M2_Direction,BACKWARD);
			break;
		}
	}
}

void MOTOR_Stop(MOTOR_type motor)
{
	switch(motor)
	{
	case M1:
			TIMER0_Pwm_Duty(0);
	break;
	case M2:
			TIMER2_Pwm_Duty(0);
	break;
	}
}