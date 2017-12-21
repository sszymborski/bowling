#include "algorithm.h"
#include "data.h"

#include"stdio.h"

using namespace std;


algorithm::algorithm(data & d)
{
cout << "Hej. Liczba torow to " << d.podajLiczbeTorow() << endl;

int minimum = 24;
int i;
int poprzedniStop = 0;
bool czyPrzypisano = 0;
int pamietaj;
int ktoryTor=1;

while(d.podajLiczbeRezerwacji() && d.podajLiczbeTorow())
{
czyPrzypisano=0;
for(i = 0; i < d.podajLiczbeRezerwacji(); ++i)
{
    if(d.podajStartyRezerwacji(i)-poprzedniStop >= 0 && d.podajStartyRezerwacji(i) - poprzedniStop < minimum)
    {
        minimum = d.podajStartyRezerwacji(i) - poprzedniStop;
        pamietaj = i;
        czyPrzypisano = 1;
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
        cout << "Brak torow" << endl;
}



poprzedniStop = d.podajStopyRezerwacji(pamietaj);
minimum = 24;
cout << "Do " << ktoryTor << " toru przypisano rezerwacje: " << pamietaj << ") " << d.podajStartyRezerwacji(pamietaj) << " - " << d.podajStopyRezerwacji(pamietaj) << endl;
d.usun(pamietaj);


}








/*
for(int j; j < d.podajLiczbeTorow(); ++j)
{

for(i = 0; i < d.podajLiczbeRezerwacji(); ++i)
{

if(d.podajStartyRezerwacji(i)-poprzedniStop > 0 && d.podajStartyRezerwacji(i) - poprzedniStop < minimum)

        minimum = d.podajStartyRezerwacji(i);
        pamietaj = i;
}

cout << minimum << endl;

poprzedniStop = d.podajStopyRezerwacji(pamietaj);

cout << j << "tor, " << pamietaj << " " <<  d.podajStartyRezerwacji(pamietaj) << "-"  << d.podajStopyRezerwacji(pamietaj);

d.usun(pamietaj);

minimum = 25;

}
*/


}

algorithm::~algorithm()
{
    //dtor
}
