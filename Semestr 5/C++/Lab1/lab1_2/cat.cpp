#include "cat.h"
#include <QDate>
using namespace std;

Cat::Cat()
{

}

Cat::Cat(int limbNr1, std::string name1, bool protectedAnimal1):Animal(limbNr1, name1, protectedAnimal1)
{

}

void Cat::initMice(int values[])
{
    for(int i=0;i<5;i++)
    {
        mice[i]=values[i];
    }
}

void Cat::initCat(int levelOfMouseHunting1, int mice1[])
{
    levelOfMouseHunting = levelOfMouseHunting1;
    for(int i=0;i<5;i++)
    {
        mice[i]=mice1[i];
    }
}

void Cat::setLevelOfMouseHunting(int value)
{
    levelOfMouseHunting = value;
}

int Cat::getLevelOfMouseHunting() const
{
    if(levelOfMouseHunting != NULL)
        return levelOfMouseHunting;
    return 0;
}

int Cat::getMice(int index) const
{
    if(index >=1 && index <= 5)
        return mice[index];
    else
        return -1;
}

void Cat::giveVoice()
{
    cout<<"Miau miau"<<endl;
}

void Cat::info()
{
    Animal::info();
    cout<<"Poziom polowania na myszy "<<levelOfMouseHunting<<endl;
    for(int i=4;i>=0;i--)
    {
        int year = QDate::currentDate().year() - i;
        cout<<"Rok "<<year<<" upolowanych myszy "<<mice[i]<<endl;
    }
}
