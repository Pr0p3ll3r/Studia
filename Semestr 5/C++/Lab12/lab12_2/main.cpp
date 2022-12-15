#include "car.h"
#include <algorithm>
#include <vector>
using namespace std;

void show(function<bool(Car, Car)> fun, vector<Car> cars)
{
    sort(cars.begin(), cars.end(), fun);
    for(int i = 0; i < cars.size(); i++)
    {
        cout<<(i+1)<<" ";
        cars[i].show();
        cout<<endl;
    }
}

int main()
{
    vector<Car> cars;
    cars.push_back(Car("X", 2003, 1.6));
    cars.push_back(Car("Y", 2011, 2.0));
    cars.push_back(Car("Z", 2005, 2.5));
    auto byYear = [](Car c1, Car c2){return c1.getProduction_year() < c2.getProduction_year();};
    auto byCapacity = [](Car c1, Car c2){return c1.getEngine_capacity() > c2.getEngine_capacity();};
    show(byYear, cars);
    cout<<endl;
    show(byCapacity, cars);
    return 0;
}
