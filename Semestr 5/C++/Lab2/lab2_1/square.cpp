#include<iostream>
#include "figure.h"
#include "square.h"

using namespace std;

Square::Square(float a1):Figure()
{
    a=a1;
    cout<<"Konstruktor klasy Square"<<endl;
}

Square::~Square()
{
    cout<<"Destruktor klasy Square"<<endl;
}

void Square::calculateArea()
{
    float p=a*a;
    setArea(p);
}

void Square::calculatePerimeter()
{
    float o=4*a;
    setPerimeter(o);
}

void Square::show()
{
    cout<<"Show w klasie Square, pole "<<getArea()<<", obwod "<<getPerimeter()<<endl;
}
