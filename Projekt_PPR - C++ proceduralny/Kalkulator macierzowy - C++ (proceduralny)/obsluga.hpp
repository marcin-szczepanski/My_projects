#ifndef obsluga
#define obsluga

#include "obsluga_podst.hpp"

void wyswietl(const char nazwa_pliku[]);
void uruchom();
void instrukcja();
void powrot_do_menu(char odpowiedz);
void powrot_odpowiedz();
void ile_macierzy();
void wprowadz_odpowiedz(char typ_dzialania);

void wyswietl(const char nazwa_pliku[])
{
    /*
        Funkcja pobiera z pliku tekst a następnie wyświetla go
        linijka po linijce.
    */
    ifstream plik;
    plik.open(nazwa_pliku, ios::in);
    string tymczasowa;
    while(getline(plik, tymczasowa))
        cout << tymczasowa << "\n";
    plik.close();
}

void uruchom()
{
    /*
        Funkcja wyświetla informacje początkowe w programie
        oraz daje dostęp do instrukcji obsługi.
    */
    wyswietl("Wstep.txt");
    wyswietl("Op_macierzowe_wstep.txt");
    instrukcja();
    ile_macierzy();
}

void instrukcja()
{
    // Funkcja wyświetla instrukcję do wybranego działania.
    odpowiedz:
    char odp;
    cin >> odp; // wprowadzamy literę odpowiadającą działaniu, którego instrukcję chcemy zobaczyć
    if (odp=='a')
    {
        system("cls");
        wyswietl("dodawanie.txt"); // wyświetlanie odpowiedniej instrukcji
        powrot_odpowiedz(); // Funkcja pozwala wrócić do menu głównego i wybrać inną instrukcję lub rozpocząć działanie.
    }
    else if (odp=='b')
    {
        system("cls");
        wyswietl("odejmowanie.txt");
        powrot_odpowiedz();
    }
    else if (odp=='c')
    {
        system("cls");
        wyswietl("mnozenie_skalar.txt");
        powrot_odpowiedz();
    }
    else if (odp=='d')
    {
        system("cls");
        wyswietl("mnozenie.txt");
        powrot_odpowiedz();
    }
    else if (odp=='e')
    {
        system("cls");
        wyswietl("transpozycja.txt");
        powrot_odpowiedz();
    }
    else if (odp=='f')
    {
        system("cls");
        wyswietl("slad.txt");
        powrot_odpowiedz();
    }
    else if (odp=='g')
    {
        system("cls");
        wyswietl("wyznacznik.txt");
        powrot_odpowiedz();
    }
    else if (odp=='h')
    {
        system("cls");
        wyswietl("rzad.txt");
        powrot_odpowiedz();
    }
    else if (odp=='i')
    {
        system("cls");
        wyswietl("postac_zredukowana.txt");
        powrot_odpowiedz();
    }
    else if (odp=='j')
    {
        system("cls");
        wyswietl("macierz_dopelnien.txt");
        powrot_odpowiedz();
    }
    else if (odp=='k')
    {
        system("cls");
        wyswietl("macierz_dolaczona.txt");
        powrot_odpowiedz();
    }
    else if (odp=='l')
    {
        system("cls");
        wyswietl("macierz_odwrotna.txt");
        powrot_odpowiedz();
    }
    else if (odp=='t') // nie oglądamy instrukcji, przechodzimy do działania
    {
        system("cls");
        return;
    }
    else
    {
        cout << "Wprowadzono bledny znak. Sproboj ponownie.\n";
        goto odpowiedz; // ponowna próba wprowadzenia znaku
    }
}

void powrot_do_menu(char odpowiedz)
{
    // Funkcja pozwala na powrót do poprzedniego menu.
    system("cls");
    if (odpowiedz=='g')
        uruchom(); // powracamy do menu głównego
    if (odpowiedz=='i')
        ile_macierzy(); // powracamy do menu, w którym wybieraliśmy, na ilu macierzach chcemy działać
}

