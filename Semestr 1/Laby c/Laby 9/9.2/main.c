#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void zamiana(float *, float *);

int main()
{
    float x,y;
    printf("Podaj 2 liczby: ");
    scanf("%f %f", &x, &y);
    zamiana(&x, &y);
    printf("Pierwsza liczba: %f\n", x);
    printf("Druga liczba: %f", y);
    return 0;
}

void zamiana(float *x, float *y)
{
    float tempw = *x;
    *x = *y;
    *y = tempw;
}
