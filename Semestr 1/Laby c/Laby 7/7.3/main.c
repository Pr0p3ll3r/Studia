#include <stdio.h>
#include <stdlib.h>

void srednia();

int main()
{
    srednia();
    return 0;
}

void srednia()
{
    int n=0,lp=0,suma=0, liczba=0;
    do
    {
        printf("Podaj liczbe elementow: \n");
        scanf("%d", &n);
    }while(n<=0);

    for(int i=0;i<n;i++)
    {
        printf("Podaj calkowity element ciagu: \n");
        scanf("%d", &liczba);
        if(liczba%2==0)
        {
            suma += liczba;
            lp++;
        }
    }

    if(lp != 0)
        printf("Srednia arytmetyczna liczb parzystych wynosi %f",(float)suma/lp);
    else
        printf("Brak liczb parzystych");
}
