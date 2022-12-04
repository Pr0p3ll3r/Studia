#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Kwiat.h"

using namespace std;

Kwiat::Kwiat()
{

}
Kwiat::Kwiat(bool czyJednoroczny, string nazwa, int rodzaj)
{
    this->czyJednoroczny=czyJednoroczny;
    this->nazwa=nazwa;
    this->rodzaj=rodzaj;
}
void Kwiat::wczytaj()
{
    ifstream plik;
    plik.open("kwiaty.txt");
    string pomoc,linia;
    if(plik.good())
    {
        for(int i=0;i<2;i++)
        {
            if(i!=0)
            {
                plik>>linia;
                istringstream ss(linia);
                getline(ss, pomoc, ';');
                if(pomoc=="0") this->czyJednoroczny=false;
                else this->czyJednoroczny=true;
                getline(ss, this->nazwa, ';');
                getline(ss, pomoc, ';');
                this->rodzaj=atoi(pomoc.c_str());
            }
        }
        plik.close();
    }
}
bool Kwiat::operator!=(Kwiat k)
{
    if(this->rodzaj!=k.rodzaj)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int zad2(vector<Kwiat> kwiaty)
{
    int liczbaJednorocznych=0;
    int liczbaWielorocznych=0;
    for(int i=0;i<kwiaty.size();i++)
    {
        if(kwiaty[i].czyJednoroczny==1)
            liczbaJednorocznych++;
        else
            liczbaWielorocznych++;
    }

    if(liczbaJednorocznych>liczbaWielorocznych)
    {
        return 1;
    }
    else if(liczbaWielorocznych>liczbaJednorocznych)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
void Error::error()
{
    cout<<"Nie da sie zapisac do pliku"<<endl;
}
void Kwiat::zapisz(string sciezka)
{
    ofstream plik;
    plik.open(sciezka, ios::app);
    if(plik.good())
    {
        if(this->czyJednoroczny==0)
        {
            throw Error();
        }
        else
        {
            plik<<this->czyJednoroczny<<';'<<this->nazwa<<';'<<this->rodzaj<<endl;
        }
    }
}
ostream & operator<<(ostream &screen, Kwiat &k)
{
    screen<<"Czy jednoroczny: "<<k.czyJednoroczny<< " Nazwa: "<<k.nazwa<<" Rodzaj: "<<k.rodzaj<<endl;
    return screen;
}
