#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>

using namespace std;

class interface
{
public:
    interface();
    virtual ~interface();
    void witaj();
    void brakTorow();
    void przypisano(int, int, int, int);
    void wyswietl(int);
    void enter();
    void wypiszLiczbeTorowIRezerwacji(int, int);
    void wypiszRezerwacje(int, int, int);
    void wypiszZaDuzaLiczbeTorowIRezerwacji(int, int);
    int okreslLiczbeTorow();
    int wybierzTrybDzialania();
    int podajLiczbeRezerwacji();
    int podajGodzineOtwarcia();
    int podajGodzineZamkniecia(int);
    int podajStartRezerwacji(int, int);
    int podajStopRezerwacji(int, int);
    string podajNazwePliku();
protected:
private:
    void blednyWybor();
};

#endif // INTERFACE_H
