#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Punct 
{
  public:
    int x, y;
    Punct (int, int);
    friend double operator | (Punct&, Punct&);
};

class Multime
{
    set <pair <int, int> > s;
  public:
    Multime();
    Multime (initializer_list <Punct>);
    Multime& operator += (Punct);
    Multime& operator += (Multime);
    Multime& operator -= (Punct);
    void Afisare();
    void Distanta_maxima_intre_puncte();
};
