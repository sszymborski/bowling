#include "algorithm.h"
#include "data.h"

#include"stdio.h"

using namespace std;


algorithm::algorithm(data & d)
{
cout << "hej" << d.podajLiczbeTorow() << endl;

int minimum = 25;
int i;
int poprzedniStop = 0;
int pamietaj;

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


}

algorithm::~algorithm()
{
    //dtor
}
