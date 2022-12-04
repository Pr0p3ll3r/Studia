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

int main()
{
    int N;
    float sumaPlac, max=0;
    printf("Podaj liczbe pracownikow \n");
    scanf("%d", &N);
    struct pracownik tab[N];
    float lista[N];
    for(int i=0;i<N;i++)
    {
        tab[i]=wczytaj();
        lista[i]=obliczPlace(tab[i]);
        sumaPlac+=lista[i];
        if(lista[i]>max)
            max=lista[i];
    }
    for(int j=0;j<N;j++)
    {
        printf("%s %s %f\n", tab[j].imie,tab[j].nazwisko,lista[j]);
    }
    printf("Suma plac %f\n", sumaPlac);
    printf("Najwiecej zarabiaja:\n");
    for(int k=0;k<N;k++)
    {
        if(lista[k]==max)
            printf("%s\n", tab[k].nazwisko);
    }
    return 0;
}

struct pracownik wczytaj()
{
    struct pracownik pr;
    printf("Podaj imie ");
    scanf("%s", &(pr.imie));
    printf("Podaj nazwisko ");
    scanf("%s", &(pr.nazwisko));
    printf("Podaj liczbe godzin ");
    scanf("%d", &(pr.godzin));
    printf("Podaj stawke ");
    scanf("%f", &(pr.stawka));
    printf("Podaj premie w %% ");
    scanf("%f", &(pr.premia));
    return pr;
}

void wyswietl(struct pracownik pr)
{
    printf("%s %s \nLiczba godzin: %d Stawka: %.2f Premia w %% %.2f%%\nPlaca: %.2f\n", pr.imie, pr.nazwisko, pr.godzin, pr.stawka, pr.premia, obliczPlace(pr));
}

float obliczPlace(struct pracownik pr)
{
    float placa = 0;
    placa += pr.godzin * pr.stawka;
    float premia = pr.premia / 100;
    placa += placa * premia;
    return placa;
}
