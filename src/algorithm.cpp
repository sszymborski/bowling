#include "algorithm.h"

algorithm::algorithm()
{}

algorithm::~algorithm()
{}

void algorithm::pierwszy(data & d, interface & interfejs)
{
    int liczbaPrzypisanychGodzin = 0;
    int liczbaOdwolanychRezerwacji = 0;
    int i, j, g, pamietaj;
    for(i = 0; i < d.podajLiczbeTorow(); ++i)
    {
        tabela.push_back(vector<int>());
        for(j = 0; j < d.podajGodzineZamkniecia() - d.podajGodzineOtwarcia(); ++j)
            tabela[i].push_back(0);
    }
    int minimum = 24;
    int ktoryTor = 1;
    int poprzedniStop = d.podajGodzineOtwarcia();
    int wstawiono = 0;
    bool czyPrzypisano = 0;

    auto t1 = std::chrono::high_resolution_clock::now();

    while(wstawiono < d.podajLiczbeRezerwacji())
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
                poprzedniStop = d.podajGodzineOtwarcia();
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

    auto t2 = std::chrono::high_resolution_clock::now();

    for(i = 0; i < d.podajLiczbeTorow(); ++i)
    {
        for(j = 0; j < d.podajGodzineZamkniecia() - d.podajGodzineOtwarcia(); ++j)
        {
            interfejs.wyswietl(tabela[i][j]);
            if(tabela[i][j])
                ++liczbaPrzypisanychGodzin;
        }
        interfejs.enter();
    }
    for(int i = 0; i < d.podajLiczbeRezerwacji(); ++i)
        if(d.podajStartyRezerwacji(i) || d.podajStopyRezerwacji(i))
            ++liczbaOdwolanychRezerwacji;
    interfejs.podsumowanie(liczbaPrzypisanychGodzin, liczbaOdwolanychRezerwacji, ktoryTor);
    interfejs.pokazCzas(std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count());
}

void algorithm::drugi(data & d, interface & interfejs)
{
    int liczbaPrzypisanychGodzin = 0;
    int liczbaOdwolanychRezerwacji = 0;
    int i, j, g, pamietaj;
    int maksimum = 0;
    int wstawiono = 0;
    int ktoryTor = 1;
    int ostatniTor = 1;
    bool wolne = 1;
    bool zaMaloTorow = 0;
    for(i = 0; i < d.podajLiczbeTorow(); ++i)
    {
        tabela.push_back(vector<int>());
        for(j = 0; j < d.podajGodzineZamkniecia() - d.podajGodzineOtwarcia(); ++j)
            tabela[i].push_back(0);
    }

    for(i = 0; i < d.podajLiczbeRezerwacji(); ++i)
    {
        pozostaleStarty.push_back(d.podajStartyRezerwacji(i));
        pozostaleStopy.push_back(d.podajStopyRezerwacji(i));
    }

    auto t1 = std::chrono::high_resolution_clock::now();

    while(wstawiono < d.podajLiczbeRezerwacji() && ktoryTor <= d.podajLiczbeTorow())
    {
        for(i = 0; i < d.podajLiczbeRezerwacji(); ++i)
            if(d.podajStopyRezerwacji(i) - d.podajStartyRezerwacji(i) > maksimum)
            {
                maksimum = d.podajStopyRezerwacji(i) - d.podajStartyRezerwacji(i);
                pamietaj = i;
            }

        while(ktoryTor<=d.podajLiczbeTorow())
        {
            wolne = 1;
            for(i=d.podajStartyRezerwacji(pamietaj)-d.podajGodzineOtwarcia(); i < d.podajStopyRezerwacji(pamietaj)-d.podajGodzineOtwarcia(); ++i)
                if(tabela[ktoryTor-1][i])
                    wolne = 0;
            if(wolne)
                break;
            ++ktoryTor;
            ktoryTor>ostatniTor?ostatniTor=ktoryTor:ostatniTor=ostatniTor;
        }


        if(wolne)
        {
            interfejs.przypisano(ktoryTor, pamietaj, d.podajStartyRezerwacji(pamietaj), d.podajStopyRezerwacji(pamietaj));
            for(g = d.podajStartyRezerwacji(pamietaj) - d.podajGodzineOtwarcia(); g < d.podajStopyRezerwacji(pamietaj) - d.podajGodzineOtwarcia(); ++g)
                tabela[ktoryTor - 1][g] = 1;
            d.usun(pamietaj);
            ++wstawiono;
            maksimum=0;
            ktoryTor=1;
        }
        else
        {
            ktoryTor = 1;
            interfejs.niePrzypisano(pamietaj, d.podajStartyRezerwacji(pamietaj), d.podajStopyRezerwacji(pamietaj));
            d.zapamietaj(pamietaj);
            maksimum = 0;
            zaMaloTorow = 1;
            ++wstawiono;
            ostatniTor = d.podajLiczbeTorow();
        }

    }


    auto t2 = std::chrono::high_resolution_clock::now();

    if(zaMaloTorow)
    {
        interfejs.zaMaloTorow();
        for(i=0; i<d.podajLiczbeRezerwacji(); ++i)
            if(d.podajStartyRezerwacji(i)==-1)
            {
                interfejs.niePrzypisano(i, pozostaleStarty[i], pozostaleStopy[i]);
                ++liczbaOdwolanychRezerwacji;
            }


    }
    for(i = 0; i < d.podajLiczbeTorow(); ++i)
    {
        for(j = 0; j < d.podajGodzineZamkniecia() - d.podajGodzineOtwarcia(); ++j)
        {
            interfejs.wyswietl(tabela[i][j]);
            if(tabela[i][j])
                ++liczbaPrzypisanychGodzin;
        }
        interfejs.enter();
    }
    interfejs.podsumowanie(liczbaPrzypisanychGodzin, liczbaOdwolanychRezerwacji, ostatniTor);
    interfejs.pokazCzas(std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count());
}


void algorithm::trzeci(data & d, interface & interfejs)
{
    int liczbaPrzypisanychGodzin = 0;
    int liczbaOdwolanychRezerwacji = 0;
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

    auto t1 = std::chrono::high_resolution_clock::now();

    while(wstawiono < d.podajLiczbeRezerwacji())
    {
        czyPrzypisano = 0;
        for(i = 0; i < d.podajLiczbeRezerwacji(); ++i)
        {
            if(d.podajStartyRezerwacji(i))
            {
                if(d.podajStartyRezerwacji(i) - poprzedniStop >= 0 && d.podajStopyRezerwacji(i) - poprzedniStop > 0 && d.podajStopyRezerwacji(i) - poprzedniStop < minimum)
                {
                    minimum = d.podajStopyRezerwacji(i) - poprzedniStop;
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

    auto t2 = std::chrono::high_resolution_clock::now();

    for(i = 0; i < d.podajLiczbeTorow(); ++i)
    {
        for(j = 0; j < d.podajGodzineZamkniecia() - d.podajGodzineOtwarcia(); ++j)
        {
            interfejs.wyswietl(tabela[i][j]);
            if(tabela[i][j])
                ++liczbaPrzypisanychGodzin;
        }
        interfejs.enter();
    }
    for(int i = 0; i < d.podajLiczbeRezerwacji(); ++i)
        if(d.podajStartyRezerwacji(i) || d.podajStopyRezerwacji(i))
            ++liczbaOdwolanychRezerwacji;
    interfejs.podsumowanie(liczbaPrzypisanychGodzin, liczbaOdwolanychRezerwacji, ktoryTor);
    interfejs.pokazCzas(std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count());
}
