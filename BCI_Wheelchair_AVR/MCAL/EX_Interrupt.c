/*
 * EX_Interrupt.c
 *
 * Created: 5/15/2023 4:00:29 PM
 *  Author: COMPUMARTS
 */ 
#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"
#include "EX_Interrupt.h"

static void (*INT0_Fptr)(void)=NULLPTR;		// THE BRACKETS around INT0_Fptr indicates that this is a pointer to function as INT0_Fptr is function, removing the brackets means that it will return a pointer to void
static void (*INT1_Fptr)(void)=NULLPTR;
static void (*INT2_Fptr)(void)=NULLPTR;


void EXI_Enable(ExInterruptSource_type Interrupt)
{
	switch(Interrupt){
		case EX_INT0:
		SET_BIT(GICR,INT0);
		break;
		case EX_INT1:
		SET_BIT(GICR,INT1);
		break;
		case EX_INT2:
		SET_BIT(GICR,INT2);
		break;	
	}
}

void EXI_Disable(ExInterruptSource_type Interrupt)
{
	switch(Interrupt){
		case EX_INT0:
		SET_BIT(GICR,INT0);
		break;
		case EX_INT1:
		SET_BIT(GICR,INT1);
		break;
		case EX_INT2:
		SET_BIT(GICR,INT2);
		break;
	}
	
}

// Use this function to avoid calling each interrupt indvidually in the main
//edit each interrupt trigger from here before code starts

void EXI_Init(void)
{
	EXI_TriggerEdge(EX_INT0,RISING_EDGE);
	EXI_TriggerEdge(EX_INT1,RISING_EDGE);
	EXI_TriggerEdge(EX_INT2,FALLING_EDGE);
}

void EXI_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge)
{
	switch(Interrupt){
		case EX_INT0:
		switch(Edge){
			case LOW_LEVEL:
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			case ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			case FALLING_EDGE:
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			
		}
		break;
		case EX_INT1:
		switch(Edge){
			case LOW_LEVEL:
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			case ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			case FALLING_EDGE:
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			
		}
		break;
		case EX_INT2:
		switch(Edge){
			case FALLING_EDGE:
			CLR_BIT(MCUCSR,ISC2);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCSR,ISC2);
			break;
			default:
			CLR_BIT(MCUCSR,ISC2);
		}
		break;
	}
}

void EXI_SetCallBack(ExInterruptSource_type Interrupt,void (*LocalPtr)(void))
{
	switch(Interrupt)
	{
		case EX_INT0:
		INT0_Fptr=LocalPtr;
		break;
		case EX_INT1:
		INT1_Fptr=LocalPtr;
		break;
		case EX_INT2:
		INT2_Fptr=LocalPtr;
		break;
	}
	
}
ISR(INT0_vect)
{
	if(INT0_Fptr!=(NULLPTR))		// if the Pointer is initialized by null then don't execute the function INT0_Fptr()
	{
		INT0_Fptr();
	}
}

ISR(INT1_vect)
{
	if(INT1_Fptr!=(NULLPTR))
	{
		INT1_Fptr();
	}
}

ISR(INT2_vect)
{
	if(INT2_Fptr!=(NULLPTR))
	{
		INT2_Fptr();
	}
	
}