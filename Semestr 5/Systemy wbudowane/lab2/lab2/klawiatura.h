#include <avr/io.h>
#include <util/delay.h>

#ifndef KLAWIATURA_H
#define KLAWIATURA_H
#define keypadDDR DDRC
#define keypadPIN PINC
#define keypadPORT PORTC

void SW_konf();
int SW_czytaj();
int SW_odczyt();

#endif //KLAWIATURA_H