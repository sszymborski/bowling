#include "interface.h"

interface::interface()
{}

interface::~interface()
{}

void interface::witaj()
{
    cout << "Witaj w systemie zarzadzania przydzialem torow w kregielni" << endl;
    cout << "Podaj dane dotyczace kregielni" << endl;
}

void interface::brakTorow()
{
    cout << endl << "Brak torow" << endl;
}

void interface::przypisano(int tor, int rezerwacja, int start, int stop)
{
    cout << "Do " << tor << " toru przypisano rezerwacje: " << rezerwacja + 1 << ") " << start << " - " << stop << endl;

    fstream plik("out.txt", ios::out | ios::app);
    if(plik.good())
    {
        plik.seekp(0, ios_base::end);
        plik <<"Do " << tor << " toru przypisano rezerwacje: " << rezerwacja + 1 << ") " << start << " - " << stop << endl;
        plik.close();
    }
}

void interface::niePrzypisano(int rezerwacja, int start, int stop)
{
    cout << "Do zadnego toru nie przypisano rezerwacji: " << rezerwacja + 1 << ") " << start << " - " << stop << endl;

    fstream plik("out.txt", ios::out | ios::app);
    if(plik.good())
    {
        plik.seekp(0, ios_base::end);
        plik << "Do zadnego toru nie przypisano rezerwacji: " << rezerwacja + 1 << ") " << start << " - " << stop << endl;

        plik.close();
    }
}

void interface::wyswietl(int a)
{
    cout << a << "\t";

    fstream plik("out.txt", ios::out | ios::app);
    if(plik.good())
    {
        plik.seekp(0, ios_base::end);
        plik << a << "\t";
        plik.close();
    }
}

void interface::enter()
{
    cout << endl;

    fstream plik("out.txt", ios::out | ios::app);
    if(plik.good())
    {
        plik.seekp(0, ios_base::end);
        plik << endl;
        plik.close();
    }
}

void interface::zaMaloTorow()
{
    cout << "LICZBA TOROW JEST ZA MALA BY POMIESCIC WSZYSTKIE REZERWACJE!" << endl;
    cout << "Rezerwacje, ktore nie zostaly przypisane:" << endl;

    fstream plik("out.txt", ios::out | ios::app);
    if(plik.good())
    {
        plik.seekp(0, ios_base::end);
        plik << "LICZBA TOROW JEST ZA MALA BY POMIESCIC WSZYSTKIE REZERWACJE!" << endl;
        plik << "Rezerwacje, ktore nie zostaly przypisane:" << endl;
        plik.close();
    }
}

void interface::podsumowanie(int i)
{
    cout << "PODSUMOWUJAC kregielnia zarobi na " << i << " godzinach gry w tym przypadku" << endl;
    fstream plik("out.txt", ios::out | ios::app);
    if(plik.good())
    {
        plik.seekp(0, ios_base::end);
        plik << "PODSUMOWUJAC kregielnia zarobi na " << i << " godzinach gry w tym przypadku" << endl;
        plik.close();
    }
}

void interface::wypiszLiczbeTorowIRezerwacji(int a, int b)
{
    cout << "Liczba torow to " << a << endl;
    cout << "Liczba rezerwacji to " << b << endl;
    cout << "Rezerwacje: " << endl;

    fstream plik("out.txt", ios::out);
    if(plik.good())
    {
        plik.seekp(0, ios_base::end);
        plik << "Liczba torow to " << a << endl;
        plik << "Liczba rezerwacji to " << b << endl;
        plik << "Rezerwacje: " << endl;
        plik.close();
    }
}

void interface::wypiszRezerwacje(int a, int b, int c)
{
    cout << a << ") " << b << " - " << c << endl;

    fstream plik("out.txt", ios::out | ios::app);
    if(plik.good())
    {
        plik.seekp(0, ios_base::end);
        plik << a << ") " << b << " - " << c << endl;
        plik.close();
    }
}

