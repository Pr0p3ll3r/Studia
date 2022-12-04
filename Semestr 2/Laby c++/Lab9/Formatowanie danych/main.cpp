#include <iostream>
#include<iomanip>
#include<sstream>
#include<cstdlib>
using namespace std;

int main()
{
    //formatowanie danych
    int a=49;
    float b=21.7345;
    //flagi
    ios_base::fmtflags stara_flaga=cout.flags(); //pobranie aktualnej flagi formatowania strumienia
    ios_base::fmtflags nowa_flaga=ios::hex|ios::showbase|ios::showpoint|ios::showpos|ios::uppercase|ios::scientific;
    //dodawanie flag za pomoca |
    cout.flags(nowa_flaga); //ustawianie nowej flagi
    cout<<"a = "<<a<<" b= "<<b<<endl;
    cout.flags(stara_flaga);

    cout<<"a = "<<a<<" b= "<<b<<endl;

    cout.precision(2); //precyzja -> do konca w programie
    cout<<"a = "<<a<<" b= "<<b<<endl;
    cout.width(20); //szerokosc okna -> tylko na jeden cout
    cout<<"Ala"<<endl;
    cout<<"kot"<<endl;
    //manipulatory

    cout<<setw(30)<<setfill('-')<<"b= "<<setprecision(5)<<b<<endl; //manipulator argumentowy
    //ustawienie pola na 30 znakow, wypelnienie miejsc przed liczba znakami -, wyswietlenie liczby na 5 polach

    //manipulatory, flagi
    cout.width(20);
    cout.setf(ios::right); //ustawienie flagi
    cout<<setfill('-')<<"Ala ma kota"<<endl;

    cout.unsetf(ios::right); //reset flagi
    cout.width(20);
    cout.setf(ios::left);
    cout<<setfill('|')<<"Ala ma kota"<<endl;

    cout<<"************************"<<endl;

    ios_base::fmtflags flaga3 = ios::right;
    ios_base::fmtflags flaga4 = ios::left;
    cout.flags(flaga3);
    cout<<setw(20)<<setfill('-')<<"Ala ma kota"<<endl;
    cout.flags(flaga4);
    cout<<setw(20)<<setfill('|')<<"Ala ma kota"<<endl;

    //konwersje
    string napis1,napis2,napis3="Ala Nowak";

    istringstream ss(napis3); //strumien umozliwia  odczyt
    getline(ss, napis1, ' '); //wyluskanie pierwszego napisu do znaku ' '
    getline(ss, napis2, ' '); //wyluskanie drugiego napisu do znaku ' '
    cout<<napis1<<" "<<napis2<<endl;

    int liczba; //konwersja z string na int
    istringstream isstream("123");
    isstream >> liczba;
    cout<<liczba<<endl;

    ostringstream osstream;  //umozliwia odczyt
    osstream << 123; //konwersja int na string
    string na=osstream.str();
    cout << na<< endl;

    liczba=atoi(na.c_str()); //konwersja string na int
    cout<<liczba<<endl;



    return 0;
}
