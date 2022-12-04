#include <stdio.h>
#include <stdlib.h>

void fun();

int main()
{
    fun();
    return 0;
}

void fun()
{
    int x, p, n, ip, in;
    do
    {
        printf("Podaj liczbe calkowita: ");
        scanf("%d", &x);
        if(x % 2 == 0)
        {
            p += x;
            ip++;
        }
        else
        {
            n += x;
            in++;
        }
    }while(x != 0);

    if(ip != 0)
        printf("Srednia liczb parzystych wynosi: %f\n", (float)p+1/ip);
    else
        printf("Nie ma liczb parzystych");

    if(in != 0)
        printf("Srednia liczb nieparzystych wynosi: %f", (float)n/in);
    else
        printf("Nie ma liczb nieparzystych");
}
