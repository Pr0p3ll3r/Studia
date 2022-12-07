#include <QCoreApplication>
#include <iostream>
#include "productcatalog.h"
#include "tv.h"
#include "fridge.h"
using namespace std;

template<typename T1>
bool Compare(int x1, T1 x2)
{
    if(x1 > x2)
        return true;
    else
        return false;
}

template<>
bool Compare<string>(int x1, string x2)
{
    if(x1 > x2.length())
        return true;
    else
        return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int x1 = 10;
    int x2 = 100;
    string x3 = "asdqwe";
    cout<<Compare<int>(x1,x2)<<endl;
    cout<<Compare<string>(x1,x3)<<endl;
    ProductCatalog pc;
    TV* tv = new TV("Tv1", 2500, 5, 50, "flat");
    Fridge* fr = new Fridge("Fridge1", 500, 10, 220, true);
    pc.addProduct(tv);
    pc.addProduct(fr);
    pc.show();
    pc.sortByStock();
    pc.show();
    return a.exec();
}
