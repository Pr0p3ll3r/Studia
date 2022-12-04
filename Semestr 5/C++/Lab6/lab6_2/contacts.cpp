#include "contacts.h"
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/multi_index/member.hpp>
#include "contact.h"
#include <set>
#include <iostream>
using namespace boost::multi_index;
using namespace std;

Contacts::Contacts()
{

}

void Contacts::addContact(string firstName, string lastName, int age, string phoneNumber, string street)
{
    if(contacts.get<1>().contains(phoneNumber))
    {
        cout<<"Podany numer jest juz w ksiazce"<<endl;
    }
    else
    {
        contacts.get<3>().push_back({firstName, lastName, age, phoneNumber, street});
    }
}

void Contacts::deleteContact(string number)
{
    if(contacts.get<1>().contains((number)))
    {
        auto &index = contacts.get<1>();
        auto it =index.find(number);
        index.erase(it);
    }
    else
    {
        cout<<"Podanego numeru nie ma w ksiazce"<<endl;
    }
}

void Contacts::findByStreet(string street)
{
    if(contacts.get<2>().contains((street)))
    {
        for(street_type::iterator it=contacts.get<2>().begin();it != contacts.get<2>().end(); ++it)
        {
            if(it->street == street)
                it->show();
        }
    }
    else
    {
        cout<<"Podanej ulicy nie ma w ksiazce"<<endl;
    }
}

void Contacts::findByAge(int minAge, int maxAge)
{
    auto &index = contacts.get<0>();
    auto from = index.lower_bound(minAge);
    auto to = index.upper_bound(maxAge);
    if(from == contacts.end())
        cout<<"Brak"<<endl;
    for(auto it=from; it != to; it++)
    {
        it->show();
    }
}

void Contacts::findByNumber(string number)
{
    if(contacts.get<1>().contains((number)))
    {
        auto &index = contacts.get<1>();
        auto it = index.find(number);
        it->show();
    }
    else
    {
        cout<<"Brak numeru w ksiazce"<<endl;
    }
}

void Contacts::changeStreet(string street, string newStreet)
{
    if(contacts.get<2>().contains((street)))
    {
        auto &index = contacts.get<2>();
        vector<street_type::iterator> elements;
        for(street_type::iterator it=contacts.get<2>().begin();it != contacts.get<2>().end(); ++it)
        {
            elements.push_back(it);
        }
        for (int i = 0; i<elements.size();i++)
            if(elements[i]->street == street)
                index.modify(elements[i],[newStreet](auto& c){c.street = newStreet;});
    }
    else
    {
        cout<<"Podanej ulicy nie ma w ksiazce"<<endl;
    }
}

void Contacts::howManyAdults()
{
    int howMany = 0;
    for(age_type::iterator it=contacts.get<0>().begin();it != contacts.get<0>().end(); it++)
    {
        if(it->age >= 18)
           howMany++;
    }
    cout<<"Ilosc osob pelnoletnich: "<<howMany<<endl;
}

void Contacts::howManyUniqueLastNames()
{
    set<string> lastNames;
    for(number_type::iterator it=contacts.get<1>().begin();it != contacts.get<1>().end(); it++)
    {
        if(!lastNames.count(it->lastName))
            lastNames.insert(it->lastName);
    }
    cout<<"Ilosc unikalnych nazwisk: "<<lastNames.size()<<endl;
}

void Contacts::showAll() const
{
    for(number_type::iterator it=contacts.get<1>().begin();it != contacts.get<1>().end(); ++it)
        it->show();
}
