#ifndef obsluga_macierzy
#define obsluga_macierzy

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

double **A, **B, **C, **D; // tablice, używane w trakcie działania programu, reprezentują odpowiednie macierze

void tworz_jedna_macierz(int n, int m);
void tworz_dwie_macierze(int n, int m, int k, int p);
void tworz_wynikowa_macierz(int n, int m);
void tworz_macierz_dopelnien(int n, int m);
void tworz_macierz_dolaczona(int m, int n);
void wprowadzanie_jednej_macierzy(int n, int m);
void wprowadzanie_dwoch_macierzy(int n, int m, int k, int p);
void wyswietl_jedna_macierz(int n, int m);
void wyswietl_dwie_macierze(int n, int m, int k, int p);
void wyswietl_wynikowa_macierz(int n, int m);
void wyswietl_macierz_dopelnien(int n, int m);
void wyswietl_macierz_dolaczona(int m, int n);
void wyczysc_jedna_macierz(int n, int m);
void wyczysc_dwie_macierze(int n, int m, int k, int p);
void wyczysc_wynikowa_macierz(int n, int m);
void wyczysc_macierz_dopelnien(int n, int m);
void wyczysc_macierz_dolaczona(int m, int n);
void przepisz_macierz(int n, int m);

void tworz_jedna_macierz(int n, int m)
{
    /*
        Tworzymy dynamiczną tablicę, która reprezentuje macierz,
        gdy działamy na jednej macierzy.
    */
    A=new double*[n];
    for (int i=0; i<n; i++)
        A[i]=new double[m];
}

void tworz_dwie_macierze(int n, int m, int k, int p)
{
    /*
        Tworzymy 2 dynamiczne tablice, które reprezentuje macierze,
        gdy działamy na dwóch macierzach.
    */
    A=new double*[n];
    B=new double*[k];
    for (int i=0; i<n; i++)
        A[i]=new double[m];
    for (int i=0; i<k; i++)
        B[i]=new double[p];
}

void tworz_wynikowa_macierz(int n, int m)
{
    // Tworzymy tablicę, która reprezentuje wynik macierzowy.
    C=new double*[n];
    for (int i=0; i<n; i++)
        C[i]=new double[m];
}

void tworz_macierz_dopelnien(int n, int m)
{
    // Tworzymy tablicę, reprezentującą macierz dopełnień algebraicznych
    D=new double*[n];
    for (int i=0; i<n; i++)
        D[i]=new double[m];
}

void tworz_macierz_dolaczona(int m, int n)
{
    // Tworzymy tablicę, reprezentującą macierz dołaćzoną
    B=new double*[m];
    for (int i=0; i<m; i++)
        B[i]=new double[n];
}

void wprowadzanie_jednej_macierzy(int n, int m)
{
    /*
        Funkcja, dzięki której możemy wprowadzić elementy do macierzy,
        gdy działamy na jednej macierzy.
    */
    tworz_jedna_macierz(n,m);
    cout << "Wprowadz macierz:\n";
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout << "Wprowadz element z wiersza o numerze: " << i+1 << " i kolumnie o numerze: " << j+1 << ".\n";
            cin >> A[i][j];
        }
    }
    system("cls");
}

void wprowadzanie_dwoch_macierzy(int n, int m, int k, int p)
{
    /*
        Funkcja, dzięki której możemy wprowadzić elementy do macierzy,
        gdy działamy na dwóch macierzach.
    */
    tworz_dwie_macierze(n,m,k,p);
    cout << "Wprowadz pierwsza macierz:\n";
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout << "Wprowadz element z wiersza o numerze: " << i+1 << " i kolumnie o numerze: " << j+1 << ".\n";
            cin >> A[i][j];
        }
    }
    system("cls");
    cout << "Wprowadz druga macierz:\n";
    for (int i=0; i<k; i++)
    {
        for (int j=0; j<p; j++)
        {
            cout << "Wprowadz element z wiersza o numerze: " << i+1 << " i kolumnie o numerze: " << j+1 << ".\n";
            cin >> B[i][j];
        }
    }
    system("cls");
}

void wyswietl_jedna_macierz(int n, int m)
{
    /*
        Funkcja wyświetla elementy macierzy,
        którą wprowadziliśmy,
        gdy działamy na jednej macierzy.
    */
    cout << "Wprowadzona macierz:\n";
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }
}

void wyswietl_dwie_macierze(int n, int m, int k, int p)
{
    /*
        Funkcja wyświetla elementy macierzy,
        którr wprowadziliśmy,
        gdy działamy na dwóch macierzach.
    */
    cout << "Pierwsza wprowadzona macierz:\n";
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }
    cout << "Druga wprowadzona macierz:\n";
    for (int i=0; i<k; i++)
    {
        for (int j=0; j<p; j++)
            cout << B[i][j] << " ";
        cout << "\n";
    }
}

void wyswietl_wynikowa_macierz(int n, int m)
{
    /*
        Funkcja wyświetla elementy macierzy wynikowej.
    */
    cout << "Wynikowa macierz:\n";
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }
}

void wyswietl_macierz_dopelnien(int n, int m)
{
    /*
        Funkcja wyświetla elementy macierzy dopełnień algebraicznych.
    */
    cout << "Wynikowa macierz:\n";
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout << D[i][j] << " ";
        cout << "\n";
    }
}

void wyswietl_macierz_dolaczona(int m, int n)
{
    /*
        Funkcja wyświetla elementy macierzy dołączonej.
    */
    cout << "Wynikowa macierz:\n";
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            cout << B[i][j] << " ";
        cout << "\n";
    }
}

void wyczysc_dwie_macierze(int n, int m, int k, int p)
{
    /*
        Funkcja, która usuwa z pamięci tablice dynamiczne,
        które reprezentowały macierze, gdy działaliśmy
        na dwóch macierzach.
    */
    for (int i=0; i<n; i++)
        delete []A[i];
    delete []A;
    for (int i=0; i<k; i++)
        delete []B[i];
    delete []B;
}

void wyczysc_jedna_macierz(int n, int m)
{
    /*
        Funkcja, która usuwa z pamięci tablicę dynamiczną,
        która reprezentowała macierz, gdy działaliśmy
        na jednej macierzy.
    */
    for (int i=0; i<n; i++)
        delete []A[i];
    delete []A;
}

void wyczysc_wynikowa_macierz(int n, int m)
{
    /*
        Funkcja, która usuwa z pamięci tablicę dynamiczną,
        która reprezentowała wynikową macierz.
    */
    for (int i=0; i<n; i++)
        delete []C[i];
    delete []C;
}

void wyczysc_macierz_dopelnien(int n, int m)
{
    /*
        Funkcja, która usuwa z pamięci tablicę dynamiczną,
        która reprezentowała macierz dopełnień algebraicznych.
    */
    for (int i=0; i<n; i++)
        delete []D[i];
    delete []D;
}

void wyczysc_macierz_dolaczona(int m, int n)
{
    /*
        Funkcja, która usuwa z pamięci tablicę dynamiczną,
        która reprezentowała macierz dołączoną.
    */
    for (int i=0; i<m; i++)
        delete []B[i];
    delete []B;
}

void przepisz_macierz(int n, int m)
{
    /*
        Funkcja przepisuje elementy macierzy wprowadzonej
        do macierzy wynikowej na potrzeby redukowania macierzy.
    */
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            C[i][j]=A[i][j];
    }
}

#endif
