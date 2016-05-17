#ifndef KSIAZKA_H
#define KSIAZKA_H

#include <QString>

using namespace std;

class Ksiazka
{
public:
    Ksiazka();
    ~Ksiazka();
    void ustawTytul(QString t);
    void ustawAutora(QString aut);
    void ustawRokWydania(QString r);
    void ustawWydawnictwo(QString w);
    void ustawGatunek(QString g);
    void ustawStan(QString s);
    void ustawIloscStron(QString i);
    QString podajTytul();
    QString podajAutora();
    QString podajRokWydania();
    QString podajWydawnictwo();
    QString podajGatunek();
    QString podajStan();
    QString podajIloscStron();
private:
    QString tytul;
    QString autor;
    QString rokWydania;
    QString wydawnictwo;
    QString gatunek;
    QString stan;
    QString iloscStron;
};

#endif // KSIAZKA_H
