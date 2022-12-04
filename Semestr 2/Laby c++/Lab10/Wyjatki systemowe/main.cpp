#include <iostream>

using namespace std;
void function_bad_alloc1()
{
    int* tab=new int [1000000000000];
}
void function_bad_alloc2(int n)
{
    if(n>10){
      throw bad_alloc(); //rzucenie standardowego wyjatku
    }
    else{
        int* tab=new int[n];
    }
}
int main()
{
    try
    {
        function_bad_alloc1();
    }
    catch(bad_alloc &ba) //lapanie wyjatku typu bad_alloc
    {
        cout<<"function1 bad alloc: "<<ba.what()<<endl; //what informuje o rodzaju wyjatku

    }

    try
    {
        function_bad_alloc1();
    }
    catch(exception &e) //lapanie wyjatku za pomoca obiektu klasy Exception
    {
        cout<<"function1 exception: "<<e.what()<<endl;

    }

     try
    {
        function_bad_alloc2(20);
    }
    catch(exception &e) //lapanie wyjatku za pomoca obiektu klasy Exception
    {
        cout<<"funkjca2 exception: "<<e.what()<<endl;

    }

    return 0;
}
