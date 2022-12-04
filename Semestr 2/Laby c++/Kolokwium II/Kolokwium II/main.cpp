#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Kwiat.h"

using namespace std;

int main()
{
    Kwiat k(false,"test",1);
    Kwiat k2;
    k2.wczytaj();
    if(k!=k2)
    {
        cout<<"Kwiaty nie sa tego samego rodzaju"<<endl;
    }
    else
    {
        cout<<"Kwiaty sa tego samego rodzaju"<<endl;
    }

    vector<Kwiat> kwiaty;
    ifstream plik;
    plik.open("kwiatki.txt");
    string pomoc,linia,nazwa;
    int rodzaj;
    bool b;
    int i=0;
    if(plik.good())
    {
        while(!plik.eof())
        {
            if(i==0)
            {
                plik>>linia;
            }
            if(i!=0)
            {
                plik>>linia;
                istringstream ss(linia);
                getline(ss, pomoc, ';');
                if(pomoc=="0") b=false;
                else b=true;
                getline(ss, nazwa, ';');
                getline(ss, pomoc, ';');
                rodzaj=atoi(pomoc.c_str());
                kwiaty.push_back(Kwiat(b,nazwa,rodzaj));
            }
            i++;
        }
        plik.close();
    }

    int wynik=zad2(kwiaty);
    if(wynik==1)
    {
        cout<<"Kwiatkow jednorocznych jest wiecej niz wielorocznych"<<endl;
    }
    else if(wynik==2)
    {
        cout<<"Kwiatkow jednorocznych jest mniej niz wielorocznych"<<endl;
    }
    else
    {
        cout<<"Kwiatkow jednorocznych jest tyle samo co wielorocznych"<<endl;
    }

    cout<<k;
    try
    {
        k.zapisz("zadanie3.txt");
    }
    catch(Error e)
    {
        e.error();
    }
    return 0;
}
