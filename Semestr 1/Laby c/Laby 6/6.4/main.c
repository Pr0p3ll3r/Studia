#include <stdio.h>
#include <stdlib.h>

void fun(char zdanie[50], char litera);

int main()
{
    char zdanie[50];
    char litera;
    printf("Podaj zdanie zakonczone '.'\n");
    scanf("%[^\n]s", &zdanie);
    printf("Podaj litere: \n");
    scanf(" %c", &litera);
    fun(zdanie, litera);
    return 0;
}

void fun(char zdanie[50], char litera)
{
    int i=0;
    int razy=0,cyfr=0;
    while(zdanie[i] != '.')
    {
        if(zdanie[i] == litera)
            razy++;

        if((int)zdanie[i] >= 48 && (int)zdanie[i] <= 57)
            cyfr++;

        i++;
    }

    printf("Podales zdanie: %s\nW podanym zdaniu litera %c wystepuje %d razy.\nCyfr: %d", zdanie, litera, razy, cyfr);
}
