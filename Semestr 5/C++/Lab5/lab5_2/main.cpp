#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void show( set <int> s)
{
    for (auto itr = s.begin(); itr != s.end(); itr++)
    {
        cout << *itr<<" ";
    }
    cout<<endl;
}

template<typename T1, typename T2>
void alternatywaWykluczajaca(T1 x, T2 y)
{
    set<int> x2;
    set_difference(x.begin(),x.end(),y.begin(),y.end(),insert_iterator(x2,x2.begin()));
    set_difference(y.begin(),y.end(),x.begin(),x.end(),insert_iterator(x2,x2.begin()));
    show(x2);
}

int main()
{
    set<int> s1={3,8,10,2,1,5};
    set<int> s2={3,8,10,7};
    alternatywaWykluczajaca(s1,s2);
    return 0;
}
