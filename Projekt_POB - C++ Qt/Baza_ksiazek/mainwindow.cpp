#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabela.h"

void MainWindow::wczytajDaneDoProgramu()
{
    QFile plik="baza.txt";
    plik.open(QIODevice::ReadWrite);
    QString w;
    w=QString(plik.readLine());

    if (w!="")
    {
        plik.close();
        Tabela tabela("baza.txt");

        int n=tabela.pobierzLiczbeWierszy();

        for (int i=0; i<n; i++)
        {
            QStringList wiersz=tabela.pobierzWiersz(i);
            QString st=wiersz.takeFirst();
            QString tyt=wiersz.takeFirst();
            QString aut=wiersz.takeFirst();
            QString gat=wiersz.takeFirst();
            QString ilstr=wiersz.takeFirst();
            QString wyd=wiersz.takeFirst();
            QString rok=wiersz.takeFirst();
            QString kl=wiersz.takeFirst();
            QString form=wiersz.takeFirst();
            QString okl=wiersz.takeFirst();
            QString roz=wiersz.takeFirst();

            int r=i;
            ui->lista_ksiazek->insertRow(r);
            ui->lista_ksiazek->setItem(r,0,new QTableWidgetItem(st));
            ui->lista_ksiazek->setItem(r,1,new QTableWidgetItem(tyt));
            ui->lista_ksiazek->setItem(r,2,new QTableWidgetItem(aut));
            ui->lista_ksiazek->setItem(r,3,new QTableWidgetItem(gat));
            ui->lista_ksiazek->setItem(r,4,new QTableWidgetItem(ilstr));
            ui->lista_ksiazek->setItem(r,5,new QTableWidgetItem(wyd));
            ui->lista_ksiazek->setItem(r,6,new QTableWidgetItem(rok));
            ui->lista_ksiazek->setItem(r,7,new QTableWidgetItem(kl));
            ui->lista_ksiazek->setItem(r,8,new QTableWidgetItem(form));
            ui->lista_ksiazek->setItem(r,9,new QTableWidgetItem(okl));
            ui->lista_ksiazek->setItem(r,10,new QTableWidgetItem(roz));
        }
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->wczytajDaneDoProgramu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

template <class klasa>
klasa* MainWindow::uzupelnijObiekt()
{
    klasa * a;
    a=new klasa;

    a->ustawTytul(ui->tytulEdit->text());
    ui->tytulEdit->clear();
    a->ustawAutora(ui->autorEdit->text());
    ui->autorEdit->clear();
    a->ustawRokWydania(ui->rokWydaniaEdit->text());
    ui->rokWydaniaEdit->clear();
    a->ustawWydawnictwo(ui->wydawnictwoEdit->text());
    ui->wydawnictwoEdit->clear();
    a->ustawGatunek(ui->gatunekEdit->text());
    ui->gatunekEdit->clear();
    a->ustawIloscStron(ui->iloscStronEdit->text());
    ui->iloscStronEdit->clear();

    if(ui->czytana->isChecked())
        a->ustawStan("W TRAKCIE CZYTANIA");
    else if(ui->nieprzeczytana->isChecked())
        a->ustawStan("NIEPRZECZYTANE");
    else if(ui->przeczytana->isChecked())
        a->ustawStan("PRZECZYTANE");
    else
        a->ustawStan("DO KUPIENIA");

    return a;
}

template <class klasa>
void MainWindow::wstawDoTabeli(klasa* wsk_obiekt)
{
    QString tyt=wsk_obiekt->podajTytul();
    QString aut=wsk_obiekt->podajAutora();
    QString r=wsk_obiekt->podajRokWydania();
    QString wyd=wsk_obiekt->podajWydawnictwo();
    QString gat=wsk_obiekt->podajGatunek();
    QString st=wsk_obiekt->podajStan();
    QString ilstr=wsk_obiekt->podajIloscStron();
    QString form=wsk_obiekt->podajFormat();
    QString okl=wsk_obiekt->podajOkladke();
    QString kl=wsk_obiekt->podajKlase();
    QString roz=wsk_obiekt->podajRozmiar();

    ui->lista_ksiazek->insertRow(ui->lista_ksiazek->rowCount());
    ui->lista_ksiazek->setItem(ui->lista_ksiazek->rowCount()-1,0,new QTableWidgetItem(st));
    ui->lista_ksiazek->setItem(ui->lista_ksiazek->rowCount()-1,1,new QTableWidgetItem(tyt));
    ui->lista_ksiazek->setItem(ui->lista_ksiazek->rowCount()-1,2,new QTableWidgetItem(aut));
    ui->lista_ksiazek->setItem(ui->lista_ksiazek->rowCount()-1,3,new QTableWidgetItem(gat));
    ui->lista_ksiazek->setItem(ui->lista_ksiazek->rowCount()-1,4,new QTableWidgetItem(ilstr));
    ui->lista_ksiazek->setItem(ui->lista_ksiazek->rowCount()-1,5,new QTableWidgetItem(wyd));
    ui->lista_ksiazek->setItem(ui->lista_ksiazek->rowCount()-1,6,new QTableWidgetItem(r));
    ui->lista_ksiazek->setItem(ui->lista_ksiazek->rowCount()-1,7,new QTableWidgetItem(kl));
    ui->lista_ksiazek->setItem(ui->lista_ksiazek->rowCount()-1,8,new QTableWidgetItem(form));
    ui->lista_ksiazek->setItem(ui->lista_ksiazek->rowCount()-1,9,new QTableWidgetItem(okl));
    ui->lista_ksiazek->setItem(ui->lista_ksiazek->rowCount()-1,10,new QTableWidgetItem(roz));

    Tabela tabela("baza.txt");
    tabela.wstawWiersz(QStringList() << st << tyt << aut << gat << ilstr << wyd << r << kl << form << okl << roz);
}

void MainWindow::on_dodajButton_clicked()
{
    ui->infoBox->clear();
    if(ui->rodzajKsiazki->currentIndex()==0)
    {
        Papierowa *wsk_obiekt=uzupelnijObiekt<Papierowa>();

        if (ui->a4->isChecked())
            wsk_obiekt->ustawFormat(A4);
        else if (ui->a5->isChecked())
            wsk_obiekt->ustawFormat(A5);
        else if (ui->b5->isChecked())
            wsk_obiekt->ustawFormat(B5);
        else if (ui->b6->isChecked())
            wsk_obiekt->ustawFormat(B6);
        else
            wsk_obiekt->ustawFormat(INNY);

        ui->ks_inny->setChecked(true);

        if (ui->miekka->isChecked())
            wsk_obiekt->ustawOkladke(miekka);
        else
            wsk_obiekt->ustawOkladke(twarda);
        wstawDoTabeli<Papierowa>(wsk_obiekt);

    }
    if (ui->rodzajKsiazki->currentIndex()==2)
    {
        Audiobook *wsk_obiekt=uzupelnijObiekt<Audiobook>();

        if(ui->mp3->isChecked())
            wsk_obiekt->ustawFormat(mp3);
        else if(ui->ogg->isChecked())
            wsk_obiekt->ustawFormat(ogg);
        else if(ui->cd->isChecked())
            wsk_obiekt->ustawFormat(cd);
        else if(ui->kaseta->isChecked())
            wsk_obiekt->ustawFormat(kaseta);
        else
            wsk_obiekt->ustawFormat(inny);

        ui->innyAudiobook->setChecked(true);

        wsk_obiekt->ustawRozmiar(ui->rozmiarAudiobooka->text());
        ui->rozmiarAudiobooka->clear();

        wstawDoTabeli<Audiobook>(wsk_obiekt);
    }
    if (ui->rodzajKsiazki->currentIndex()==1)
    {
        Ebook *wsk_obiekt=uzupelnijObiekt<Ebook>();

        if(ui->pdf->isChecked())
            wsk_obiekt->ustawFormat(pdf);
        else if(ui->mobi->isChecked())
            wsk_obiekt->ustawFormat(mobi);
        else if(ui->ePub->isChecked())
            wsk_obiekt->ustawFormat(ePub);
        else
            wsk_obiekt->ustawFormat(Inny);

        ui->innyEbook->setChecked(true);

        wsk_obiekt->ustawRozmiar(ui->rozmiarEbookaEdit->text());
        ui->rozmiarEbookaEdit->clear();

        wstawDoTabeli<Ebook>(wsk_obiekt);
    }
}

void MainWindow::on_usun_clicked()
{
    ui->infoBox->clear();
    int rowNum = ui->lista_ksiazek->currentRow();
       if (rowNum != -1)
       {
           ui->lista_ksiazek->removeRow(rowNum);
           Tabela tabela("baza.txt");
           tabela.usunWiersz(rowNum);
       }
       else
           ui->infoBox->setText("Nie wybrano pozycji!");
}

void MainWindow::on_edytujButton_clicked()
{
    int r = ui->lista_ksiazek->currentRow();
    if (r != -1)
    {
        Tabela tabela("baza.txt");

        QString st;
        if(ui->czytana->isChecked())
            st="W TRAKCIE CZYTANIA";
        else if(ui->nieprzeczytana->isChecked())
            st="NIEPRZECZYTANE";
        else if(ui->przeczytana->isChecked())
            st="PRZECZYTANE";
        else
            st="DO KUPIENIA";

        QString tyt=ui->lista_ksiazek->item(r,1)->text();
        QString aut=ui->lista_ksiazek->item(r,2)->text();
        QString gat=ui->lista_ksiazek->item(r,3)->text();
        QString ilstr=ui->lista_ksiazek->item(r,4)->text();
        QString wyd=ui->lista_ksiazek->item(r,5)->text();
        QString rok=ui->lista_ksiazek->item(r,6)->text();

        QString kl;
        QString form;
        QString okl="nie dotyczy";
        QString roz="nie dotyczy";
        if(ui->rodzajKsiazki->currentIndex()==0)
        {
            kl="wersja papierowa";

            if (ui->a4->isChecked())
                form="A4";
            else if (ui->a5->isChecked())
                form="A5";
            else if (ui->b5->isChecked())
                form="B5";
            else if (ui->b6->isChecked())
                form="B6";
            else
                form="inny";

            ui->ks_inny->setChecked(true);

            if (ui->miekka->isChecked())
                okl="miękka";
            else
                okl="twarda";
        }
        else if (ui->rodzajKsiazki->currentIndex()==1)
        {
            kl="e-book";

            if(ui->pdf->isChecked())
                form="pdf";
            else if(ui->mobi->isChecked())
                form="mobi";
            else if(ui->ePub->isChecked())
                form="ePub";
            else
                form="inny";

            ui->innyEbook->setChecked(true);

            roz=ui->rozmiarEbookaEdit->text();
            if (ui->rozmiarEbookaEdit->text()=="")
               roz="użyj pola tekstowego rozmiar do edycji tego elementu!";
        }
        else
        {
            kl="audiobook";

            if(ui->mp3->isChecked())
                form="mp3";
            else if(ui->ogg->isChecked())
                form="ogg";
            else if(ui->cd->isChecked())
                form="CD";
            else if(ui->kaseta->isChecked())
                form="kaseta";
            else
                form="inny";

            ui->innyAudiobook->setChecked(true);

            roz=ui->rozmiarAudiobooka->text();
            if (ui->rozmiarAudiobooka->text()=="")
               roz="użyj pola tekstowego rozmiar do edycji tego elementu!";
        }

        ui->lista_ksiazek->removeRow(r);

        ui->lista_ksiazek->insertRow(r);
        ui->lista_ksiazek->setItem(r,0,new QTableWidgetItem(st));
        ui->lista_ksiazek->setItem(r,1,new QTableWidgetItem(tyt));
        ui->lista_ksiazek->setItem(r,2,new QTableWidgetItem(aut));
        ui->lista_ksiazek->setItem(r,3,new QTableWidgetItem(gat));
        ui->lista_ksiazek->setItem(r,4,new QTableWidgetItem(ilstr));
        ui->lista_ksiazek->setItem(r,5,new QTableWidgetItem(wyd));
        ui->lista_ksiazek->setItem(r,6,new QTableWidgetItem(rok));
        ui->lista_ksiazek->setItem(r,7,new QTableWidgetItem(kl));
        ui->lista_ksiazek->setItem(r,8,new QTableWidgetItem(form));
        ui->lista_ksiazek->setItem(r,9,new QTableWidgetItem(okl));
        ui->lista_ksiazek->setItem(r,10,new QTableWidgetItem(roz));

        tabela.usunWiersz(r);
        tabela.wstawWiersz(QStringList() << st << tyt << aut << gat << ilstr << wyd << rok << kl << form << okl << roz);

    }
    else
        ui->infoBox->setText("Nie wybrano pozycji!");
}
