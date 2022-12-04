#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14

float poleKwadratu(float a)
{
    return pow(a, 2);
}

float poleKola(float r)
{
    return PI * pow(r, 2);
}

void czyWKwadracie(float r, float a)
{
    if(r <= (0.5 * a))
        cout<<"Kolo da sie narysowac wewnatrz kwadratu"<<endl;
    else
        cout<<"Kola nie da sie narysowac wewnatrz kwadratu"<<endl;
}

void czyWKole(float r, float a)
{
    if(r >= (0.5 * sqrt(2) * a))
        cout<<"Kwadrat da sie narysowac wewnatrz kola"<<endl;
    else
        cout<<"Kwadratu nie da sie narysowac wewnatrz kola"<<endl;
}

int main()
{
    float a, r;
    cout<<"Podaj dlugosc boku kwadratu: ";
    cin>>a;
    cout<<"Podaj promien kola: ";
    cin>>r;

    cout<<"Pole kwadratu: "<<poleKwadratu(a)<<endl;
    cout<<"Pole kola: "<<poleKola(r)<<endl;

    czyWKwadracie(r, a);
    czyWKole(r, a);

    return 0;
}
