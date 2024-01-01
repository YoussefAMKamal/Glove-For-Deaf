/*
 * CTC_Private.h
 *
 * Created: 12/27/2023 5:04:22 PM
 *  Author: Youssef
 */ 


#ifndef CTC_PRIVATE_H_
#define CTC_PRIVATE_H_

#include "CTC_Configuration.h"

void Timer0_CTC_WithoutInterrupt_Inti(void);
void Timer0_CTC_WithoutInterrupt_Start(void);
void Timer0_CTC_WithoutInterrupt_Stop(void);
void Timer0_CTC_WithoutInterrupt_SetDelay(uint32_t delay);

void Timer0_CTC_WithInterrupt_Inti(void);
void Timer0_CTC_WithInterrupt_Start(void);
void Timer0_CTC_WithInterrupt_Stop(void);
void Timer0_CTC_WithInterrupt_SetDelay(uint32_t delay);

#endif /* CTC_PRIVATE_H_ */