#include "LCD_Private.h"


void LCD_Init(void)
{
		DIO_SetPin_Direction(LCD_CNTRL_PRT, LCD_EN, LCD_OUT);
		DIO_SetPin_Direction(LCD_CNTRL_PRT, LCD_RS, LCD_OUT);
		DIO_SetPin_Direction(LCD_CNTRL_PRT, LCD_RW, LCD_OUT);
		
		DIO_SetPin_Direction(LCD_DATA_PRT, LCD_D4, LCD_OUT);
		DIO_SetPin_Direction(LCD_DATA_PRT, LCD_D5, LCD_OUT);
		DIO_SetPin_Direction(LCD_DATA_PRT, LCD_D6, LCD_OUT);
		DIO_SetPin_Direction(LCD_DATA_PRT, LCD_D7, LCD_OUT);
		
		LCD_Write_Command(0x33);
		LCD_Write_Command(0x32);
		LCD_Write_Command(0x28);	// 2 line, 5*7 matrix in 4-bit mode
		
		LCD_Write_Command(0x01);	//Clear screen
		LCD_Write_Command(0x02);	//Return home
		LCD_Write_Command(0x06);	//Shift cursor to right
		LCD_Write_Command(0x0C);	//Display on cursor off
}

void LCD_Write_Command(uint8_t command)
{
		//Select command register
		DIO_SetPin_Value(LCD_CNTRL_PRT, LCD_RS, LCD_LOW);
		//Select write on screen
		DIO_SetPin_Value(LCD_CNTRL_PRT, LCD_RW, LCD_LOW);
		//Insure that enable is low
		DIO_SetPin_Value(LCD_CNTRL_PRT, LCD_EN, LCD_LOW);
		//Send the high nibble
		LCD = (command & 0xF0) | (LCD & 0x0F);
		DIO_SetPin_Value(LCD_CNTRL_PRT, LCD_EN, LCD_HIGH);
		_delay_ms(1);
		DIO_SetPin_Value(LCD_CNTRL_PRT, LCD_EN, LCD_LOW);
		//Send the low nibble
		LCD = ((command & 0x0F) << 4) | (LCD & 0x0F);
		DIO_SetPin_Value(LCD_CNTRL_PRT, LCD_EN, LCD_HIGH);
		_delay_ms(1);
		DIO_SetPin_Value(LCD_CNTRL_PRT, LCD_EN, LCD_LOW);
		_delay_ms(2);
}

void LCD_Write_Character(uint8_t character)
{
	//Select data register
	DIO_SetPin_Value(LCD_CNTRL_PRT, LCD_RS, LCD_HIGH);
	//Select write on screen
	DIO_SetPin_Value(LCD_CNTRL_PRT, LCD_RW, LCD_LOW);
	//Insure that enable is low
	DIO_SetPin_Value(LCD_CNTRL_PRT, LCD_EN, LCD_LOW);
	//Send the high nibble
	LCD = (character & 0xF0) | (LCD & 0x0F);
	DIO_SetPin_Value(LCD_CNTRL_PRT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPin_Value(LCD_CNTRL_PRT, LCD_EN, LCD_LOW);
	//Send the low nibble
	LCD = ((character & 0x0F) << 4) | (LCD & 0x0F);
	DIO_SetPin_Value(LCD_CNTRL_PRT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPin_Value(LCD_CNTRL_PRT, LCD_EN, LCD_LOW);
	_delay_ms(2);
}

void LCD_Write_String(uint8_t* str)
{
	while(*str != '\0')
	{
		LCD_Write_Character(*str);
		_delay_ms(2);
		str++;
	}
}

void LCD_Write_Number(uint32_t number)
{
	uint8_t *num;
	num = malloc(sizeof(number)/4);
	ltoa(number,num,10);
	LCD_Write_String(num);
}

void LCD_CLear(void)
{
	LCD_Write_Command(0x01);
}