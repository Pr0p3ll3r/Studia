#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>

class Animal
{
private:
    int limbNr;
    std::string name;
    bool protectedAnimal;
public:
    Animal();
    Animal(int limbNr1, std::string name1, bool protectedAnimal1 = true);
    void setLimb(int limbNr1);
    int getLimb() const;
    void setNazwa(std::string name1);
    std::string getNazwa() const;
    void setProtected(bool protectedAnimal1);
    bool getProtected() const;
    void giveVoice();
    void info();
};

#endif // ANIMAL_H
