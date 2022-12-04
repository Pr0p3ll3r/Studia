#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,x;
    int lp;
    int przedostatni=0, ostatni=0;
    do
    {
        printf("Podaj liczbe elementow (minimum 2): \n");
        scanf("%d", &n);
    }while(n<2);

    do
    {
    printf("Podaj ktory element chcesz wyznaczyc: \n");
    scanf("%d", &k);
    }while(k>n);

    przedostatni = 1;
    ostatni = 2;
    lp=1;
    printf("\n%d\n",przedostatni);
    printf("%d\n",ostatni);
    if(k==1)
        x=przedostatni;
    else if(k==2)
        x=ostatni;

    for(int i=3;i<=n;i++)
    {
        int temp;
        temp = przedostatni + 2 * ostatni;
        if(temp%2==0)
            lp++;
        printf("%d\n", temp);

        przedostatni = ostatni;
        ostatni = temp;

        if(i==k)
            x=temp;
    }

    printf("\nWyznaczony element to: %d\n", x);
    printf("Elementow parzystych: %d", lp);

    return 0;
}
