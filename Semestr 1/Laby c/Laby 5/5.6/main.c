#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float pole(float a, float b, float c);

int main()
{
    float a,b,c;
    printf("Podaj dlugosci bokow trojkata: \n");
    scanf("%f %f %f", &a, &b, &c);
    if ((a+b>c) && (a+c>b) && (b+c>a))
    {
        printf("Pole wynosi: %f", pole(a,b,c));
    }
    else
    {
        printf("Z podanych bokow nie mozna zbudowac trojkata");
    }
    return 0;
}

float pole(float a, float b, float c)
{
    float p;
    p = (a+b+c)/2;
    return sqrt(p*(p - a)*(p - b)*(p - c));
}
