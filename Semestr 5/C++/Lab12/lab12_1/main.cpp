#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9,10};
    for_each(vec.begin(), vec.end(), [](int el){cout<<el<<"|";});
    cout<<endl<<"Srednia "<<accumulate(vec.begin(), vec.end(), 0.0, [&](double a, double b){return a + b / vec.size();})<<endl;
    cout<<"Parzystych: "<<count_if(vec.begin(), vec.end(), [](int el){return el % 2 ==0;})<<endl;
    sort(vec.begin(), vec.end(), [](int a, int b){return (a % 2 == 0 && b % 2 != 0);});  
    cout<<"Po sortowaniu: ";
    for_each(vec.begin(), vec.end(), [](int el){cout<<el<<"|";});
    transform(vec.begin(), vec.end(), vec.begin(), [](int el){if(el == 0) return 0;else return el*-1;});
    cout<<endl<<"Po zamianie na liczby przeciwne: ";
    for_each(vec.begin(), vec.end(), [](int el){cout<<el<<"|";});
    vec.erase(remove_if(vec.begin(), vec.end(), [](int el){return el<0;}), vec.end());
    cout<<endl<<"Po usunieciu ujemnych: ";
    for_each(vec.begin(), vec.end(), [](int el){cout<<el<<"|";});
    vec.push_back(5); vec.push_back(7); vec.push_back(8); vec.push_back(9);
    cout<<endl<<"Po dodaniu kilku elementow ";
    for_each(vec.begin(), vec.end(), [](int el){cout<<el<<"|";});
    auto ifSmaller = [vec](int x) { return count_if(vec.begin(), vec.end(), [x](int y){return y<x;}); };
    cout<<endl<<"Mniejsze niz 8: "<<ifSmaller(8)<<endl;
    return 0;
}
