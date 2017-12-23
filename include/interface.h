#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <fstream>

using namespace std;

class interface
{
public:
    interface();
    virtual ~interface();
    void witaj();
    void brakTorow();
    void przypisano(int, int, int, int);
    void niePrzypisano(int, int, int);
    void wyswietl(int);
    void enter();
    void zaMaloTorow();
    void podsumowanie(int, int);
    void wypiszLiczbeTorowIRezerwacji(int, int);
    void wypiszRezerwacje(int, int, int);
    void wypiszZaDuzaLiczbeTorowIRezerwacji(int, int);
    void pokazCzas(double);
    int okreslLiczbeTorow();
    int wybierzTrybDzialania();
    int wybierzNumerAlgorytmu();
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
