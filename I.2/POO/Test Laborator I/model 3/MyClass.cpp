#include "MyClass.h"

Multime::Multime()
{
    Count = 0;
}

Multime::Multime (int* Lista, int Count)
{
    Count = std::min (100, Count);
    this->Count = Count;
    memcpy (Numere, Lista, Count * sizeof (int)); //ca bajetii
    /*for (int i = 0; i < Count; ++i)
    {
        Numere[i] = *(lista+i);
    }*/
}

int Multime::Max()
{
    int maxi = -0x3f3f3f3f;
    for (int i = 0; i < Count; ++i)
    {
        if (Numere[i] > maxi) maxi = Numere[i];
    }
    return maxi;
}

int Multime::Min()
{
    int mini = 0x3f3f3f3f;
    for (int i = 0; i < Count; ++i)
    {
        if (Numere[i] < mini) mini = Numere[i];
    }
    return mini;
}

void Multime::Sort (int (*Compare) (int, int))
{
    for (int i = 0; i < Count - 1; ++i)
    {
        for (int j = i+1; j < Count; ++j)
        {
            if (Compare (Numere[i], Numere[j])) std::swap (Numere[i], Numere[j]);
        }
    }
}

int Multime::GetSize()
{
    return Count;
}

int& Multime::operator [] (int index)
{
    index = std::min (index, Count);
    return Numere[index];
}

Multime::operator double ()
{
    int sum = 0;
    for (int i = 0; i < Count; ++i)
    {
        sum += Numere[i];
    }
    return sum;
}

Multime operator & (Multime& m1, Multime& m2)
{
    Multime m3;
    for (int i = 0; i < m1.Count; ++i)
    {
        m3.Numere[m3.Count++] = m1.Numere[i];
    }
    for (int i = 0; i < m2.Count; ++i)
    {
        bool found = 0;
        for (int j = 0; j < m3.Count && !found; ++j)
        {
            if (m2.Numere[i] == m3.Numere[j]) found = 1;
        }
        if (!found)
        {
            m3.Numere[m3.Count++] = m2.Numere[i];
            if (m3.Count == 100) return m3;
        }
    }
    return m3;
}

Multime operator | (Multime& m1, Multime& m2)
{
    Multime m3;
    for (int i = 0; i < m1.Count; ++i)
    {
        bool found = 0;
        for (int j = 0; j < m2.Count && !found; ++j)
        {
            if (m1.Numere[i] == m2.Numere[j]) found = 1;
        }
        if (found)
        {
            m3.Numere[m3.Count++] = m1.Numere[i];
        }
    }
    return m3;
}
