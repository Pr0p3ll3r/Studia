#include <stdio.h>
#include <stdlib.h>
struct daneos
{
    char imie[15];
    char nazwisko[25];
};
struct daneos wczytaj();
void wyswietl(struct daneos os);
void wczytaj2(struct daneos *wsk);
void wyswietl2(struct daneos *wsk);

int main(int argc, char *argv[])
{
    struct daneos osoba, osoba2;
    printf("Osoba 1\n");
    osoba=wczytaj();
    wyswietl(osoba);
    printf("Osoba 2\n");
    wczytaj2(&osoba2);
    wyswietl2(&osoba2);
    system("PAUSE");
    return 0;
}

struct daneos wczytaj()
{
    struct daneos os;
    printf("Podaj imie ");
    gets(os.imie);
    printf("Podaj nazwisko ");
    gets(os.nazwisko);
    return os;
}

void wyswietl(struct daneos os)
{
    printf("%s %s \n", os.imie, os.nazwisko);
}

void wczytaj2(struct daneos *wsk)
{
    printf("Podaj imie ");
    gets(wsk->imie);
    printf("Podaj nazwisko ");
    gets(wsk->nazwisko);
}

void wyswietl2(struct daneos *wsk)
{
    printf("%s %s \n",  wsk->imie,wsk->nazwisko);
}
