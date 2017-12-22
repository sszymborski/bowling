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

        int okreslLiczbeTorow();
        int wybierzTrybDzialania();
        int podajLiczbeRezerwacji();
        int podajGodzineOtwarcia();
        int podajGodzineZamkniecia(int);

        void blednyWybor();

    protected:
    private:
};

#endif // INTERFACE_H
