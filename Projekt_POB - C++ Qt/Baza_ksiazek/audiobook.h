#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "ksiazka.h"
#include <QString>

enum FormatA {mp3, ogg, cd, kaseta, inny};

class Audiobook : public Ksiazka
{
public:

    void ustawFormat(FormatA f);
    void ustawRozmiar(QString r);
    QString podajFormat();
    QString podajRozmiar();
    QString podajKlase();
    QString podajOkladke();
private:
    FormatA format;
    QString rozmiar;
};

#endif // AUDIOBOOK_H
