#include <time.h>
#include "algorithm.h"
#include "data.h"
#include "interface.h"

int main()
{
    int i, liczbaTorow, godzinaOtwarcia, godzinaZamkniecia, liczbaRezerwacji, trybDzialania;
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
        for(i = 0; i < liczbaRezerwacji; ++i)
            start[i] = rand() % (godzinaZamkniecia-godzinaOtwarcia) + godzinaOtwarcia;
        for(i = 0; i < liczbaRezerwacji; ++i)
        {
            stop[i] = rand() % (godzinaZamkniecia-godzinaOtwarcia) + godzinaOtwarcia + 1;
            if(stop[i]<=start[i])
                --i;
        }
        data dane(liczbaTorow);
        for(i = 0; i < liczbaRezerwacji; ++i)
            dane.wstawRezerwacje(start[i], stop[i]);
        dane.pokazWszystko();
        algorithm algorytm(dane);
    }
    else if(trybDzialania == 2)
    {
        srand (time(NULL));
        liczbaRezerwacji = interfejs.podajLiczbeRezerwacji();
        int start[liczbaRezerwacji];
        int stop[liczbaRezerwacji];
        for(i = 0; i < liczbaRezerwacji; ++i)
        {
            start[i] = interfejs.podajStartRezerwacji(godzinaOtwarcia,godzinaZamkniecia);
            stop[i] = interfejs.podajStopRezerwacji(start[i], godzinaZamkniecia);
        }
        data dane(liczbaTorow);
        for(i = 0; i < liczbaRezerwacji; ++i)
            dane.wstawRezerwacje(start[i], stop[i]);
        dane.pokazWszystko();
        algorithm algorytm(dane);
    }
    else if(trybDzialania == 3)
    {
      //  cout << "Jeszcze nie dzialam - plik" << endl;
    }
    else
        interfejs.blednyWybor();
    return 0;
}
