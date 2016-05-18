#include "statystyka.h"

Statystyka::Statystyka(int w, int k, QString s):ile_wierszy(w),nr_kolumny(k),szukany_element(s)
{
    ile_elementow=0;
}

int Statystyka::policzIleSzukanych(QTableWidget *tab)
{
    for (int i=0; i<ile_wierszy; i++)
    {
        if (tab->item(i,nr_kolumny)->text()==szukany_element)
            ile_elementow++;
    }

    return ile_elementow;
}
