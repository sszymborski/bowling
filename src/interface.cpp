#include "interface.h"


interface::interface()
{
    //ctor
}

interface::~interface()
{
    //dtor
}

int interface::start()
{
    int a;
    cout << "Podaj metode wprowadzenia danych" << endl;
    cout << "1. Losuj dane" << endl;
    cout << "2. Wprowadz dane" << endl;
    cin >> a;
    return a;
}

int interface::okresl()
{
    int a;
    cout << "Podaj liczbe torow" << endl;
    cin >> a;
    return a;
}
