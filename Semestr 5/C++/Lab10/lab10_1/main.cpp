#include <QCoreApplication>
#include <regex>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    regex regPattern("[+-]{1}[0-9]+.[0-9]+");
    string napis = "-73.0322333";
    string napis2 = "+72.032222";
    if (regex_match(napis, regPattern))
        cout<<"Pasuje"<<endl;
    else
        cout<<"Nie pasuje!"<<endl;
    if (regex_match(napis2, regPattern))
        cout<<"Pasuje"<<endl;
    else
        cout<<"Nie pasuje!"<<endl;
    return a.exec();
}
