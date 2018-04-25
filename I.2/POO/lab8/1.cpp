#include <iostream>
#include <vector>

using namespace std;

template <class T>
int cmp (T &e1, T &e2)
{
    return e1 > e2;
}

template <class T>
void Sort(std::vector<T> &lista, int (*Compare)(T &e1, T &e2))
{
    for (unsigned int i = 0; i < lista.size() - 1; i++)
    {
        for (unsigned int j = i + 1; j < lista.size(); j++)
        {
            if (Compare (lista[i], lista[j])) swap (lista[i], lista[j]);
        }
    }
}

int main()
{
    int i, n, x;
    vector <int> v;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back (x);
    }
    Sort(v, cmp);
    for (i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}
