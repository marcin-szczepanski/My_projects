#include "papierowa.h"


void Papierowa::ustawFormat(FormatP f)
{
    format=f;
}

void Papierowa::ustawOkladke(OkladkaP o)
{
    okladka=o;
}

QString Papierowa::podajFormat()
{
    if (format==A4)
        return "A4";
    else if (format==A5)
        return "A5";
    else if (format==B5)
        return "B5";
    else if (format==B6)
        return "B6";
    else
        return "inny";
}

QString Papierowa::podajOkladke()
{
    if (okladka==miekka)
        return "miękka";
    else
        return "twarda";
}

QString Papierowa::podajKlase()
{
    return "wersja papierowa";
}

QString Papierowa::podajRozmiar()
{
    return "nie dotyczy";
}
