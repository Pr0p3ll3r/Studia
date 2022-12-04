/*
 * GccApplication1.c
 *
 * Created: 09.11.2022 14:49:37
 * Author : Student_PL
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

int main(void)
{
    LCD_init();	
	LCD_clear();	
    LCD_write("POLLUB");

    while(1)
    {

    }
    
    return 0;
}

