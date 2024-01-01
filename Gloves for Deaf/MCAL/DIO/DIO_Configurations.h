#ifndef DIO_CONFIGURATIONS_H_
#define DIO_CONFIGURATIONS_H_

#include "CPU_Configuration.h"
#include "DIO_Address.h"

typedef enum
{
	DIO_PORTA = 0,
	DIO_PORTB = 1,
	DIO_PORTC = 2,
	DIO_PORTD = 3
}DIO_Port;

typedef enum
{
	DIO_PIN0 = 0,
	DIO_PIN1 = 1,
	DIO_PIN2 = 2,
	DIO_PIN3 = 3,
	DIO_PIN4 = 4,
	DIO_PIN5 = 5,
	DIO_PIN6 = 6,
	DIO_PIN7 = 7
}DIO_Pin;

typedef enum
{
	DIO_INPUT = 0,
	DIO_OUTPUT = 1
}DIO_State;

typedef enum
{
	DIO_LOW = 0,
	DIO_HIGH = 1
}DIO_Status;

#endif /* DIO_CONFIGURATIONS_H_ */