void powrot_odpowiedz() // Funkcja pozwala na powrót do menu głównego.
{
    odpowiedz1:
    char odp1;
    cin >> odp1;
    if (odp1=='m')
        powrot_do_menu('g'); // uruchamiam funkcję "powrot_do_menu"
    else
    {
        cout << "Wprowadzono bledny znak. Sproboj ponownie.\n";
        goto odpowiedz1; // powrót na początek, aby jeszcze raz wprowadzić znak.
    }
}

void ile_macierzy()
{
    wyswietl("ile_macierzy.txt"); // wyświetlamy informację, na ilu macierzach można działać
    ilemacierzy:
    char ile;
    cin >> ile; // wybieramy na ilu macierzach chcemy działąć
    if (ile=='1')
    {
        system("cls");
        wyswietl("jedna_macierz.txt"); // wyświetlamy dostępne działania na jednej macierzy
        wprowadz_odpowiedz('j');
    }
    else if (ile=='2')
    {
        system("cls");
        wyswietl("dwie_macierze.txt"); // wyświetlamy dostępne działania na dwóch macierzach
        wprowadz_odpowiedz('d');
    }
    else if (ile=='m')
    {
        system("cls");
        powrot_do_menu('g'); // wracamy do menu głównego
    }
    else
    {
        cout << "Wprowadzono bledny znak. Sproboj ponownie.\n";
        goto ilemacierzy; // wracamy na początek aby móc ponownie wprowadzić znak
    }
}

