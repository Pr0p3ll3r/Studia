#include <iostream>

using namespace std;

int horner(int, int[], int);
int silnia(int);

int main()
{
    int n = 4;
    int a[n+1] = {-3, 0, 1, -2, 4};
    int x = 2;

    for(int i = 0; i < n+1; i++)
    {
        int wynik;
        wynik = horner(x, a, n-i);
        a[n-i]=wynik;
        cout<<"w"<<i<<" = "<<a[n-i]*silnia(i)<<endl;
    }

    return 0;
}

int horner(int x, int a[], int n)
{
    int wynik = a[0];
    for(int i = 0;i < n; i++)
    {
        wynik = x*wynik + a[i+1];
        a[i+1] = wynik;
    }
    return wynik;
}

int silnia(int x)
{
    if(x==0 || x==1) return 1;
    int wynik=1;
    for(int i = 0; i < x; i++)
    {
        wynik *= i+1;
    }
    return wynik;
}
