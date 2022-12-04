/*
 * GccApplication10.c
 *
 * Created: 26.10.2022 14:23:29
 * Author : Student_PL
 */ 

//Zrobi³em zadanie 1 i 2

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL
#include <util/delay.h>

//Zadanie 1
/*
int main(void)
{
	DDRA=0xFF;
	PORTA=0x00;
	TCCR0|=(1<<CS00)|(1<<CS02); //ustawienie preskalera 1024
	TCNT0=155; //wartosc poczatkowa timera
	int licz=0;
    while (1) 
    {
		while(licz<=10)
		{
			if(TIFR&=(1<<TOV0)) //flaga przepe³nienia
			{
				TIFR|=(1<<TOV0); //zerowanie flagi
				TCNT0=155; //wartoœæ pocz¹tkowa timera
				licz++;
			}
		}
		PORTA^=0x01; //zmiana stanu jednej diody
		licz=0;
    }
}
*/

//Zadanie 2
/*
int licz = 0;
ISR(TIMER0_OVF_vect) //przerwanie przepe³nienie timera
{
	licz++;
	TCNT0=155; //wartoœæ pocz¹tkowa timera
	TIFR|=(1<<TOV0); //zerowanie flagi
	if(licz == 10)
	{
		PORTA^=0x01; //zmiana stanu jednej diody
		licz=0;
	}
}

int main(void)
{
	DDRA=0xFF;
	PORTA=0x00;
	TCCR0|=(1<<CS00)|(1<<CS02); //ustawienie preskalera 1024
	TCNT0=155; //wartoœæ poczatkowa timera
	TIMSK|=1<<TOIE0; //w³¹czenie przerwania przepe³nienia flagi
	sei(); //globalne w³¹czenie przerwañ
	while (1)
	{

	}
}
*/

//Zadanie 3
int check_keyboard()
{
	uint8_t key;
	int pressed;
	DDRB = 0xf0;
	pressed = 0;
	PORTB = 0b11101111;
	_delay_ms(2);
	key = PINB & 0x0f;
	switch (key)
	{
			case 0b00001111:if(pressed == 0)pressed = 0;break;
			case 0b00001110:pressed = 1;break;
			case 0b00001101:pressed = 5;break;
			case 0b00001011:pressed = 9;break;
			case 0b00000111:pressed = 13;break;
			default:pressed = 255;
	}
	_delay_ms(2);
	PORTB = 0b11011111;
	_delay_ms(2);
	key = PINB & 0x0f;
	switch (key)
	{
		case 0b00001111:if(pressed == 0)pressed = 0;break;
		case 0b00001110:pressed = 2;break;
		case 0b00001101:pressed = 6;break;
		case 0b00001011:pressed = 10;break;
		case 0b00000111:pressed = 14;break;
		default:pressed = 255;
	}			
	_delay_ms(2);
	PORTB = 0b10111111;
	_delay_ms(2);
	key = PINB & 0x0f;
	switch (key)
	{
		case 0b00001111:if(pressed == 0)pressed = 0;break;
		case 0b00001110:pressed = 3;break;
		case 0b00001101:pressed = 7;break;
		case 0b00001011:pressed = 11;break;
		case 0b00000111:pressed = 15;break;
		default:pressed = 255;
	}
	_delay_ms(2);
	PORTB = 0b01111111;
	_delay_ms(2);
	key = PINB & 0x0f;
	switch (key)
	{
		case 0b00001111: if(pressed == 0)pressed = 0; break;
		case 0b00001110: pressed = 4; break;
		case 0b00001101:pressed = 8;break;
		case 0b00001011:pressed = 12;break;
		case 0b00000111:pressed = 16;break;
		default: pressed = 255;
	}
	_delay_ms(2);
	return pressed;
}

int licz = 0;
int ile = 10;
ISR(TIMER0_OVF_vect) //przerwanie przepe³nienie timera
{
	licz++;
	TCNT0=155; //wartoœæ pocz¹tkowa timera
	TIFR|=(1<<TOV0); //zerowanie flagi
	if(licz == ile)
	{
		PORTA^=0x01; //zmiana stanu jednej diody
		licz=0;
	}
}

ISR(INT0_vect)
{
	int klawisz = check_keyboard();
	if(klawisz == 15)
	{
				
	}
	else if(klawisz == 14)
	{
		
	}
	else
	{		
		ile = klawisz;
	}
}

int main(void)
{
	DDRA=0xFF;
	DDRB=0xFF;
	PORTA=0x00;
	TCCR0|=(1<<CS00)|(1<<CS02); //ustawienie preskalera 1024
	TCNT0=155; //wartoœæ poczatkowa timera
	TIMSK|=1<<TOIE0; //w³¹czenie przerwania przepe³nienia flagi
	GIMSK|=(1<<INT0); //w³¹czenie obs³ugi przerwania INT0
	sei(); //globalne w³¹czenie przerwañ
	ile = 10;
	licz = 0;
	while (1)
	{

	}
}
