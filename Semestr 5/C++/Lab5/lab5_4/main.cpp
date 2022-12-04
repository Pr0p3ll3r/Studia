#include <iostream>
#include "dictionary.h"
using namespace std;

int main()
{
    Dictionary d = Dictionary();
    d.addWord("Triangle","Trojkat");
    d.addWord("Circle","Kolo");
    d.addWord("Rectangle","Prostokat");
    d.addWord("Rectangle","Prostokat");
    cout<<"Przed sortowaniem"<<endl;
    d.show();
    d.sort();
    cout<<endl<<"Po sortowaniu"<<endl;
    d.show();
    d.deleteWord("cos");
    d.deleteWord("Triangle");
    d.show();
    d.showTranslation("Rectangle");
}
