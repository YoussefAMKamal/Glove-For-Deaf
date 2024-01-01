/*
 * CTC_Interface.c
 *
 * Created: 12/27/2023 5:04:53 PM
 *  Author: Youssef
 */ 

#include "OVF_Private.h"

// Blocking Mode

void Timer0_CTC_WithoutInterrupt_Inti(void)
{
	// Choose Mode
	SET_BIT(TCCR0, WGM01);	CLR_BIT(TCCR0,WGM00);
	// Pin Disconnected
	CLR_BIT(TCCR0, COM01);	CLR_BIT(TCCR0, COM00);
	// Disable Interrupt
	CLR_BIT(TIMSK, OCIE0);
}
void Timer0_CTC_WithoutInterrupt_Start(void)
{
	// Choose 1024 Prescaler
	SET_BIT(TCCR0, CS02);	CLR_BIT(TCCR0, CS01);	SET_BIT(TCCR0, CS00);
}
void Timer0_CTC_WithoutInterrupt_Stop(void)
{
	// Choose 0 Prescaler
	CLR_BIT(TCCR0, CS02);	CLR_BIT(TCCR0, CS01);	CLR_BIT(TCCR0, CS00);
}
void Timer0_CTC_WithoutInterrupt_SetDelay(uint32_t delay)
{
	uint32_t counter = 0;
	uint8_t Tick = ((1* CTC_PRESCALER) / CTC_FREQUENCY);
	uint32_t Count = ((delay * CTC_MICROSECON) / Tick);
	uint32_t OVF = Count / CTC_BITS;
	uint8_t InitialValue = (CTC_BITS - (Count % CTC_BITS));
	TCNT0 = InitialValue;
	OVF++;
	while (counter != OVF)
	{
		while (GET_BIT(TIFR, OCF0) != 1);
		SET_BIT(TIFR, OCF0);
		counter++;
	}
}

// Non-Blocking Mode

uint8_t Initial_Value = 0;
uint32_t NUM_CTC  = 0;

void Timer0_CTC_WithInterrupt_Inti(void)
{
	// Choose Mode
	SET_BIT(TCCR0, WGM01);	CLR_BIT(TCCR0,WGM00);
	// Pin Disconnected
	CLR_BIT(TCCR0, COM01);	CLR_BIT(TCCR0, COM00);
	// Enable Interrupt
	SET_BIT(TIMSK, OCIE0);
	// Enable Global Interrupt
	SET_BIT(SREG, 7);
}
void Timer0_CTC_WithInterrupt_Start(void)
{
	// Choose 1024 Prescaler
	SET_BIT(TCCR0, CS02);	CLR_BIT(TCCR0, CS01);	SET_BIT(TCCR0, CS00);
}
void Timer0_CTC_WithInterrupt_Stop(void)
{
	// Choose 0 Prescaler
	CLR_BIT(TCCR0, CS02);	CLR_BIT(TCCR0, CS01);	CLR_BIT(TCCR0, CS00);
}
void Timer0_CTC_WithInterrupt_SetDelay(uint32_t delay)
{
	uint8_t Tick = ((1* CTC_PRESCALER) / CTC_FREQUENCY);
	uint32_t Count = ((delay * CTC_MICROSECON) / Tick);
	NUM_CTC = Count / CTC_BITS;
	Initial_Value = (CTC_BITS - (Count % CTC_BITS));
	TCNT0 = Initial_Value;
	NUM_CTC++;
}