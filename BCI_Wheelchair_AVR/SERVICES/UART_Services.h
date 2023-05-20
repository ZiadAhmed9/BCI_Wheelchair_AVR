/*
 * UART_Services.h
 *
 * Created: 5/18/2023 1:29:05 AM
 *  Author: COMPUMARTS
 */ 


#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

void UART_SendString(u8*str);
void UART_ReceiveString(u8*str);
void UART_SendNumber(u32 num);
u32 UART_ReceiveNumber(void);
void UART_SendStringAsynch(u8*str);

#endif /* UART_SERVICES_H_ */