#include <iostream>
#include <fstream> //odczyt i zapis z/do pliku
using namespace std;

int main()
{
    //zapis do pliku
    //ofstream plik_zapis("zapis.txt");
    ofstream plik_zapis; //uchwyt do zapisu
    plik_zapis.open("plik.txt"); //tryb ios::out z klasy ios_base jesli nie ma pliku to plik jest tworzony,
    //jesli plik istnieje jest nadpisywany
    //ios::app umozliwia dolaczenie do pliku ktory juz istnieje
    if(plik_zapis.good()) //sprawdzenie czy plik zostal poprawnie otworzony
    {
        cout<<"Plik otworzyc sie poprawnie"<<endl;
        plik_zapis<<"8 Ala ma kota"<<endl; //zapis do pliku
        plik_zapis<<"a kot ma ale"<<endl;
        plik_zapis<<10<<endl;
        plik_zapis<<1.1<<endl;
        plik_zapis<<'a'<<endl;
        plik_zapis.close(); //zamkniecie pliku
    }
    else
    {
        cout<<"Blad przy otwieraniu pliku!"<<endl;
    }



    //odczyt z pliku
    ifstream plik_odczyt; //uchyt do odczytu pliku
    plik_odczyt.open("plik.txt"); //ios::in
    //czytanie do bialego znaku
    int liczba ;
    plik_odczyt>>liczba;
    string napis;
    plik_odczyt>>napis;
    cout<<liczba<<" "<<napis<<endl;

    //wczytywanie calej linijki
    string linijka1;
    string linijka2;
    getline(plik_odczyt,linijka1);
    getline(plik_odczyt,linijka2);
    cout<<linijka1<<endl<<linijka2<<endl;

    //czytanie znaku
    char znak;
    plik_odczyt>>znak;
    cout<<znak<<endl;

    //czytanie do konca pliku
    while(!plik_odczyt.eof()) //czytanie do koca pliku
    {
        getline(plik_odczyt,linijka1); //pobieranie calej linii do znaku enter
        cout<<linijka1<<endl;
    }
    /* while(getline(plik_odczyt,linijka1)){ //druga mozliwosc
        cout<<linijka1<<endl;
    } */
    if(plik_odczyt.is_open()) //sprawdzenie czy plik jest otwarty
    {
        cout<<"Otwarty plik"<<endl;
    }
    else{
        cout<<"Zamkniety plik"<<endl;
    }
    plik_odczyt.close();


    return 0;
}
