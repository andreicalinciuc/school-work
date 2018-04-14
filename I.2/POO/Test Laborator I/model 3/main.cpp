#include "MyClass.h"
#include <iostream>

using namespace std;

int MyCompareFunction (int a, int b)
{
    return a > b;
}

int main()
{
    int Lista1[] = {4, 2, 1, 3, 5};
    Multime m (Lista1, 5);
    int Lista2[] = {3, 8, 7, 9, 2};
    Multime n (Lista2, 5);
    for (int i = 0; i < m.GetSize(); ++i) cout << m[i] << " "; cout << endl;
    m.Sort (MyCompareFunction);
    for (int i = 0; i < m.GetSize(); ++i) cout << m[i] << " "; cout << endl;
    cout << m.Min() << endl << m.Max() << endl << (double) m << endl << (m & n).GetSize() << endl << (m | n).GetSize();
}
