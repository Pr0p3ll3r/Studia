#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/multi_index/member.hpp>
#include "contact.h"
#include <iostream>
using namespace boost::multi_index;
using namespace std;

#ifndef CONTACTS_H
#define CONTACTS_H

typedef multi_index_container<Contact,indexed_by<
ordered_non_unique<member<Contact, int, &Contact::age>>,
ordered_unique<member<Contact, string, &Contact::phoneNumber>>,
ordered_non_unique<member<Contact, string, &Contact::street>>,
random_access<> >> contact_multi;

typedef contact_multi::nth_index<0>::type age_type;
typedef contact_multi::nth_index<1>::type number_type;
typedef contact_multi::nth_index<2>::type street_type;

class Contacts
{
private:
    contact_multi contacts;
public:
    Contacts();
    void addContact(string firstName, string lastName, int age, string phoneNumber, string street);
    void deleteContact(string number);
    void findByStreet(string street);
    void findByAge(int minAge, int maxAge);
    void findByNumber(string number);
    void changeStreet(string street, string newStreet);
    void howManyAdults();
    void howManyUniqueLastNames();
    void showAll() const;
};

#endif // CONTACTS_H
