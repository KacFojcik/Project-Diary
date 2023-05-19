/********************************************************************************
** Form generated from reading UI file 'dodajwpis.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DODAJWPIS_H
#define UI_DODAJWPIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DodajWpis
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QTextEdit *txtTrescWpisu;
    QDateTimeEdit *dtDataWpisu;
    QComboBox *cbNastroj;

    void setupUi(QDialog *DodajWpis)
    {
        if (DodajWpis->objectName().isEmpty())
            DodajWpis->setObjectName(QString::fromUtf8("DodajWpis"));
        DodajWpis->resize(433, 313);
        gridLayout = new QGridLayout(DodajWpis);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DodajWpis);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DodajWpis);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        gridLayout->addWidget(buttonBox, 2, 2, 1, 1);

        txtTrescWpisu = new QTextEdit(DodajWpis);
        txtTrescWpisu->setObjectName(QString::fromUtf8("txtTrescWpisu"));
        QFont font;
        font.setPointSize(10);
        txtTrescWpisu->setFont(font);

        gridLayout->addWidget(txtTrescWpisu, 1, 0, 1, 3);

        dtDataWpisu = new QDateTimeEdit(DodajWpis);
        dtDataWpisu->setObjectName(QString::fromUtf8("dtDataWpisu"));

        gridLayout->addWidget(dtDataWpisu, 2, 0, 1, 1);

        cbNastroj = new QComboBox(DodajWpis);
        cbNastroj->addItem(QString());
        cbNastroj->addItem(QString());
        cbNastroj->addItem(QString());
        cbNastroj->setObjectName(QString::fromUtf8("cbNastroj"));

        gridLayout->addWidget(cbNastroj, 2, 1, 1, 1);


        retranslateUi(DodajWpis);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DodajWpis, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DodajWpis, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DodajWpis);
    } // setupUi

    void retranslateUi(QDialog *DodajWpis)
    {
        DodajWpis->setWindowTitle(QCoreApplication::translate("DodajWpis", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DodajWpis", "Tresc wpisu", nullptr));
        cbNastroj->setItemText(0, QCoreApplication::translate("DodajWpis", "neutralny", nullptr));
        cbNastroj->setItemText(1, QCoreApplication::translate("DodajWpis", "smutny", nullptr));
        cbNastroj->setItemText(2, QCoreApplication::translate("DodajWpis", "radosny", nullptr));

    } // retranslateUi

};

namespace Ui {
    class DodajWpis: public Ui_DodajWpis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DODAJWPIS_H
