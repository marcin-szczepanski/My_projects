#ifndef macierze
#define macierze

#include "gauss.hpp"

void wymiary_jednej_macierzy(int &n, int &m);
void wymiary_dwoch_macierzy(int &n, int &m, int &k, int &p);
void sprawdz_wymiar(int n, int m, int k, int p, char typ, bool &wartosc);
void mnozenie_skalar(int n, int m, double skalar);
void transpozycja(int n, int m);
void dodawanie(int n, int m, int k, int p);
void odejmowanie(int n, int m, int k, int p);
void mnozenie(int n, int m, int k, int p);

void wymiary_jednej_macierzy(int &n, int &m)
{
    /*
        Funkcja ta pobiera wymiary macierzy, gdy działamy tylko na jednej.
    */
    cout << "Podaj ilosc wierszy macierzy i wcisnij enter:\n";
    cin >> n;
    cout << "Podaj ilosc kolumn macierzy i wcisnij enter:\n";
    cin >> m;
    system("cls");
}

void wymiary_dwoch_macierzy(int &n, int &m, int &k, int &p)
{
    /*
        Funkcja ta pobiera wymiary macierzy, gdy działamy na dwóch macierzach.
    */
    cout << "Podaj ilosc wierszy pierwszej macierzy i wcisnij enter:\n";
    cin >> n;
    cout << "Podaj ilosc kolumn pierwszej macierzy i wcisnij enter:\n";
    cin >> m;
    cout << "Podaj ilosc wierszy drugiej macierzy i wcisnij enter:\n";
    cin >> k;
    cout << "Podaj ilosc kolumn drugiej macierzy i wcisnij enter:\n";
    cin >> p;
    system("cls");
}

void sprawdz_wymiar(int n, int m, int k, int p, char typ, bool &wartosc)
{
    if (typ=='a')
    /*
        Sprawdzamy, czy możemy dodać lub odjąć macierze.
        Aby działania te wykonać, macierze muszą mieć te same wymiary.
    */
        {
            if ((n!=k) && (m!=p))
                {
                    cout << "Blad: wymiary macierzy nie sa takie same!\n" << "Sproboj ponownie.\n";
                    wartosc=false;
                }
            else
                wartosc=true;
        }
    else
        {
            if (m!=k)
            /*
                Sprawdzamy, czy wykonalne jest mnożenie macierzy.
            */
                {
                    cout << "Blad: Ilosc kolumn pierwszej macierzy nie jest taka sama jak ilosc wierszy drugiej macierzy!\n";
                    cout << "Sproboj ponownie.\n";
                    wartosc=false;
                }
            else
                wartosc=true;
        }
}


void mnozenie_skalar(int n, int m, double skalar)
{
    cout << "Mnozenie macierzy przez liczbe " << skalar << ":\n";
    tworz_wynikowa_macierz(n,m);
    /*
        Mnożenie macierzy przez liczbę polega na pomnożeniu każdego
        elementu macierzy przez tą liczbę.
    */
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (skalar!=0) // eliminujemy problem "-0"
            {
                if (A[i][j]!=0) // eliminujemy problem "-0"
                    C[i][j]=skalar*A[i][j];
                else
                    C[i][j]=0;
            }
            else
                C[i][j]=0;
        }
    }
    wyswietl_wynikowa_macierz(n,m);
    wyczysc_wynikowa_macierz(n,m);
}

void transpozycja(int n, int m)
{
    /*
        Transpozycja macierzy polega na zamianie wierszy w kolumny
        i kolumny w wiersze.
    */
    cout << "Transpozycja macierzy:\n";
    tworz_wynikowa_macierz(m,n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            C[j][i]=A[i][j];
    }
    wyswietl_wynikowa_macierz(m,n);
    wyczysc_wynikowa_macierz(m,n);
}


void dodawanie(int n, int m, int k, int p)
{
    /*
        Dodawanie macierzy polega na dodaniu do siebie
        odpowiednio każdego elementu z pierwszej macierzy
        do każdego elementu drugiej macierzy.
    */
    cout << "Dodawanie macierzy:\n";
    tworz_wynikowa_macierz(n,m);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            C[i][j]=A[i][j]+B[i][j];
    }
    wyswietl_wynikowa_macierz(n,m);
    wyczysc_wynikowa_macierz(n,m);
}

void odejmowanie(int n, int m, int k, int p)
{
    /*
        Odejmowanie macierzy polega na odjęciu odpowiednio
        każdego elementu drugiej macierzy od każdego
        elementu pierwszej macierzy.
    */
    cout << "Odejmowanie macierzy:\n";
    tworz_wynikowa_macierz(n,m);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            C[i][j]=A[i][j]-B[i][j];
    }
    wyswietl_wynikowa_macierz(n,m);
    wyczysc_wynikowa_macierz(n,m);
}

void mnozenie(int n, int m, int k, int p)
{
    /*
        Mnożenie macierzy to operacja, w której elementy wynikowej macierzy
        powstają następująco: mnożymy odpowiednio każdy element danego wiersza
        pierwszej macierzy przez odpowiednio każdy element danej kolumny
        drugiej macierzy i to wszystko dodajemy do siebie.
    */
    cout << "Mnozenie macierzy:\n";
    tworz_wynikowa_macierz(n,p);
    double element;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<p; j++)
        {
            element=0; // resetowanie zmiennej na potrzeby obliczania kolejnego elementu mnożenia macierzy
            for (int k=0; k<m; k++)
            {
                if ((A[i][k]!=0) && (B[k][j]!=0))
                    element=element+A[i][k]*B[k][j];
            }
            C[i][j]=element;
        }
    }
    wyswietl_wynikowa_macierz(n,p);
    wyczysc_wynikowa_macierz(n,p);
}

#endif
