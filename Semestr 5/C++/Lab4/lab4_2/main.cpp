#include <random>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    list<int> lista;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> d(1,10);
    int n = d(gen);
    uniform_int_distribution<> dist(-100,100);
    for(int i=0;i<n;i++)
    {
        int x = dist(gen);
        if(x>=0)
            lista.push_front(x);
        else
            lista.push_back(x);
    }
    for(auto it=lista.begin();it!=lista.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
