/*
 * lcd.h
 *
 * Created: 09.11.2022 14:54:53
 *  Author: Student_PL
 */ 
#include <avr/io.h>
#include <util/delay.h>

#define LCD_DIR		DDRA
#define LCD_PORT	PORTA
#define LCD_RS		(1 << PA2)
#define LCD_E		(1 << PA3)
#define LCD_D4		(1 << PA4)
#define LCD_D5		(1 << PA5)
#define LCD_D6		(1 << PA6)
#define LCD_D7		(1 << PA7)

#ifndef LCD_H_
#define LCD_H_

void LCD_clear(); //czyszczenie ca³ego wyœwietlacza
void LCD_xy(int x, int y); //ustawianie markera na wybranej pozycji wyœwietlacza, gdzie x =(0 -górny wiersz,1 - dolny wiersz), y= (0,15)
void LCD_write(char *text); //procedura pisania tekstu z automatycznym prze³¹czaniem wiersz górny/wiersz dolny
void LCD_init(); //konfiguracja do trybu 4-bitowego wyœwietlacza
void LCD_cmd(uint8_t command); //przes³anie instrukcji do wyœwietlacza

#endif /* LCD_H_ */