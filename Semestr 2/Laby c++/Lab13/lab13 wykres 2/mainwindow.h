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
    void on_wykres_liniowy_stateChanged(int arg1);

    void on_wykres_slupkowy_stateChanged(int arg1);

    void on_rysuj_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
