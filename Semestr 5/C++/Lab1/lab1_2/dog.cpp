#include "dog.h"
using namespace std;

Dog::Dog()
{

}

Dog::Dog(int limbNr1, std::string name1, std::string breed1, int levelOfGuideSkills1, int levelofTracerSkills1, bool protectedAnimal1):Animal(limbNr1, name1, protectedAnimal1)
{
    breed = breed1;
    levelOfGuideSkills = levelOfGuideSkills1;
    levelOfTracerSkills = levelofTracerSkills1;
}

Dog::Dog(int limbNr1, std::string name1, bool protectedAnimal1):Animal(limbNr1, name1, protectedAnimal1)
{

}

void Dog::setSkillLevel(int type, int value)
{
    switch(type)
    {
        case 0:
            levelOfGuideSkills = value;
            break;
        case 1:
            levelOfTracerSkills = value;
            break;
    }
}

int Dog::getSkillLevel(int type) const
{
    switch(type)
    {
        case 0:
        if(levelOfGuideSkills != NULL)
                 return levelOfGuideSkills;
        case 1:
        if(levelOfTracerSkills != NULL)
            return levelOfTracerSkills;
    }
    return 0;
}

void Dog::giveVoice()
{
    cout<<"Hau, hau"<<endl;
}

void Dog::info()
{
    Animal::info();
    cout<<"Rasa "<<breed<<" Poziom umiejetnosci przewodnika "<<levelOfGuideSkills<<" Poziom umiejetnosci sledzacych "<<levelOfTracerSkills<<endl;
}


