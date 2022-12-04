#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wykres_liniowy.h"

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
void MainWindow::on_liniowy_clicked()
{   QString aa=ui->a->text();
    QString bb=ui->b->text();
    QString cc=ui->c->text();
    int a=aa.toInt();
    int b=bb.toInt();
    int c=cc.toInt();

    //stworzenie wskaznika na obiekt klasy Wykres_liniowy
    Wykres_liniowy *wykres=new Wykres_liniowy();
    wykres->generowanie_danych(a,b,c);
    wykres->tworzene_wykresu();

    //stworzenie widoku wykresu
    QChartView *chartView = new QChartView(wykres->getChart());
    //jako argument przekazany jest wskaznik na obiekt typu Chart
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow* window = new QMainWindow(); //stworzenie okienka w ktorym
    //zostanie wyswietlony wykres
    window->setCentralWidget(chartView); //ustawienie wykresu w okienku
    window->resize(400, 300); //rozmiar okienka
    window->show(); //wyswietlenie okienka
    window->setAttribute(Qt::WA_DeleteOnClose); //zwolnienie zasobow po zamknieciu okienka

}
void MainWindow::on_slupkowy_clicked()
{
    //stworzenie zbiorow dla wykresu slupkowego
    QBarSet *set0 = new QBarSet("Jane");
    QBarSet *set1 = new QBarSet("John");
    QBarSet *set2 = new QBarSet("Axel");
    QBarSet *set3 = new QBarSet("Mary");
    QBarSet *set4 = new QBarSet("Sam");

    //I sposob dodania wartosci do zbioru
    for(int i=1;i<=6;i++){
        set0->append(i);
    }
    //II sposob dodania wartosci do zbioru
    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
    *set3 << 5 << 6 << 7 << 3 << 4 << 5;

    //III sposob dodania wartosci do zbioru
    QList<qreal> values; //stworzenie listy ktora przechowuje liczby
    for(int i=11;i>=1;i=i-2){
        values.append(i);
    }
    set4->append(values); //dodanie listy do zbioru

    //stworzenie serii na podstawie zbiorow
    QBarSeries *barseries = new QBarSeries();
    barseries->append(set0);
    barseries->append(set1);
    barseries->append(set2);
    barseries->append(set3);
    barseries->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(barseries); //dodanie serii do wykresu

    chart->setTitle("Barchart example");
    QStringList categories; //kategorie dla wykresu slupkowego
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";     //dodanie kategorii

    //osie na wykresie slupkowym
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    barseries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    barseries->attachAxis(axisY);
    int zakres2 = 25;
    axisY->setRange(0, zakres2); //ustawienie zakresu osi pionowej

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom); //polozenie legendy

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QMainWindow* window =  new QMainWindow();
    window->setCentralWidget(chartView);
    window->resize(440, 300);
    window->show();
}



