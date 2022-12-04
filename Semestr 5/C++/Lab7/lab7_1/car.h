#ifndef CAR_H
#define CAR_H
#include <QString>

class Car
{
private:
    std::string mark;
    std::string model;
    int production_year;
    std::string vin;
public:
    Car();
    Car(std::string mark, std::string model, int production_year, std::string vin);
    int getProduction_year() const;
    void setProduction_year(int newProduction_year);
    const std::string &getModel() const;
    void setModel(const std::string &newModel);
    const std::string &getMark() const;
    void setMark(const std::string &newMark);
    const std::string &getVin() const;
    void setVin(const std::string &newVin);
    void show();
};

#endif // CAR_H
