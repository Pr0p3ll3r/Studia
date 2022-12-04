#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losuj(int tab[]);
int *nowatabDyn(int*tabS, int n, int a, int b, int*m);

int main()
{
    srand(time(NULL));
    int tab[100];
    int a=0,b=0,m=0;
    int *tabDyn;
    losuj(tab);
    printf("Tablica statyczna\n");
    for(int j=0;j<100;j++)
    {
        printf("tab[%d]= %d\n", j,tab[j]);
    }
    printf("Tablica dynamiczna\nPodaj przedzial\n");
    printf("Od: ");
    scanf("%d", &a);
    printf("Do: ");
    scanf("%d", &b);
    tabDyn=nowatabDyn(tab, 100, a, b, &m);
    for(int k=0;k<m;k++)
    {
        printf("tab[%d]= %d\n", k, *(tabDyn+k));
    }
    return 0;
}

void losuj(int tab[])
{
    for(int i=0;i<100;i++)
    {
        tab[i] = rand()%100 + 1;
    }
}

int *nowatabDyn(int*tabS, int n, int a, int b, int*m)
{
    for(int i=0;i<n;i++)
    {
        if(*(tabS+i) >= a && *(tabS+i) <= b)
            *m += 1;
    }

    int *t = (int*) malloc(*m*sizeof(int));

    int x = 0;
    for(int j=0;j<n;j++)
    {
        if(*(tabS+j) >= a && *(tabS+j) <= b)
        {
            *(t + x) = *(tabS+j);
            x++;
        }
    }
    return t;
}
