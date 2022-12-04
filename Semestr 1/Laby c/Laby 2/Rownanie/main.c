#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c,d;
    printf("Podaj wspolczynniki rownania:\n");
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    if(a==0)
    {
        if(b==0)
        {
            if(c==0)
            {
                printf("Nieskonczenie wiele rozwiazan");
            }
            else
            {
                printf("Brak rozwiazan");
            }
        }
        else
        {
            printf("1 rozwiazanie");
        }
    }
    else
    {
        d = b*b-4*a*c;
        if(d<0)
        {
            printf("Brak rozwiazan");
        }
        else
        {
            if(d==0)
            {
                printf("1 rozwiazanie");
            }
            else
            {
                printf("2 rozwiazania");
            }
        }
    }
    return 0;
}
