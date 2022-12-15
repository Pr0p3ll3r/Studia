#include "car.h"
using namespace std;

Car::Car()
{

}

Car::Car(std::string model, int production_year, float engine_capacity)
{
    this->model = model;
    this->production_year = production_year;
    this->engine_capacity = engine_capacity;
}

const std::string &Car::getModel() const
{
    return model;
}

void Car::setModel(const std::string &newModel)
{
    model = newModel;
}

int Car::getProduction_year() const
{
    return production_year;
}

void Car::setProduction_year(int newProduction_year)
{
    production_year = newProduction_year;
}

float Car::getEngine_capacity() const
{
    return engine_capacity;
}

void Car::setEngine_capacity(float newEngine_capacity)
{
    engine_capacity = newEngine_capacity;
}

void Car::show()
{
    cout<<"Model: "<<model<<" Rok produkcji: "<<production_year<<" Pojemnosc silnika "<<engine_capacity<<endl;
}
