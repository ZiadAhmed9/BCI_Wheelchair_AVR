/*
 * SPI.h
 *
 * Created: 5/20/2023 12:42:04 AM
 *  Author: COMPUMARTS
 */ 


#ifndef SPI_H_
#define SPI_H_

#define SPI_MODE MASTER

//enum to choose the state of this MCU
typedef enum{
	MASTER,
	SLAVE,
	}SPIMODE_type;
	
	
void SPI_Init(SPIMODE_type mode);
u8 SPI_SendReceive(u8 data);  // used for master mainly
void SPI_SendNoBlock(u8 data);




#endif /* SPI_H_ */