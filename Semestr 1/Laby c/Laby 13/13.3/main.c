#include <stdio.h>
#include <stdlib.h>

struct pracownik
{
    char imie[15];
    char nazwisko[25];
    int godzin;
    float stawka;
    float premia;
};
struct pracownik wczytaj();
float obliczPlace();
void wyswietl(struct pracownik pr);
void wczytaj_wsk(struct pracownik *wsk);
void wyswietl_wsk(struct pracownik *wsk);
float obliczPlace_wsk(struct pracownik *wsk);

int main()
{
    struct pracownik pr, pr2;
    pr=wczytaj();
    wyswietl(pr);
    wczytaj_wsk(&pr2);
    wyswietl_wsk(&pr2);
    return 0;
}

struct pracownik wczytaj()
{
    struct pracownik pr;
    printf("Podaj imie ");
    gets(pr.imie);
    printf("Podaj nazwisko ");
    gets(pr.nazwisko);
    printf("Podaj liczbe godzin ");
    scanf("%d", &(pr.godzin));
    printf("Podaj stawke ");
    scanf("%f", &(pr.stawka));
    printf("Podaj premie w %% ");
    scanf("%f", &(pr.premia));
    return pr;
}

void wczytaj_wsk(struct pracownik *wsk)
{
    printf("Podaj imie ");
    gets(wsk->imie);
    printf("Podaj nazwisko ");
    gets(wsk->nazwisko);
    printf("Podaj liczbe godzin ");
    scanf("%d", wsk->godzin);
    printf("Podaj stawke ");
    scanf("%f", wsk->stawka);
    printf("Podaj premie w %% ");
    scanf("%f", wsk->premia);
}

void wyswietl(struct pracownik pr)
{
    printf("%s %s \nLiczba godzin: %d Stawka: %.2f Premia w %% %.2f%%\nPlaca: %.2f\n", pr.imie, pr.nazwisko, pr.godzin, pr.stawka, pr.premia, obliczPlace(pr));
}

void wyswietl_wsk(struct pracownik *wsk)
{
     printf("%s %s \nLiczba godzin: %d Stawka: %.2f Premia w %% %.2f%%\nPlaca: %.2f", wsk->imie, wsk->nazwisko, wsk->godzin, wsk->stawka, wsk->premia, obliczPlace_wsk(wsk));
}

float obliczPlace(struct pracownik pr)
{
    float placa = 0;
    placa += pr.godzin * pr.stawka;
    float premia = pr.premia / 100;
    placa += placa * premia;
    return placa;
}

float obliczPlace_wsk(struct pracownik *wsk)
{
    float placa = 0;
    placa += wsk->godzin * wsk->stawka;
    float premia = wsk->premia / 100;
    placa += placa * premia;
    return placa;
}
