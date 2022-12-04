#include <stdio.h>
#include <stdlib.h>

int liczby(int x, int y, int z);

int main()
{
    int x, y ,z;
    printf("Podaj 3 liczby calkowite dodatnie: \n");
    scanf("%d %d %d", &x, &y, &z);
    printf("%d",liczby(x, y ,z));
    return 0;
}

int liczby(int x, int y, int z)
{
    if(x%2==0 && y%2==0 && z%2==0)
        return x+y+z;
    else if(x==1 || y==1 || z==1)
        return x*y*z;
    else
        return -1;
}
