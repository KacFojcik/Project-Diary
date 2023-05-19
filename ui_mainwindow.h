/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QTextEdit *txtSrodkowy;
    QPushButton *btnWczytajWsp;
    QTextEdit *txtGorny;
    QPushButton *btnZapiszWsp;
    QTextEdit *txtDolny;
    QPushButton *btnHaslo;
    QPushButton *btnDodaj;
    QPushButton *btnNastepne;
    QPushButton *btnKolor;
    QPushButton *btnPoprzednie;
    QPushButton *btnUsun;
    QLabel *label_3;
    QLabel *label_5;
    QCheckBox *chbSmutne;
    QCheckBox *chbNeutralne;
    QCheckBox *chbRadosne;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(356, 499);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 2);

        txtSrodkowy = new QTextEdit(centralwidget);
        txtSrodkowy->setObjectName(QString::fromUtf8("txtSrodkowy"));
        QFont font;
        font.setPointSize(10);
        txtSrodkowy->setFont(font);
        txtSrodkowy->setReadOnly(true);

        gridLayout->addWidget(txtSrodkowy, 3, 0, 1, 4);

        btnWczytajWsp = new QPushButton(centralwidget);
        btnWczytajWsp->setObjectName(QString::fromUtf8("btnWczytajWsp"));

        gridLayout->addWidget(btnWczytajWsp, 7, 2, 1, 1);

        txtGorny = new QTextEdit(centralwidget);
        txtGorny->setObjectName(QString::fromUtf8("txtGorny"));
        txtGorny->setFont(font);
        txtGorny->setReadOnly(true);

        gridLayout->addWidget(txtGorny, 1, 0, 1, 4);

        btnZapiszWsp = new QPushButton(centralwidget);
        btnZapiszWsp->setObjectName(QString::fromUtf8("btnZapiszWsp"));

        gridLayout->addWidget(btnZapiszWsp, 7, 1, 1, 1);

        txtDolny = new QTextEdit(centralwidget);
        txtDolny->setObjectName(QString::fromUtf8("txtDolny"));
        txtDolny->setFont(font);
        txtDolny->setReadOnly(true);

        gridLayout->addWidget(txtDolny, 5, 0, 1, 4);

        btnHaslo = new QPushButton(centralwidget);
        btnHaslo->setObjectName(QString::fromUtf8("btnHaslo"));

        gridLayout->addWidget(btnHaslo, 7, 0, 1, 1);

        btnDodaj = new QPushButton(centralwidget);
        btnDodaj->setObjectName(QString::fromUtf8("btnDodaj"));

        gridLayout->addWidget(btnDodaj, 6, 3, 1, 1);

        btnNastepne = new QPushButton(centralwidget);
        btnNastepne->setObjectName(QString::fromUtf8("btnNastepne"));
        QFont font1;
        font1.setPointSize(16);
        btnNastepne->setFont(font1);

        gridLayout->addWidget(btnNastepne, 6, 2, 1, 1);

        btnKolor = new QPushButton(centralwidget);
        btnKolor->setObjectName(QString::fromUtf8("btnKolor"));

        gridLayout->addWidget(btnKolor, 7, 3, 1, 1);

        btnPoprzednie = new QPushButton(centralwidget);
        btnPoprzednie->setObjectName(QString::fromUtf8("btnPoprzednie"));
        btnPoprzednie->setFont(font1);

        gridLayout->addWidget(btnPoprzednie, 6, 0, 1, 1);

        btnUsun = new QPushButton(centralwidget);
        btnUsun->setObjectName(QString::fromUtf8("btnUsun"));

        gridLayout->addWidget(btnUsun, 6, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 2);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 2);

        chbSmutne = new QCheckBox(centralwidget);
        chbSmutne->setObjectName(QString::fromUtf8("chbSmutne"));

        gridLayout->addWidget(chbSmutne, 9, 2, 1, 1);

        chbNeutralne = new QCheckBox(centralwidget);
        chbNeutralne->setObjectName(QString::fromUtf8("chbNeutralne"));

        gridLayout->addWidget(chbNeutralne, 9, 1, 1, 1);

        chbRadosne = new QCheckBox(centralwidget);
        chbRadosne->setObjectName(QString::fromUtf8("chbRadosne"));

        gridLayout->addWidget(chbRadosne, 9, 3, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);

        gridLayout->addWidget(label, 9, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 356, 20));
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
        label_4->setText(QCoreApplication::translate("MainWindow", "Poprzednie wspomnienie", nullptr));
        btnWczytajWsp->setText(QCoreApplication::translate("MainWindow", "Wczytaj Wpisy", nullptr));
        btnZapiszWsp->setText(QCoreApplication::translate("MainWindow", "Zapisz Wpisy", nullptr));
        btnHaslo->setText(QCoreApplication::translate("MainWindow", "Ustaw has\305\202o", nullptr));
        btnDodaj->setText(QCoreApplication::translate("MainWindow", "Dodaj wpis", nullptr));
        btnNastepne->setText(QCoreApplication::translate("MainWindow", "\342\226\274", nullptr));
        btnKolor->setText(QCoreApplication::translate("MainWindow", "Kolor", nullptr));
        btnPoprzednie->setText(QCoreApplication::translate("MainWindow", "\342\226\262", nullptr));
        btnUsun->setText(QCoreApplication::translate("MainWindow", "Usu\305\204 aktualne", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Aktualne wspomnienie", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Nastepne wspomnienie", nullptr));
        chbSmutne->setText(QCoreApplication::translate("MainWindow", "smutny", nullptr));
        chbNeutralne->setText(QCoreApplication::translate("MainWindow", "neutralny", nullptr));
        chbRadosne->setText(QCoreApplication::translate("MainWindow", "radosny", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Filtruj:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
