/*
 * CPU_Configuration.h
 *
 * Created: 12/20/2023 9:10:08 PM
 *  Author: Youssef
 */ 


#ifndef CPU_CONFIGURATION_H_
#define CPU_CONFIGURATION_H_

#undef F_CPU				// Disable internal CPU frequency
#define F_CPU 16000000		// Enable internal CPU frequency
#include <avr/io.h>			// Define library for AVR MC
#include <util/delay.h>
#include "BIT_Math.h"
#include "DIO_Private.h"
#include "ADC_Private.h"
//#include "CTC_Private.h"
//#include "OVF_Private.h"

#endif /* CPU_CONFIGURATION_H_ */