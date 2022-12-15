#ifndef CAR_H
#define CAR_H
#include <iostream>

class Car
{
private:
    std::string model;
    int production_year;
    float engine_capacity;
public:
    Car();
    Car(std::string model, int production_year, float engine_capacity);
    const std::string &getModel() const;
    void setModel(const std::string &newModel);
    int getProduction_year() const;
    void setProduction_year(int newProduction_year);
    float getEngine_capacity() const;
    void setEngine_capacity(float newEngine_capacity);
    void show();
};

#endif // CAR_H
