#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>

using namespace std;


class data
{
    public:
        data(int);
        virtual ~data();
        int podajLiczbeTorow();
        int podajLiczbeRezerwacji();
        int podajStartyRezerwacji(int);
        int podajStopyRezerwacji(int);
        void wstawRezerwacje(int, int);
        void pokazWszystko();
        void usun(int);
        void pokazCoZostalo();

    protected:
    private:

    int liczbaTorow;
    int liczbaRezerwacji;
    std::vector<int> start; //start[9]
    std::vector<int> stop;

};

#endif // DATA_H
