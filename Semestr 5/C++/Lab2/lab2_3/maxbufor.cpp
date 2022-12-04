#include "maxbufor.h"
#include <climits>
#include <iostream>
using namespace std;

MaxBufor::MaxBufor()
{

}

MaxBufor::MaxBufor(int size1):Bufor(size1)
{

}

MaxBufor::~MaxBufor()
{

}

double MaxBufor::calculate()
{
    int max = INT_MIN;
    int size = getSize();
    for(int i=0;i<size;i++)
    {
        if(max<getTab(i))
           max=getTab(i);
    }
    return max;
}

void MaxBufor::add(int value)
{
    if(getIndex()<=getSize())
        setFirst(value);
    else
        cout<<"Brak miejsca w tablicy"<<endl;
}
