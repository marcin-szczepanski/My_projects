#ifndef obsluga_podst
#define obsluga_podst

#include "macierze.hpp"

void sortuj(string &A);
bool szukaj(string &tab, char szukana);
void dalej();

void sortuj(string &A)
{
    // sortowanie bąbelkowe, kolejność niemalejąca
    int n=A.length();
    for (int i=0; i<(n-1); i++)
    {
        for (int j=n-1; j>=i+1; j--)
        {
            if (A[j]<A[j-1])
                swap(A[j],A[j-1]);
        }
    }
}

bool szukaj(string &tab, char szukana)
{
    // wyszukiwanie binarne
    sortuj(tab);
    int sr;
    int l=0;
    int p=tab.length();
    while(l<=p)
    {
        sr=(l+p)/2;
        if(tab[sr]==szukana)
          return true;
        if(tab[sr]>szukana)
          p=sr-1;
        else
          l=sr+1;
    }
    return false;
}

void dalej()
{
    // funkcja, która powoduje przejście do następnych instrukcji po wciśnięciu odpowiedniego klawisza
    cout << "Aby przejsc dalej, wcisnij (d) i enter.\n";
    litera:
    char odp;
    cin >> odp;
    if (odp!='d')
    {
        cout << "Wprowadzono bledny znak. Sproboj ponownie.\n";
        goto litera;
    }
    else
        system("cls");
}

#endif
