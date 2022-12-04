#include <stdio.h>
#include <stdlib.h>

void ciag();

int main()
{
    ciag();
    return 0;
}

void ciag()
{
    int n=0,liczba=0,temp=0,roznica=0, roznicatemp=0, x=0;
    do
    {
        printf("Podaj liczbe elementow (minimum 3): \n");
        scanf("%d", &n);
    }while(n<3);

    printf("Podaj element: \n");
    scanf("%d", &liczba);
    temp = liczba;
    printf("Podaj element: \n");
    scanf("%d", &liczba);
    roznicatemp = liczba - temp;
    temp = liczba;
    for(int i=2;i<n;i++)
    {
        printf("Podaj element: \n");
        scanf("%d", &liczba);
        roznica = liczba - temp;
        if(roznica != roznicatemp)
            x=1;
    }

    if(x==1)
        printf("Nie jest to ciag arytmetyczny");
    else
        printf("Jest to ciag arytmetyczny");
}
