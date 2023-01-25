#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <memory>
#include <regex>
#include "product.h"
#include "character.h"
using namespace std;

//Zadanie 2
void sortuj(vector<tuple<string, float>> &pracownicy)
{
    sort(pracownicy.begin(), pracownicy.end(), [](tuple<string, float> p1, tuple<string, float> p2){ return get<1>(p1) > get<1>(p2);});
}

//Zadanie 3
void wyswietlPostaci(vector<unique_ptr<Character>> &characters)
{
    for(auto it=characters.begin();it!=characters.end();it++)
    {
        cout<<"Class: "<<it->get()->getCharClass()<<" Level:"<<it->get()->getLevel()<<" HP:"<<it->get()->getHp()<<" Mana:"<<it->get()->getMana()<<endl;
    }
}

//Zadanie 5
void wczytajOceny(vector<float> &oceny)
{
    while(oceny.size() != 5)
    {
        float ocena;
        cout<<"Podaj ocene: [2, 3, 3.5, 4, 4.5, 5]"<<endl;
        cin>>ocena;
        if(ocena != 2 && ocena != 3 && ocena != 3.5 && ocena != 4 && ocena != 4.5 && ocena != 5)
            throw "Ocena musi byc z zakresu [2, 3, 3.5, 4, 4.5, 5]";
        oceny.push_back(ocena);
    }
}
float srednia(vector<float> &oceny)
{
    float srednia = 0;
    for_each(oceny.begin(), oceny.end(), [&srednia](float ocena){ srednia += ocena;});
    return srednia/oceny.size();
}

int main()
{
    //Zadanie 1
    vector<Product> produkty;
    ifstream plik("towar.csv");
    if(plik.is_open())
    {
        string linia;
        while(!plik.eof())
        {
            getline(plik,linia,',');
            if(linia=="") continue;
            string name = linia;
            getline(plik,linia);
            if(linia=="") continue;
            int amount = stoi(linia);
            produkty.push_back(Product(name, amount));
        }
    }
    sort(produkty.begin(), produkty.end(), [](Product p1, Product p2){ return p1.getAmount() < p2.getAmount();});
    for(auto it=produkty.begin();it!=produkty.end();it++)
    {
        cout<<it->getName()<<": "<<it->getAmount()<<endl;
    }

    //Zadanie 2
    vector<tuple<string, float>> pracownicy;
    pracownicy.push_back(make_tuple("Nowak", 2000));
    pracownicy.push_back(make_tuple("Nowak1", 5000));
    pracownicy.push_back(make_tuple("Nowak2", 3000));
    cout<<"Przed sortowaniem"<<endl;
    for(auto it=pracownicy.begin();it!=pracownicy.end();it++)
    {
        cout<<"Nazwisko: "<<get<0>(*it)<<" Wyplata: "<<get<1>(*it)<<endl;
    }
    sortuj(pracownicy);
    cout<<"Po sortowaniu"<<endl;
    for(auto it=pracownicy.begin();it!=pracownicy.end();it++)
    {
        cout<<"Nazwisko: "<<get<0>(*it)<<" Wyplata: "<<get<1>(*it)<<endl;
    }

    //Zadanie 3
    string zdanie="";
    cout<<"Podaj zdanie"<<endl;
    getline(cin, zdanie);
    regex pattern("\\b@[a-z.]*");
    regex_replace(ostreambuf_iterator<char>(cout), zdanie.begin(), zdanie.end(), pattern, "@nowadomena.pl");
    cout<<endl<<regex_replace(zdanie, pattern, "[$&]")<<endl;

    //Zadanie 4
    vector<unique_ptr<Character>> characters;
    characters.push_back(make_unique<Character>("wojownik", 100, 100 , 1));
    characters.push_back(make_unique<Character>("mag", 100, 300 , 1));
    wyswietlPostaci(characters);

    vector<float> oceny;
    //Zadanie 5
    try
    {
        wczytajOceny(oceny);
        cout<<"Srednia wynosi: "<<srednia(oceny)<<endl;
    }
    catch (const char *error)
    {
        cout<<error<<endl;
    }

    return 0;
}
