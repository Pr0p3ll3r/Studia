/*
 * lab2.c
 *
 * Created: 19.10.2022 10:26:09
 * Author : Student_PL
 */ 
#define F_CPU 1000000UL

#include "klawiatura.h"
#include "diody.h"


int main(void)
{
    LED_konf();
	SW_konf();
    while (1) 
    {
		PORTA = SW_czytaj();
		_delay_ms(2);
    }
}

