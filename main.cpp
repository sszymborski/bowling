#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "algorithm.h"
#include "data.h"
#include "interface.h"

using namespace std;


int main()
{
    int liczbaTorow, godzinaOtwarcia, godzinaZamkniecia, liczbaRezerwacji, trybDzialania;
    interface interfejs;
    interfejs.witaj();
    liczbaTorow = interfejs.okreslLiczbeTorow();
    godzinaOtwarcia = interfejs.podajGodzineOtwarcia();
    godzinaZamkniecia = interfejs.podajGodzineZamkniecia(godzinaOtwarcia);
    trybDzialania = interfejs.wybierzTrybDzialania();

    if (trybDzialania == 1)
    {
        srand (time(NULL));
        liczbaRezerwacji = interfejs.podajLiczbeRezerwacji();
        int start[liczbaRezerwacji];
        int stop[liczbaRezerwacji];
        for(int i = 0; i < liczbaRezerwacji; ++i)
            start[i] = rand() % (godzinaZamkniecia-godzinaOtwarcia) + godzinaOtwarcia;
        for(int i = 0; i < liczbaRezerwacji; ++i)
        {
            stop[i] = rand() % (godzinaZamkniecia-godzinaOtwarcia) + godzinaOtwarcia + 1;
            if(stop[i]<=start[i])
                --i;
        }
        data dane(liczbaTorow);
        for(int i = 0; i < liczbaRezerwacji; ++i)
            dane.wstawRezerwacje(start[i], stop[i]);
        dane.pokazWszystko();
        algorithm algorytm(dane);
    }
    else if(trybDzialania == 2)
    {
        cout << "Jeszcze nie dzialam - konsola" << endl;
    }
    else if(trybDzialania == 3)
    {
        cout << "Jeszcze nie dzialam - plik" << endl;
    }
    else
        interfejs.blednyWybor();
    return 0;
}
