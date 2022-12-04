#include <QCoreApplication>
#include <QVector>
#include "car.h"
#include <algorithm>
#include <iostream>
using namespace std;

void show(QVector<Car> cars)
{
    for(auto it=cars.begin();it!=cars.end();it++)
    {
        it->show();
    }
}

int olderThan(QVector<Car> cars, int year)
{
    int count=0;
    for(auto it=cars.begin();it!=cars.end();it++)
    {
        if(it->getProduction_year()<year)
            count++;
    }
    return count;
}

void deleteCar(QVector<Car> &cars, string vin)
{
    auto ite = cars.end();
    for(auto it=cars.begin();it!=cars.end();it++)
    {
        if(it->getVin() == vin)
            ite = it;
    }
    if(ite != cars.end())
        cars.erase(ite);
    else
        cout<<"Brak samochodu o podanym numerze VIN"<<endl;
}

bool year(Car x1, Car x2)
{
    return x1.getProduction_year() > x2.getProduction_year();
}

bool mark(Car x1, Car x2)
{
    return x1.getMark()<x2.getMark();
}

void sortByYear(QVector<Car> &cars)
{
    sort(cars.begin(),cars.end(), year);
    show(cars);
}

void sortByMark(QVector<Car> &cars)
{
    sort(cars.begin(),cars.end(), mark);
    show(cars);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector<Car> cars;    
    cars.push_back(Car("Audi", "A3", 2015, "WUASNAFG8EN000698"));
    cars.push_back(Car("Volkswagen", "Golf", 2019, "WVGZZZ5NZ8W031284"));
    cars.push_back(Car("BMW", "X3", 2017, "WBSFC4419L8000810"));
    show(cars);
    cout<<"Po sortowaniu malejaco wzgledem roku produkcji"<<endl;
    sortByYear(cars);
    cout<<"Po sortowaniu alfabetycznym od a do z wzgledem marki samochodu"<<endl;
    sortByMark(cars);
    cout<<"Po usunieciu WBSFC4419L8000810"<<endl;
    deleteCar(cars, "WBSFC4419L8000810");
    show(cars);
    return a.exec();
}
