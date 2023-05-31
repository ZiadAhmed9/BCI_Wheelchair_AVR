/*
 * Encoder.h
 *
 * Created: 5/22/2023 12:50:20 AM
 *  Author: COMPUMARTS
 */ 


#ifndef ENCODER_H_
#define ENCODER_H_
extern volatile u8 pos_i,pos_ii;

typedef enum{
	Encoder1,
	Encoder2
	}Encoder_type;
void ENCODER_Read(Encoder_type encoder);




#endif /* ENCODER_H_ */