#include "obsluga.hpp"

char pobierz_znak();

int main()
{
    uruchom:
    uruchom(); // funkcja uruchamiająca kalkulator
    cout << "Jesli chcesz dzialac dalej wcisnij (t) i enter.\n";
    cout << "Jesli chcesz zakonczyc dzialanie programu, nacisnij dowolny klawisz znaku (z wyjatkiem (t)) i enter.\n";
    char x=pobierz_znak();
    system("cls"); // czyścimy konsolę
    if (x=='t')
        goto uruchom; // powrót na początek programu
    return 0;
}

char pobierz_znak()
{
    char znak;
    cin >> znak;
    return znak;
}
