/*
 * ALARM_CHECK.h
 *
 * Created: 6/13/2023 8:12:32 PM
 *  Author: COMPUMARTS
 */ 


#ifndef ALARM_CHECK_H_
#define ALARM_CHECK_H_


void STATE_Update(float* Xa,float *Ya,float* Za,float* t);
void STATE_UpdateTest(void);
u8 CHECK_Danger(void);

#endif /* ALARM_CHECK_H_ */