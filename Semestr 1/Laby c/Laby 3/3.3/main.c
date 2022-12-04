#include <stdio.h>
#include <stdlib.h>

#define STATUS "student"
#define SREDNIA 3.55

int main()
{
    char imie[20], nazwisko[20], plec[2];
    int wiek;
    printf("Podaj imie\n");
    scanf("%s", imie);
    printf("Podaj nazwisko\n");
    scanf("%s", nazwisko);
    printf("Podaj wiek\n");
    scanf("%d", &wiek);
    printf("Podaj plec(M/K)\n");
    scanf("%s", &plec);
    printf("%s %s %d %s\n", imie, nazwisko, wiek, plec);
    printf("%s, %1.2f", STATUS, SREDNIA);
    return 0;
}
