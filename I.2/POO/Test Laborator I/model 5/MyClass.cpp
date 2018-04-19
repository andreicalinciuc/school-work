#include "MyClass.h"

Punct::Punct (int x, int y)
{
    this->x = x;
    this->y = y;
}

double operator | (Punct& p1, Punct& p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

Multime::Multime()
{

}

Multime::Multime (initializer_list <Punct> args)
{
    for (initializer_list <Punct>::iterator it = args.begin(); it != args.end(); ++it)
    {
        s.insert (make_pair (it->x, it->y));
    }
}

Multime& Multime::operator += (Punct p)
{
    s.insert (make_pair (p.x, p.y));
    return *this;
}

Multime& Multime::operator += (Multime m)
{
    for (set <pair <int, int> >::iterator it = m.s.begin(); it != m.s.end(); ++it)
    {
        s.insert (*it);
        //s.insert (make_pair (it->first, it->second));
    }
    return *this;
}

Multime& Multime::operator -= (Punct p)
{
    set <pair <int, int> >::iterator it = s.find (make_pair (p.x, p.y));
    s.erase (it);
    return *this;
}

void Multime::Afisare()
{
    for (set <pair <int, int> >::iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
}

void Multime::Distanta_maxima_intre_puncte()
{
    double maxi = 0;
    for (auto it1 : s)
    {
        for (auto it2 : s)
        {
            Punct p1 (it1.first, it1.second);
            Punct p2 (it2.first, it2.second);
            double distanta = p1 | p2;
            if (distanta > maxi) maxi = distanta;
        }
    }
    cout << "Distanta maxima intre 2 puncte este: " << maxi << endl;
}

