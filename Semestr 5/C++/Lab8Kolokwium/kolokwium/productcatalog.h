#ifndef PRODUCTCATALOG_H
#define PRODUCTCATALOG_H
#include <list>
#include <QList>
#include "product.h"
using namespace std;

class ProductCatalog
{
private:
    QList<Product*> catalog;
public:
    ProductCatalog();
    void addProduct(Product *p);
    void deleteProduct(std::string name);
    void show();
    void sortByStock();
    int howManyProduct();
};

#endif // PRODUCTCATALOG_H

