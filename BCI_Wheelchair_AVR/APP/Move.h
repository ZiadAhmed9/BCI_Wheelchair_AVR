/*
 * Move.h
 *
 * Created: 5/21/2023 12:24:07 AM
 *  Author: COMPUMARTS
 */ 


#ifndef MOVE_H_
#define MOVE_H_

//Contains the data expected from raspberry pi
typedef enum{
	STOP=0,
	FORWARD_SPEED1,  //1
	FORWARD_SPEED2,	//2
	BACKWARD_SPEED1,	//3
	BACKWARD_SPEED2,	//4
	RIGHT,		//5
	LEFT		//6
	}MoveDirectionSpeed_type;

void MOVE(void);
void TEST_FORWARD(void);
void TEST_Backword(void);
void GET_BCIReading(void);

#endif /* MOVE_H_ */