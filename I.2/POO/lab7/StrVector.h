#include <iostream>
#include <cstring>
#include <initializer_list>

using namespace std;

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
    char** c;
    unsigned int size;
  public:
    StrVector (initializer_list <const char*> args)
    { 
        size = args.size();
        c = new char* [size];
        unsigned int index = 0;
        for (auto it : args)
        {
            c[index] = new char [strlen (it) + 1];
            strcpy (c[index], it);
            ++index;
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
