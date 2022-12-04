#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dodawanie_clicked()
{
    QString liczba1=ui->liczba1->text();
    QString liczba2=ui->liczba2->text();
    QString wynik="";
    bool flaga;
    float liczba1_i=liczba1.toFloat(&flaga);
    if(flaga)
    {
        float liczba2_i=liczba2.toFloat(&flaga);
        if(flaga)
        {
            float wynik_i=liczba1_i+liczba2_i;
            wynik=QString::number(wynik_i);
        }
        else
        {
             wynik="Niepoprawna liczba";
        }
    }
    else
    {
        wynik="Niepoprawna liczba";
    }

    ui->wynik->setText(wynik);
}

void MainWindow::on_odejmowanie_clicked()
{
    QString liczba1=ui->liczba1->text();
    QString liczba2=ui->liczba2->text();
    QString wynik="";
    bool flaga;
    float liczba1_i=liczba1.toFloat(&flaga);
    if(flaga)
    {
        float liczba2_i=liczba2.toFloat(&flaga);
        if(flaga)
        {
            float wynik_i=liczba1_i-liczba2_i;
            wynik=QString::number(wynik_i);
        }
        else
        {
             wynik="Niepoprawna liczba";
        }
    }
    else
    {
        wynik="Niepoprawna liczba";
    }

    ui->wynik->setText(wynik);
}

void MainWindow::on_mnozenie_clicked()
{
    QString liczba1=ui->liczba1->text();
    QString liczba2=ui->liczba2->text();
    QString wynik="";
    bool flaga;
    float liczba1_i=liczba1.toFloat(&flaga);
    if(flaga)
    {
        float liczba2_i=liczba2.toFloat(&flaga);
        if(flaga)
        {
            float wynik_i=liczba1_i*liczba2_i;
            wynik=QString::number(wynik_i);
        }
        else
        {
             wynik="Niepoprawna liczba";
        }
    }
    else
    {
        wynik="Niepoprawna liczba";
    }

    ui->wynik->setText(wynik);
}

void MainWindow::on_dzielenie_clicked()
{
    QString liczba1=ui->liczba1->text();
    QString liczba2=ui->liczba2->text();
    QString wynik="";
    bool flaga;
    float liczba1_i=liczba1.toFloat(&flaga);
    if(flaga)
    {
        float liczba2_i=liczba2.toFloat(&flaga);
        if(flaga)
        {
            if(liczba2_i != 0)
            {
                float wynik_i=liczba1_i/liczba2_i;
                wynik=QString::number(wynik_i);
            }
            else
            {
                wynik="Błąd: Dzielenie przez zero!";
            }

        }
        else
        {
             wynik="Niepoprawna liczba";
        }
    }
    else
    {
        wynik="Niepoprawna liczba";
    }

    ui->wynik->setText(wynik);
}

void MainWindow::on_wszystkie_clicked()
{

}

void MainWindow::on_wyczysc_clicked()
{
    ui->liczba1->setText("");
    ui->liczba2->setText("");
}
