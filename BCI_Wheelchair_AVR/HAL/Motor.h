/*
 * Motor.h
 *
 * Created: 5/20/2023 9:54:19 PM
 *  Author: COMPUMARTS
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

typedef enum{
	M1=0,
	M2,
	NUMBER_MOTORS
}MOTOR_type;

typedef enum{
	speed1=0,
	speed2
}MotorSpeed_type;


void MOTOR_Init(void);
void MOTOR_Forward(MOTOR_type motor,MotorSpeed_type speed);
void MOTOR_Backward(MOTOR_type motor,MotorSpeed_type speed);
void MOTOR_Stop(MOTOR_type motor);
void MOTOR_Forward_Pwm(MOTOR_type motor,u16 duty);
void MOTOR_Backward_Pwm(MOTOR_type motor,u16 duty);

#endif /* MOTOR_H_ */
