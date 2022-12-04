#include <iostream>

using namespace std;

class CKolo
{
private:
    int promien;

public:
    CKolo(int promien)
    {
        this->promien=promien;
        cout<<"Zostal wywolany konstruktor"<<endl;
    }

    ~CKolo()
    {
        cout<<"Zostal wywolany destruktor"<<endl;
    }
    int getPromien()
    {
        return promien;
    }
    void setPromien(int promien)
    {
        this->promien=promien;
    }
    double obwod()
    {
        double obw;
        obw=2*3.14*promien;
        return obw;
    }
    double pole()
    {
        double pole;
        pole=3.14*promien*promien;
        return pole;
    }
    void wyswietl()
    {
        cout<<"Promien kola: "<<promien<<endl;
    }

};

void compare(Kolo &k1, Kolo k2)
{
    if(k1.getPromien()>k2.getPromien())
    {
        cout<<"Promien 1 jest wiekszy od promienia 2"<<endl;

    }
    else
    {
        cout<<"Promien 1 jest mniejszy badz rowny od promienia 2"<<endl;
    }
}

int main()
{
    //statyczny obiekt
    CKolo k(3);
    cout<<"Obwod: "<<k.obwod()<<endl;
    cout<<"Pole: "<<k.pole()<<endl;
    cout<<"GetPromien: "<<k.getPromien()<<endl;
    k.setPromien(5);
    k.show();

    //dynamiczny obiekt
    cout<<"Dynamiczny obiekt"<<endl;
    CKolo *kk; //stworzenie wskaznika na obiekt
    kk=new Kolo(6); //zaalokowanie pamieci wraz z wywolaniem konstruktora
    kk->show(); //odwolanie do metody poprzez strzalke
    cout<<"Obwod: "<<kk->obwod()<<endl;
    delete kk; //usuniecie obiektu

    //statyczna tablica
    CKolo tab[3]= {CKolo(1),CKolo(2),CKolo(3)}; //stworzenie tablicy obiektow, kazda komorka przechowuje jeden obiekt
                  //podczas tworzenia tablicy wywolywane sa konstruktory dla poszczegolnych obiektow
    tab[0].show(); //odolanie sie do 0 obiektu i wywolanie metody show
    tab[1].show();
    tab[2].show();
    //lub
    CKolo tab1[3]; //stworzenie statycznej tablicy obiektow bez poczatkowej inicjalizacji obiektow
    tab1[0].show(); //wartosc promienia NIE jest ustawiona
    tab1[0].setPromien(55); //ustawienie wartosci promienia
    tab1[0].show();

  //dynamiczna tablica dynamicznych obiektow
    CKolo **tab3;
    tab3=new Kolo*[3]; //zaalokowanie pamieci - okreslenie dlugosci tablicy, kazdy element bedzie wskaznikiem na obiekt
    for(int i=0; i<3; i++)
    {
        tab3[i]=new CKolo(i+200); //zaalokowanie pamieci poszczegolnym elementom tablicy, wywolanie konstruktora
    }
    for(int i=0; i<3; i++)
    {
        tab3[i]->show(); //tab[i] - odwolanie sie do i obiektu w tablicy oraz wywoalnie dla niego metody show
    }               //odwolanie poprzez strzalke

    for(int i=0;i<3;i++){
        delete tab3[i];
    }
    delete [] tab3;


    //statyczna tablica obiektow dynamicznych
    CKolo *tab2[3];
    for(int i=0; i<3; i++)
    {
        tab2[i]=new CKolo(i+20); //kazdemu elementowi tablicy, ktory jest obiektem przydzielana jest pamiec
    }
    for(int i=0; i<3; i++)
    {
        tab2[i]->show(); //element tablicy jest wskaznikiem na obiekt stad w odolaniu wystepuje strzalka
    }
    for(int i=0;i<3;i++){
        delete tab2[i];
    }


   //dynamiczna tablica statycznych obiektow
    CKolo *tab4;
    tab4=new CKolo[3]; //przydzielenie pamieci - okreslenie rozmiaru tablicy
    for(int i=0; i<3; i++)
    {
        tab4[i].setPromien(i+6); //ustawienie wartosci promienia dla poszczegolnych obiektow
        tab4[i].show();          //obiekty sa statyczne, odwolanie poprzed kropke
    }
    delete [] tab4;

    //kopiowanie obiektow jesli polami klasy NIE sa wskazniki
    CKolo k11(1);
    CKolo k33(2);
    compare(k11,k33);  //wywolanie funkcji NIE metody compare, przekazanie dwoch obiektow
    k11.show();


    return 0;

}
