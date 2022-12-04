#include "car.h"
#include <iostream>

int Car::getProduction_year() const
{
    return production_year;
}

void Car::setProduction_year(int newProduction_year)
{
    production_year = newProduction_year;
}

const std::string &Car::getModel() const
{
    return model;
}

void Car::setModel(const std::string &newModel)
{
    model = newModel;
}

const std::string &Car::getMark() const
{
    return mark;
}

void Car::setMark(const std::string &newMark)
{
    mark = newMark;
}

const std::string &Car::getVin() const
{
    return vin;
}

void Car::setVin(const std::string &newVin)
{
    vin = newVin;
}

void Car::show()
{
    std::cout<<"Marka: "<<mark<<" Model: "<<model<<" Production Year: "<<production_year<<" VIN: "<<vin<<std::endl;
}

Car::Car()
{

}

Car::Car(std::string mark, std::string model, int production_year, std::string vin)
{
    this->mark = mark;
    this->model = model;
    this->production_year = production_year;
    this->vin = vin;
}
