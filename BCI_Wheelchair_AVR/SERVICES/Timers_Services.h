/*
 * Timers_Services.h
 *
 * Created: 5/25/2023 2:54:57 AM
 *  Author: COMPUMARTS
 */ 


#ifndef TIMERS_SERVICES_H_
#define TIMERS_SERVICES_H_
typedef enum
{
	Timer1A,
	Timer1B
	}Timer1_type;

void Timer0_CountMillis(void);
u32 Timer_reading(void);
void millis(void);
void TIMER1_Pwm_Freq_HZ(u16 freq);
void TIMER1_Pwm_Duty(u16 duty,Timer1_type type);
void TIMER2_Pwm_Duty(u16 duty);
void TIMER0_Pwm_Duty(u16 duty);
void Timer1_SetInterruptTime_ms (u16 time,void(*LocalFptr)(void));


#endif /* TIMERS_SERVICES_H_ */