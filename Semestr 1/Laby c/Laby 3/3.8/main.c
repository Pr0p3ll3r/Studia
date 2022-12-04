#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float wyr1(float x);
float wyr2(float x);
float wyr3(float alfa);
float wyr4(float beta);

int main()
{
    float x;
    float alfa, beta;

    printf("Wynik 1 wyrazenia: %f\n", wyr1(x));
    printf("Wynik 2 wyrazenia: %f\n", wyr2(x));
    printf("Wynik 3 wyrazenia: %f\n", wyr3(alfa));
    printf("Wynik 4 wyrazenia: %f\n", wyr4(beta));

    return 0;
}

float wyr1(float x)
{
    float wynik =0;

    printf("Podaj x: \n");
    scanf("%f", &x);

    wynik = 10 * cos(x) - 0.1 * pow(x, 2) + sin(x) + sqrt(4 * pow(x, 2) + 7);
    return wynik;
}

float wyr2(float x)
{
    float wynik =0;

    wynik = log10(x+5) + exp(x+1) - abs(tan(x) + 1);
    return wynik;
}

float wyr3(float alfa)
{
    float wynik =0;

    printf("Podaj kat alfa: (w stopniach)\n");
    scanf("%f", &alfa);
    alfa *= M_PI / 180;
    wynik = (pow(sin(alfa), 2) + 0.5)/(cos(pow(alfa, 4))) + pow(tan(pow(alfa, 2)), 4);
    return wynik;
}

float wyr4(float beta)
{
    float wynik =0;

    printf("Podaj kat beta: (w stopniach)\n");
    scanf("%f", &beta);
    beta *= M_PI / 180;
    wynik = sqrt((abs(5 * sin(pow(beta, 5)) + 1))/3.5 * (pow(sin(beta) + cos(beta), 2)));
    return wynik;
}
