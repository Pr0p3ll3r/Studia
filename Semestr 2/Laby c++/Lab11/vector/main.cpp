#include <iostream>
#include <vector>

using namespace std;

int main()
{   // wektor - tablica dynamiczna

    //wektor przechowujacy liczby calkowite
    vector<int> vec;
    vec.push_back(1); //dodanie do koniec
    vec.push_back(2);
    vec.push_back(3);

    for(int i=0; i<vec.size(); i++) //I sposob wyswietlania
    {
        cout<<vec[i]<<endl; //odwolanie jak do tablicy
    }

    for(int i=0; i<vec.size(); i++) // II sposob wyswietlenia wszystkich elementow
    {

        cout<<vec.at(i)<<endl; //odwolanie sie do i elementu
    }

    cout<<"Iterator: "<<endl;
    vector < int >::iterator it; //III sposob wyswietlenia
    for(it=vec.begin(); it != vec.end(); it++ )
        cout <<* it<<endl; //iterator to wskaznik wiec odowlanie sie do wartosc jest poprzez *

    vec.insert(vec.begin()+1,100); //wstawienie na pozycje liczac od poczatku, wektor.begin() musi byc, od niego zaczyna sie przesuniecie

    cout<<"begin()"<< *vec.begin()<<endl; //funkcja begin() zwraca wskaznik na pierwszy element
    cout<<"end()"<< *(vec.end()-1)<<endl; //funkcja end() zwraca wskaznik na element za tablica stad -1

    vec.pop_back(); //usuwanie z konca tablicy
    vec.erase(vec.begin()+1,vec.begin()+2); //usuwanie elementow z podanego zakrezu [a,b)

    vec.clear(); //czyszczenie wektora, wektor pusty


    return 0;
}
