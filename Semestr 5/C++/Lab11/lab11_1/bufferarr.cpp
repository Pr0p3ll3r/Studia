#include "bufferarr.h"
using namespace std;

BufferArr::BufferArr(int n)
{
    this->n = n;
    tab = new int[n];
    current = 0;
    cout<<"Konstruktor klasy BufferArr"<<endl;
}

BufferArr::~BufferArr()
{
    delete [] tab;
    cout<<"Destruktor klasy BufferArr"<<endl;
}

void BufferArr::add(int a)
{
    if(current < n)
    {
        tab[current] = a;
        current++;
    }
    else
    {
        cout<<"Tablica jest pelna"<<endl;
    }
}

void BufferArr::write()
{
    for(int i=0;i<current;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}
