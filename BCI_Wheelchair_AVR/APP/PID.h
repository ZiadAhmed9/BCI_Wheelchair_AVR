/*
 * PID.h
 *
 * Created: 5/31/2023 3:55:54 AM
 *  Author: COMPUMARTS
 */ 


#ifndef PID_H_
#define PID_H_

#define KP 0.5
#define KI 0.4
void SPEED_Calc(void);

void PID_Result(u8 Desired);
u8 SPEED_DutyCycle_Convert(volatile s16* speed);
void TIME_Diff(void);
void SPEED_Filter(void);
void RPM_Conv(void);
void RESET(void);
#endif /* PID_H_ */