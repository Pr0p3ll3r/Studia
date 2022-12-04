#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, pp, v;
    printf("Podaj bok szescianu\n");
    scanf("%f",&a);
    if(a>0)
    {
        pp=6*a*a;
        v=a*a*a;
        printf("Pole powierzchni szescianu o boku %0.2f wynosi %0.2f,\na jego objetosc %0.2f",a,pp,v);
    }
    else
    {
        printf("Bledne dane!");
    }
}
