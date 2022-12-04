#include <QCoreApplication>
#include "array.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Array<int> a1(2);
    Array<std::string> a2(2);
    a1.add(2);
    a1.add(1);
    a2.add("jeden");
    a2.add("dwa");

    cout<<"Przed sortowaniem"<<endl;
    a1.show();
    a2.show();

    a1.sort();
    a2.sort();
    cout<<"Po sortowaniu"<<endl;
    a1.show();
    a2.show();

    cout<<"Maksymalny element"<<endl;
    cout<<a1.getMax()<<endl;
    cout<<a2.getMax()<<endl;
    return a.exec();
}
