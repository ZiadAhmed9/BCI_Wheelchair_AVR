/*
 * UART_Services.c
 *
 * Created: 5/18/2023 1:28:53 AM
 *  Author: COMPUMARTS
 */ 
#include "StdTypes.h"
#include "UART.h"
#include "UART_Services.h"

u8*TX_str;

void UART_SendString(u8*str)
{
	u8 i;
	for(i=0;i<str[i];i++)
	{
		UART_SendData(str[i]);
	}
	UART_SendData('#');
}
void UART_ReceiveString(u8*str)
{
	u8 i=0;
	str[i]=UART_ReceiveData();
	for( ;str[i]!='#';)
	{
		i++;
		str[i]=UART_ReceiveData();
	}
	str[i]=0;
}

void UART_SendNumber(u32 num)
{
	UART_SendData((u8)num);
	UART_SendData((u8)(num>>8));
	UART_SendData((u8)(num>>16));
	UART_SendData((u8)(num>>24));
}
u32 UART_ReceiveNumber(void)
{
	u32 num=0;
	u32 b1=UART_ReceiveData();
	u32 b2=UART_ReceiveData();
	u32 b3=UART_ReceiveData();
	u32 b4=UART_ReceiveData();
	num=(u32)b1|(u32)b2<<8|(u32)b3<<16|(u32)b4<<24;
	return num;
}
void TX_Func(void)		// to be executed when interrupt is called
{
	static u8 i=1;
	if(TX_str[i]!=0)
	{
		UART_SendNoBlock(TX_str[i]); //send rest of characters
		i++;
	}
	else
	{
		i=1;
	}
}
//sending a character then calling interrupt after done
void UART_SendStringAsynch(u8*str)
{
	UART_TX_InterruptEnable();
	UART_TX_SetCallBack(TX_Func);
	UART_SendNoBlock(str[0]); //send first char
	TX_str=str; 
}




void USART_SendString(char *str)					/* Send string of USART data function */
{
	int i=0;
	while (str[i]!=0)
	{
		USART_TxChar(str[i]);						/* Send each char of string till the NULL */
		i++;
	}
}