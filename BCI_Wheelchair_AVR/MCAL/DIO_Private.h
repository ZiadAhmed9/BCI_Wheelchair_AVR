/*
 * DIO_Private.h
 *
 * Created: 5/10/2023 9:37:37 PM
 *  Author: COMPUMARTS
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


extern const DIO_PinStatus_type PinsStatusArray[TOTAL_PINS];
static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status);




#endif /* DIO_PRIVATE_H_ */