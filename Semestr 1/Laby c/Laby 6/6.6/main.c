#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=0;
    do
    {
        printf("0: Koniec programu\n1: Dodawanie\n2: Odejmowanie\n3: Mnozenie\n4: Dzielenie\n");
        scanf("%d", &x);
        switch(x)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("Dodawanie\n");
            break;
        case 2:
            printf("Odejmowanie\n");
            break;
        case 3:
            printf("Mnozenie\n");
            break;
        case 4:
            printf("Dzielenie\n");
            break;
        default:
            printf("Blad\n");
        }
    }while(x != 0);

    return 0;
}
