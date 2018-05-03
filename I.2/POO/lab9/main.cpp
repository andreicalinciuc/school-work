#include "MyClass.h"

int main()
{
    int n = 5;
    int v[5] = {1, 5, 3, 4, 2};
    Array <int> a (v, n);
    
    for (auto it : a)  cout << a[it] << " ";
    cout << endl;
    auto cmp1 = [] (const int &e1, const int &e2) -> int {if (e1 == e2) return 1; else if (e1 < e2) return -1; else return 1;};
    a.Sort (cmp1);
    for (auto it : a) cout << a[it] << " ";
    cout << endl;
    
    a (v, n);
    for (auto it : a) cout << a[it] << " ";
    cout << endl;
    Compare *cmp2 = new IntCompare;
    a.Sort(cmp2);
    for (auto it : a) cout << a[it] << " ";
    cout << endl;
    delete cmp2;

    try
    {
        //cout << a[5];
        //int x = 6; a += x;
    }
    catch (exception& e)
    {
        cout << "Exceptie: " << e.what() << endl;
    }
}
