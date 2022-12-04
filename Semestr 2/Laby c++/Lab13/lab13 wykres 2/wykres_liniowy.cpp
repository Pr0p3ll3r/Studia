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
void Wykres_liniowy::wczytanie_danych(QString sciezka){
    QList <QPointF> dane; //tworzenie listy przechowujacej punkty
    QFile plik_odczyt(sciezka);//uchwyt do pliku
    plik_odczyt.open(QIODevice::ReadWrite|QIODevice::Text);//otwarcie pliku
    QTextStream in(&plik_odczyt);//przekazanie pliku do strumienia
    QString linijka;
    linijka=in.readLine();//pierwszy wiersz
    while(!in.atEnd()){//czytanie pliku do konca
        linijka=in.readLine();//czytanie linijka po linijce
        QStringList lista=linijka.split(';');
        float x = lista[0].toFloat();
        float y = lista[1].toFloat();
        dane.append(QPointF(x,y)); //dodanie kolejnego obiektu reprezentujacego punkt
    }

    plik_odczyt.close();//zamkniecie pliku

    float zakresXp=-10;
    float zakresXk=10;
    float krok=0.1;
    int ile=(zakresXk-zakresXp)/krok;
    float x=zakresXp;
    //generowanie danych w celu stworzenia wykresu funkcji kwadratowej
    //o wspolczynnikach a b c
    for(int i=0;i<=ile;i++){
        x=x+krok;
    }

    *series<<dane; //dodanie danych do series
}
void Wykres_liniowy::tworzene_wykresu(){
    chart->legend()->hide(); //ukrycie legendy
    chart->addSeries(series); //dodanie danych do wykresu
    chart->setTitle("Funkcja kwadratowa"); //ustawienie tytulu
    chart->createDefaultAxes(); //stworzenie osi
    chart->axes(Qt::Vertical).first()->setRange(0, 50); //ustawienie zakresu osi, 200 dla przykladu ;)
    chart->axes(Qt::Horizontal).first()->setGridLineVisible(false); //ustawienie widocznosci siatki
    chart->axes(Qt::Vertical).first()->setTitleText(QString("oś y"));//opis osi pionowej
    chart->axes(Qt::Horizontal).first()->setTitleText(QString("oś x")); //opis osi poziomej
}
QChart* Wykres_liniowy::getChart(){
    return chart;
}

