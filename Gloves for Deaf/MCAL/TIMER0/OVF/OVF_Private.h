/*
 * OVF_Private.h
 *
 * Created: 12/27/2023 4:59:45 PM
 *  Author: Youssef
 */ 


#ifndef OVF_PRIVATE_H_
#define OVF_PRIVATE_H_

#include "OVF_Configuration.h"

void Timer0_OVF_WithoutInterrupt_Inti(void);
void Timer0_OVF_WithoutInterrupt_Start(void);
void Timer0_OVF_WithoutInterrupt_Stop(void);
void Timer0_OVF_WithoutInterrupt_SetDelay(uint32_t delay);

void Timer0_OVF_WithInterrupt_Inti(void);
void Timer0_OVF_WithInterrupt_Start(void);
void Timer0_OVF_WithInterrupt_Stop(void);
void Timer0_OVF_WithInterrupt_SetDelay(uint32_t delay);

#endif /* OVF_PRIVATE_H_ */