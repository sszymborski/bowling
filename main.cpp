#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "algorithm.h"
#include "data.h"
#include "interface.h"

using namespace std;


int main()
{
//    algorithm algorytm;
//    data dane;
    interface interfejs;

    cout << "Hello world!" << endl;

    int liczbaTorow = interfejs.okresl();

    int odpowiedz = interfejs.start();

    if (odpowiedz == 1)
    {
        cout << "Losuje dane" << endl;
        srand (time(NULL));
        int liczbaProb = rand() % 20 + 1;
        cout << liczbaProb << endl;
        int start[liczbaProb];
        int stop[liczbaProb];

        for(int i = 0; i < liczbaProb; ++i)
        {
            start[i] = rand() % 16 + 8;
        }

        for(int i = 0; i < liczbaProb; ++i)
        {
            stop[i] = rand() % 16 + 9;
            if(stop[i]<=start[i])
            {
                --i;
            }
        }

        cout << "Wylosowano: " << endl;

        for(int i = 0; i < liczbaProb; ++i)
        {
        cout << i+1 << ") " << start[i] << " - " << stop[i] << endl;
        }

data dane(liczbaTorow);

for(int i = 0; i < liczbaProb; ++i)
{
dane.wstawRezerwacje(start[i], stop[i]);
}

dane.pokazWszystko();

algorithm algorytm(dane);

    }
    else if(odpowiedz == 2)
    {
        cout << "Jeszcze nie dzialam" << endl;
    }
    else
        cout << "Bledny wybor";



    return 0;
}
