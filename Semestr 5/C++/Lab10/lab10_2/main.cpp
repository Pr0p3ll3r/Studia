#include <QCoreApplication>
#include <regex>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    regex regPatternTime("(2[0-3]|[01][0-9]):([0-5]{1}[0-9]{1})(:[0-5]{1}[0-9]{1})?");
    string napis = "23:59:59";
    if (regex_match(napis, regPatternTime))
        cout<<"Pasuje"<<endl;
    else
        cout<<"Nie pasuje!"<<endl;
    return a.exec();
}
