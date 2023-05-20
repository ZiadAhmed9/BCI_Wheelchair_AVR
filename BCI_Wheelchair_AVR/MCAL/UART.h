/*
 * UART.h
 *
 * Created: 5/18/2023 12:16:10 AM
 *  Author: COMPUMARTS
 */ 


#ifndef UART_H_
#define UART_H_


void UART_init(void);
void UART_SendData(u8 data);
u8 UART_ReceiveData(void);
u8 UART_ReceivePeriodic(u8* pdata);
void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);
void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);
void UART_SendNoBlock(u8 data);
u8 UART_ReceiveNoBlock(void);

void UART_RX_SetCallBack(void(*LocalFptr)(void));
void UART_TX_SetCallBack(void(*LocalFptr)(void));
#endif /* UART_H_ */