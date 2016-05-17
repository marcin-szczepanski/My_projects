#include "ksiazka.h"

Ksiazka::Ksiazka()
{

}

Ksiazka::~Ksiazka()
{

}

void Ksiazka::ustawTytul(QString t)
{
    tytul=t;
}


void Ksiazka::ustawAutora(QString aut)
{
    autor=aut;
}

void Ksiazka::ustawRokWydania(QString r)
{
    rokWydania=r;
}

void Ksiazka::ustawWydawnictwo(QString w)
{
    wydawnictwo=w;
}

void Ksiazka::ustawGatunek(QString g)
{
    gatunek=g;
}

void Ksiazka::ustawStan(QString s)
{
    stan=s;
}

void Ksiazka::ustawIloscStron(QString i)
{
    iloscStron=i;
}

QString Ksiazka::podajTytul()
{
    return tytul;
}


QString Ksiazka::podajAutora()
{
    return autor;
}

QString Ksiazka::podajRokWydania()
{
    return rokWydania;
}

QString Ksiazka::podajWydawnictwo()
{
    return wydawnictwo;
}

QString Ksiazka::podajGatunek()
{
    return gatunek;
}

QString Ksiazka::podajStan()
{
    return stan;
}

QString Ksiazka::podajIloscStron()
{
    return iloscStron;
}
