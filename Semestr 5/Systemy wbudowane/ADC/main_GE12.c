#include <targets\AT91SAM7.h>
#include "pcf8833u8_lcd.h"
#include <ctl_api.h>
#include <string.h>

void TIMER0_ISR () {
    TC0_SR; // na pocz�tku pusty odczyt rejestru statusu - kasowanie flagi przerwania CPCS
    ADC_CR = 1<<1; // lub ADC_CR_START; // start konwersji na aktywnych kana�ach
    while ((ADC_SR & ADC_SR_EOC5) == 0) {} // dop�ki flaga EOC5 jest rowna 0 (konwersja na kanale 5 nie zakooczy�a si�) czekaj
    int a = 20 + (ADC_CDR5 - 500)/5;
    char b[4];
    itoa(a, b, 10);
    LCDPutStr(b, 20, 20, LARGE, WHITE, BLACK);
    TC0_RC = 9375;
  }

void PIOB_przerwanie(){
     PIOB_ODSR ^= 1<<20;
  }

int main (){

InitLCD();
SetContrast(50);
LCDClearScreen();
PMC_PCER = 1<<3 | 1<<17 | 1<<12 | 1<<1; // Power management controller (s. 30 datasheet)
// konfiguracja ADC, konwersja warto�ci napi�cia z kana�u 3 przetwornika:
ADC_CR = 1 << 0; // lub ADC_CR_SWRST � to inny zapis tego samego � reset przetwornika
ADC_CHER = 1 << 5; // aktywowanie kana��w na kt�rych ma byd przeprowadzona konwersja
ADC_IDR = 0xFFFFF; // �wiadomie wy��czamy przerwania od wszystkich zdarzeo(�r�de�) z ADC
ADC_MR = (23<<ADC_MR_PRESCAL_BIT) | (2<<ADC_MR_STARTUP_BIT) | (1<<ADC_MR_SHTIM_BIT);
// w rejestrze ADC_MR mo�liwe r�wnie� ustawienia ni�szej rozdzielczo�ci

//Zadanie 2
ctl_global_interrupts_disable();  //globalne wy��czenie przerwa�

PMC_PCER = PMC_PCER_PIOA | PMC_PCER_TC0; // za��czenie zegara PIOA USART0 TIMER0 

TC0_CCR = TC0_CCR_CLKDIS;    //trzeba wy��czy� zegar
TC0_IDR = 0xFF;  // wy��czy� wszystkie przerwania strona 421
TC0_SR;  //PUSTY ODCZYT, czytamy, ale warto�ci nigdzie nie zapisujemy ///// odczyt na pusto rejestru TC_SR, jak si� go czyta to si� zeruje
// wybranie preskalera TIMER_CLOCK1 = MCK/2, 389
TC0_CMR = (1<<2); // wybieramy preskaler /1024 czyli MCK/8, preskaler 5 /// p�niej ustawimy bit CPCTRG - rc compare --> reset counter i star clock //  skracamy licznik
TC0_CMR = (1<<2) | TC0_CMR_CPCTRG;  // strona 409 MCK/1024 i reset licznika przy por�wnaniu warto�ci licznika z rejestrem RC

TC0_RC = 9375;

ctl_set_isr(12,1,CTL_ISR_TRIGGER_FIXED,TIMER0_ISR,0);   // konfiguracja przerwania od timera, powi�zanie procedury obs�ugi przerwania ze �r�d�em
TC0_IER = TC0_IER_CPCS;   // za��czenie �r�d�a przerwania od por�wnania warto�ci licznika z rejestrem RC
ctl_unmask_isr(12);   // zezwolenie na przerwania od timera (wy�czenie procedury obs�ugi przerwania)
//start TIMERA
TC0_CCR = TC0_CCR_CLKEN | TC0_CCR_SWTRG; // za��czenie zegara | reset licznika

ctl_global_interrupts_enable(); //zezwolenie na globalne przerwania

while(1){
  
}

//Zadanie 1
/*
while(1){
  ADC_CR = 1<<1; // lub ADC_CR_START; // start konwersji na aktywnych kana�ach
  while ((ADC_SR & ADC_SR_EOC5) == 0) {} // dop�ki flaga EOC5 jest rowna 0 (konwersja na kanale 5 nie zakooczy�a si�) czekaj
  int a = 20 + (ADC_CDR5 - 500)/5;
  char b[4];
  itoa(a, b, 10);
  LCDPutStr(b, 20, 20, LARGE, WHITE, BLACK);
}
*/
}