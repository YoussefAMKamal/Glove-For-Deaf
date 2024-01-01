#ifndef ADC_CONFIGURATION_H_
#define ADC_CONFIGURATION_H_

#include "CPU_Configuration.h"
#include "ADC_Address.h"

typedef enum
{
	Aref = 0,
	Avcc = 1,
	A_Internal = 2
}ADC_Vref;

typedef enum
{
	ADC0_Ch = 0,
	ADC1_Ch = 1,
	ADC2_Ch = 2,
	ADC3_Ch = 3,
	ADC4_Ch = 4,
	ADC5_Ch = 5,
	ADC6_Ch = 6,
	ADC7_Ch = 7
}ADC_Channel;

typedef enum
{
	ADC_Pre1	= 0,
	ADC_Pre2	= 1,
	ADC_Pre4	= 2,
	ADC_Pre8	= 3,
	ADC_Pre16	= 4,
	ADC_Pre32	= 5,
	ADC_Pre64	= 6,
	ADC_Pre128	= 7
}ADC_Prescaler;

#endif /* ADC_CONFIGURATION_H_ */