#include "main.h"

extern uint32_t status[5];

int main(void)
{
	// Variables Initializations 
    uint8_t *data;
    // Components Initializations.
	LCD_Init();
	LCD_CLear();
	Glove_Init();
	// The Loop.
    while (1) 
    {
		// Delaying.
		_delay_ms(500);
		// Clearing LCD.
		LCD_CLear();
		// Getting Result.
		data = Glove_Result();
		// Making Sure There is an Output.
		if(data != 0)
			// Writing Result on LCD.
			LCD_Write_String(data);
    }
}