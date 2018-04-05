#include <iostream>
#include <map>

using namespace std;


class ListaCumparaturi
{
  protected:
    map <string, int> m;
  public:
    pair <string, int> Cumparaturi (string, int);
    ListaCumparaturi& operator += (pair <string, int>);
    ListaCumparaturi& operator -= (string);
    friend ListaCumparaturi operator | (ListaCumparaturi, ListaCumparaturi);
    void Print();
};
