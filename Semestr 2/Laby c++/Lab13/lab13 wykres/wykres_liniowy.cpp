#include "wykres_liniowy.h"

//implementacja metod klasy do obslugi wykresu liniowego
Wykres_liniowy::Wykres_liniowy(){
    series = new QLineSeries();
    chart = new QChart();
}
Wykres_liniowy::~Wykres_liniowy(){
    delete series;
    delete chart;
}
void Wykres_liniowy::generowanie_danych(float a,float b, float c){
    QList <QPointF> dane; //tworzenie listy przechowujacej punkty
    float zakresXp=-10;
    float zakresXk=10;
    float krok=0.1;
    int ile=(zakresXk-zakresXp)/krok;
    float x=zakresXp;
    //generowanie danych w celu stworzenia wykresu funkcji kwadratowej
    //o wspolczynnikach a b c
    for(int i=0;i<=ile;i++){
        float y=a*x*x+b*x+c;
        dane.append(QPointF(x,y)); //dodanie kolejnego obiektu reprezentujacego punkt
        x=x+krok;
    }

    *series<<dane; //dodanie danych do series
}
void Wykres_liniowy::tworzene_wykresu(){
    chart->legend()->hide(); //ukrycie legendy
    chart->addSeries(series); //dodanie danych do wykresu
    chart->setTitle("Funkcja kwadratowa"); //ustawienie tytulu
    chart->createDefaultAxes(); //stworzenie osi
    chart->axes(Qt::Vertical).first()->setRange(0, 200); //ustawienie zakresu osi, 200 dla przykladu ;)
    chart->axes(Qt::Horizontal).first()->setGridLineVisible(false); //ustawienie widocznosci siatki
    chart->axes(Qt::Vertical).first()->setTitleText(QString("oś y"));//opis osi pionowej
    chart->axes(Qt::Horizontal).first()->setTitleText(QString("oś x")); //opis osi poziomej
}
QChart* Wykres_liniowy::getChart(){
    return chart;
}

