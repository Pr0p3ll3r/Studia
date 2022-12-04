#include <iostream>
#include <map>
using namespace std;

char znajdzZnak(string s1, string s2)
{
    char znak;
    map<char, char> m;
    for(int i=0;i<s1.size();i++)
        m.insert(make_pair(s1[i], s1[i]));
    for(int i=0;i<s2.size();i++)
        if(m.count(s2[i]))
            znak = s2[i];
    return znak;
}

int main()
{
    string s1 = "asdqwe";
    string s2 = "qwegasd";
    cout<<"Dodatkowy znak "<<znajdzZnak(s1,s2)<<endl;
    return 0;
}
