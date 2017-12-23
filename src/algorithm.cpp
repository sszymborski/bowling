#include "algorithm.h"

algorithm::algorithm()
{}

algorithm::~algorithm()
{}

void algorithm::pierwszy(data & d, interface & interfejs)
{
    int i, j, g, pamietaj;
    for(i = 0; i < d.podajLiczbeTorow(); ++i)
    {
        tabela.push_back(vector<int>());
        for(j = 0; j < d.podajGodzineZamkniecia() - d.podajGodzineOtwarcia(); ++j)
            tabela[i].push_back(0);
    }
    int minimum = 24;
    int ktoryTor = 1;
    int poprzedniStop = 0;
    int wstawiono = 0;
    bool czyPrzypisano = 0;
    while(wstawiono < d.podajLiczbeRezerwacji() && d.podajLiczbeTorow())
    {
        czyPrzypisano = 0;
        for(i = 0; i < d.podajLiczbeRezerwacji(); ++i)
        {
            if(d.podajStartyRezerwacji(i))
            {
                if(d.podajStartyRezerwacji(i) - poprzedniStop == 0)
                {
                    minimum = d.podajStartyRezerwacji(i) - poprzedniStop;
                    pamietaj = i;
                    czyPrzypisano = 1;
                    break;
                }
                if(d.podajStartyRezerwacji(i) - poprzedniStop >= 0 && d.podajStartyRezerwacji(i) - poprzedniStop < minimum)
                {
                    minimum = d.podajStartyRezerwacji(i) - poprzedniStop;
                    pamietaj = i;
                    czyPrzypisano = 1;
                }
            }
        }
        if(!czyPrzypisano)
        {
            if(ktoryTor < d.podajLiczbeTorow())
            {
                ++ktoryTor;
                poprzedniStop = 0;
                minimum = 24;
                continue;
            }
            else
                interfejs.brakTorow();
            d.pokazCoZostalo(interfejs);
            break;
        }
        poprzedniStop = d.podajStopyRezerwacji(pamietaj);
        minimum = 24;
        interfejs.przypisano(ktoryTor, pamietaj, d.podajStartyRezerwacji(pamietaj), d.podajStopyRezerwacji(pamietaj));
        for(g = d.podajStartyRezerwacji(pamietaj) - d.podajGodzineOtwarcia(); g < d.podajStopyRezerwacji(pamietaj) - d.podajGodzineOtwarcia(); ++g)
            tabela[ktoryTor - 1][g] = 1;
        d.usun(pamietaj);
        ++wstawiono;
    }
    for(i = 0; i < d.podajLiczbeTorow(); ++i)
    {
        for(j = 0; j < d.podajGodzineZamkniecia() - d.podajGodzineOtwarcia(); ++j)
            interfejs.wyswietl(tabela[i][j]);
        interfejs.enter();
    }
}
