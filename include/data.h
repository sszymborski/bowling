#ifndef DATA_H
#define DATA_H
#include <vector>
#include "interface.h"

class data
{
public:
    data(int);
    virtual ~data();
    int podajLiczbeTorow();
    int podajLiczbeRezerwacji();
    int podajStartyRezerwacji(int);
    int podajStopyRezerwacji(int);
    int podajGodzineOtwarcia();
    int podajGodzineZamkniecia();
    void ustalGodziny(int, int);
    void wstawRezerwacje(int, int);
    void pokazWszystko(interface &);
    void usun(int);
    void pokazCoZostalo( interface &);
protected:
private:
    std::vector<int> start;
    std::vector<int> stop;
    int godzinaOtwarcia;
    int godzinaZamkniecia;
    int liczbaTorow;
    int liczbaRezerwacji;
};

#endif // DATA_H
