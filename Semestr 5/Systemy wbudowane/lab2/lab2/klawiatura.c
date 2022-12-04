#include "klawiatura.h"

void SW_konf(){
	keypadDDR = 0xF0; //konfiguracja DDR do prawid³owej obs³ugi klawiatury
	keypadPORT = 0x0F; //konfiguracja PORT do prawid³owej obs³ugi klawiatury	
}

int SW_odczyt(){
	return keypadPIN&0x0F;
}

int SW_czytaj(){ //funkcja getKey
	int y = 0; //zerowanie zmiennej odpowiadajacej ilosci wcisnietych przyciskow
	int wynik = 0; //zmienna wynik odpowiada jaka wartosc jest zwracana z funkcji
	int x = 0;
	
	for(int i=4;i<8;i++){
		keypadPORT - _BV(i) //wybranie (i-3)-tej kolumny
		_delay_ms(1); //opoznienie 1ms
		x = SW.odczyt(); //zapamietanie stanu klawiatury
		_delay_ms(1); //opoznienie 1ms
		
		switch(x) //wybor po odczytanym stanie klawiatury
		{
			case 0b00001110: //pierwszy wiersz
				y=y+1;
				if(y>1){
					return 255 //jesli zostal juz wcisniety jakis klawisz zwracamy wartosc 255
				}else {
					wynik = i-3; //zapisz wartosc przycisku
				}
				break;
			case 0b00001101: //drugi wiersz
				y=y+1;
				if(y>1){
					return 255 //jesli zostal juz wcisniety jakis klawisz zwracamy wartosc 255
				}else {
					wynik = i+1; //zapisz wartosc przycisku
				}
				break;
			case 0b00001011: //trzeci wiersz
				y=y+1;
				if(y>1){
					return 255 //jesli zostal juz wcisniety jakis klawisz zwracamy wartosc 255
				}else {
					wynik = i+5; //zapisz wartosc przycisku
				}
				break;
			case 0b00000111: //czwarty wiersz
				y=y+1;
				if(y>1){
					return 255 //jesli zostal juz wcisniety jakis klawisz zwracamy wartosc 255
				}else {
					wynik = i+9; //zapisz wartosc przycisku
				}
				break;
			default:
				if(x != 0b00001111) //jesli wartosc pozyskana jest rozna od wartosci braku przycisnietych przyciskow
				{
					wynik = 255;
				}
		}
	}	
	return wynik;
}