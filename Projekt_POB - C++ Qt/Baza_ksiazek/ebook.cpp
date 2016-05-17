#include "ebook.h"

void Ebook::ustawFormat(FormatE f)
{
    format=f;
}

void Ebook::ustawRozmiar(QString r)
{
    rozmiar=r;
}

QString Ebook::podajFormat()
{
    if (format==pdf)
        return "pdf";
    else if (format==mobi)
        return "mobi";
    else if (format==ePub)
        return "ePub";
    else
        return "inny";
}

QString Ebook::podajRozmiar()
{
    return rozmiar;
}

QString Ebook::podajKlase()
{
    return "e-book";
}

QString Ebook::podajOkladke()
{
    return "nie dotyczy";
}
