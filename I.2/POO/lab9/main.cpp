#include "MyClass.h"

using namespace std;

int main()
{
    Array <int> a;
    int x = 5;
    int y = 4;
    a.List = new int* [100];
    a.List[0] = &x;
    a.List[1] = &y;
    a.Size = 2;
    //auto cmp = [] (const int &e1, const int &e2) -> int {return e1 > e2;};
    //a.Sort (cmp);
    Compare *cmp = new IntCompare;
    a.Sort(cmp);
    cout << *a.List[0] << " " << *a.List[1] << " " << a.BinarySearch (y);
}
