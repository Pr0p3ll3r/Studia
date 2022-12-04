#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

bool sumaCyfr(int l, int r)
{
    string left = to_string(l);
    string right = to_string(r);
    int sumLeft = 0;
    int sumRight = 0;
    for(int i = 0;i<left.size();i++)
    {
        sumLeft += (int(left[i]+0));
    }
    for(int i = 0;i<right.size();i++)
    {
        sumRight += (int(right[i]+0));
    }
    return sumLeft < sumRight;
}

bool liczbaCyfr(int l, int r)
{
    string left = to_string(l);
    string right = to_string(r);
    return left.size() > right.size();
}

void print(int x){
    cout<<x<<"|";
}

int main()
{
    vector<int> liczby {1,2213,55,12,243,22,33,1233,56865,10};
    for_each(liczby.begin(),liczby.end(),print);
    cout<<endl;
    sort(liczby.begin(),liczby.end(),sumaCyfr);
    for_each(liczby.begin(),liczby.end(),print);
    cout<<endl;
    sort(liczby.begin(),liczby.end(),liczbaCyfr);
    for_each(liczby.begin(),liczby.end(),print);
    return 0;
}
