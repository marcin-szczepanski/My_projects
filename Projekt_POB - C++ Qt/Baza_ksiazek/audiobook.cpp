#include "audiobook.h"

void Audiobook::ustawFormat(FormatA f)
{
    format=f;
}

void Audiobook::ustawRozmiar(QString r)
{
    rozmiar=r;
}

QString Audiobook::podajFormat()
{
    if (format==mp3)
        return "mp3";
    else if (format==ogg)
        return "ogg";
    else if (format==cd)
        return "CD";
    else if (format==kaseta)
        return "kaseta";
    else
        return "inny";
}

QString Audiobook::podajRozmiar()
{
    return rozmiar;
}

QString Audiobook::podajKlase()
{
    return "audiobook";
}

QString Audiobook::podajOkladke()
{
    return "nie dotyczy";
}
