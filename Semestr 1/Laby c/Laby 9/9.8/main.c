#include <stdio.h>
#include <stdlib.h>

float lokaty(float, float, float, float *);

int main()
{
    float pierwszeOpro, drugaOpro, kwota1, kwota2;
    printf("Podaj kwote: ");
    scanf("%f", &kwota1);
    kwota2 = kwota1;
    printf("Podaj oprocentowanie polroczne i oprocentowanie roczne:(.../...)\n");
    scanf("%f/%f", &pierwszeOpro, &drugaOpro);
    kwota1 = lokaty(kwota1, pierwszeOpro, drugaOpro, &kwota2);
    printf("Kwota po pierwszym oprocentowaniu: %f\nKwota po pierwszym oprocentowaniu: %f", kwota1, kwota2);
    return 0;
}

float lokaty(float kwota, float x, float y, float *kwota2)
{
    x /= 100;
    y /= 100;
    printf("%f \n%f\n", x, y);
    for(int i = 0; i < 2; i++)
    {
        kwota = kwota + kwota * x;
    }
    *kwota2 = *kwota2 + *kwota2 * y;
    return kwota;
}
