#include <stdio.h>
#include <stdlib.h>

void szczesliwy(char numer[6]);

int main()
{
    char numer[6];
    printf("Podaj szesciocyfrowy numer: \n");
    scanf("%s", numer);
    szczesliwy(numer);
    return 0;
}

void szczesliwy(char numer[6])
{
    int x,y;
    x = numer[0] + numer[1] + numer[2];
    y = numer[3] + numer[4] + numer[5];
    if(x == y)
        printf("Bilet jest \"szczesliwy\" ");
    else
        printf("Bilet nie jest \"szczesliwy\" ");
}
