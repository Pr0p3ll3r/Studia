/*
 * lcd.c
 *
 * Created: 09.11.2022 14:54:40
 *  Author: Student_PL
 */ 
	
#include "lcd.h"

void LCD_clear() //czyszczenie ca³ego wyœwietlacza
{ 
	LCD_cmd(0x01);  //wyczyszczenie wyœwietlacza
	LCD_cmd(0x80);	//kursor na pozycji startowej
	_delay_ms(2);
}
	
void LCD_xy(int x, int y) //ustawianie markera na wybranej pozycji wyœwietlacza, gdzie x =(0 -górny wiersz,1 - dolny wiersz), y= (0,15)
{		
	LCD_WriteCommand(0x80 | (x + (0x40 * y)));
}

void _LCD_OutNibble(unsigned char nibbleToWrite)
{
	if(nibbleToWrite & 0x01)
		LCD_PORT |= LCD_DB4;
	else
		LCD_PORT  &= ~LCD_DB4;

	if(nibbleToWrite & 0x02)
		LCD_PORT |= LCD_DB5;
	else
		LCD_PORT  &= ~LCD_DB5;

	if(nibbleToWrite & 0x04)
		LCD_PORT |= LCD_DB6;
	else
		LCD_PORT  &= ~LCD_DB6;

	if(nibbleToWrite & 0x08)
		LCD_PORT |= LCD_DB7;
	else
		LCD_PORT  &= ~LCD_DB7;
}

void LCD_write(char *text) //procedura pisania tekstu z automatycznym prze³¹czaniem wiersz górny/wiersz dolny
{
	LCD_PORT |= LCD_RS;
	while(*text)
	{
		LCD_PORT |= LCD_E;
		_LCD_OutNibble(*text >> 4);
		LCD_PORT &= ~LCD_E;
		LCD_PORT |= LCD_E;
		_LCD_OutNibble(*text);
		LCD_PORT &= ~LCD_E;
		_delay_us(50);
		*text++;	
	}
}

void LCD_init() //konfiguracja do trybu 4-bitowego wyœwietlacza
{
	unsigned char i;
	LCD_PORT = 0xFF; //Konfiguracja kierunku pracy wyprowadzeñ
	LCD_DIR = 0xFF; //
	_delay_ms(15); // oczekiwanie na ustalibizowanie siê napiecia zasilajacego
	LCD_PORT &= ~LCD_RS; // wyzerowanie linii RS
	LCD_PORT &= ~LCD_E;  // wyzerowanie linii E

	for(i = 0; i < 3; i++) // trzykrotne powtórzenie bloku instrukcji
	{
		LCD_PORT |= LCD_E; //  E = 1
		_LCD_OutNibble(0x03); // tryb 8-bitowy
		LCD_PORT &= ~LCD_E; // E = 0
		_delay_ms(5); // czekaj 5ms
	}

	LCD_PORT |= LCD_E; // E = 1
	_LCD_OutNibble(0x02); // tryb 4-bitowy
	LCD_PORT &= ~LCD_E; // E = 0
	_delay_ms(1);
	LCD_cmd(0x28);		// Interfejs 4-bity, 2 linie, znak 5x7
	LCD_cmd(0x0C);		// Wyœwietlacz ON Kursor OFF
	LCD_cmd(0x06);		// Automatyczna inkrementacja kursora
	LCD_cmd(0x80);		// Pierwszy wiersz pierwsza kolumna
}

void LCD_cmd(uint8_t data) //przes³anie instrukcji do wyœwietlacza
{
	LCD_PORT &= ~LCD_RS; // wyzerowanie linii RS
	LCD_PORT |= LCD_E; // E = 1
	_LCD_OutNibble(data >> 4);
	LCD_PORT &= ~LCD_E; // E = 0
	LCD_PORT |= LCD_E; // E = 1
	_LCD_OutNibble(data);
	LCD_PORT &= ~LCD_E; // E = 0
	_delay_us(50);
}
