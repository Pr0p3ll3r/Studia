#include <QCoreApplication>
#include "animal.h"
#include "dog.h"
#include "cat.h"
using namespace std;

int howManyProtectedAnimals(Animal [], int);
int howManyTrackerDogs(Dog [], int);
void howManyCats(Cat [], int);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Animal tab1[3];
    Dog tab2[3];
    Cat tab3[3];

    tab1[0] = Animal(4, "Slon");
    tab1[1] = Animal(4, "Pies", 0);
    tab1[2] = Animal(4, "Kot", 0);

    for(int i=0;i<3;i++)
    {
        tab1[i].giveVoice();
        tab1[i].info();
    }

    cout<<"Zwierzat pod ochrona: "<<howManyProtectedAnimals(tab1, 3)<<endl;

    tab2[0] = Dog(4, "Burek", "Sznaucer", 1, 2, 0);
    tab2[1] = Dog(4, "Tunga", "Akita", 5, 1, 0);
    tab2[2] = Dog(4, "Azor", "Pitbul", 2, 2, 0);

    for(int i=0;i<3;i++)
    {
        tab2[i].giveVoice();
        tab2[i].info();
    }

    cout<<"Psow tropicieli: "<<howManyTrackerDogs(tab2, 3)<<endl;

    tab3[0] = Cat(4, "Lily", 0);
    tab3[1] = Cat(4, "Lucy", 0);
    tab3[2] = Cat(4, "Nala", 0);

    int mices1[5];
    int mices2[5];

    for(int i=0;i<5;i++)
    {
        mices1[i] = i;
        mices2[i] = 10-i;
    }

    tab3[0].initCat(2, mices1);
    tab3[1].initCat(3, mices1);
    tab3[2].initCat(7, mices2);

    for(int i=0;i<3;i++)
    {
        tab3[i].giveVoice();
        tab3[i].info();
    }

    cout<<"Upolowanych myszy w przeciagu 5 lat"<<endl;
    howManyCats(tab3, 3);

    return a.exec();
}

int howManyProtectedAnimals(Animal animals[], int rozmiar)
{
    int howMany=0;
    for(int i=0;i<rozmiar;i++)
    {
        if(animals[i].getProtected())
            howMany++;
    }
    return howMany;
}

int howManyTrackerDogs(Dog dogs[], int rozmiar)
{
    int howMany=0;
    for(int i=0;i<rozmiar;i++)
    {
        if(dogs[i].getSkillLevel(1) > dogs[i].getSkillLevel(0))
            howMany++;
    }
    return howMany;
}

void howManyCats(Cat cats[], int rozmiar)
{
    for(int i=0;i<rozmiar;i++)
    {
        int howMany=0;
        for(int j=0;j<5;j++)
        {
            howMany+=cats[i].getMice(j);
        }
        cout<<"Kot "<<cats[i].getNazwa()<<" : "<<howMany<<endl;
    }
}
