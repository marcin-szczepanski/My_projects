#include "tabela.h"

Tabela::Tabela(QString plik):mFile(plik)
{
    mFile.open(QIODevice::ReadWrite);
}

QStringList Tabela::pobierzWiersz(int n)
{
    QString wiersz;
    for (int i = 0; i <= n; i++)
        wiersz = QString(mFile.readLine());
    wiersz.chop(1);
    mFile.reset();
    return wiersz.split(";");
}

void Tabela::edytujWiersz(int n, QStringList wartosci)
{
    QFile tmp("tmp" + mFile.fileName());
    tmp.open(QIODevice::WriteOnly);
    for (int i = 0; i < this->pobierzLiczbeWierszy(); i++)
    {
        if (i == n)
        {
            // validate input
            for (int i = 0; i < wartosci.count(); i++)
                wartosci[i] = wartosci[i].replace("\n", "NL").replace(";", ",");
            // go to end of file
            tmp.seek(tmp.size());
            QString wiersz = wartosci.join(";").append("\n");
            tmp.write(wiersz.toUtf8());
        }
        else
        {
            QString row = this->pobierzWiersz(i).join(";").append("\n");
            tmp.write(row.toUtf8());
        }
    }
    // replace old file with updated one
    QString nazwaPliku = mFile.fileName();
    mFile.remove();
    tmp.rename(nazwaPliku);
    tmp.close();
    mFile.open(QIODevice::ReadWrite);



}

void Tabela::usunWiersz(int n)
{
    QFile tmp("tmp" + mFile.fileName());
    tmp.open(QIODevice::WriteOnly);
    for (int i = 0; i < this->pobierzLiczbeWierszy(); i++)
    {
        if (i == n) {continue;}
        QString row = this->pobierzWiersz(i).join(";").append("\n");
        tmp.write(row.toUtf8());
    }
    // replace old file with updated one
    QString nazwaPliku = mFile.fileName();
    mFile.remove();
    tmp.rename(nazwaPliku);
    tmp.close();
    mFile.open(QIODevice::ReadWrite);
}

void Tabela::wstawWiersz(QStringList wartosci)
{
    // validate input
    for (int i = 0; i < wartosci.count(); i++)
        wartosci[i] = wartosci[i].replace("\n", "NL").replace(";", ",");
    // go to end of file
    mFile.seek(mFile.size());
    QString wiersz = wartosci.join(";").append("\n");
    mFile.write(wiersz.toUtf8());
    mFile.reset();
}

int Tabela::pobierzLiczbeWierszy()
{
    int n = QString(mFile.readAll()).count("\n");
    mFile.reset();
    return n;
}

void Tabela::czysc()
{
    mFile.remove();
    mFile.open(QIODevice::ReadWrite);
}

Tabela::~Tabela()
{
    mFile.close();
}
