#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct student
{
    string imie;
    string nazwisko;
    int punkty;
};

void sortowanieQuickSort(student* tab, int lewy, int prawy, int tryb)
{
    int srodek = (int)(lewy+prawy)/2;
    student piwot = tab[srodek];
    tab[srodek] = tab[prawy];
    int granica = lewy;
    int i = lewy;
    while(i<prawy)
    {
        if(tryb==1)
        {
            if(tab[i].punkty<piwot.punkty)
            {
                swap(tab[granica],tab[i]);
                granica+=1;
            }
        }
        if(tryb==0)
        {
             if(tab[i].punkty>piwot.punkty)
            {
                swap(tab[granica],tab[i]);
                granica+=1;
            }
        }
        i+=1;
    }
    tab[prawy]=tab[granica];
    tab[granica]=piwot;
    if(lewy<granica-1) sortowanieQuickSort(tab, lewy, granica-1, tryb);
    if(granica+1<prawy) sortowanieQuickSort(tab, granica+1, prawy, tryb);
}

void wczytajStudentow(student*& tab, int& liczbaStudentow)
{
    string sciezka,linia,pomoc;
    ifstream plik;
    char sredniki;
    sciezka="studenci.csv";
    plik.open(sciezka);
    plik >> liczbaStudentow;
    tab = new student[liczbaStudentow];
    for(int i = 0; i < 2; i++)
        plik >> sredniki;

    for(int i=0; i<liczbaStudentow; i++)
    {
        plik>>linia;
        istringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, pomoc);
        tab[i].punkty=atoi(pomoc.c_str());
    }
    plik.close();
}

void usunTabliceStudentow(student*& tab)
{
    delete [] tab;
    tab=nullptr;
}

void wyswietlStudentow(student* tab, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].punkty<<endl;
    }
}

int main()
{
    student* tab;
    int tryb;
    int liczbaStudentow;
    wczytajStudentow(tab, liczbaStudentow);
    cout<<"Wybierz tryb sortowania (0-malejaco, 1-rosnaco)"<<endl;
    cin>>tryb;
    wyswietlStudentow(tab, liczbaStudentow);
    sortowanieQuickSort(tab, 0, liczbaStudentow-1, tryb);
    cout<<endl;
    wyswietlStudentow(tab, liczbaStudentow);
    usunTabliceStudentow(tab);
    return 0;
}
