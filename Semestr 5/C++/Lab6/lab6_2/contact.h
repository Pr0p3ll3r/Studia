#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>

class Contact
{
public:
    std::string firstName;
    std::string lastName;
    int age;
    std::string phoneNumber;
    std::string street;
    void show() const;
};

inline void Contact::show() const
{
    std::cout<<"First Name: "<<firstName<<" Last Name: "<<lastName<<" Age: "<<age<<" Phone Number: "<<phoneNumber<<" Street: "<<street<<std::endl;
}

#endif // CONTACT_H
