#include "Glove_Private.h"

uint32_t status[5];

// Glove Initialization.
void Glove_Init(void)
{
	ADC_Init(ADC_Pre128,Avcc);
}

// Glove Fingers Status.
void Glove_Status(void)
{
	// Identify Each Finger Status.
	// 1 for Closed and 0 For Opened.
	status[Thumb_Pos] = ADC_Read(Thumb) >= Thumb_Threshold ? 1:0;
	status[Index_Pos] = ADC_Read(Index) >= Index_Threshold ? 1:0;
	status[Middel_Pos] = ADC_Read(Middel) >= Middle_Threshold ? 1:0;
	status[Ring_Pos] = ADC_Read(Ring) >= Ring_Threshold ? 1:0;
	status[Littel_Pos] = ADC_Read(Little) >= Little_Threshold ? 1:0;
}

// Identify The Output String According to The Status.
uint8_t* Glove_Result(void)
{
	char *string;
	uint32_t result = 0;
	
	// Getting Glove Status.
	Glove_Status();
	
	// Converting Output to Number.	
	for(int i=0;i<5;i++)
	{
		result *= 10;
		result += status[i]+1;
	}
	
	/*
		1 Means The Finger is Opened.
		2 Means The Finger is Closed.
	*/
	
	if(result == 11111)			//00000	
		string = "Stop";
	else if(result == 11121)	//00010	
		string = "I Really Love U";
	else if(result == 11221)	//00110	
		string = "I Love U";
	else if(result == 12221)	//01110	
		string = "Call Me";
	else if(result == 12222)	//01111
		string = "Good Job";
	else if(result == 21122)	//10011
		string = "I'm Watching U";
	else if(result == 21221)	//10110
		string = "That's Great";
	else if(result == 21222)	//10111
		string = "You";
	else if(result == 22111)	//11000
		string = "OK";
	else if(result == 22222)	//11111
		string = "Hold";
	else						// If The Gesture is Not Found in The System.
		string = ".....";
		
	return (uint8_t*)string;
}
