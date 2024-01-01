#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#include "DIO_Configurations.h"

void DIO_SetPin_Direction(DIO_Port port, DIO_Pin pin, DIO_State state);
void DIO_SetPin_Value(DIO_Port port, DIO_Pin pin, DIO_Status status);
void DIO_TogglePin_Value(DIO_Port port, DIO_Pin pin);
uint8_t DIO_ReadPin_Value(DIO_Port port, DIO_Pin pin);
void DIO_SetPin_PullUp(DIO_Port port, DIO_Pin pin);

#endif /* DIO_PRIVATE_H_ */