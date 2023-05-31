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
#include "Encoder.h"
#include "PID.h"

//Variables that will hold the pos variables from read encoder function
volatile u8 pos1,pos2;
volatile u32 currT=0,prevT=0,M1_CurrentSpeed,M2_CurrentSpeed;
u32 TIME_Diff(void)
{
	u8 deltaT;
	currT=Timer_reading();
	deltaT=(currT-prevT)/1000;
	prevT=currT;
	return deltaT;
}

void SPEED_Calc(void)
{
	static volatile u8 posPrev1, posPrev2;
	static volatile u32 time;
	pos1=0;		//Zeroed every call for this function
	pos2=0;
	cli();
	pos1=pos_i;
	pos2=pos_ii;
	sei();
	time=TIME_Diff();
	M1_CurrentSpeed=(pos1-posPrev1)/time;
	M2_CurrentSpeed=(pos2-posPrev2)/time;
	posPrev1=pos1;
	posPrev2=pos2;
}

void RPM_Conv(void)
{
	M1_CurrentSpeed=M1_CurrentSpeed/600*60;
	M2_CurrentSpeed=M2_CurrentSpeed/600*60;
}
