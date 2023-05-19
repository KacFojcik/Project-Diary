#include "program.h"
#include <QDebug>

bool isLess(Wpis& w1, Wpis& w2)
{
    return !(w1 > w2);
}


void Program::dodajWpis(QString tresc, QDateTime data, QString nastroj)
{
    bool takieSame = false;
    int index = 0;
    Wpis wpis(tresc,data, nastroj);
    foreach(Wpis w, lista)
    {
        if(wpis == w)
        {
            takieSame = true;
            break;
        }
        index++;
    }

    if(takieSame)
            lista.replace(index,wpis);
    else
        lista.append(wpis);

    m_indexAktualny = lista.size() - 1;

    Wpis w = lista[m_indexAktualny];

    std::sort(lista.begin(),lista.end(), isLess);

    m_indexAktualny = lista.indexOf(w);


    GUI->wyswietlWpisy(lista);
   // wyswietlWpisy();

    //ui->txtWpis->clear();


}

void Program::usunZListy()
{
     lista.removeAt(m_indexAktualny);

     if(m_indexAktualny == 0)
         m_indexAktualny++;
     else
         m_indexAktualny--;
}

void Program::ZapiszWspomniena()
{
    QFile plik("wspomnienia.txt");
    if(plik.open(QIODevice::WriteOnly | QIODevice::Text))
       {
         QTextStream outStream(&plik);

         foreach(Wpis w, lista)
         {
             outStream  << w.getTresc() +" " + w.getData().toString() + " " + w.getNastroj() + "\n";

         }
          plik.close();
    }

    QFile plikIndex("index.txt");
    if(plikIndex.open(QIODevice::WriteOnly | QIODevice::Text))
       {
         QTextStream outStream(&plikIndex);
         outStream << m_indexAktualny;
         plikIndex.close();
    }

    QFile plikKolor("kolor.txt");
    if(plikKolor.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream outStream(&plikKolor);


        QString kolorText = QString("%1 %2 %3 %4").arg(kolor.red())
                .arg(kolor.green())
                .arg(kolor.blue())
                .arg(kolor.alpha());

        outStream << kolorText;
        plikKolor.close();
    }

    QFile plikHaslo("haslo.txt");
     if(plikHaslo.open(QIODevice::WriteOnly | QIODevice::Text))
     {
        QTextStream outStream(&plikHaslo);

        outStream << haslo;
        plikHaslo.close();
     }
}

void Program::odczytajWspomnienia()
{
    QFile plikIndex("index.txt");
    if(plikIndex.open(QIODevice::ReadOnly | QIODevice::Text))
       {
         QTextStream inStream(&plikIndex);
         int x;
         inStream >> x;
        //qDebug() << QString::number(x);
         m_indexAktualny = x;
         plikIndex.close();
  }



   QFile plik("wspomnienia.txt");
   if(plik.open(QIODevice::ReadOnly | QIODevice::Text))
   {
       QTextStream inStream(&plik);

       while (!inStream.atEnd())
       {
           QString wpis = inStream.readLine();
            QStringList listaWpisu = wpis.split(" ");
            QString tresc;
            QString data;
            QString nastroj;
            for(int i = 0; i < listaWpisu.size()-6; i++)
                tresc += listaWpisu[i]+ " ";

            for(int i = 5; i > 0; i--)
                data += listaWpisu[listaWpisu.size()-(i+1)] + " ";

            nastroj = listaWpisu[listaWpisu.size() - 1];

            QDateTime dt = QDateTime::fromString(data);
             Wpis w(tresc,dt, nastroj);
          //qDebug() << w.getTresc() + w.getData().toString();
          lista.append(w);
       }

        if(lista.size()>0)
        GUI->wyswietlWpisy(lista);

        plik.close();
   }

   QFile plikKolor("kolor.txt");
   if(plikKolor.open(QIODevice::ReadOnly | QIODevice::Text))
   {
       QTextStream inStream(&plikKolor);

       QString c = inStream.readLine();

       QStringList lista = c.split(" ");

      kolor = QColor::fromRgba(qRgba(lista[0].toUInt(), lista[1].toUInt(), lista[2].toUInt(), lista[3].toUInt()));

      //qDebug() << kolor;
     GUI->setKolor(kolor);

      plikKolor.close();
   }

   QFile plikHaslo("haslo.txt");
    if(plikHaslo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QTextStream inStream(&plikHaslo);

       haslo = inStream.readLine();
       plikHaslo.close();
    }

}

void Program::zapiszWsp()
{
    QString file = QFileDialog::getSaveFileName(GUI, "Zapisz wspomnienia", QDir::homePath());

    QFile plik(file);
    if(plik.open(QIODevice::WriteOnly | QIODevice::Text))
       {
         QTextStream outStream(&plik);

         foreach(Wpis w, lista)
         {
             outStream  << w.getTresc() +" " + w.getData().toString() + " " + w.getNastroj() + "\n";

         }
          plik.close();
    }

}

void Program::wczytajWsp()
{
    QString file = QFileDialog::getOpenFileName(GUI, "Wczytaj wspomnienia", QDir::homePath());

    QFile plik(file);
    if(plik.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream inStream(&plik);
        lista.clear();
        m_indexAktualny = 0;
        while (!inStream.atEnd())
        {
            QString wpis = inStream.readLine();
             QStringList listaWpisu = wpis.split(" ");
             QString tresc;
             QString data;
             QString nastroj;
             for(int i = 0; i < listaWpisu.size()-6; i++)
                 tresc += listaWpisu[i]+ " ";

             for(int i = 5; i > 0; i--)
                 data += listaWpisu[listaWpisu.size()-(i+1)] + " ";

             nastroj = listaWpisu[listaWpisu.size() - 1];

             QDateTime dt = QDateTime::fromString(data);
              Wpis w(tresc,dt, nastroj);
           //qDebug() << w.getTresc() + w.getData().toString();
           lista.append(w);
        }

         if(lista.size()>0)
         GUI->wyswietlWpisy(lista);

         plik.close();
    }
}

void Program::filtruj(QString nastroj, int zaznaczony)
{
    listaOdfiltrowana.clear();

    if(nastroj == "neutralny" && zaznaczony)
    {
        foreach(Wpis w, lista)
        {
            if(w.getNastroj() == "neutralny")
                listaOdfiltrowana.append(w);
        }
    }


    if(nastroj == "smutny" && zaznaczony)
    {
        foreach(Wpis w, lista)
        {
            if(w.getNastroj() == "smutny")
                listaOdfiltrowana.append(w);
        }
    }


    if(nastroj == "radosny" && zaznaczony)
    {
        foreach(Wpis w, lista)
        {
            if(w.getNastroj() == "radosny")
                listaOdfiltrowana.append(w);
        }
    }

    if(!listaOdfiltrowana.isEmpty())
        m_indexAktualny = 0;
    GUI->wyswietlWpisy(listaOdfiltrowana);
    listaAktualna = 2;

}



