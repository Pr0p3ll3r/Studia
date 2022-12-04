#include <QCoreApplication>
#include <QSet>
#include <iostream>
#include <cctype>
using namespace std;

void IsPangram(string sentence)
{
    QSet<char> set;
    for(int i=0;i<sentence.size();i++)
    {
        char c = sentence[i];
        c = tolower(c);
        if((int)c >= 97 && (int)c <= 122)
        {
           set.insert(c);
        }
    }
    cout<<set.size()<<endl;
    if(set.size() == 26)
    {
        cout<<"Jest pangramem"<<endl;
    }
    else
    {
        cout<<"Nie jest pangramem"<<endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string sentence = "The quick brown fox jumps over the lazy dog";
    IsPangram(sentence);
    return a.exec();
}
