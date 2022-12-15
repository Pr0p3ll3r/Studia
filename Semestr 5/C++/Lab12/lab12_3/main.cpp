#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>

using namespace std;

tuple<int,double,string> stats(vector<string> strings)
{
    auto shortest = min_element(strings.begin(), strings.end(), [](string s1, string s2){return s1.size() < s2.size();});
    double average = (double)accumulate(strings.begin(), strings.end(), 0, [strings](int sum, string s2){return sum + s2.length();})/strings.size();
    auto longest = max_element(strings.begin(), strings.end(), [](string a, string b){return a.length() < b.length();});
    tuple<int,double,string> tuple(shortest->size(), average, *longest) ;
    return tuple;
}

int main()
{
    vector<string> strings{"asdsd", "qwerty", "asdfghjkl", "asdqwe"};
    tuple<int,double,string> t = stats(strings);
    cout<<"Dlugosc najkrotszego napisu: "<<get<0>(t)<<endl;
    cout<<"Srednia dlugosc napisu: "<<get<1>(t)<<endl;
    cout<<"Najdluzszy napis: "<<get<2>(t)<<endl;
    return 0;
}
