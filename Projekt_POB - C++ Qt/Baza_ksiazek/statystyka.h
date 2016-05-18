#ifndef STATYSTYKA_H
#define STATYSTYKA_H

#include <QString>
#include <QTableWidget>

class Statystyka
{
public:
    Statystyka(int w,int k, QString s);
    int policzIleSzukanych(QTableWidget *tab);
private:
    int ile_wierszy;
    int ile_elementow;
    int nr_kolumny;
    QString szukany_element;
};

#endif // STATYSTYKA_H
