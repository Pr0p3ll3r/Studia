#include <targets/AT91SAM7.h>
#include <ctl_api.h>

//Zadanie 5
int main(void)
{
  PMC_PCER = 1<<3 | 1<<12;// ustawienie zegara systemowego dla peryferiom TC0 oraz PIOB (str. 30 datasheet)
  PIOB_OER = 1<<20; // konfiguracja linii wyjsciowej (LAB1 – spotkanie 1 oraz 2)
  PIOB_OWER = 1<<20;
  TC0_CCR = 1 << 1; // wy³¹czamy inkrementacjê licznika tak, by mo¿liwa by³a jego konfiguracja
  TC0_SR; // pusty odczyt w celu wyzerowania ewentualnie ustawionych flag
  TC0_CMR = 3 | 1<<14; // wybór czêstotliwoœci inkrementacji licznika MCK/1024 (TIMER_CLOCK5)
  TC0_RC = 37500;
  TC0_CCR = 1<<0 | 1<<2; // w³¹czenie zegara timera oraz reset programowy (rejestr TC_CCR)
  while (1){
    if((TC0_SR & 1<<4) != 0) { // sprawdzenie czy na bicie 4 jest 1 – programowy odczyt powoduje reset wartoœci rejestru TC0_SR
        PIOB_ODSR ^= 1<<20;
    } 
  } 
}

/*
void PIOB_przerwanie()
{
   PIOB_ODSR ^= 1<<20;
}

//Zadanie 6
int main(void)
{
  PMC_PCER = 1<<3 | 1<<12;// ustawienie zegara systemowego dla peryferiom TC0 oraz PIOB (str. 30 datasheet)
  PIOB_OER = 1<<20; // konfiguracja linii wyjsciowej (LAB1 – spotkanie 1 oraz 2)
  PIOB_OWER = 1<<20;
  ctl_global_interrupts_disable(); //globalne wy³¹czenie przerwan
  ctl_set_isr(PIOB_ID,1,CTL_ISR_TRIGGER_FIXED,PIOB_przerwanie,0); //konfiguracja przerwania od timera, powi¹zanie procedury obs³ugi przerwania ze Ÿród³em
  PIOB_IER = 1<<24|1<<25; 
  ctl_unmask_isr(PIOB_ID); //isr - interrupt service routine (w³¹czenie w kontrolerze przerwao AIC obs³ugi tego konkretnego przerwania
  ctl_global_interrupts_enable(); //zezwolenie na globalne przerwania
  TC0_CCR = 1 << 1; // wy³¹czamy inkrementacjê licznika tak, by mo¿liwa by³a jego konfiguracja
  TC0_SR; // pusty odczyt w celu wyzerowania ewentualnie ustawionych flag
  TC0_CMR = 3 | 1<<14; // wybór czêstotliwoœci inkrementacji licznika MCK/1024 (TIMER_CLOCK5)
  TC0_RC = 37500;
  TC0_CCR = 1<<0 | 1<<2; // w³¹czenie zegara timera oraz reset programowy (rejestr TC_CCR)

  while (1){

  } 
}
*/