#ifndef PROGRAM_H
#define PROGRAM_H
#include <QObject>
#include "wpis.h"
#include "mainwindow.h"
#include <QFileDialog>
#include <QDir>

class MainWindow;

class Program : public QObject
{
    Q_OBJECT
public:
    explicit Program(QObject *parent = nullptr)
        :QObject (parent){}

    void setGUI(MainWindow *ui = nullptr) {GUI = ui;}

    void dodajWpis(QString tresc, QDateTime data, QString nastroj);
    void ZapiszWspomniena();
    void odczytajWspomnienia();
    void usunZListy();
    void wczytajWsp();
    void zapiszWsp();
    void filtruj(QString nastroj, int zaznaczony);


    void setIndexAkt(int i) {m_indexAktualny = i;}
    void setLista(QList<Wpis> l) {lista = l;}
    void setKolor(QColor k) {kolor = k;}
    void setHaslo(QString h) {haslo = h;}

    int getIndexAkt() const {return m_indexAktualny;}
    QList<Wpis> getLista() const {return lista;}
    QColor getKolor() const {return kolor;}
    QString getHaslo() const {return haslo;}
    int getListaAktualna() const {return listaAktualna;}
     QList<Wpis> getListaOdfiltrowana() const {return listaOdfiltrowana;}


private:
    MainWindow *GUI = nullptr;

    QList<Wpis> lista;
    QList<Wpis> listaOdfiltrowana;
    int listaAktualna = 1;
    int m_index;
    int m_indexAktualny;
    QString haslo;
    QColor kolor;
};

#endif // PROGRAM_H
