/*
 * EX_Interrupt.h
 *
 * Created: 5/15/2023 3:55:45 PM
 *  Author: COMPUMARTS
 */ 


#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_

typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
	}TriggerEdge_type;
	
typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
	}ExInterruptSource_type;
	
	
void EXI_Init(void);
void EXI_Enable(ExInterruptSource_type Interrupt);
void EXI_Disable(ExInterruptSource_type Interrupt);
void EXI_SetCallBack(ExInterruptSource_type iNTERRUPT,void(*LocalPtr)(void));
void EXI_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge);

#endif /* EX_INTERRUPT_H_ */