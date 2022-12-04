#include <stdio.h>
#include <stdlib.h>

int main()
{
    float w;
    printf("Podaj wzrost\n");
    scanf("%f", &w);
    if(w>0)
    {
        if(w<1.65)
            printf("Osoba jest niskiego wzrostu");
        else if(w<=1.85)
            printf("Osoba jest sredniego wzrostu");
        else
            printf("Osoba jest wysokiego wzrostu");
    }
    else
    {
        printf("Bledne dane");
    }
    return 0;
}
