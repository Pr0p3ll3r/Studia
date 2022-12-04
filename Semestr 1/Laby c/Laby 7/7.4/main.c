#include <stdio.h>
#include <stdlib.h>

void place();

int main()
{
    place();
    return 0;
}

void place()
{
    int n=0,liczba=0;
    float suma=0;
    do
    {
        printf("Podaj liczbe pracownikow: \n");
        scanf("%d", &n);
    }while(n<=0);

    for(int i=0;i<n;i++)
    {
        printf("Podaj zarobki pracownika: \n");
        scanf("%d", &liczba);
        float temp = liczba;
        if(liczba > 5000)
        {
            temp += liczba * 0.05;
            printf("Zarobki po podwyzce: %f\n", temp);
        }
        else
        {
            temp += liczba * 0.1;
            printf("Zarobki po podwyzce: %f\n", temp);
        }
        suma += temp;
    }

    printf("Suma nowych plac: %f", suma);
}
