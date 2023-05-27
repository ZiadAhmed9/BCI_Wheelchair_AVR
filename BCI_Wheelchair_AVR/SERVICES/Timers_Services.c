/*
 * Timers_Services.c
 *
 * Created: 5/25/2023 2:55:10 AM
 *  Author: COMPUMARTS
 */ 
#include "MemMap.h"
#include "StdTypes.h"
#include "Timers.h"
#include "Timers_Services.h"

volatile u32 time_in_millis=0;	// This variable is used to be incremented every time an interrupt is called to count milli seconds can count up to 50 days before overflowing

//The following function will initialize timer 0 to generate interrupt every 1 ms
// void Timer0_CountMillis(void)
// {
// 	TIMER0_Init(TIMER0_CTC_MODE,TIMER0_SCALER_64);
// 	TCNT0=0;
// 	OCR0 = 249;
// 	TIMER0_OC_SetCallBack(millis);
// 	TIMER0_OC_InterruptEnable();
// }
// 
// //This function takes reading of the variable created above while interrupt is disabled then returns it
// // u32 Timer_reading(void)
// // {
// // 	u32 m;
// // 	cli();
// // 	m=time_in_millis;
// // 	sei();
// // 	return m;
// // }
// 
// //This function is called whenever interrupt happens
// void millis(void)
// {
// 	time_in_millis++;
// }

void TIMER1_Pwm_Freq_HZ(u16 freq)
{
	if (freq==0);
	else
	{
		u16 Ttotal=(u32)125000/freq;
		if (Ttotal>=1)
		{
			ICR1=Ttotal-1;
		}
		else ICR1=0;
	}
}


void TIMER1_Pwm_Duty(u16 duty, Timer1_type type)
{
	switch(type)
	{
	case Timer1A:
	if (duty<=100)
	{
		u16 Ton=((u32)duty*(ICR1+1))/100;
		if (Ton>1)
		{
			OCR1A=Ton-1;
		}
		else
		OCR1A=0;
	}
	case Timer1B:
	if (duty<=100)
	{
		u16 Ton=((u32)duty*(ICR1+1))/100;
		if (Ton>1)
		{
			OCR1B=Ton-1;
		}
		else
		OCR1B=0;
	}
	}
}

void TIMER2_Pwm_Duty(u16 duty)
{
	if (duty<=100)
	{
		u16 Ton=((u32)duty*(255+1))/100;
		if (Ton>1)
		{
			OCR2=Ton-1;
		}
		else
		OCR2=0;
	}
}