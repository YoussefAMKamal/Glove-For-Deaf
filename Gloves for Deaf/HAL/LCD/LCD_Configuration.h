#ifndef LCD_CONFIGURATION_H_
#define LCD_CONFIGURATION_H_

#include "CPU_Configuration.h"

#define LCD PORTD
//Control & data ports
#define LCD_DATA_PRT  DIO_PORTD
#define LCD_CNTRL_PRT DIO_PORTB
//Data pins
#define LCD_D4 DIO_PIN4
#define LCD_D5 DIO_PIN5
#define LCD_D6 DIO_PIN6
#define LCD_D7 DIO_PIN7
//Control pins
#define LCD_RS DIO_PIN1
#define LCD_RW DIO_PIN2
#define LCD_EN DIO_PIN3
//State
#define LCD_OUT DIO_OUTPUT
//Status
#define LCD_LOW  DIO_LOW
#define LCD_HIGH DIO_HIGH

#endif /* LCD_CONFIGURATION_H_ */