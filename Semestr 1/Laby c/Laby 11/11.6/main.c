#include <stdio.h>
#include <stdlib.h>

float* f1(int n, int m, float tab2[n][m],int*d);
float* f2(int n, int m, float tab2[n][m],int*d);

int main()
{
    int n,m;
    printf("Podaj liczbe wierszy tablicy: ");
    scanf("%d",&n);
    printf("Podaj liczbe kolumn tablicy: ");
    scanf("%d",&m);
    float tab2[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("tab[%d][%d]= ", i,j);
            scanf("%f", &tab2[i][j]);
        }
    }

    for(int j=0;j<n;j++)
    {
        for(int k=0;k<m;k++)
        {
            printf("tab[%d][%d]= %f\t", j,k,tab2[j][k]);
        }
        printf("\n");
    }
    float *tabD;
    int d = 0;
    float *tabU;
    int u = 0;
    printf("Tablica Dodatnich\n");
    tabD=f1(n,m,tab2,&d);
    for(int l=0;l<d;l++)
    {
        printf("tab[%d]= %f\n", l,*(tabD+l));
    }
    printf("Tablica Ujemnych\n");
    tabD=f2(n,m,tab2,&u);
    for(int v=0;v<u;v++)
    {
        printf("tab[%d]= %f\n", v,*(tabD+v));
    }

    return 0;
}

float* f1(int n, int m, float tab2[n][m],int*d)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(tab2[i][j]>0.0)
                *d += 1;
        }
    }

    float *t = (float*) malloc(*d * sizeof(float));
    if(t==NULL)
    {
        printf("Brak wolnej pamieci");
        exit(1);
    }
    int x = 0;
    for(int e=0;e<n;e++)
    {
        for(int r=0;r<m;r++)
        {
            if(tab2[e][r]>0.0)
            {
                *(t + x) = tab2[e][r];
                x++;
            }
        }
    }
    return t;
}

float* f2(int n, int m, float tab2[n][m],int*d)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(tab2[i][j]>0.0)
                *d += 1;
        }
    }

    float *t = (float*) malloc(*d * sizeof(float));
    if(t==NULL)
    {
        printf("Brak wolnej pamieci");
        exit(1);
    }
    int x = 0;
    for(int e=0;e<n;e++)
    {
        for(int r=0;r<m;r++)
        {
            if(tab2[e][r]<0.0)
            {
                *(t + x) = tab2[e][r];
                x++;
            }
        }
    }
    return t;
}
