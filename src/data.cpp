#include "data.h"

data::data(int i)
{
    liczbaTorow = i;
    liczbaRezerwacji = 0;
}

data::~data()
{}

int data::podajLiczbeTorow()
{
    return liczbaTorow;
}

int data::podajLiczbeRezerwacji()
{
    return liczbaRezerwacji;
}

int data::podajStartyRezerwacji(int i)
{
    return start[i];
}

int data::podajStopyRezerwacji(int i)
{
    return stop[i];
}

int data::podajGodzineOtwarcia()
{
    return godzinaOtwarcia;
}

int data::podajGodzineZamkniecia()
{
    return godzinaZamkniecia;
}

void data::ustalGodziny(int i, int j)
{
    godzinaOtwarcia = i;
    godzinaZamkniecia = j;
}

void data::wstawRezerwacje(int i, int j)
{
    ++liczbaRezerwacji;
    start.push_back(i);
    stop.push_back(j);
}

void data::usun(int i)
{
    start[i] = 0;
    stop[i] = 0;
}

void data::pokazWszystko(interface & interfejs)
{
    interfejs.wypiszLiczbeTorowIRezerwacji(podajLiczbeTorow(), podajLiczbeRezerwacji());
    for(int i = 0; i <  podajLiczbeRezerwacji(); ++i)
        interfejs.wypiszRezerwacje(i + 1, podajStartyRezerwacji(i), podajStopyRezerwacji(i));
}

void data::pokazCoZostalo(interface & interfejs)
{
    interfejs.wypiszZaDuzaLiczbeTorowIRezerwacji(podajLiczbeTorow(), podajLiczbeRezerwacji());
    for(int i = 0; i <  podajLiczbeRezerwacji(); ++i)
        if(podajStartyRezerwacji(i) || podajStopyRezerwacji(i))
            interfejs.wypiszRezerwacje(i + 1, podajStartyRezerwacji(i), podajStopyRezerwacji(i));
}
