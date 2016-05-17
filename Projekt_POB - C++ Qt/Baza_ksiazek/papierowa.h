#ifndef PAPIEROWA_H
#define PAPIEROWA_H

#include "ksiazka.h"

enum FormatP {A4, A5, B5, B6, INNY};
enum OkladkaP {miekka, twarda};

class Papierowa : public Ksiazka
{
public:

    void ustawFormat(FormatP f);
    void ustawOkladke(OkladkaP o);
    QString podajFormat();
    QString podajOkladke();
    QString podajRozmiar();
    QString podajKlase();
private:
    FormatP format;
    OkladkaP okladka;
};

#endif // PAPIEROWA_H
