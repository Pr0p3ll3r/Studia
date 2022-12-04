#include <iostream>

using namespace std;
class Figure  //klasa abstrakcyjna - zawiera zbior metod jakie chcemy implementowac na rozne sposoby w klasach dziedziacych
{
private:
    float area;
    float circuit;
public:
    Figure()
    {
        cout<<"Konstruktor klasy bazowej Figura"<<endl;
    }
    virtual ~Figure() //wirtualny destruktor, potrzebny aby poprawnie usunac obiekty
    //(powinien wywolac sie destruktor klasy potomnej oraz bazowej)
    {
        cout<<"Wirtualny destruktor klasy bazowej Figure"<<endl;
    }
    float getArea()
    {
        return area;
    }
    float getCircuit()
    {
        return circuit;
    }
    void setArea(float area1)
    {
        area=area1;
    }
    void setCircuit(float circuit1)
    {
        circuit=circuit1;
    }
    virtual void calculateArea()=0; //metoda czysto wirtualna, implementacja tej metody bedzie w klasach potomnych
    virtual void calculateCircuit()=0;
    void show()
    {
        cout<<"Obwod: "<<circuit<<"  pole: "<<area<<endl;
    }
};
class Square: public Figure
{
private:
    float a;
public:
    Square(float a1):Figure()
    {
        a=a1;
        cout<<"Konstruktor klasy Square"<<endl;
    }
    virtual~Square()
    {
        cout<<"Destruktor klasy Square"<<endl;
    }
    virtual void calculateArea() //implementacja metody, ktora w klasie bazowej byla czysto wirtualna
    {
        float p=a*a;
        setArea(p);
    }
    virtual void calculateCircuit()
    {
        float o=4*a;
        setCircuit(o);
    }
};
class Circle: public Figure
{
private:
    float r;
public:
    Circle(float r1)
    {
        r=r1;
        cout<<"Konstruktor w klasie Circle"<<endl;
    }
    virtual~Circle()
    {
        cout<<"Destruktor w klasie Circle"<<endl;
    }
    virtual void calculateArea() //implementacja metody ktora byla w klasie bazowej czysto wirtualna
    {
        float p=3.14*r*r;
        setArea(p);
    }
    virtual void calculateCircuit()
    {
        float o=2*3.14*r;
        setCircuit(o);
    }

};
int main()
{
    //Figura *f=new Figura(); //obiektu klasy abstrakcyjnej nie mozna stworzyc
    Figure *f=new Square(3);  //polimorfizm, stworzenie wskaznika na obiekt klasy Figure oraz stworzenie obiektu typu Square
    f->calculateCircuit(); //obliczenie pola kwadratu poslugujac sie wskaznikiem na obiekt klasy Figura
    f->calculateArea();
    f->show();

    Figure *f2=new Circle(2);
    f2->calculateCircuit();
    f2->calculateArea();
    f2->show();

    delete f;  //usuniecie obiektu, wywolanie konstruktora klasy Square oraz klasy Figure
    delete f2;

    Square *k=new Square(5);
    k->calculateArea();
    k->calculateCircuit();
    k->show();
    delete k;


  //statyczna tablica wskaznikow na obiekt typu Figure
    Figure* tab1[5];
    for(int i=0; i<3; i++)
    {
        tab1[i]=new Square(i); //kazdy element tablicy jest wskaznikiem na obiekt
        tab1[i]->calculateArea();
        tab1[i]->calculateCircuit();
    }
    for(int i=3; i<5; i++)
    {
        tab1[i]=new Circle(i); //kazdy element tablicy jest wskaznikiem na obiekt
        tab1[i]->calculateArea();
        tab1[i]->calculateCircuit();
    }
    for(int i=0; i<5; i++)
    {
        tab1[i]->show(); //kazdy element jest wskaznkiem na obiekt wiec wywolanie metody odbywa sie poprzez strzalke
    }

    //usuniecie zaalokowanej pamieci
    for(int i=0; i<5; i++)
    {
        delete tab1[i];
    }

    //dynamiczna tablica wskaznikow na obiekt typu Figure
    Figure **tab2;
    tab2=new Figure*[5];
    for(int i=0; i<3; i++)
    {
        tab2[i]=new Square(i); //kazdy element tablicy jest wskaznikiem na obiekt
    }
    for(int i=3; i<5; i++)
    {
        tab2[i]=new Circle(i); //kazdy element tablicy jest wskaznikiem na obiekt
    }
    for(int i=0; i<5; i++)
    {
        tab2[i]->calculateArea();
        tab2[i]->calculateCircuit();
        tab2[i]->show(); //kazdy element jest wskaznikiem na obiekt wiec wywolanie metody odbywa sie poprzez strzalke
    }

    //usuniecie zaalokowanej pamieci
    for(int i=0; i<5; i++)
    {
        delete tab2[i];
    }
    delete [] tab2;

    return 0;
}
