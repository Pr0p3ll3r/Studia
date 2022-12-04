#include <stdio.h>
#include <stdlib.h>

struct Zespolone{
    int re;
    int im;
};

struct Zespolone wczytaj();
void wyswietl(struct Zespolone z);
void roznica(struct Zespolone z1, struct Zespolone z2);

int main()
{
    struct Zespolone z1, z2;
    printf("Liczba zespolona 1:\n");
    z1=wczytaj();
    printf("Liczba zespolona 2:\n");
    z2=wczytaj();
    printf("Liczba zespolona 1: ");
    wyswietl(z1);
    printf("Liczba zespolona 2: ");
    wyswietl(z2);
    roznica(z1,z2);
    return 0;
}

struct Zespolone wczytaj()
{
    struct Zespolone z;
    printf("Podaj czesc rzeczywista liczby zespolonej ");
    scanf("%d", &z.re);
    printf("Podaj czesc urojona liczby zespolonej ");
    scanf("%d", &z.im);
    return z;
}

void wyswietl(struct Zespolone z)
{
    if(z.im >= 0)
        printf("%d+%di \n", z.re, z.im);
    else
        printf("%d%di \n", z.re, z.im);
}

void roznica(struct Zespolone z1, struct Zespolone z2)
{
    int re = z1.re - z2.re;
    int im = z1.im - z2.im;
    if(im >= 0)
        printf("Roznica: %d+%di", re, im);
    else
        printf("Roznica: %d%di", re, im);
}
