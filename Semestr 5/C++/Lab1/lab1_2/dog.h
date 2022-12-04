#ifndef DOG_H
#define DOG_H

#include "animal.h"

class Dog : public Animal
{
private:
    std::string breed;
    int levelOfGuideSkills;
    int levelOfTracerSkills;
public:
    Dog();
    Dog(int limbNr1, std::string name1, std::string breed1, int levelOfGuideSkills1, int levelofTracerSkills1, bool protectedAnimal1 = true);
    Dog(int limbNr1, std::string name1, bool protectedAnimal1 = true);
    void setSkillLevel(int type, int value);
    int getSkillLevel(int type) const;
    void giveVoice();
    void info();
};

#endif // DOG_H
