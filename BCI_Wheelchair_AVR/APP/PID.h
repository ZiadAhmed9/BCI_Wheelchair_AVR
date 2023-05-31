/*
 * PID.h
 *
 * Created: 5/31/2023 3:55:54 AM
 *  Author: COMPUMARTS
 */ 


#ifndef PID_H_
#define PID_H_

void SPEED_Calc(void);

u8 PID_Result(u8 Desired,u8 Actual);

u32 TIME_Diff(void);

void RPM_Conv(void);
#endif /* PID_H_ */