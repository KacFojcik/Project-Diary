#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>
#include "wpis.h"
#include <QFile>
#include <QKeyEvent>
#include "dodajwpis.h"
#include "haslo.h"
#include "program.h"

class Program;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,
               Program *app = nullptr);
    ~MainWindow();

    void wyswietlWpisy(QList<Wpis> lista);
    void zapiszWspomnienia();
    void odczytajWspomnienia();
    void spradzBtn();
    void setKolor(QColor k);


private slots:


    void on_btnDodaj_clicked();

    void on_btnPoprzednie_clicked();

    void on_btnNastepne_clicked();

    void on_btnUsun_clicked();

    void on_btnKolor_clicked();

    void on_btnHaslo_clicked();

    void on_btnZapiszWsp_clicked();

    void on_btnWczytajWsp_clicked();

    void on_chbNeutralne_stateChanged(int arg1);

    void on_chbSmutne_stateChanged(int arg1);

    void on_chbRadosne_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    Program *mainApp = nullptr;


    DodajWpis *dodajWpisOkienko;
    Haslo *hasloOkienko;

    void keyPressEvent(QKeyEvent *) override;

    void Poprzednie();
    void Nastepne();
};
#endif // MAINWINDOW_H
