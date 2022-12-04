#include <iostream>
#include "city.h"
#include "citizen.h"
using namespace std;

void showCities(vector<City> c)
{
    for(int i=0;i<c.size();i++)
    {
        cout<<"Nazwa miasta ";
        c[i].show_city();
        c[i].show_citizens();
    }
}

void the_most_different_postcodes(vector<City> c)
{
    int max = 0;
    int index = 0;
    for(int i=0;i<c.size();i++)
    {
        if(max < c[i].postal_codes())
        {
            max = c[i].postal_codes();
            index = i;
        }
    }
    cout<<"Najwiecej roznych kodow pocztowych w ";
    c[index].show_city();
}

void the_fewest_citizes(vector<City> c)
{
    int min = c[0].city_citizens();
    int index = 0;
    for(int i=1;i<c.size();i++)
    {
        if(c[i].city_citizens() < min)
        {
            min = c[i].city_citizens();
            index = i;
        }
    }
    cout<<"Najmniej mieszkancow w ";
    c[index].show_city();
}


void the_most(vector<City> c, int mode)
{
    if(mode == 1)
        the_most_different_postcodes(c);
    else
        the_fewest_citizes(c);
}

void statistic(vector <City> c)
{
    for(int i=0;i<c.size();i++)
    {
        c[i].show_city();
        cout<<"Liczba mieszkancow: "<<c[i].city_citizens()<<endl;
        cout<<"Liczba kobiet: "<<c[i].women()<<" Liczba mezczyzn: "<<c[i].city_citizens() - c[i].women()<<endl;
        cout<<"Osob niepelnoletnich: "<<c[i].city_citizens() - c[i].adults()<<" Osob pelnoletnich: "<<c[i].adults()<<endl;
    }
}

void sort_cities(vector <City> &c)
{
    for(int i=0;i<c.size()-1;i++)
    {
        for(int j=0;j<c.size()-i-1;j++)
        {
            if (c[j].city_citizens() > c[j + 1].city_citizens())
                swap(c[j], c[j + 1]);
        }
    }
}

int main()
{
    City c1 = City("Miasto 1");
    City c2 = City("Miasto 2");
    vector<City> cities;
    Citizen ci1 = Citizen("Adam", "Dabrowski", 20, 'M', "20-389");
    Citizen ci2 = Citizen("Jakub", "Dudek", 23, 'M', "20-137");
    Citizen ci3 = Citizen("Monika", "Kalinowska", 32, 'K', "30-678");
    Citizen ci4 = Citizen("Piotr", "Nowak", 35, 'M', "30-678");

    c1.addCitizen(ci1);
    c1.addCitizen(ci2);
    c1.addCitizen(ci3);
    c1.addCitizen(ci4);

    c2.addCitizen(ci1);
    c2.addCitizen(ci2);
    c2.addCitizen(ci3);

    cities.push_back(c1);
    cities.push_back(c2);

    the_most(cities, 1);
    the_most(cities, 2);
    statistic(cities);

    cout<<"Przed sortowaniem"<<endl;
    showCities(cities);
    sort_cities(cities);
    cout<<"Po sortowaniu"<<endl;
    showCities(cities);

    return 0;
}
