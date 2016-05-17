#ifndef gauss
#define gauss

#include "obsluga_macierzy.hpp"

void slad(int n, int m);
void redukuj(int n, int m, double &wyznacznik, double &rzad);
void dopelnienia(int n, int m, double &wyznacznik);
void dolaczona(int n, int m);
void odwracanie(int n, int m, double wyznacznik_glowny);

void slad(int n, int m)
{
    // Ślad macierzy to suma elementów diagonalnych.
    cout << "Slad macierzy:\n";
    double slad=0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (i==j)
                slad=slad+A[i][j];
        }
    }
    cout << slad << "\n";
}

void redukuj(int n, int m, double &wyznacznik, double &rzad)
{
    /*
        Postać zredukowana macierzy to macierz trójkątna górna,
        która ma jedynki na przekątnej głównej.
        Tworzy się ją poprzez odpowiednie operacje elementarne na macierzy.
    */

    /*
        Będziemy zmieniać wartość wyznacznika pamiętająć o zasadach:
        (a) zamiana kolejności dwóch wierszy (kolumn) powoduje zmianę znaku wyznacznika na przeciwny;
        (b) mnożenie (dzielenie) wiersza (kolumny) przez liczbę powoduje pomnożenie (podzielenie) wyznacznika przez tą liczbę;
        (c) wartość wyznacznika jest równa iloczynowi elementów diagonalnych macierzy trójkątnej.
    */
    wyznacznik=1;
    /*
        Zamiana miejscami wierszy, tak aby pierwszy wiersz miał pierwszy element równy jeden.
        Jeśli nie ma takiego wiersza, nie dokonamy zamiany.
    */
    if (C[0][0]!=1) // jeśli pierwszy element w pierwszym wierszu jest równy jeden, to nie będę nic robić
    {
        for (int i=n-1; i>0; i--) // badam wiersze od ostatniego do pierwszego
        {
            if ((C[0][0]!=1) && ((C[i][0]==1)))
            /*
                Sprawdzam, czy pierwszy element w pierszym wierszu nie jest równy jeden
                i czy pierwszy element z i-tego wiersza jest równy jeden - tylko wtedy wykonuję zamianę miejscami.
            */
            {
                if (n==m) // wyznacznik liczymy tylko dla macierzy kwadratowej!
                    wyznacznik=-1*wyznacznik;
                for (int k=0; k<m; k++)
                    swap(C[0][k],C[i][k]);
            }
        }
    }
    /* Ustalenie, ile razy będziemy musieli powtarzać główną pętlę sterującą zamianą wierszy, o których mowa będzie niżej */
    int liczba;
    if (n%2==0) // czy liczba wierszy jest parzysta?
    {
        if (n%3==0) // czy liczba wierszy jest podzielna przez 3?
            liczba=n;
        else
            liczba=n-1;
    }
    else
        liczba=n;
    /*
        Zamiana kolejności wierszy, których pierwszy element jest równy zero.
        Zamieniamy zgodnie z zasadą: ten wiersz który ma kolejno od pierwszej pozycji więcej zer jest niżej.
    */
    for (int s=0; s<liczba; s++)
    {
        for (int i=0; i<n-1; i++)
        {
            for (int j=0; j<m; j++)
            {
                if ((C[n-1-i][j]!=0) && ((C[n-2-i][j]==0)))
                /*
                    Jeśli element znajdujący się bezpośrednio o jeden wiersz niżej od tego drugiego jest równy zero
                    lub jeśli ten (*)drugi nie jest równy zero, nie dokonuję zamiany.
                */
                {
                    if (n==m)
                        wyznacznik=-1*wyznacznik;
                    for (int k=0; k<m; k++)
                        swap(C[n-1-i][k],C[n-2-i][k]);
                }
                else if (C[n-2-i][j]!=0)
                /*
                    Jeśli (*) jest równy zero to kończę proces zamiany wierszami dla aktualnie badanych wierszy.
                */
                    break;
            }
        }
    }
    /*
        Zamiana miejscami wierszy, które mają pierwszy element niezerowy, zaś mają choć jedno zero.
        Zamiana następuje zgodnie z hierarchią: wyżej jest ten wiersz, który ma mniej zer.
    */
    int w=0; // ta zmienna będzie informować o tym, czy dokonano zamiany wierszy miejscami
    for (int s=0; s<liczba; s++)
    {
        for (int i=0; i<n-1; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (C[i][0]!=0)
                /*
                    Jeśli pierwszy element w danym wierszy jest równy zero nie będę zamieniać wierszy miejscami.
                    W tym przypadku idę do następnego wiersza.
                */
                {
                    if ((C[n-1-i][j]!=0) && ((C[n-2-i][j]==0)))
                    /*
                        Jeśli element znajdujący się bezpośrednio o jeden wiersz niżej od tego drugiego jest równy zero
                        lub jeśli ten (*)drugi nie jest równy zero, nie dokonuję zamiany.
                    */
                    {
                        if (n==m)
                            wyznacznik=-1*wyznacznik;
                        for (int k=0; k<m; k++)
                        {
                            swap(C[n-1-i][k],C[n-2-i][k]);
                            w=-1; // dokonano zamiany miejscami wierszy, zmieniam wartosc zmiennej "w"
                        }
                        if (w==-1)
                            break; // jeśli dokonaliśmy już zamiany, kończymy proces zamiany dla badanych wierszy
                    }
                }
                else
                    break; // nie było potrzeby zamiany, więc idziemy do następnego wiersza.
            }
        }
    }
    double dzielnik, czynnik;
    /*
        Szukam pierwszego niezerowego elementu w wierszu, aby ten wiersz podzielić przez ten element.
        Robię to po to, aby otrzymać jedynkę jako pierwszy niezerowy element w wierszu.
    */
    for (int i=0; i<n; i++)
    {
        dzielnik=C[i][i];
        int a=i+1; // sprawdzam kolejne elementy w wierszu od następnego po diagonalnym
        int b=i; // nr kolumny aktualnie badanego elementu; na końcu będzie to nr kolumny szukanego elementu
        while ((dzielnik==0) && (a<m))
        /*
            Jeśli badany element jest niezerowy lub skończyliśmy badać cały wiersz,
            kończymy poszukiwanie dzielnika wiersza.
        */
        {
            dzielnik=C[i][a];
            b=a;
            a++; // przechodzę do następnego elementu w wierszu
        }
        if (n==m)
        {
            if (wyznacznik!=0) // jeśli wyznacznik jest równy zero to mnożenie go przez cokolwiek nie zmieni jego wartości
            {
                if (dzielnik!=0) // w ten sposób unikamy problemu otrzymania liczby "-0"
                    wyznacznik=wyznacznik*dzielnik; // własność (b) wyznacznika, o której było mowa na początku funkcji
                else
                    wyznacznik=0;
            }
        }
        if (dzielnik!=0)
        {
            rzad++; // zwiększamy rząd macierzy o jeden, bo mamy co najmniej jeden więcej liniowo niezależny wiersz
            for (int j=i; j<m; j++)
            {
                if (C[i][j]!=0)
                    C[i][j]=C[i][j]/dzielnik; // dzielimy cały wiersz przez znaleziony wcześniej dzielnik
            }
            for (int k=i+1; k<n; k++)
            {
                czynnik=C[k][b];
                /*
                    element, przez który pomnożymy wiersz a następnie wiersz ten dodamy do następnego;
                    mnożenie "w pamięci" - nie zmieniamy wartości wierszy na stałe!
                */
                for (int j=0; j<m; j++)
                {
                    if ((C[i][j]!=0) && (czynnik!=0))
                    {
                        double a=czynnik*C[i][j];
                        if (C[k][j]!=a) // znów unikamy problemu "-0"
                            C[k][j]=C[k][j]-a; // owe mnożenie i dodawanie do wiersza innego wiersza
                        else
                            C[k][j]=0;
                    }
                }
            }
        }
    }
    /*
        Znowu zamieniamy miejscami wiersze, których pierwszy element jest równy zero,
        zgodnie z przyjętą wcześniej zasadą: wiersz, który ma kolejno więcej zer jest niżej.
    */
    for (int s=0; s<liczba; s++)
    {
        for (int i=0; i<n-1; i++)
        {
            for (int j=0; j<m; j++)
            {
                if ((C[n-1-i][j]!=0) && ((C[n-2-i][j]==0)))
                {
                    if (n==m)
                    {
                        if (wyznacznik!=0)
                            wyznacznik=-1*wyznacznik;
                        else
                            wyznacznik=0;
                    }
                    for (int k=0; k<m; k++)
                        swap(C[n-1-i][k],C[n-2-i][k]);
                }
                else if (C[n-2-i][j]!=0)
                    break;
            }
        }
    }
    /*
        Ostatecznie liczymy wyznacznik zgodnie z własnością (c), o której była mowa
        na początku funkcji.
    */
    if (n==m)
    {
        for (int i=0; i<n; i++)
        {
            if ((wyznacznik!=0) && (C[i][i]!=0))   
                wyznacznik=wyznacznik*C[i][i];
            else
                wyznacznik=0;
        }
    }
}

