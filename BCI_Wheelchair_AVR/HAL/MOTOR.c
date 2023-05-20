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
#include "Motor.h"

void MOTOR_Init(void)
{
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_64);
	TIMER0_OC0Mode(OC0_NON_INVERTING);
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_64);
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	Timer1_OCRB1Mode(OCRB_NON_INVERTING);
	TIMER2_Init(TIMER2_FASTPWM_MODE,TIMER2_SCALER_64);
	TIMER2_OC0Mode(OC0_NON_INVERTING);
	ICR1=255;
}

void MOTOR_Forward(MOTOR_type motor,MotorSpeed_type speed)
{
	switch(motor)
	{
		case M1:
		switch(speed)
		{
			case speed1:
				OCR1A=127;
				OCR1B=0;
			break;
			case speed2:
				OCR1A=255;
				OCR1B=0;
			break;
			break;
		}
		case M2:
			switch(speed)
			{
				case speed1:
				OCR0=127;
				OCR2=0;
				break;
				case speed2:
				OCR0=255;
				OCR2=0;
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
			OCR1A=0;
			OCR1B=127;
			break;
			case speed2:
			OCR1A=0;
			OCR1B=255;
			break;
			break;
		}
		case M2:
		switch(speed)
		{
			case speed1:
			OCR0=0;
			OCR2=127;
			break;
			case speed2:
			OCR0=0;
			OCR2=255;
			break;
		}
	}
}

void MOTOR_Stop(MOTOR_type motor)
{
	switch(motor)
	{
	case M1:
		OCR1A=0;
		OCR1B=0;
	break;
	case M2:
		OCR0=0;
		OCR2=0;
	break;
	}
}
