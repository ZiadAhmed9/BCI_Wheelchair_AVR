/*
 * ALARM_CHECK.c
 *
 * Created: 6/13/2023 8:10:26 PM
 *  Author: COMPUMARTS
 */ 
#include <stdio.h>
#include "StdTypes.h"
#include "Gyroscope.h"
#include "UART_Services.h"
float Xa,Ya,Za,t,Xg,Yg,Zg;

void STATE_Update(float* Xa,float *Ya,float* Za,float* t)
{
	static float Xg,Yg,Zg;
	static char buffer[20], float_[10];
	Read_RawValue(&Xa,&Ya,&Za,&Xg,&Yg,&Zg,&t);
// 	Xa = Xa/16384.0;
// 	Ya = Ya/16384.0;
// 	Za = Za/16384.0;
	*t = (*t/340.00)+36.53;
	dtostrf( *Xa, 3, 2, float_ );
	sprintf(buffer," Ax = %s g\t",float_);
	USART_SendString(buffer);

	dtostrf( *Ya, 3, 2, float_ );
	sprintf(buffer," Ay = %s g\t",float_);
	USART_SendString(buffer);
	
	dtostrf( *Za, 3, 2, float_ );
	sprintf(buffer," Az = %s g\t",float_);
	USART_SendString(buffer);

	dtostrf( *t, 3, 2, float_ );
	/* 0xF8 Ascii value of degree on serial */
	sprintf(buffer," (((T = %s%c)))",float_,0xF8);
	USART_SendString(buffer);

	dtostrf( Xg, 3, 2, float_ );
	sprintf(buffer," Gx = %s%c/s\t",float_,0xF8);
	USART_SendString(buffer);

	dtostrf( Yg, 3, 2, float_ );
	sprintf(buffer," Gy = %s%c/s\t",float_,0xF8);
	USART_SendString(buffer);
	
	dtostrf( Zg, 3, 2, float_ );
	sprintf(buffer," Gz = %s%c/s\r\n",float_,0xF8);
	USART_SendString(buffer);
}


void STATE_UpdateTest(void)
{
	static char buffer[20], float_[10];
	Read_RawValue(&Xa,&Ya,&Za,&Xg,&Yg,&Zg,&t);
	// 	Xa = Xa/16384.0;
	// 	Ya = Ya/16384.0;
	// 	Za = Za/16384.0;
	t = (t/340.00)+36.53;
// 	dtostrf( Xa, 3, 2, float_ );
// 	sprintf(buffer," Ax = %s g\t",float_);
// 	USART_SendString(buffer);
// 
// 	dtostrf( Ya, 3, 2, float_ );
// 	sprintf(buffer," Ay = %s g\t",float_);
// 	USART_SendString(buffer);
// 	
// 	dtostrf( Za, 3, 2, float_ );
// 	sprintf(buffer," Az = %s g\t",float_);
// 	USART_SendString(buffer);
// 
// 	dtostrf( t, 3, 2, float_ );
// 	/* 0xF8 Ascii value of degree on serial */
// 	sprintf(buffer," T = %s%cC\t",float_,0xF8);
// 	USART_SendString(buffer);
// 
// 	dtostrf( Xg, 3, 2, float_ );
// 	sprintf(buffer," Gx = %s%c/s\t",float_,0xF8);
// 	USART_SendString(buffer);
// 
// 	dtostrf( Yg, 3, 2, float_ );
// 	sprintf(buffer," Gy = %s%c/s\t",float_,0xF8);
// 	USART_SendString(buffer);
// 	
// 	dtostrf( Zg, 3, 2, float_ );
// 	sprintf(buffer," Gz = %s%c/s\r\n",float_,0xF8);
// 	USART_SendString(buffer);
}

u8 CHECK_Danger(void)
{
	static char buffer[20], float_[10];
	STATE_UpdateTest();
	if(t>=30)
	{
		dtostrf( t, 3, 2, float_ );
		/* 0xF8 Ascii value of degree on serial */
		sprintf(buffer," (((T = %s)))",float_);
		USART_SendString(buffer);
		return 0;
	}
	else if(Ya<=-10000 || Ya>=10000)
	{
		UART_SendString("F ");
		return 0;
	}

}
