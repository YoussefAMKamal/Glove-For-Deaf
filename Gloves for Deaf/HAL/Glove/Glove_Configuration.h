#ifndef GLOVE_CONFIGURATION_H_
#define GLOVE_CONFIGURATION_H_

#include "CPU_Configuration.h"
// Pin configurations.
#define Thumb	ADC0_Ch
#define Index	ADC4_Ch
#define Middel	ADC5_Ch
#define Ring	ADC6_Ch
#define Little	ADC7_Ch
// Thresholds
#define Thumb_Threshold 712
#define Index_Threshold 803
#define Middle_Threshold 820       
#define Ring_Threshold 805
#define Little_Threshold 880
// Fingers Positions.
typedef enum
{
	Thumb_Pos = 0,
	Index_Pos = 1,
	Middel_Pos = 2,
	Ring_Pos = 3,
	Littel_Pos = 4
}Fingers_Pos;

#endif /* GLOVE_CONFIGURATION_H_ */