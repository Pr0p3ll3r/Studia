#ifndef POSTALCODE_H
#define POSTALCODE_H
#include <iostream>

class PostalCode
{
private:
    std::string postal_code;
    int citizens;
public :
    PostalCode();
    PostalCode(std::string _postal_code);
    std::string getPostalCode() const;
    int getCitizens() const;
    void addCitizen();
};

#endif // POSTALCODE_H
