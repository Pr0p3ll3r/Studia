#include <QCoreApplication>
#include "bufor.h"
#include "meanbufor.h"
#include "maxbufor.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Bufor* tab[2];
    tab[0]= new MeanBufor(10);
    tab[1]= new MaxBufor(10);

    for(int i=0; i<12; i++)
    {
        tab[0]->add(i);
        tab[1]->add(i);
    }

    tab[0]->show();
    tab[1]->show();
    cout<<tab[0]->calculate()<<endl;
    cout<<tab[1]->calculate()<<endl;

    delete tab[0];
    delete tab[1];

    return a.exec();
}
