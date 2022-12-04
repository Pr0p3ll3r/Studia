#include <QCoreApplication>
#include "employee.h"
#include "developer.h"
#include "teamleader.h"
using namespace std;

void whoWorkMoreThan5Years(Employee** pracownicy, int rozmiar);
int howManyEarnLessThanMeanBonus(Employee** pracownicy, int rozmiar);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Employee** pracownicy;
    pracownicy = new Employee*[4];
    pracownicy[0] = new Developer("Jakub", 22, 2, 4000);
    pracownicy[1] = new Developer("Marcin", 24, 3, 4000);
    pracownicy[2] = new Developer("Adam", 27, 5, 4000);
    pracownicy[3] = new TeamLeader("Andrzej", 32, 5, 6000);

    for(int i=0;i<4;i++)
    {
        pracownicy[i]->show();
        cout<<"Bonus "<<pracownicy[i]->calculateBonus(1)<<endl;
    }

    whoWorkMoreThan5Years(pracownicy, 4);

    cout<<"Premie nizsza niz srednia premia dostalo "<<howManyEarnLessThanMeanBonus(pracownicy,4)<<endl;

    for(int i=0;i<4;i++)
    {
        delete pracownicy[i];
    }
    delete [] pracownicy;

    return a.exec();
}

void whoWorkMoreThan5Years(Employee** pracownicy, int rozmiar)
{
    for(int i=0;i<rozmiar;i++)
    {
        if(pracownicy[i]->getExperience()>5)
            pracownicy[i]->show();
    }
}

int howManyEarnLessThanMeanBonus(Employee** pracownicy, int rozmiar)
{
    int ile=0;
    float mean=0;
    for(int i=0;i<rozmiar;i++)
    {
        mean+=pracownicy[i]->calculateBonus(1);
    }
    mean/=rozmiar;
    for(int i=0;i<rozmiar;i++)
    {
        if(pracownicy[i]->calculateBonus(1)<mean)
            ile++;
    }
    return ile;
}
