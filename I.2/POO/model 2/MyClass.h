#include <iostream>
#include <map>

using namespace std;


class ListaCumparaturi
{
    map <string, int> m;
  public:
    pair <string, int> Cumparaturi (string, int);
    ListaCumparaturi& operator += (pair <string, int>);
    ListaCumparaturi& operator -= (string);
    ListaCumparaturi operator | (ListaCumparaturi L2);
    void Print();
};
