#include "interface.h"


interface::interface()
{
    //ctor
}

interface::~interface()
{
    //dtor
}

void interface::witaj()
{
    cout << "Witaj w systemie zarzadzania przydzialem torow w kregielni" << endl;
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
    cout << endl << "Podaj metode wprowadzenia danych" << endl;
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
    cout << endl << "Podaj liczbe rezerwacji do wylosowania" << endl;
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

int interface::podajGodzineZamkniecia(int i)
{
    int a;
    do{
    cout << endl << "Podaj godzine zamkniecia kregielni" << endl;
    cin >> a;
    }while((a<1 || a>=25) || a <= i);
    return a;
}

void interface::blednyWybor()
{
    cout << "Bledny wybor" << endl;
}
