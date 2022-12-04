#ifndef CITY_H
#define CITY_H
#include <vector>
#include <deque>
#include "citizen.h"
#include "postalcode.h"

class City
{
private:
    std::vector<Citizen> citizens;
    std::string city_name;
    std::deque<PostalCode> postalCodes;
public:
    City();
    City(std::string _city_name);
    void addCitizen(Citizen c);
    void deleteCitizen(int age, std::string name);
    void show_citizens();
    void show_city();
    int women();
    int city_citizens();
    int adults();
    int postal_codes();
};

#endif // CITY_H
