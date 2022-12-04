#include <stdio.h>
#include <stdlib.h>

int main()
{
    float stawka, premia, dodatek;
    int l;
    printf("Podaj stawke: ");
    scanf("%f", &stawka);
    printf("Podaj premie: ");
    scanf("%f", &premia);
    printf("Podaj ilosc lat: ");
    scanf("%d", &l);
    if(l>=5)
    {
        if(l>20)
        {
            dodatek = (stawka * 20)/100;
        }
        else
        {
            dodatek = (stawka * l)/100;
        }
    }

    printf("Stawka: %0.2f\n", stawka);
    printf("Dodatek: %0.2f\n", dodatek);
    printf("Premia: %0.2f\n", premia);
    return 0;
}
