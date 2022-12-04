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
    cout<<"Dane wczytane"<<endl;
}

void usunTabliceStudentow(student*& tab)
{
    delete [] tab;
    tab=nullptr;
}

void wyswietlStudentow(student* tab, int n1, int n2)
{
    for(int i=n1;i<n2;i++)
    {
        cout<<tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].punkty<<endl;
    }
}

int podzial_2_czesci(student* tab, int liczbaStudentow, int granica)
{
    int i=0, j=liczbaStudentow-1;
    while(i<j)
    {
        while(tab[i].punkty<=granica && i<j)
            i++;
        while(tab[j].punkty>granica && i<j)
            j--;
        if(i<j)
        {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }
    if(tab[i].punkty<=granica)
        return i+=1;
    else
        return i;
}

int podzial_3_czesci(student* tab, int liczbaStudentow, int& k)
{
    int i=-1, j=0;
    k=liczbaStudentow;
    while(j<k)
    {
        if(tab[j].punkty%3==0)
        {
            i++;
            swap(tab[i], tab[j]);
            j++;
        }
        else
        {
            if(tab[j].punkty%3==2)
            {
                k--;
                swap(tab[k], tab[j]);
            }
            else j++;
        }
    }
    return i+=1;
}

int main()
{
    int wybor, liczbaStudentow, p, k;
    student* tab;
    for(;;)
    {
        cout<<"MENU"<<endl;
        cout<<"1: Zad4.1"<<endl;
        cout<<"2: Zad4.2"<<endl;
        cout<<"3: Zad4.3"<<endl;
        cout<<"4: Koniec programu"<<endl;
        cin>>wybor;

        switch(wybor)
        {
            case 1:
                wczytajStudentow(tab, liczbaStudentow);
                break;
            case 2:
                wyswietlStudentow(tab, 0, liczbaStudentow);
                p=podzial_2_czesci(tab, liczbaStudentow, 10);
                cout<<endl<<"Studenci, ktorzy otrzymali <=10 punktow:"<<endl;
                wyswietlStudentow(tab, 0, p);
                cout<<endl<<"Studenci, ktorzy otrzymali >10 punktow:"<<endl;
                wyswietlStudentow(tab, p, liczbaStudentow);
                cout<<endl;
                break;
            case 3:
                wyswietlStudentow(tab, 0, liczbaStudentow);
                p=podzial_3_czesci(tab, liczbaStudentow, k);
                cout<<endl<<"Studenci, ktorzy otrzymali liczbe punktow podzielna przez 3:"<<endl;
                wyswietlStudentow(tab, 0, p);
                cout<<endl<<"Studenci, ktorzy otrzymali liczbe punktow podzielna przez 3 z reszta 1:"<<endl;
                wyswietlStudentow(tab, p, k);
                cout<<endl<<"Studenci, ktorzy otrzymali liczbe punktow podzielna przez 3 z reszta 2:"<<endl;
                wyswietlStudentow(tab, k, liczbaStudentow);
                cout<<endl;
                break;
            case 4:
                exit(0);
            default:
                cout<<"Niepoprawny wybor"<<endl;
        }
    }
}
