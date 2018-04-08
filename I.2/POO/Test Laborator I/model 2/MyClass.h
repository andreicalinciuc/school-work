#include <iostream>
#include <map>

using namespace std;

class Cumparaturi
{
  public:
    string s;
    int n;
    Cumparaturi (string, int);
};

class ListaCumparaturi
{
  protected:
    map <string, int> m;
  public:
    ListaCumparaturi& operator += (const Cumparaturi&);
    ListaCumparaturi& operator -= (string);
    friend ListaCumparaturi operator | (ListaCumparaturi, ListaCumparaturi);
    void Print();
};
