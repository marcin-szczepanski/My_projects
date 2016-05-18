
#ifndef TABELA_H
#define TABELA_H

#include <QString>
#include <QStringList>
#include <QFile>
#include <QDebug>

class Tabela
{
public:
    Tabela(QString plik);
    QStringList pobierzWiersz(int n);
    void edytujWiersz(int n, QStringList wartosci);
    void usunWiersz(int n);
    void wstawWiersz(QStringList wartosci);
    int pobierzLiczbeWierszy();
    void czysc();
    virtual ~Tabela();
private:
    QFile mFile;
};

#endif // TABELA_H
