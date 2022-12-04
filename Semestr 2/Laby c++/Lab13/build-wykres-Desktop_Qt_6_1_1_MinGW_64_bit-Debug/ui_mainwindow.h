/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lable_sciezka;
    QLineEdit *sciezka;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *wykres_liniowy;
    QCheckBox *wykres_slupkowy;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lable_tytul;
    QLineEdit *tytul_wykresu;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lable_osY;
    QLineEdit *osY;
    QLabel *lable_osX;
    QLineEdit *osX;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lable_tytul_osY;
    QLineEdit *tytul_osY;
    QLabel *lable_tytul_osX;
    QLineEdit *tytul_osX;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *siatka_osY;
    QCheckBox *siatka_osX;
    QCheckBox *legenda;
    QPushButton *rysuj;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(732, 369);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(120, 20, 491, 291));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lable_sciezka = new QLabel(verticalLayoutWidget);
        lable_sciezka->setObjectName(QString::fromUtf8("lable_sciezka"));

        horizontalLayout_2->addWidget(lable_sciezka);

        sciezka = new QLineEdit(verticalLayoutWidget);
        sciezka->setObjectName(QString::fromUtf8("sciezka"));

        horizontalLayout_2->addWidget(sciezka);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        wykres_liniowy = new QCheckBox(verticalLayoutWidget);
        wykres_liniowy->setObjectName(QString::fromUtf8("wykres_liniowy"));

        horizontalLayout_3->addWidget(wykres_liniowy);

        wykres_slupkowy = new QCheckBox(verticalLayoutWidget);
        wykres_slupkowy->setObjectName(QString::fromUtf8("wykres_slupkowy"));

        horizontalLayout_3->addWidget(wykres_slupkowy);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lable_tytul = new QLabel(verticalLayoutWidget);
        lable_tytul->setObjectName(QString::fromUtf8("lable_tytul"));

        horizontalLayout_4->addWidget(lable_tytul);

        tytul_wykresu = new QLineEdit(verticalLayoutWidget);
        tytul_wykresu->setObjectName(QString::fromUtf8("tytul_wykresu"));

        horizontalLayout_4->addWidget(tytul_wykresu);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lable_osY = new QLabel(verticalLayoutWidget);
        lable_osY->setObjectName(QString::fromUtf8("lable_osY"));

        horizontalLayout_5->addWidget(lable_osY);

        osY = new QLineEdit(verticalLayoutWidget);
        osY->setObjectName(QString::fromUtf8("osY"));

        horizontalLayout_5->addWidget(osY);

        lable_osX = new QLabel(verticalLayoutWidget);
        lable_osX->setObjectName(QString::fromUtf8("lable_osX"));

        horizontalLayout_5->addWidget(lable_osX);

        osX = new QLineEdit(verticalLayoutWidget);
        osX->setObjectName(QString::fromUtf8("osX"));

        horizontalLayout_5->addWidget(osX);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lable_tytul_osY = new QLabel(verticalLayoutWidget);
        lable_tytul_osY->setObjectName(QString::fromUtf8("lable_tytul_osY"));

        horizontalLayout_6->addWidget(lable_tytul_osY);

        tytul_osY = new QLineEdit(verticalLayoutWidget);
        tytul_osY->setObjectName(QString::fromUtf8("tytul_osY"));

        horizontalLayout_6->addWidget(tytul_osY);

        lable_tytul_osX = new QLabel(verticalLayoutWidget);
        lable_tytul_osX->setObjectName(QString::fromUtf8("lable_tytul_osX"));

        horizontalLayout_6->addWidget(lable_tytul_osX);

        tytul_osX = new QLineEdit(verticalLayoutWidget);
        tytul_osX->setObjectName(QString::fromUtf8("tytul_osX"));

        horizontalLayout_6->addWidget(tytul_osX);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        siatka_osY = new QCheckBox(verticalLayoutWidget);
        siatka_osY->setObjectName(QString::fromUtf8("siatka_osY"));

        horizontalLayout_7->addWidget(siatka_osY);

        siatka_osX = new QCheckBox(verticalLayoutWidget);
        siatka_osX->setObjectName(QString::fromUtf8("siatka_osX"));

        horizontalLayout_7->addWidget(siatka_osX);

        legenda = new QCheckBox(verticalLayoutWidget);
        legenda->setObjectName(QString::fromUtf8("legenda"));

        horizontalLayout_7->addWidget(legenda);


        verticalLayout->addLayout(horizontalLayout_7);

        rysuj = new QPushButton(verticalLayoutWidget);
        rysuj->setObjectName(QString::fromUtf8("rysuj"));

        verticalLayout->addWidget(rysuj);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 732, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lable_sciezka->setText(QCoreApplication::translate("MainWindow", "\305\233cie\305\274ka", nullptr));
        wykres_liniowy->setText(QCoreApplication::translate("MainWindow", "wykres liniowy", nullptr));
        wykres_slupkowy->setText(QCoreApplication::translate("MainWindow", "wykres s\305\202upkowy", nullptr));
        lable_tytul->setText(QCoreApplication::translate("MainWindow", "tytu\305\202 wykresu", nullptr));
        lable_osY->setText(QCoreApplication::translate("MainWindow", "zakres osi pionowej", nullptr));
        lable_osX->setText(QCoreApplication::translate("MainWindow", "zakres osi poziomej", nullptr));
        lable_tytul_osY->setText(QCoreApplication::translate("MainWindow", "tytu\305\202 osi pionowej", nullptr));
        lable_tytul_osX->setText(QCoreApplication::translate("MainWindow", "tytu\305\202 osi poziomej", nullptr));
        siatka_osY->setText(QCoreApplication::translate("MainWindow", "siatka osi pionowej", nullptr));
        siatka_osX->setText(QCoreApplication::translate("MainWindow", "siatka osi poziomej", nullptr));
        legenda->setText(QCoreApplication::translate("MainWindow", "legenda", nullptr));
        rysuj->setText(QCoreApplication::translate("MainWindow", "rysuj wykres", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
