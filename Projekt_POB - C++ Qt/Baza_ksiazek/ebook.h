#ifndef EBOOK_H
#define EBOOK_H

#include "ksiazka.h"
#include <QString>

enum FormatE {pdf, mobi, ePub, Inny};

class Ebook : public Ksiazka
{
public:

    void ustawFormat(FormatE f);
    void ustawRozmiar(QString r);
    QString podajFormat();
    QString podajRozmiar();
    QString podajKlase();
    QString podajOkladke();
private:
    FormatE format;
    QString rozmiar;
};

#endif // EBOOK_H
