#include <iostream>
#include <cmath>

using namespace std;

class Wielomian
{
private:
    float a;
    float b;
    float c;
public:
    Wielomian()
    {

    }
    void init(float a, float b, float c)
    {
        this->a=a;
        this->b=b;
        this->c=c;
    }
    void calculate()
    {
        float d;
        d = b*b-4*a*c;
        if(d<0)
        {
            cout<<"Brak rozwiazan"<<endl;
        }
        else
        {
            if(d==0)
            {
                cout<<"1 rozwiazanie: "<<-b/2*a<<endl;
            }
            else
            {
                cout<<"2 rozwiazania: "<<endl<<(-b-sqrt(d))/2*a<<endl<<(-b+sqrt(d))/2*a<<endl;
            }
        }
    }
    bool is_real()
    {
        float d;
        d = b*b-4*a*c;
        if(d<0) return false;
        else return true;
    }
    bool is_a_non_zero()
    {
        if(a!=0)
            return true;
        else
            return false;
    }
    float get_x1()
    {
        float d;
        if(is_a_non_zero() && is_real())
        {
            d = b*b-4*a*c;
            return (-b-sqrt(d))/2*a;
        }
    }
    float get_x2()
    {
        float d;
        if(is_a_non_zero() && is_real())
        {
            d = b*b-4*a*c;
            return (-b+sqrt(d))/2*a;
        }
    }
};

int main()
{
    Wielomian w;
    w.init(1,3,-4);
    w.calculate();
    return 0;
}
