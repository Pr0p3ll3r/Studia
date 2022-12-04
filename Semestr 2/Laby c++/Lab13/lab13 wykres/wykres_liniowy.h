#ifndef WYKRES_LINIOWY_H
#define WYKRES_LINIOWY_H
#include <QtCharts>
//definicja klasy do obslugi wykresu liniowego
class Wykres_liniowy{

private:
    QChart *chart; //pole do przechowywania wykresu
    QLineSeries *series; //pole do przechowywania danych
public:
    Wykres_liniowy();
    ~Wykres_liniowy();
    void generowanie_danych(float a, float b, float c); //stworzenie danych series
    void tworzene_wykresu(); //stworzenie wykresu
    QChart* getChart(); //zwrocenie wykresu poniewaz jest to pole prywatne
};

#endif // WYKRES_LINIOWY_H
