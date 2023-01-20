#include "shop.h"
#include "warehouse.h"
using namespace std;

int main()
{
    unique_ptr<Shop> shopes[3];
    for(int i=0;i<3;i++)
    {
        shopes[i] = make_unique<Shop>("Sklep " + to_string(i + 1));
    }

    shared_ptr<Warehouse> w1 = make_shared<Warehouse>("Ksiazka", 5);
    shared_ptr<Warehouse> w2 = make_shared<Warehouse>("Komputer", 5);
    shared_ptr<Warehouse> w3 = make_shared<Warehouse>("Lozko", 5);

    shopes[0]->add(w1);

    shopes[1]->add(w1);
    shopes[1]->add(w2);

    shopes[2]->add(w1);
    shopes[2]->add(w2);
    shopes[2]->add(w3);

    for(int i=0;i<3;i++)
    {
        shopes[i]->showName();
        shopes[i]->showWarehouses();
        cout<<endl;
    }

    shopes[2]->sell("Ksiazka", 6);
    shopes[2]->sell("Ksiazka", 2);
    cout<<endl;

    for(int i=0;i<3;i++)
    {
        shopes[i]->showName();
        shopes[i]->showWarehouses();
        cout<<endl;
    }
    return 0;
}
