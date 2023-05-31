/*
 * PID.c
 *
 * Created: 5/31/2023 3:56:45 AM
 *  Author: COMPUMARTS
 */ 

#include "MemMap.h"
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "Timers_Services.h"
#include "MOTOR.h"
#include "Encoder.h"
#include "PID.h"

//Variables that will hold the pos variables from read encoder function
volatile s8 pos1,pos2,posPrev1, posPrev2;;
volatile s8 pos_i,pos_ii;
//variables that will be used in calculating time and speed
volatile s16 M1_error,M2_error, M1_prev_error,M2_prev_error, M1_integral,M2_integral,output1,output2;
/////////////////
volatile s16 M1_CurrentSpeed,M2_CurrentSpeed,M1_FilteredSpeed,M2_FilteredSpeed,M1_PrevFilteredSpeed,M2_PrevFilteredSpeed;
volatile float deltaT,currT,prevT,timeD;
//This function return the time difference between when it is called and last time called
void TIME_Diff(void)
{
	currT=Timer_reading();
	deltaT=(currT-prevT)/1000;
	prevT=currT;
}

void SPEED_Calc(void)
{
	pos1=0;		//Zeroed every call for this function
	pos2=0;
	cli();
	pos1=pos_i;
	pos2=pos_ii;
	sei();
	TIME_Diff();
	timeD=deltaT;
	M1_CurrentSpeed=(pos1-posPrev1)/timeD;
	M2_CurrentSpeed=(pos2-posPrev2)/timeD;
	posPrev1=pos1;
	posPrev2=pos2;
}

void RPM_Conv(void)
{
	M1_CurrentSpeed=M1_CurrentSpeed/600*60;
	M2_CurrentSpeed=M2_CurrentSpeed/600*60;
}

//Low Pass Filter with cutoff 25 hz
void SPEED_Filter(void)
{
	M1_FilteredSpeed=0.854*M1_FilteredSpeed+0.0728*M1_CurrentSpeed+0.0728*M1_PrevFilteredSpeed;
	M2_FilteredSpeed=0.854*M2_FilteredSpeed+0.0728*M2_CurrentSpeed+0.0728*M2_PrevFilteredSpeed;
	M1_PrevFilteredSpeed=M1_CurrentSpeed;
	M2_PrevFilteredSpeed=M2_CurrentSpeed;
}

//This function return a value that will decide which direction to move
//and also it will modify the variable of the speed and store PWM in it instead of SPEED
u8 SPEED_DutyCycle_Convert(volatile s16* speed)
{
	*speed=((*speed) *100) /255;
	if( *speed>100)
	{
		*speed= 100;
		return 1;
	}
	else if (*speed<0)
	{
		return -1;
	}
	else
		return 1;
}

/* This function will take the desired speed, calculalte the output needed
Then give order to the motor to change their values*/
void PID_Result(u8 Speed_Desired)
{
	SPEED_Calc();
	RPM_Conv();
	SPEED_Filter();
	//Step 1 error calculation
	M1_error=Speed_Desired-M1_FilteredSpeed;
	M2_error=Speed_Desired-M2_FilteredSpeed;
	//Step 2 integral error calculation
	M1_integral=M1_integral+M1_error*deltaT;
	M2_integral=M2_integral+M2_error*deltaT;
	//Step 3 Final New Speed calculation
	output1=KP* M1_error+KI*M1_integral;
	output2=KP* M2_error+KI*M2_integral;
	//Calculate speed and change the direction accordingly
	if(SPEED_DutyCycle_Convert(&output1)==1)
	{
		MOTOR_Forward_Pwm(M1,output1);
	}
	else
	{
		MOTOR_Backward_Pwm(M1,output1);
	}
	if(SPEED_DutyCycle_Convert(&output2)==1)
	{
		MOTOR_Forward_Pwm(M2,output2);
	}
	else
	{
		MOTOR_Backward_Pwm(M2,output2);
	}	
}

void RESET(void)
{
	MOTOR_Stop(M1);
	MOTOR_Stop(M2);
	M1_FilteredSpeed=0;
	M2_FilteredSpeed=0;
	M1_error=0;
	M2_error=0;
	M1_integral=0;
	M2_integral=0;
	output1=0;
	output2=0;
	posPrev1=pos1;
	posPrev2=pos2;
}