#ifndef PERSON_H
#define PERSON_H
#include <iostream>

class Person
{
public:
    std::string name;
    int age;
    void show ()const;
};
void Person::show () const{
    std::cout<<"name: "<<name<<" age: "<<age<<std::endl;
}

#endif // PERSON_H
