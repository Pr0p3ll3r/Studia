#include "city.h"
#include <iostream>
using namespace std;

City::City()
{

}

City::City(std::string _city_name)
{
    city_name = _city_name;
}

void City::addCitizen(Citizen c)
{
    citizens.push_back(c);
    bool newPostal = true;
    for(int i=0;i<postalCodes.size();i++)
    {
        if(c.getPostalCode() == postalCodes[i].getPostalCode())
        {
            postalCodes[i].addCitizen();
            newPostal = false;
            break;
        }
    }
    if(newPostal)
         postalCodes.push_front(PostalCode(c.getPostalCode()));
}

void City::deleteCitizen(int age, std::string name)
{
    for(int i=0;i<citizens.size();i++)
    {
        if(citizens[i].getName() == name && citizens[i].getAge() == age)
            citizens.erase(citizens.begin() + i);
    }
}

void City::show_citizens()
{
    for(int i=0;i<citizens.size();i++)
    {
        citizens[i].show();
    }
}

void City::show_city()
{
    cout<<city_name<<endl;
}

int City::women()
{
    int counter = 0;
    for(int i=0;i<citizens.size();i++)
    {
        string name = citizens[i].getName();
        if(name[name.size()-1] == 'a')
             counter++;
    }
    return counter;
}

int City::city_citizens()
{
    return citizens.size();
}

int City::adults()
{
    int counter = 0;
    for(int i=0;i<citizens.size();i++)
    {
        int age = citizens[i].getAge();
        if(age >= 18)
             counter++;
    }
    return counter;
}

int City::postal_codes()
{
    for(int i=0;i<postalCodes.size();i++)
    {
        cout<<postalCodes[i].getPostalCode()<<" -> "<<postalCodes[i].getCitizens()<<", ";
    }
    cout<<endl;
    return postalCodes.size();
}
