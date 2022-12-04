#include "postalcode.h"

PostalCode::PostalCode()
{

}

PostalCode::PostalCode(std::string _postal_code)
{
    postal_code = _postal_code;
    citizens = 1;
}

std::string PostalCode::getPostalCode() const
{
    return postal_code;
}

int PostalCode::getCitizens() const
{
    return citizens;
}

void PostalCode::addCitizen()
{
    citizens++;
}
