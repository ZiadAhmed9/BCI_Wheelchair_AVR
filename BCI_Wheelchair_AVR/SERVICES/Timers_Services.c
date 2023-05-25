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

static u32 time_in_millis=0;	// This variable is used to be incremented every time an interrupt is called to count milli seconds can count up to 50 days before overflowing

//The following function will initialize timer 0 to generate interrupt every 1 ms
void Timer0_CountMillis(void)
{
	TIMER0_Init(TIMER0_CTC_MODE,TIMER0_SCALER_64);
	TCNT0=0;
	OCR0 = 249;
	TIMER0_OC_SetCallBack(millis);
	TIMER0_OC_InterruptEnable();
}

//This function takes reading of the variable created above while interrupt is disabled then returns it
u32 Timer_reading(void)
{
	u32 m;
	cli();
	m=time_in_millis;
	sei();
	return m;
}

//This function is called whenever interrupt happens
void millis(void)
{
	time_in_millis++;
}