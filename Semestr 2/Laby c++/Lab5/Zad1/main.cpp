#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    string surname;
    int age;
public:
    Person(string name1, string surname1, int age1)
    {
        name=name1;
        surname=surname1;
        age=age1;
        cout<<"Konstruktor klasy bazowej - Person"<<endl;
    }
    Person()
    {
        cout<<"Konstruktor bezparametrowy klasy bazowej - Person"<<endl;
    }
    void setName(string name1)
    {
        name=name1;
    }
    void setSurname(string surname1)
    {
        surname=surname1;
    }
    void setAge(int age1)
    {
        age=age1;
    }
    string getName()
    {
        return name;
    }
    string getSurname()
    {
        return surname;
    }
    int getAge()
    {
        return age;
    }
    bool is_18()
    {
        if(age>=18)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void show() //metoda show klasy bazowej Person
    {
        cout<<"Imie: "<<name<<" nazwisko: "<<surname<<" wiek: "<<age<<endl;
    }
};

//klasa dziedziczaca - klasa potomna
class Teacher: public Person //dziedziczenie po klasie Person
{
private:
    int experience;
    string title;
public:
    //konstruktor zawierajacy parametry klasy bazowej + swoje czyli experience i title
    //po dwukropku wywolanie klasy bazowej czyli po tej po ktorej klasa dziedziczy
    Teacher(string name1, string surname1, int age1,int experience1, string title1):Person(name1,surname1,age1)
    {
        experience=experience1;
        title=title1;
        cout<<"Konstruktor klasy pochodnej Teacher"<<endl;
    }
    Teacher()
    {
        cout<<"Konstruktor bezparametrowy klasy pochodnej Teacher"<<endl;
    }
    void setExperience(int experience1)
    {
        experience=experience1;
    }
    void setTitle(string title1)
    {
        title=title1;
    }
    int getExperience()
    {
        return experience;
    }
    string getTitle()
    {
        return title;
    }
    bool is_Phd()
    {
        if(title=="Phd")
            return true;
        else
            return false;
    }
    void info()
    {
       show();
       cout<<"Staz pracy: "<<experience<<" tytul naukowy: "<<title<<endl;
    }
    void show() //metoda show klasy pochodnej Teacher
    {
        Person::show(); //W celu wyswietlenia informacji o imieniu, nazwisku oraz wieku nauczyciela, wywolywana jest metoda show
        //z klasy {Person. Nazwy jednej i drugiej metody sa takie same wiec nalezy uzyc :: w celu okreslenia z ktorej klasy ma
        //pochodzic metoda show (przestrzen nazw)
        //jesli nie chcemy wywolywac metody klasy bazowej mozna skorzystac z getterow klasy bazowej poniewaz mamy do nich dostep

        //cout<<"Imie: "<<getName()<<" nazwisko: "<<getSurname()<<" wiek: "<<getAge()<<endl;
       cout<<"Staz pracy: "<<experience<<" tytul naukowy: "<<title<<endl;
    }
} ;

//klasa potomna Student
class Student: public Person
{
private:
    string index;
public:
    Student(string name1, string surname1, int age1,string index1):Person(name1,surname1,age1)
    {
        index=index1;
        cout<<"Konstruktor klasy pochodnej Student"<<endl;
    }
    Student()
    {
        cout<<"Konstruktor bezparametrowy klasy pochodnej Student"<<endl;
    }
    void setIndex(string index1)
    {
        index=index1;
    }
    string getIndex()
    {
        return index;
    }
    void show()
    {
        Person::show();
        cout<<"Nr indeksu: "<<index<<endl;
    }

    /* void show1(){ //Mozna rowniez stworzyc metode wyswietlajaca informacje o Studencie o innej nazwie niz ta w klasie bazowej
    // wtedy nie trzeba uzywac Osoba:: poniewaz nie ma dwoch metod o takiej samej nazwie.
     show();
     cout<<"Nr indeksu: "<<index<<endl;
     } */

};
int main()
{
    cout<<"Obiekty statyczne"<<endl;
    cout<<endl<<"Obiekty klasy Person"<<endl;
    Person o1("Grazyna","Nowak",45);
    o1.show();
    cout<<"Czy pelnoletnia?: "<<o1.is_18()<<endl;
    o1.setName("Magdalena");
    cout<<"Imie: "<<o1.getName()<<endl;

    cout<<endl<<"Obiekty klasy Teacher"<<endl;

    Teacher n1("Barbara","Kowalska",56,30,"Phd"); //obiekt klasy Teacher ma dostep do wszystkich metody klasy Person oraz
    n1.show();                                       //do swoich
    cout<<"Czy ma Phd?: "<<n1.is_Phd()<<endl; //wywolanie metody w klasy Teacher
    n1.setName("Monika"); //wywolanie metody z klasy Person
    cout<<"Imie: "<<n1.getName()<<endl; //wywolanie metody z klasy Person

    Teacher n2; //przyklad tworzenia obiektu gdzie wywolywane sa konstruktory bezparametrowe

    cout<<endl<<"Obiekty klasy Student"<<endl;

    Student s1("Pawel","Adamiak",17,"123456");
    s1.show(); //wywolanie metody z klasy Student
    cout<<"Czy pelnoletni?: "<<s1.is_18()<<endl; //wywolanie metody z klasy Person
    s1.setName("Piotr");  //wywolanie metody z klasy Person
    cout<<"Imie: "<<s1.getName()<<endl;  //wywolanie metody z klasy Person

    cout<<endl<<"Statyczna tablica"<<endl;
    Person os[5]; //tablica statyczna zawierajaca 5 statycznych obiektow, przy tworzeniu tablicy wywolywane sa konstruktory bezparametrowe
    Teacher na[5];
    Student st[5];
    na[0].setName("Ola"); //ustwienie wartosci pola imie pierwszemu obiektowi (pierwszemu nauczycielowi)
    na[1].setName("Agata");
    na[2].setName("Michal");
    na[0].setSurname("Nowacka");
    na[0].setAge(34);
    na[0].setExperience(10);
    na[0].setTitle("Mgr");
    na[0].show();


    return 0;
}
