#include "contacts.h"
#include <iostream>
using namespace std;

int main()
{
    Contacts contacts;
    contacts.addContact("Adam", "Nowak", 50, "333222111", "Mila");
    contacts.addContact("Ewa", "Nowak", 48, "321321321", "Mila");
    contacts.addContact("Michal", "Nowak", 17, "123123123", "Mila");
    contacts.addContact("Konrad", "Dabrowski", 22, "444555222", "Lubiana");
    contacts.showAll();
    cout<<"Po zmianie ulicy"<<endl;
    contacts.changeStreet("Mila", "Nowa");
    contacts.showAll();
    contacts.howManyAdults();
    contacts.howManyUniqueLastNames();
    cout<<"Osoby w wieku od 17 do 22"<<endl;
    contacts.findByAge(17,22);
    cout<<"Osoby mieszkajace na ulicy Nowej"<<endl;
    contacts.findByStreet("Nowa");
    cout<<"Osoba z numerem 444555222"<<endl;
    contacts.findByNumber("444555222");
    cout<<"Po usunieciu"<<endl;
    contacts.deleteContact("123123123");
    contacts.showAll();
    return 0;
}
