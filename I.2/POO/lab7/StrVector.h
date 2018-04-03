#include <iostream>
#include <cstring>
#include <initializer_list>

using namespace std;

const int Nmax = 100;

class StrIterator
{
  public:
    char** it;
    StrIterator operator ++ ()
    {
        ++it;
        return *this;
    }
    StrIterator operator ++ (int)
    {
        StrIterator aux = *this;
        ++it;
        return aux;
    }
    char* operator * ()
    {
        return *it;
    }
    bool operator != (StrIterator other)
    {
        return (*this).it != other.it;
    }
};

class StrVector
{
    char *c[Nmax];
    unsigned int size = 0;
  public:
    StrVector (initializer_list <const char*> args)
    {
        for (auto it : args)
        {
            c[size] = new char (strlen (it) + 1);
            strcpy (c[size], it);
            size++;
        }
    }
    int GetCount()
    {
        return size;
    }
    StrIterator GetIterator()
    {
        StrIterator aux;
        aux.it = &c[0];
        return aux;
    }
    StrIterator begin()
    {
        StrIterator aux;
        aux.it = &c[0];
        return aux;
    }
    StrIterator end()
    {
        StrIterator aux;
        aux.it = &c[size];
        return aux;
    }
};
