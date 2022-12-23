#include <QCoreApplication>
#include <regex>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    regex regPatternStreet("[A-Za-z ]+");
    regex regPatternCode("[0-9]{2}-[0-9]{3}");
    regex regPatternNumberHouse("[0-9]+|[0-9]+[a-zA-Z]{1}");
    regex regPatternNumberApartment("[0-9]+");
    if (regex_match("Nadbystrzycka", regPatternStreet))
        cout<<"Pasuje"<<endl;
    else
        cout<<"Nie pasuje!"<<endl;
    if (regex_match("20-135", regPatternCode))
        cout<<"Pasuje"<<endl;
    else
        cout<<"Nie pasuje!"<<endl;
    if (regex_match("28B", regPatternNumberHouse))
        cout<<"Pasuje"<<endl;
    else
        cout<<"Nie pasuje!"<<endl;
    if (regex_match("20", regPatternNumberApartment))
        cout<<"Pasuje"<<endl;
    else
        cout<<"Nie pasuje!"<<endl;
    return a.exec();
}