void dopelnienia(int n, int m, double &wyznacznik)
{
    /*
        Macierz dopełnień algebraicznych to macierz składająca się
        z minorów dla wszystkich elementów macierzy.
    */
    int d, e; // indeksy w głównej macierzy, które mówią, jakie elementy mamy brać do aktualnej podmacierzy
    double rzad=1; // zmienna na wypadek, gdy będziemy chcieli liczyć rząd macierzy
    tworz_macierz_dopelnien(m,n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            d=0;
            e=0;
            tworz_wynikowa_macierz(n-1,m-1); // tworzymy podmacierz o jeden stopień niższą
            for (int a=0; a<n-1; a++)
            {
                e=0;
                if (d==i) // który wiersz ma nie być brany pod uwagę?
                    d++;
                for (int b=0; b<m-1; b++)
                {
                    if (e==j) // która kolumna nie ma być brana pod uwagę?
                        e++;
                    C[a][b]=A[d][e]; // do podmacierzy wpisujemy odpowiednie elementy z macierzy głównej
                    e++;
                }
                d++;
            }
            redukuj(n-1,m-1,wyznacznik,rzad); // tą funkcją liczę wyznacznik podmacierzy (tzw. minor)
            if (wyznacznik!=0)
                D[i][j]=pow(-1,(i+j))*wyznacznik; // liczę dopełnienie algebraiczne danego elementu macierzy głównej
            else
                D[i][j]=0;
            wyznacznik=1; // resetuję wartość wyznacznika na potrzeby kolejnej podmacierzy
            wyczysc_wynikowa_macierz(n-1,m-1);
        }
    }
}

void dolaczona(int n, int m)
{
    /*
        Macierz dołączona to transponowana macierz dopełnień algebraicznych (transpozycja tablicy D)
    */
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            B[j][i]=D[i][j];
    }
}

void odwracanie(int n, int m, double wyznacznik_glowny)
{
    /*
        Macierz odwrotna to macierz powstała poprzez wymnożenie macierzy dołączonej
        przez odwrotność wyznacznika macierzy, której macierzy odwrotną znajdujemy.
    */
    tworz_wynikowa_macierz(n,m);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (B[i][j]!=0)
                C[i][j]=(1/wyznacznik_glowny)*B[i][j]; // obliczam elementy macierzy odwrotnej
            else
                C[i][j]=0;
        }
    }
    wyswietl_wynikowa_macierz(n,m);
    wyczysc_wynikowa_macierz(n,m);
}

#endif
