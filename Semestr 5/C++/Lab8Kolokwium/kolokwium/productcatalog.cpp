#include "productcatalog.h"
#include <iostream>
using namespace std;

ProductCatalog::ProductCatalog()
{

}

void ProductCatalog::addProduct(Product *p)
{
    catalog.append(p);
}

void ProductCatalog::deleteProduct(std::string name)
{
    for (int i = 0; i < catalog.size(); ++i)
    {
        if(catalog.at(i)->getName()==name)
        {
            catalog.removeAt(i);
            break;
        }
    }
}

void ProductCatalog::show()
{
    for (int i = 0; i < catalog.size(); i++)
    {
        catalog.at(i)->show();
    }
}


void ProductCatalog::sortByStock()
{
    sort(catalog.begin(), catalog.end(), [](Product *p1, Product *p2){ return p1->getStock() > p2->getStock();});
}

int ProductCatalog::howManyProduct()
{
   int counter=0;
   for (int i = 0; i < catalog.size(); i++)
    {
        if(catalog.at(i)->cyberMondayDiscount() > 500)
        {
            counter++;
        }
    }
    return counter;
}