void interface::wypiszZaDuzaLiczbeTorowIRezerwacji(int a, int b)
{
    cout << "Liczba torow to " << a << endl;
    cout << "Liczba rezerwacji to " << b << endl;
    cout << "LICZBA TOROW JEST ZA MALA BY POMIESCIC WSZYSTKIE REZERWACJE!" << endl;
    cout << "Rezerwacje, ktore nie zostaly przypisane:" << endl;

    fstream plik("out.txt", ios::out | ios::app);
    if(plik.good())
    {
        plik.seekp(0, ios_base::end);
        plik << "Liczba torow to " << a << endl;
        plik << "Liczba rezerwacji to " << b << endl;
        plik << "LICZBA TOROW JEST ZA MALA BY POMIESCIC WSZYSTKIE REZERWACJE!" << endl;
        plik << "Rezerwacje, ktore nie zostaly przypisane:" << endl;
        plik.close();
    }
}

int interface::okreslLiczbeTorow()
{
    int a;
    while(1)
    {
        cout << endl << "Podaj liczbe torow" << endl;
        cout << "Liczba torow: ";
        cin >> a;
        if(a > 0)
            return a;
        blednyWybor();
    }
}

int interface::wybierzTrybDzialania()
{
    int a;
    while(1)
    {
        cout << endl << "Podaj metode wprowadzenia danych rezerwacji" << endl;
        cout << "1. Losuj dane" << endl;
        cout << "2. Wprowadz dane z konsoli" << endl;
        cout << "3. Wprowadz dane z pliku" << endl;
        cout << "Tryb dzialania: ";
        cin >> a;
        if(a == 1 || a == 2 || a == 3)
            return a;
        blednyWybor();
    }
}

int interface::podajLiczbeRezerwacji()
{
    int a;
    while(1)
    {
        cout << endl << "Podaj liczbe rezerwacji" << endl;
        cout << "Liczba rezerwacji: ";
        cin >> a;
        if(a > 0)
            return a;
        blednyWybor();
    }
}

int interface::podajGodzineOtwarcia()
{
    int a;
    while(1)
    {
        cout << endl << "Podaj godzine otwarcia kregielni" << endl;
        cout << "Godzina otwarcia: ";
        cin >> a;
        if(a >= 0 && a < 24)
            return a;
        blednyWybor();
    }
}

int interface::podajGodzineZamkniecia(int godzinaOtwarcia)
{
    int a;
    while(1)
    {
        cout << endl << "Podaj godzine zamkniecia kregielni" << endl;
        cout << "Godzina zamkniecia: ";
        cin >> a;
        if(a > 0 && a <= 24 && a > godzinaOtwarcia)
            return a;
        blednyWybor();
    }
}

int interface::podajStartRezerwacji(int godzinaOtwarcia, int godzinaZmkniecia)
{
    int a;
    while(1)
    {
        cout << endl << "Podaj godzine rozpoczecia rezerwacji" << endl;
        cout << "Godzina rozpoczecia rezerwacji: ";
        cin >> a;
        if(a >= godzinaOtwarcia && a < godzinaZmkniecia)
            return a;
        blednyWybor();
    }
}

int interface::podajStopRezerwacji(int godzinaRozpoczecia, int godzinaZamkniecia)
{
    int a;
    while(1)
    {
        cout << endl << "Podaj godzine zakonczenia rezerwacji" << endl;
        cout << "Godzina zakonczenia rezerwacji: ";
        cin >> a;
        if(a > godzinaRozpoczecia && a <= godzinaZamkniecia)
            return a;
        blednyWybor();
    }
}

string interface::podajNazwePliku()
{
    string s;
    cout << endl << "Podaj nazwe pliku z danymi" << endl;
    cout << "Poprawny format pliku:" << endl;
    cout << "[Liczba rezerwacji]" << endl;
    cout << "[Godzina rozpoczecia pierwszej rezerwacji]" << endl;
    cout << "[Godzina zakonczenia pierwszej rezerwacji]" << endl;
    cout << "[Godzina rozpoczecia drugiej rezerwacji]" << endl;
    cout << "[Godzina zakonczenia drugiej rezerwacji]" << endl;
    cout << "itd." << endl;
    cout << "Nazwa pliku: ";
    cin >> s;
    return s;
}

void interface::blednyWybor()
{
    cout << endl << "Bledny wybor!" << endl;
}