void wprowadz_odpowiedz(char typ_dzialania)
{
    // Tutaj będziemy wykonywać działania.
    wprowadz:
    int blad=0; // zmienna mówiąca o tym, czy nie ma jakiegoś błędu; 0 - nie ma błędu.
    string odp; // wprowadzamy ciąg znaków, odpowiadający różnym działaniom
    cin >> odp;
    int n=odp.length(); // badamy długość wprowadzonego ciągu.
    if (szukaj(odp,'m')==true)
        powrot_do_menu('i'); // powrót do menu "ile macierzy"
    if (typ_dzialania=='j') // działania na jednej macierzy
    {
        for (int i=0; i<n; i++)
        {
            if ((odp[i]!='a') && (odp[i]!='b') && (odp[i]!='c') && (odp[i]!='d') && (odp[i]!='e') && (odp[i]!='f') && (odp[i]!='g') && (odp[i]!='h') && (odp[i]!='i'))
            // Sprawdzamy, czy w odpowiedzi znajdują się niedozwolone znaki. Jeśli tak to wpisujemy znaki jeszcze raz.
            {
                cout << "W Twojej odpowiedzi znajduje sie niepoprawny znak. Sproboj wpisac wyrazenie jeszcze raz.\n";
                blad=1;
                break;
            }
        }
        if (blad==0)
        {
            proba:
            system("cls");
            int n=0, m=0; // wymiary macierzy
            double wyznacznik; // zmienna potrzebna do liczenia wyznacznika macierzy
            double rzad=0; // zmienna potrzebna do liczenia rzędu macierzy
            wymiary_jednej_macierzy(n,m);
            if ((szukaj(odp,'c')==true) || (szukaj(odp,'d')==true) || (szukaj(odp,'g')==true) || (szukaj(odp,'h')==true) || (szukaj(odp,'i')==true))
            {
                /*
                    Jeśli chcemy wykonać działanie, które można wykonać tylko na macierzy kwadratowej,
                    a ona nie jest kwadratowa, musimy podać nowe wymiary macierzy.
                */
                if (n!=m)
                {
                    cout << "Probojesz wykonac jedno z dzialan: slad, wyznacznik, macierz dopelnien algebraicznych, macierz dolaczona, macierz odwrotna.\n";
                    cout << "Macierz musi byc kwadratowa! Sproboj podac wymiary ponownie.\n";
                    dalej();
                    goto proba; // wracamy do miejsca, w którym wpisywaliśmy wymiary macierzy
                }
            }
            wprowadzanie_jednej_macierzy(n,m);
            cout << "Wprowadzona macierz to:\n";
            wyswietl_jedna_macierz(n,m);
            dalej();
            if (szukaj(odp,'a')==true)
                {
                    double skalar;
                    cout << "Podaj liczbe, przez ktora chcesz mnozyc macierz:\n";
                    cin >> skalar;
                    system("cls");
                    mnozenie_skalar(n,m,skalar);
                    dalej();
                }
            if (szukaj(odp,'b')==true)
                {
                    transpozycja(n,m);
                    dalej();
                }
            if (szukaj(odp,'c')==true)
            {
                slad(n,m);
                dalej();
            }
            if (szukaj(odp,'d')==true)
            {
                cout << "Wyznacznik macierzy:\n";
                tworz_wynikowa_macierz(n,m);
                przepisz_macierz(n,m);
                wyznacznik=1;
                redukuj(n,m,wyznacznik,rzad);
                cout << wyznacznik << "\n";
                dalej();
            }
            if (szukaj(odp,'e')==true)
                {
                    cout << "Rzad macierzy:\n";
                    if ((szukaj(odp,'d')==false) || (n!=m))
                    // Jeśli nie redukowaliśmy macierzy wcześniej, to musimy to zrobić teraz
                    {
                        tworz_wynikowa_macierz(n,m);
                        przepisz_macierz(n,m);
                        wyznacznik=1;
                        redukuj(n,m,wyznacznik,rzad);
                    }
                    cout << rzad << "\n";
                    dalej();
                }
            if (szukaj(odp,'f')==true)
                {
                    cout << "Postac zredukowana (schodkowa) macierzy:\n";
                    if ((szukaj(odp,'d')==false) || (n!=m) || (szukaj(odp,'e')==false))
                    // Jeśli nie redukowaliśmy macierzy wcześniej, to musimy to zrobić teraz
                    {
                        tworz_wynikowa_macierz(n,m);
                        przepisz_macierz(n,m);
                        wyznacznik=1;
                        redukuj(n,m,wyznacznik,rzad);
                    }
                    wyswietl_wynikowa_macierz(n,m);
                    wyczysc_wynikowa_macierz(n,m);
                    dalej();
                }
            if (szukaj(odp,'g')==true)
            {
                cout << "Macierz dopelnien algebraicznych:\n";
                if (szukaj(odp,'d')==false)
                /*
                    jeśli nie liczyliśmy wyznacznika, to musimy mu nadać jakąś wartość
                    na potrzeby działania funkcji "dopelnienia"
                */
                    wyznacznik=1;
                dopelnienia(n,m,wyznacznik);
                wyswietl_macierz_dopelnien(n,m);
                if (szukaj(odp,'h')==false && (szukaj(odp,'i')==false))
                /*
                     Jeśli już tablica reprezentująca macierz dopełnień algebraicznych
                     nie jest nam potrzebna to możemy ją usunąć z pamięci.
                */
                    wyczysc_macierz_dopelnien(n,m);
                dalej();
            }
            if (szukaj(odp,'h')==true)
            {
                cout << "Macierz dolaczona:\n";
                tworz_macierz_dolaczona(m,n);
                if (szukaj(odp,'g')==false)
                {
                /*
                    jeśli nie liczyliśmy macierzy dopełnień algebraicznych,
                    to robimy to teraz
                */
                    if (szukaj(odp,'d')==false)
                        wyznacznik=1;
                    dopelnienia(n,m,wyznacznik);
                }
                dolaczona(n,m);
                wyswietl_macierz_dolaczona(n,m);
                wyczysc_macierz_dopelnien(n,m);
                if (szukaj(odp,'i')==false)
                /*
                     Jeśli już tablica reprezentująca macierz dołączona
                     nie jest nam potrzebna to możemy ją usunąć z pamięci.
                */
                    wyczysc_macierz_dolaczona(m,n);
                dalej();
            }
            if (szukaj(odp,'i')==true)
            {
                cout << "Macierz odwrotna:\n";
                tworz_wynikowa_macierz(n,m);
                przepisz_macierz(n,m);
                double wyznacznik_glowny=1;
                redukuj(n,m,wyznacznik_glowny,rzad); // liczymy wyznacznik macierzy, której odwrotność liczymy
                wyczysc_wynikowa_macierz(n,m);
                if (wyznacznik_glowny==0)
                    cout << "Wyznacznik macierzy wynosi zero. Macierz odwrotna do takiej macierzy nie istnieje.\n";
                else
                {
                    if (szukaj(odp,'h')==false)
                    {
                    /*
                        Jeśli wcześniej nie liczyliśmy macierzy dołączonej,
                        robimy to teraz.
                    */
                        if (szukaj(odp,'g')==false)
                        {
                            tworz_macierz_dolaczona(m,n);
                            if (szukaj(odp,'d')==false)
                                wyznacznik=1;
                            dopelnienia(n,m,wyznacznik);
                            dolaczona(n,m);
                        }
                        else
                            dolaczona(n,m);
                    }
                    odwracanie(n,m,wyznacznik_glowny);
                }
                dalej();
            }
            wyczysc_jedna_macierz(n,m); // usuwamy z pamięci wprowadzoną macierz
        }
    }
    else // działamy na dwóch macierzach
    {
        for (int i=0; i<n; i++)
        {
            if ((odp[i]!='a') && (odp[i]!='b') && (odp[i]!='c'))
            // sprawdzamy, czy wprowadzono niedozwolony znak, jeśli tak to wprowadzamy jeszcze raz
            {
                system("cls");
                cout << "W Twojej odpowiedzi znajduje sie niepoprawny znak. Sproboj wpisac wyrazenie jeszcze raz.\n";
                blad=1;
                break;
            }
        }
        if (blad==0)
        {
            int n=0, m=0, k=0, p=0;
            bool a=szukaj(odp,'a'); // Jakie operacje mamy wykonać?
            bool b=szukaj(odp,'b');
            bool c=szukaj(odp,'c');
            wymiar:
            system("cls");
            wymiary_dwoch_macierzy(n,m,k,p);
            if ((a==true) || (b==true)) // dodajemy lub odejmujemy macierze
            {
                bool wym1=true; // zmienna ta informuje nas, czy wymiary są poprawne
                sprawdz_wymiar(n,m,k,p,'a',wym1);
                if (wym1==false)
                {
                    dalej();
                    goto wymiar; // jeszcze raz wprowadzamy wymiary, bo są nieprawidłowe
                }

            }
            if (c==true) // mnożymy macierze
            {
                bool wym2=true; // zmienna ta informuje nas, czy wymiary są poprawne
                sprawdz_wymiar(n,m,k,p,'c',wym2);
                if (wym2==false)
                {
                    dalej();
                    goto wymiar; // jeszcze raz wprowadzamy wymiary, bo są nieprawidłowe
                }
            }
            wprowadzanie_dwoch_macierzy(n,m,k,p);
            wyswietl_dwie_macierze(n,m,k,p);
            dalej();
            if (a==true)
            {
                dodawanie(n,m,k,p);
                dalej();
            }
            if (b==true)
            {
                odejmowanie(n,m,k,p);
                dalej();
            }
            if (c==true)
            {
                mnozenie(n,m,k,p);
                dalej();
            }
            wyczysc_dwie_macierze(n,m,k,p); // usuwamy z pamięci wprowadzone macierze
        }
    }
    if (blad==1)
        goto wprowadz; // gdy wprowadzono na początku niedozwolony znak, wprowadzamy go ponownie
}

#endif
