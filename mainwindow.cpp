#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wpis.h"
#include <QtAlgorithms>
#include <QFontMetrics>
#include <algorithm>
#include <QDebug>
#include <QColorDialog>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent, Program *app)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      mainApp(app)
{
    app->setGUI(this);
    ui->setupUi(this);
   // ui->dtData->setDateTime(QDateTime::currentDateTime());
    ui->btnNastepne->setEnabled(false);
    ui->btnPoprzednie->setEnabled(false);
    odczytajWspomnienia();
    if(mainApp->getLista().isEmpty())
        ui->btnUsun->setEnabled(false);
    wyswietlWpisy(mainApp->getLista());

    if(mainApp->getHaslo() != nullptr)
    {
        bool czyPoprawne = false;
            do
            {
                hasloOkienko = new Haslo(nullptr);
                int result = hasloOkienko->exec();
                if(result)
                {
                    if(mainApp->getHaslo() != hasloOkienko->getHaslo())
                    {
                        QMessageBox msg;
                        msg.setText("Zle haslo!");
                        msg.exec();
                    }
                    else
                    {
                        czyPoprawne = true;
                    }

                }
                else
                {
                   exit(1);
                }

            }
            while(!czyPoprawne);

            delete hasloOkienko;
    }
}

MainWindow::~MainWindow()
{
    zapiszWspomnienia();
    delete ui;
}



void MainWindow::wyswietlWpisy(QList<Wpis> lista)
{
    ui->txtSrodkowy->clear();
    ui->txtGorny->clear();
    ui->txtDolny->clear();

    QString brak = "<html><i><font color=red>Brak wspomnienia</font></i></html>";

    if(!lista.isEmpty())
    {

//qDebug() << QString::number(m_indexAktualny);
        QString data = "<html><b>" +  lista[mainApp->getIndexAkt()].getData().toString() + "</b></html>" + "("+lista[mainApp->getIndexAkt()].getNastroj() +")";
        ui->txtSrodkowy->append(data);
        ui->txtSrodkowy->append(lista[mainApp->getIndexAkt()].getTresc());


        if(mainApp->getIndexAkt()-1 >= 0)
        {
        QString dataG = "<html><b>" +  lista[mainApp->getIndexAkt()-1].getData().toString() + "</b></html>" + "("+lista[mainApp->getIndexAkt()-1].getNastroj() +")";
        ui->txtGorny->append(dataG);
        ui->txtGorny->append(lista[mainApp->getIndexAkt()-1].getTresc());
        }
        else
        {
            ui->txtGorny->append(brak);
        }

        if(mainApp->getIndexAkt()+1 < lista.size())
        {
        QString dataD = "<html><b>" +  lista[mainApp->getIndexAkt()+1].getData().toString() + "</b></html>" + "("+lista[mainApp->getIndexAkt()+1].getNastroj() +")";
        ui->txtDolny->append(dataD);
        ui->txtDolny->append(lista[mainApp->getIndexAkt()+1].getTresc());
        }
        else
        {
            ui->txtDolny->append(brak);
        }

        if(mainApp->getIndexAkt() > 0)
            ui->btnPoprzednie->setEnabled(true);
        if(mainApp->getIndexAkt() < lista.size()-1)
            ui->btnNastepne->setEnabled(true);
    }
    else
    {
        ui->txtGorny->append(brak);
        ui->txtSrodkowy->append(brak);
        ui->txtDolny->append(brak);

        ui->btnNastepne->setEnabled(false);
        ui->btnPoprzednie->setEnabled(false);
    }
}



void MainWindow::on_btnDodaj_clicked()
{
    //dodajWpis(ui->txtWpis->toPlainText(),ui->dtData->dateTime());
    dodajWpisOkienko = new DodajWpis(nullptr);

    int result = dodajWpisOkienko->exec();

    if(result)
        mainApp->dodajWpis(dodajWpisOkienko->getTrescWpisu(), dodajWpisOkienko->getDateWpisu(), dodajWpisOkienko->getNastroj());


    delete dodajWpisOkienko;
}

void MainWindow::Poprzednie()
{
    if(mainApp->getListaAktualna() == 1)
    {
        if(mainApp->getIndexAkt() > 0)
        {
            mainApp->setIndexAkt(mainApp->getIndexAkt() - 1);

            if(!ui->btnNastepne->isEnabled())
                ui->btnNastepne->setEnabled(true);
        }
        if(mainApp->getIndexAkt()==0)
            ui->btnPoprzednie->setEnabled(false);


        wyswietlWpisy(mainApp->getLista());
    }
    else if (mainApp->getListaAktualna() == 2)
    {
        if(mainApp->getIndexAkt() > 0)
                {
                    mainApp->setIndexAkt(mainApp->getIndexAkt() - 1);

                    if(!ui->btnNastepne->isEnabled())
                        ui->btnNastepne->setEnabled(true);
                }
                if(mainApp->getIndexAkt()==0)
                    ui->btnPoprzednie->setEnabled(false);
        wyswietlWpisy(mainApp->getListaOdfiltrowana());
    }

}

