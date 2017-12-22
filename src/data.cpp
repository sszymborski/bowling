#include "data.h"


data::data(int i)
{
    liczbaTorow = i;
    liczbaRezerwacji = 0;
}

data::~data()
{
    //dtor
}

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

void data::wstawRezerwacje(int i, int j)
{
    ++liczbaRezerwacji;
    start.push_back(i);
    stop.push_back(j);

}

void data::pokazWszystko()
{
    cout << "Liczba torow to " << podajLiczbeTorow() << endl;
    cout << "Liczba rezerwacji to " << podajLiczbeRezerwacji() << endl;
    cout << "Rezerwacje: " << endl;

    for(int i = 0; i <  podajLiczbeRezerwacji(); ++i)
    {
        cout << i+1 << ")) " << podajStartyRezerwacji(i) << " - " << podajStopyRezerwacji(i) << endl;
    }

}

void data::usun(int i)
{
    start[i] = 0;// start[liczbaRezerwacji-1];
    stop[i] = 0;// stop[liczbaRezerwacji-1];
    //--liczbaRezerwacji;
}
