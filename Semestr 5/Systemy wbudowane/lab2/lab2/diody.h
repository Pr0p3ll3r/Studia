#include <avr/io.h>
#include <util/delay.h>

#ifndef DIODY_H
#define DIODY_H
#define diodDDR DDRA
#define diodPORT PORTA

void LED_konf();
void LED_Set(unsigned int LED_number);
void LED_Clear(unsigned int LED_number);
void LED_Toggle(unsigned int LED_number);
unsigned int LED_GetState(unsigned int LED_Number);

#endif //DIODY_H