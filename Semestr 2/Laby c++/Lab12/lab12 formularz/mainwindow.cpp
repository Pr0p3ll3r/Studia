#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     ui->kobieta->setChecked(true); //wybranie opcji kobieta
     ui->wypisz->setVisible(false); //ustawienie elementu wypisz jako niewidoczny
     ui->potwierdzenie->setVisible(false); //ustawienie elementu potwierdzenie jako niewidoczny
     ui->zatwierdz->setStyleSheet("background-color:green;"); //ustawienie koloru przycisku
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_zatwierdz_clicked()
{
    //czyszczenie
   /* ui->imie->setText("");
    ui->nazwisko->setText("");
    ui->wiek->setText("");
    ui->kobieta->setAutoExclusive(false);
    ui->kobieta->setChecked(false);
    ui->mezczyzna->setAutoExclusive(false);
    ui->mezczyzna->setChecked(false);
    ui->kot->setChecked(false);
    ui->pies->setChecked(false);
    ui->dzieci->setValue(0);
    ui->wyksztalcenie->setCurrentIndex(0); */


     QString imie=ui->imie->text(); //pobranie wartosci z pola tekstowego
     QString nazwisko=ui->nazwisko->text();
     QString wiek=ui->wiek->text();

     bool flaga;
     int wiek_i=wiek.toInt(&flaga); //konwersja wieku na liczbe
     //uzycie flagi pomoze rozroznic czy konwersja wykonala sie poprawnie

     QString wyksztalcenie=ui->wyksztalcenie->currentText(); //pobranie wartosc z combo box

     int dzieci=ui->dzieci->value(); //pobranie wartosc ze spin box

     bool kot=ui->kot->isChecked(); //pobranie statusu radio button
     bool pies=ui->pies->isChecked();

     bool kobieta=ui->kobieta->isChecked(); //pobranie statusu check box
     bool mezczyzna=ui->mezczyzna->isChecked();

     QString wynik="";
     QString pelnoletni="niepelnoletni";
     if(wiek_i>=18){
         pelnoletni="pelnoletni";
     }
     QString plec;
     if(kobieta==true){
         plec="kobieta";
     }else{
         plec="mezczyzna";
     }
     QString dzieci_s=QString::number(dzieci); //konwersja z int na String
     wynik=wynik+nazwisko+" "+imie+" "+pelnoletni+", "+wiek+", "+plec+", liczba dzieci: "+dzieci_s;
     wynik=wynik+" wykształcenie: "+wyksztalcenie;
     wynik=wynik+ ", zwierzeta: ";
     if(kot==true){
         wynik=wynik+"kot, ";
     }
     if(pies==true){
         wynik=wynik+"pies";
     }

     ui->wypisz->setVisible(true); //ustawienie widocznosc elementu wpisz
     ui->potwierdzenie->setVisible(true); //ustawienie widocznosci elementu potwierdzenie
     ui->potwierdzenie->setText(wynik); //ustawienie wartosc elementu Text Browser
}





