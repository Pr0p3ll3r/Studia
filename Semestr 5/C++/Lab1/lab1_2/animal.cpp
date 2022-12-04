#include "animal.h"
#include <iostream>
using namespace std;

Animal::Animal()
{

}

Animal::Animal(int limbNr1, std::string name1, bool protectedAnimal1)
{
    limbNr = limbNr1;
    name = name1;
    protectedAnimal = protectedAnimal1;
}

void Animal::setLimb(int limbNr1)
{
    limbNr = limbNr1;
}

int Animal::getLimb() const
{
    return limbNr;
}

void Animal::setNazwa(std::string name1)
{
    name = name1;
}

std::string Animal::getNazwa() const
{
    return name;
}

void Animal::setProtected(bool protectedAnimal1)
{
    protectedAnimal = protectedAnimal1;
}

bool Animal::getProtected() const
{
    return protectedAnimal;
}

void Animal::giveVoice()
{
    cout<<"Chrum, miua, hau, piiiii"<<endl;
}

void Animal::info()
{
    cout<<"Nazwa: "<<name<<" Liczba konczyn: "<<limbNr<<" Pod ochrona? "<<protectedAnimal<<endl;
}
