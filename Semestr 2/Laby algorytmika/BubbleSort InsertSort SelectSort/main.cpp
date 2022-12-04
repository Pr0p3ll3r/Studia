#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

void przydzielPamiec1D(int *&tab, int n)
{
    tab = new int[n];
}

void wypelnijTablice1D(int *tab, int n, int a, int b)
{
    for(int i=0;i<n;i++)
    {
        tab[i]=rand()%(b-a+1)+a;
    }
}

void wyswietlTablice1D(int *tab, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

void usunTablice1D(int *&tab)
{
    delete [] tab;
    tab=nullptr;
}

void sortowanieBabelkowe(int* tab, int n, int a, int b, int tryb)
{
    przydzielPamiec1D(tab, n);
    wypelnijTablice1D(tab, n, a, b);
    wyswietlTablice1D(tab, n);

    if(tryb==0)
    {
        for(int i=n-1;i>0;i--)
        {
            for(int j=0;j<i;j++)
            {
                if(tab[j]>tab[j+1])
                {
                    swap(tab[j], tab[j+1]);
                }
            }
        }
    }
    else if(tryb==-1)
    {
        for(int i=n-1;i>0;i--)
        {
            for(int j=0;j<i;j++)
            {
                if(tab[j]<tab[j+1])
                {
                    swap(tab[j], tab[j+1]);
                }
            }
        }
    }

    wyswietlTablice1D(tab, n);
    usunTablice1D(tab);
}

void sortowaniePrzezWybor(int* tab, int n, int a, int b, int tryb)
{
    przydzielPamiec1D(tab, n);
    wypelnijTablice1D(tab, n, a, b);
    wyswietlTablice1D(tab, n);

    if(tryb==0)
    {
        for(int i=n-1;i>0;i--)
        {
            int ind=0;
            for(int j=1;j<=i;j++)
            {
                if(tab[j]>tab[ind])
                {
                    ind=j;
                }
            }
            swap(tab[i], tab[ind]);
        }
    }
    else if(tryb==-1)
    {
        for(int i=n-1;i>0;i--)
        {
            int ind=0;
            for(int j=1;j<=i;j++)
            {
                if(tab[j]<tab[ind])
                {
                    ind=j;
                }
            }
            swap(tab[i], tab[ind]);
        }
    }

    wyswietlTablice1D(tab, n);
    usunTablice1D(tab);
}

void sortowaniePrzezWstawianie(int* tab, int n, int a, int b, int tryb)
{
    przydzielPamiec1D(tab, n);
    wypelnijTablice1D(tab, n, a, b);
    wyswietlTablice1D(tab, n);
    if(tryb==0)
    {
        for(int i=n-2;i>=0;i--)
        {
            int j=i;
            int temp=tab[j];
            while(temp>tab[j+1] && j<n-1)
            {
                tab[j]=tab[j+1];
                j+=1;
            }
            tab[j]=temp;
        }
    }
    else if(tryb==-1)
    {
         for(int i=n-2;i>=0;i--)
        {
            int j=i;
            int temp=tab[j];
            while(temp<tab[j+1] && j<n-1)
            {
                tab[j]=tab[j+1];
                j+=1;
            }
            tab[j]=temp;
        }
    }

    wyswietlTablice1D(tab, n);
    usunTablice1D(tab);
}

void dane(int &n, int &a, int &b, int &t)
{
    cout<<"Podaj rozmiar tablicy: "<<endl;
    cin>>n;
    cout<<"Podaj przedzial <a,b>"<<endl;
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;
    cout<<"Podaj tryb (0 - rosnaco, -1 - malejaco)"<<endl;
    cin>>t;
}

int main()
{
    srand(time(NULL));
    int n, m, a, b, t, nrKol, *tab, **tab2, wybor;

    for(;;)
    {
        cout<<"MENU"<<endl;
        cout<<"1: Sortowanie babelkowe"<<endl;
        cout<<"2: Sortowanie przez wybor"<<endl;
        cout<<"3: Sortowanie przez wstawianie"<<endl;
        cout<<"4: Koniec programu"<<endl;
        cin>>wybor;

        switch(wybor)
        {
            case 1:
                dane(n,a,b,t);
                sortowanieBabelkowe(tab, n, a, b, t);
                break;
            case 2:
                dane(n,a,b,t);
                sortowaniePrzezWybor(tab, n, a, b, t);
                break;
            case 3:
                dane(n,a,b,t);
                sortowaniePrzezWstawianie(tab, n, a, b, t);
                break;
            case 4:
                exit(0);
            default:
                cout<<"Niepoprawny wybor"<<endl;
        }
    }
}
