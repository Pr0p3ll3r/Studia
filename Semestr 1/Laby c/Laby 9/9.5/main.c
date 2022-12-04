#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fun(double);

int main()
{
    double x;
    printf("Podaj 1 liczbe rzeczywista:\n");
    scanf("%lf", &x);
    fun(x);
    printf("Podaj 2 liczbe rzeczywista:\n");
    scanf("%lf", &x);
    fun(x);
    printf("Podaj 3 liczbe rzeczywista:\n");
    scanf("%lf", &x);
    fun(x);
}

void fun(double x)
{
    double calkowita;
    double rzeczywista = modf(x, & calkowita);
    printf("Czesc calkowita z liczby %lf to %lf, a czesc rzeczywista to %lf\n", x, calkowita, rzeczywista);
}
