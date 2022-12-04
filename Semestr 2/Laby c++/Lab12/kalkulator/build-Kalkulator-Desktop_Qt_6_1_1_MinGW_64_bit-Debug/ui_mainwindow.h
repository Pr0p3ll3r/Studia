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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *liczba1;
    QLineEdit *liczba2;
    QPushButton *wyczysc;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *dodawanie;
    QPushButton *odejmowanie;
    QPushButton *dzielenie;
    QPushButton *mnozenie;
    QPushButton *wszystkie;
    QTextEdit *wynik;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(140, 80, 371, 164));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        liczba1 = new QLineEdit(verticalLayoutWidget);
        liczba1->setObjectName(QString::fromUtf8("liczba1"));

        horizontalLayout_3->addWidget(liczba1);

        liczba2 = new QLineEdit(verticalLayoutWidget);
        liczba2->setObjectName(QString::fromUtf8("liczba2"));

        horizontalLayout_3->addWidget(liczba2);

        wyczysc = new QPushButton(verticalLayoutWidget);
        wyczysc->setObjectName(QString::fromUtf8("wyczysc"));

        horizontalLayout_3->addWidget(wyczysc);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        dodawanie = new QPushButton(verticalLayoutWidget);
        dodawanie->setObjectName(QString::fromUtf8("dodawanie"));

        horizontalLayout_4->addWidget(dodawanie);

        odejmowanie = new QPushButton(verticalLayoutWidget);
        odejmowanie->setObjectName(QString::fromUtf8("odejmowanie"));

        horizontalLayout_4->addWidget(odejmowanie);

        dzielenie = new QPushButton(verticalLayoutWidget);
        dzielenie->setObjectName(QString::fromUtf8("dzielenie"));

        horizontalLayout_4->addWidget(dzielenie);

        mnozenie = new QPushButton(verticalLayoutWidget);
        mnozenie->setObjectName(QString::fromUtf8("mnozenie"));

        horizontalLayout_4->addWidget(mnozenie);


        verticalLayout->addLayout(horizontalLayout_4);

        wszystkie = new QPushButton(verticalLayoutWidget);
        wszystkie->setObjectName(QString::fromUtf8("wszystkie"));

        verticalLayout->addWidget(wszystkie);

        wynik = new QTextEdit(verticalLayoutWidget);
        wynik->setObjectName(QString::fromUtf8("wynik"));

        verticalLayout->addWidget(wynik);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
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
        wyczysc->setText(QCoreApplication::translate("MainWindow", "WYCZYSC", nullptr));
        dodawanie->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        odejmowanie->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        dzielenie->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        mnozenie->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        wszystkie->setText(QCoreApplication::translate("MainWindow", "wszystkie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
