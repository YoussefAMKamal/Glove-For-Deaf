#include "External_Interrupt_Private.h"

void EXTERNAL_INTERRUPT_Init(Interrupts inter, Interrupt0_Sence sense, Interrupt1_Sence senses)
{
	// Disable Global Interrupt
	CLR_BIT(SREG,7);
	switch(inter)
	{
		case Ext_Int0:
		switch(sense)
		{
			case Int0_Low:
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			case Int0_High:
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			case Int0_Falling:
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			case Int0_Rising:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		}
		SET_BIT(GICR,6);
		break;
		case Ext_Int1:
		switch(senses)
		{
			case Int1_Low:
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			case Int1_High:
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			case Int1_Falling:
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			case Int1_Rising:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
		}
		SET_BIT(GICR,7);
		break;
		case Ext_Int2:
		break;
	}
	// Enable Global Interrupt
	SET_BIT(SREG,7);
}