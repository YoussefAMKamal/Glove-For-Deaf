#ifndef EXTERNAL_INTERRUPT_CONFIGURATIONS_H_
#define EXTERNAL_INTERRUPT_CONFIGURATIONS_H_

#include "CPU_Configuration.h"
#include "External_Interrupt_Address.h"

typedef enum
{
	Int0_Low = 0,
	Int0_High = 1,
	Int0_Falling = 2,
	Int0_Rising = 3
}Interrupt0_Sence;

typedef enum
{
	Int1_Low = 0,
	Int1_High = 1,
	Int1_Falling = 2,
	Int1_Rising = 3
}Interrupt1_Sence;


typedef enum
{
	Ext_Int0 = 0,
	Ext_Int1 = 1,
	Ext_Int2 = 2
}Interrupts;

#endif /* EXTERNAL_INTERRUPT_CONFIGURATIONS_H_ */