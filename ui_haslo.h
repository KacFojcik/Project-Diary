/********************************************************************************
** Form generated from reading UI file 'haslo.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HASLO_H
#define UI_HASLO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Haslo
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *txtHaslo;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Haslo)
    {
        if (Haslo->objectName().isEmpty())
            Haslo->setObjectName(QString::fromUtf8("Haslo"));
        Haslo->resize(181, 96);
        gridLayout = new QGridLayout(Haslo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Haslo);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        txtHaslo = new QLineEdit(Haslo);
        txtHaslo->setObjectName(QString::fromUtf8("txtHaslo"));
        txtHaslo->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(txtHaslo, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Haslo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(Haslo);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Haslo, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Haslo, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Haslo);
    } // setupUi

    void retranslateUi(QDialog *Haslo)
    {
        Haslo->setWindowTitle(QCoreApplication::translate("Haslo", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Haslo", "Podaj has\305\202o", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Haslo: public Ui_Haslo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HASLO_H
