#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <boost/bind.hpp>
using namespace std;

template <typename T>
void show(vector<T> vec)
{
    float average = 0;
    float median = 0;
    sort(vec.begin(), vec.end());
    for(typename vector<T>::iterator it = vec.begin();it != vec.end();it++)
    {
        average += *it;
    }
    average /= vec.size();
    if(vec.size() % 2 == 0)
    {
        median = vec[(vec.size()-1)/2] + vec[vec.size()/2];
        median /= 2;
    }
    else
    {
        median = vec[vec.size()/2];
    }
    cout<<"Srednia "<<average<<" Mediana "<<median<<endl;
    cout<<"Elementy mniejsze niz srednia arytmetyczna"<<endl;
    for(typename vector<T>::iterator it = vec.begin();it != vec.end();it++)
    {
        if(*it < average)
            cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"Elementy miedzy srednia arytmetyczna a mediana"<<endl;
    for(typename vector<T>::iterator it = vec.begin();it != vec.end();it++)
    {
        if(*it >= average && *it<= median)
            cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"Elementy dodatnie"<<endl;
    for(typename vector<T>::iterator it = vec.begin();it != vec.end();it++)
    {
        if(*it > 0)
            cout<<*it<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> vec {1,2,3,4,5,6,7,8,9,10,0,-1,-2,-100};
    show(vec);
    return 0;
}
