#include <iostream>
#include <set>
#include <vector>
using namespace std;
pair<int,int> findDuplicate(vector<int> numbers)
{
    set<int> s;
    pair<int,int> p = make_pair(0,0);
    for(vector<int>::iterator it=numbers.begin();it!=numbers.end();it++)
    {
        int i = *it;
        if(s.count(i))
        {
             p.first = i;
        }
        else
        {
             s.insert(i);
             p.second += i;
        }
    }
    return p;
}
int main()
{
    vector <int> vec;
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(7);
    pair<int,int> p = findDuplicate(vec);
    cout<<"Zduplikowana wartosc "<<p.first<<" Suma unikatowych elementow "<<p.second<<endl;
    return 0;
}
