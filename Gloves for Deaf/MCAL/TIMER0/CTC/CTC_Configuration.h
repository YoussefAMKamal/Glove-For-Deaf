/*
 * CTC_Configuration.h
 *
 * Created: 12/27/2023 5:04:06 PM
 *  Author: Youssef
 */ 


#ifndef CTC_CONFIGURATION_H_
#define CTC_CONFIGURATION_H_

#include "CPU_Configuration.h"
#include "CTC_Address.h"

#define CTC_BITS		256
#define CTC_PRESCALER	1024
#define CTC_FREQUENCY	16		//Used in MHz to prevent converting.
#define CTC_MICROSECON	1000

typedef enum
{
	
}Timer0_CTC_Prescaler;

typedef enum
{
	
}Timer0_CTC_OCPin;


#endif /* CTC_CONFIGURATION_H_ */