/*
 * OVF_Configuration.h
 *
 * Created: 12/27/2023 4:59:33 PM
 *  Author: Youssef
 */ 


#ifndef OVF_CONFIGURATION_H_
#define OVF_CONFIGURATION_H_

#include "CPU_Configuration.h"
#include "OVF_Address.h"

#define OVF_BITS		256
#define OVF_PRESCALER	1024
#define OVF_FREQUENCY	16		//Used in MHz to prevent converting.
#define OVF_MICROSECON	1000

typedef enum
{
	No_Clock_Source = 0,
	No_Prescaling = 1,
	PRESCALER_8 = 2,
	PRESCALER_16 = 3,
	PRESCALER_32 = 4,
	PRESCALER_64 = 5,
	PRESCALER_256 = 6,
	PRESCALER_1024 = 7,
	Clock_Falling_Edge = 8,
	Clock_Rising_Edge = 9
}Timer0_OVF_Prescaler;

#endif /* OVF_CONFIGURATION_H_ */