#include "MyClass.h"

pair <string, int> Cumparaturi (string s, int n)
{
    return make_pair(s, n);
}

ListaCumparaturi& ListaCumparaturi::operator += (pair <string, int> p)
{
    m.insert(p);
    return *this;
}

ListaCumparaturi& ListaCumparaturi::operator -= (string s)
{
    map <string, int>::iterator it = m.find(s);
    if (it != m.end()) m.erase(it);
    return *this;
}

ListaCumparaturi operator | (ListaCumparaturi L1, ListaCumparaturi L2)
{
    ListaCumparaturi L3;
    for (map <string, int>::iterator it = L1.m.begin(); it != L1.m.end(); ++it)
    {
        L3.m[it->first] += it->second;
    }
    for (map <string, int>::iterator it = L2.m.begin(); it != L2.m.end(); ++it)
    {
        L3.m[it->first] += it->second;
    }
    return L3;
}

void ListaCumparaturi::Print()
{
    for (map <string, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << ": " << it->second << ", ";
    }
    cout << "\n";
}
