#include <algorithm>
#include <cstring>

class Multime
{
    int Numere[100];
    int Count;
  public:
    Multime();
    Multime (int* Lista, int size);
    int Max();
    int Min();
    void Sort (int (*) (int, int));
    int GetSize();
    int& operator [] (int index);
    operator double ();
    friend Multime operator & (Multime&, Multime&);
    friend Multime operator | (Multime&, Multime&);
};
