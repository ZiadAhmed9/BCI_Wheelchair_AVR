/*
 * Utils.h
 *
 * Created: 5/9/2023 2:55:28 PM
 *  Author: COMPUMARTS
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define READ_BIT(reg,bit)	((reg>>bit)&1)
#define SET_BIT(reg,bit)	(reg=reg|(1<<bit))
#define CLR_BIT(reg,bit)	(reg=reg&~(1<<bit))
#define TOG_BIT(reg,bit)	(reg=reg^(1<<bit))
#define BIT_IS_CLEAR(REG,BIT) ( ! (REG & (1<<BIT)) )

#endif /* UTILS_H_ */