void MainWindow::Nastepne()
{
    if(mainApp->getListaAktualna() == 1)
    {
    if(mainApp->getIndexAkt() < mainApp->getLista().size())
    {
        mainApp->setIndexAkt(mainApp->getIndexAkt() + 1);
        if(!ui->btnPoprzednie->isEnabled())
            ui->btnPoprzednie->setEnabled(true);
    }
    if(mainApp->getIndexAkt() == mainApp->getLista().size()-1)
        ui->btnNastepne->setEnabled(false);

    wyswietlWpisy(mainApp->getLista());
    }
    else if (mainApp->getListaAktualna() == 2)
    {
        if(mainApp->getIndexAkt() < mainApp->getListaOdfiltrowana().size())
        {
            mainApp->setIndexAkt(mainApp->getIndexAkt() + 1);
            if(!ui->btnPoprzednie->isEnabled())
                ui->btnPoprzednie->setEnabled(true);
        }
        if(mainApp->getIndexAkt() == mainApp->getListaOdfiltrowana().size()-1)
            ui->btnNastepne->setEnabled(false);

        wyswietlWpisy(mainApp->getListaOdfiltrowana());
    }
}


void MainWindow::on_btnPoprzednie_clicked()
{
    Poprzednie();
}


void MainWindow::on_btnNastepne_clicked()
{
    Nastepne();
}

void MainWindow::spradzBtn()
{
    if(!ui->btnUsun->isEnabled())
        ui->btnUsun->setEnabled(true);

    if(mainApp->getIndexAkt() > 0)
        ui->btnPoprzednie->setEnabled(true);
    else
        ui->btnPoprzednie->setEnabled(false);
    if(mainApp->getIndexAkt() < mainApp->getLista().size()-1)
        ui->btnNastepne->setEnabled(true);
    else
        ui->btnNastepne->setEnabled(false);
}


void MainWindow::zapiszWspomnienia()
{
    mainApp->ZapiszWspomniena();
}

void MainWindow::odczytajWspomnienia()
{
    mainApp->odczytajWspomnienia();
}

void MainWindow::on_btnUsun_clicked()
{

    mainApp->usunZListy();
   int m_indexAktualny = mainApp->getIndexAkt();
   // m_index--;

    if(m_indexAktualny < 0)
        ui->btnUsun->setEnabled(false);
    else if (m_indexAktualny > mainApp->getLista().size()-1)
        ui->btnUsun->setEnabled(false);



         if(m_indexAktualny > 0)
             ui->btnPoprzednie->setEnabled(true);
         else
             ui->btnPoprzednie->setEnabled(false);
         if(m_indexAktualny < mainApp->getLista().size()-1)
             ui->btnNastepne->setEnabled(true);
         else
             ui->btnNastepne->setEnabled(false);


         // if(!lista.isEmpty())
               wyswietlWpisy(mainApp->getLista());

         //qDebug() << QString::number(m_indexAktualny);

}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    int keyCode = event->key();

    if(keyCode == Qt::Key_W)
        Nastepne();
    else if (keyCode == Qt::Key_S)
        Poprzednie();


//    switch (keyCode)
//    {
//        case Qt::Key_Up:
//            Poprzednie();
//        break;
//        case Qt::Key_Down:
//            Nastepne();
//        break;
//    }
}


void MainWindow::setKolor(QColor k)
{
    ui->txtGorny->setTextColor(k);
    ui->txtSrodkowy->setTextColor(k);
    ui->txtDolny->setTextColor(k);
}

void MainWindow::on_btnKolor_clicked()
{
    QColorDialog *okienkoKolor = new QColorDialog(nullptr);

    int result = okienkoKolor->exec();

   if(result)
   {
    //qDebug() << okienkoKolor->currentColor().toRgb();
       mainApp->setKolor(okienkoKolor->currentColor());
   ui->txtGorny->setTextColor(mainApp->getKolor());
   ui->txtSrodkowy->setTextColor(mainApp->getKolor());
   ui->txtDolny->setTextColor(mainApp->getKolor());
   }

    delete okienkoKolor;

    wyswietlWpisy(mainApp->getLista());
}


void MainWindow::on_btnHaslo_clicked()
{
    hasloOkienko = new Haslo(nullptr);

    int result = hasloOkienko->exec();

    if(result)
    {
        mainApp->setHaslo(hasloOkienko->getHaslo());
        //qDebug() << haslo;
    }

    delete hasloOkienko;
}


void MainWindow::on_btnZapiszWsp_clicked()
{
    mainApp->zapiszWsp();
}


void MainWindow::on_btnWczytajWsp_clicked()
{
    mainApp->wczytajWsp();
    wyswietlWpisy(mainApp->getLista());
}


void MainWindow::on_chbNeutralne_stateChanged(int arg1)
{
    mainApp->filtruj(ui->chbNeutralne->text(), arg1);
}


void MainWindow::on_chbSmutne_stateChanged(int arg1)
{
    mainApp->filtruj(ui->chbSmutne->text(), arg1);
}


void MainWindow::on_chbRadosne_stateChanged(int arg1)
{
    mainApp->filtruj(ui->chbRadosne->text(), arg1);
}

