#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#include "ADC_Configuration.h"

void ADC_Init(ADC_Prescaler Prescaler, ADC_Vref Vref);
uint16_t ADC_Read(ADC_Channel Channel);

#endif /* ADC_PRIVATE_H_ */