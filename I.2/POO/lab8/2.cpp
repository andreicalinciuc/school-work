#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template <class T>
void Sort (vector <T> &lista, std::function<int (T &e1, T &e2)> Compare)
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
    std::function <int (int&, int&)> cmp = [] (int &e1, int &e2) -> int {return e1 > e2;};
    Sort(v, cmp);
    for (i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}
