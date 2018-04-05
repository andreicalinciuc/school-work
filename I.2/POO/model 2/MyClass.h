#include <iostream>
#include <map>

using namespace std;

pair <string, int> Cumparaturi (string, int);

class ListaCumparaturi
{
  protected:
    map <string, int> m;
  public:
    ListaCumparaturi& operator += (pair <string, int>);
    ListaCumparaturi& operator -= (string);
    friend ListaCumparaturi operator | (ListaCumparaturi, ListaCumparaturi);
    void Print();
};
