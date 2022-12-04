#include <iostream>

using namespace std;

class Student
{
private:
    string imie;
    string nazwisko;
    string pesel;
    string kierunek;
    float srednia;
    char rok_studiow;
    float srednie[5];
public:
    Student(string a_imie, string a_nazwisko, string a_pesel, string a_kierunek, char a_rok_studiow)
    {
        imie=a_imie;
        nazwisko=a_nazwisko;
        pesel=a_pesel;
        kierunek=a_kierunek;
        rok_studiow=a_rok_studiow;
        srednia=0;
        for(int i=0;i<5;i++)
        {
            srednie[i]=0;
        }
        cout<<"Konstruktor z nazwa kierunku"<<endl;
    }
    Student(string a_imie, string a_nazwisko, string a_pesel, char a_rok_studiow)
    {
        imie=a_imie;
        nazwisko=a_nazwisko;
        pesel=a_pesel;
        kierunek="";
        rok_studiow=a_rok_studiow;
        srednia=0;
        for(int i=0;i<5;i++)
        {
            srednie[i]=0;
        }
        cout<<"Konstruktor bez nazwy kierunku"<<endl;
    }
    Student()
    {
        imie="";
        nazwisko="";
        pesel="";
        kierunek="";
        rok_studiow='1';
        srednia=0;
        for(int i=0;i<5;i++)
        {
            srednie[i]=0;
        }
        cout<<"Konstruktor bezparametrowy"<<endl;
    }
    Student(Student &s)
    {
        imie=s.imie;
        nazwisko=s.nazwisko;
        pesel=s.pesel;
        kierunek=s.kierunek;
        rok_studiow=s.rok_studiow;
        srednia=s.srednia;
        for(int i=0;i<5;i++)
        {
            srednie[i]=s.srednie[i];
        }
        cout<<"Konstruktor kopiujacy"<<endl;
    }
    ~Student()
    {
        cout<<"Destruktor"<<endl;
    }
private:
    float policzSrednia()
    {
        float suma=0, ocena=0;
        int ileOcen=0;
        cout<<"Ile ocen?"<<endl;
        cin>>ileOcen;
        for(int i=0;i<ileOcen;i++)
        {
            cout<<"Podaj ocene"<<endl;
            cin>>ocena;
            suma+=ocena;
        }
        return srednia=(float)suma/ileOcen;
    }
public:
    void wyswietlDane()
    {
        cout<<"Imie: "<<imie<<" Nazwisko: "<<nazwisko<<endl;
        cout<<"Pesel: "<<pesel<<endl;
        cout<<"Kierunek: "<<kierunek<<" Rok studiow: "<<rok_studiow<<endl;
        cout<<"Srednia: "<<srednia<<endl;
        cout<<"Srednie"<<endl;
        int ileLat=rok_studiow-'0';
        for(int i=1;i<ileLat+1;i++)
        {
            cout<<"Srednia rok "<<i<<": "<<srednie[i-1]<<endl;
        }
    }
    void ileDoMagisterki()
    {
        cout<<"Za "<<'5'-rok_studiow<<" lata student bedzie pisal magisterke"<<endl;
    }
    string getImie()
    {
        return imie;
    }
    char getRok_studiow()
    {
        return rok_studiow;
    }
    void policzSrednieLat()
    {
        int ileLat=rok_studiow-'0';
        for(int i=0;i<ileLat;i++)
        {
            srednie[i]=policzSrednia();
        }
    }
};

class Kolo_naukowe
{
private:
    string nazwa;
    string opiekun;
    int rozmiar;
    Student *studenci;
    int ile;
public:
    Kolo_naukowe(string a_nazwa, string a_opiekun, int a_rozmiar)
    {
        nazwa=a_nazwa;
        opiekun=a_opiekun;
        rozmiar=a_rozmiar;
        studenci=new Student[rozmiar];
        ile=0;
    }
    ~Kolo_naukowe()
    {
        delete [] studenci;
    }
    void show()
    {
        cout<<"Kolo naukowe: "<<nazwa<<endl;
        cout<<"Opiekun: "<<opiekun<<endl;
    }
    int ile_studentek()
    {
        int ile=0;
        for(int i=0;i<rozmiar;i++)
        {
            int dlugosc = studenci[i].getImie().length();
            if(studenci[i].getImie()[dlugosc-1]=='a')
                ile++;
        }
        return ile;
    }
    void dodaj_studenta(Student s)
    {
        if(ile<rozmiar)
        {
            studenci[ile]=s;
            ile++;
        }
        else
        {
            cout<<"Nie mozna dodac kolejnego studenta"<<endl;
        }
    }
    void show_students()
    {
        for(int i=0;i<ile;i++)
        {
            studenci[i].wyswietlDane();
        }
    }
};

void pierwszy_rok(Student* tab, int n)
{
    for(int i=0;i<n;i++)
    {
        if(tab[i].getRok_studiow()=='1')
            tab[i].wyswietlDane();
    }
}

int main()
{
    //statyczny

    Student s("Agata", "Nowak", "00121257482", "Informatyka", '2');
    s.wyswietlDane();
    //s.policzSrednieLat();
   // s.wyswietlDane();
    //s.ileDoMagisterki();

    //dynamiczny
    /*
    Student *s2 = new Student("Andrzej", "Nowak", "00010123045", "Informatyka", '3');
    s2->wyswietlDane();
    s2->policzSrednieLat();
    s2->wyswietlDane();
    delete s2;
    */
    //tablic statyczna
    //Student tab[5];
    //pierwszy_rok(tab, 5);

    //tablica dynamiczna
    /*
    Student *tab2[5];
    for(int i=0;i<5;i++)
    {
        tab2[i] = new Student();
    }
    for(int i=0;i<5;i++)
    {
        tab2[i]->wyswietlDane();
    }
    for(int i=0;i<5;i++)
    {
        delete tab2[i];
    }*/

    Kolo_naukowe kolo("Grafika", "Janusz Nowak", 5);
    kolo.show();
    kolo.show_students();
    kolo.dodaj_studenta(s);
    kolo.show_students();
    cout<<"Studentek: "<<kolo.ile_studentek()<<endl;;
    return 0;
}
