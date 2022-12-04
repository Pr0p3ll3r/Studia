#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TabliceDyn2.h"

int** utworzT2D(int n, int m)
{
    int**tab2D; int i,j;
    tab2D = (int*) malloc(sizeof(int *)*n);
    if(tab2D==NULL)
    {
        printf("Blad przydzialu pamieci\n");
        exit(EXIT_FAILURE);
    }
    for(i=0; i < n; i++)
    {
        tab2D[i] = (int*) malloc(sizeof(int)*m);
        if(tab2D[i]==NULL)
        {
            printf("Blad przydzialu pamieci\n");
            exit(EXIT_FAILURE);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            *(*(tab2D+i)+j)=i*j;
            printf("tab[%d][%d]= ", i,j);
            scanf("%d", *(tab2D+i)+j);
        }
     }
     return tab2D;
}

void wyswietlT2D(int**tab2D,int n, int m)
{
    int i,j;
    printf("Tablica dynamiczna 2D\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d\t",*(*(tab2D+i)+j));
        }
        printf("\n");
    }
}

void usunTD(int *tabD)
{
    free(tabD);
    tabD=0;
}
