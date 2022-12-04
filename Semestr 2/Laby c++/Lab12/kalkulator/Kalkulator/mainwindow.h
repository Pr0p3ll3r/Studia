#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_dodawanie_clicked();
    void on_odejmowanie_clicked();
    void on_mnozenie_clicked();
    void on_dzielenie_clicked();
    void on_wszystkie_clicked();
    void on_wyczysc_clicked();
    bool sprawdz_dane(QString liczba1, QString liczba2);
    bool czy_zero(QString liczba2);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
