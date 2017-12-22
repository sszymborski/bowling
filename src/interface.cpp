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

int interface::okreslLiczbeTorow()
{
    int a=0;
    do{
    cout << endl << "Podaj liczbe torow" << endl;
    cin >> a;
    }while(a<=0);
    return a;
}

int interface::wybierzTrybDzialania()
{
    int a;
    do{
    cout << endl << "Podaj metode wprowadzenia danych rezerwacji" << endl;
    cout << "1. Losuj dane" << endl;
    cout << "2. Wprowadz dane z konsoli" << endl;
    cout << "3. Wprowadz dane z pliku" << endl;
    cin >> a;
    }while(a!=1 && a!= 2 && a !=3);
    return a;
}

int interface::podajLiczbeRezerwacji()
{
    int a;
    do{
    cout << endl << "Podaj liczbe rezerwacji" << endl;
    cin >> a;
    }while(a<=0);
    return a;
}

int interface::podajGodzineOtwarcia()
{
    int a;
    do{
    cout << endl << "Podaj godzine otwarcia kregielni" << endl;
    cin >> a;
    }while(a<0 || a>=24);
    return a;
}

int interface::podajGodzineZamkniecia(int godzinaOtwarcia)
{
    int a;
    do{
    cout << endl << "Podaj godzine zamkniecia kregielni" << endl;
    cin >> a;
    }while((a<1 || a>=25) || a <= godzinaOtwarcia);
    return a;
}

int interface::podajStartRezerwacji(int godzinaOtwarcia, int godzinaZmkniecia)
{
    int a;
    do{
    cout << endl << "Podaj godzine rozpoczecia rezerwacji" << endl;
    cin >> a;
    }while(a<0 || a>=24 || a<godzinaOtwarcia || a>=godzinaZmkniecia);
    return a;
}

int interface::podajStopRezerwacji(int godzinaRozpoczecia, int godzinaZamkniecia)
{
    int a;
    do{
    cout << endl << "Podaj godzine zakonczenia rezerwacji" << endl;
    cin >> a;
    }while((a<1 || a>=25) || a <= godzinaRozpoczecia || a>godzinaZamkniecia);
    return a;
}

string interface::podajNazwePliku()
{
string a;
cout << endl << "Podaj nazwe pliku z danymi" << endl;
cin >> a;
return a;
}

void interface::blednyWybor()
{
    cout << "Bledny wybor" << endl;
}
