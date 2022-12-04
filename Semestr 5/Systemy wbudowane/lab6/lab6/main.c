/*
 * lab6.c
 *
 * Created: 16.11.2022 14:28:16
 * Author : Student_PL
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL // ustawienie czêstotliwoœci zegara –proponowane 8MHz
#define BAUDRATE 9600 //okreœlenie prêdkoœci przesy³ania
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) -1) //wyznaczenie  za-wartoœci rejestru UBRR ze wzoru
 
void USART_Init(void){
	UBRRH = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRRL = (uint8_t)(BAUD_PRESCALLER);
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}
void USART_putchar(unsigned char data)
{
	while (!(UCSRA & (1<<UDRE)));
	UDR = data;
}
void USART_putstring(char *text)
{
	while(*text)
	{
		USART_putchar(*text);
		text++;
	}
	
}
unsigned char UART_RxChar()
{
	while ((UCSRA & (1<<RXC))==0);
	return UDR;
}

int main()
{
	USART_Init();

	USART_putstring("Nacisnij klawisz [q]");
	while  (1){
			char x = UART_RxChar();
			USART_putstring("asd");
			if(x == 'q')
			{
				USART_putstring("Znak prawidlowy");
			}
			else
			{
				USART_putstring("Bledny znak");
			}
		
	}

}

