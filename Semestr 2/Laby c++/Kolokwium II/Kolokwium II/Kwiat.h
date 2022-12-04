#include <iostream>

#ifndef KWIAT_H_INCLUDED
#define KWIAT_H_INCLUDED
using namespace std;

class Kwiat
{
private:
    bool czyJednoroczny;
    string nazwa;
    int rodzaj;
public:
    Kwiat();
    Kwiat(bool czyJednoroczny, string nazwa, int rodzaj);
    void wczytaj();
    bool operator!=(Kwiat k);
    friend int zad2(vector<Kwiat> kwiaty);
    void zapisz(string sciezka);
    friend ostream & operator<<(ostream &screen, Kwiat &k);
};

class Error
{
public:
    void error();
};

#endif // KWIAT_H_INCLUDED
