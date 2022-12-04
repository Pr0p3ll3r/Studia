#include <stdio.h>
#include <stdlib.h>

void szlaczek();

int main()
{
    szlaczek();
    return 0;
}

void szlaczek()
{
    int d = 0;
    printf("Podaj dlugosc szlaczku: \n");
    scanf("%d", &d);
    for(int i=0;i<d;i++)
    {
        printf("*");
    }
}
