#include <iostream>
#include <cmath>

using namespace std;

void alokowaniePamieci(float *&tab, int n)
{
    tab = new float[n];
}

void fun(float *tab, int n)
{
    for(int i=0;i<n;i++)
    {
        tab[i]=sqrt(i+1);
        cout<<tab[i]<<endl;
    }
}

void usuwaniePamieci(float *&tab)
{
    delete [] tab;
    tab = nullptr;
}

int main()
{
    int n;
    float *tab;
    cout << "Podaj rozmiar tablicy: ";
    cin>>n;
    alokowaniePamieci(tab, n);
    fun(tab, n);
    usuwaniePamieci(tab);
    return 0;
}
