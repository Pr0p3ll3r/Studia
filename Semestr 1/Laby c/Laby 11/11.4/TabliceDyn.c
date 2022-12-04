#include <stdio.h>
#include <stdlib.h>
#include "TabliceDyn.h"

float *utworzTablice(int n)
{
    float *t = (float*) malloc (n*sizeof(float));
    if(t==NULL)
    {
        printf("Brak wolnej pamieci");
        exit(1);
    }
    for(int i=0;i<n;i++)
    {
        printf("tab[%d] = ", i);
        scanf("%f", t + i);
    }
    return t;
}

void wyswietlTablice(float *t, int n)
{
    printf("Zawartosc tablicy:\n");
    for(int i=0;i<n;i++)
    {
        printf("%f\t", *(t+i));
    }
    printf("\n");
}

float **utworzTablice2D(int n, int m)
{
    float **t = (float*) malloc (n*sizeof(float));
    if(t==NULL)
    {
        printf("Brak wolnej pamieci");
        exit(1);
    }
    for(int i=0;i<n;i++)
    {
        t[i] = (int*) malloc(sizeof(float)*m);
        if(t[i]==NULL)
        {
            printf("Brak wolnej pamieci");
            exit(1);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            *(*(t+i)+j)=i*j;
            printf("tab[%d][%d]= ", i,j);
            scanf("%f", *(t+i)+j);
        }
    }
    return t;
}

void wyswietlTablice2D(float **t, int n, int m)
{
    printf("Zawartosc tablicy:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%f\t", *(*(t+i)+j));
        }
        printf("\n");
    }
    printf("\n");
}

void usunTablice(float *t)
{
    free(t);
    t = 0;
}
