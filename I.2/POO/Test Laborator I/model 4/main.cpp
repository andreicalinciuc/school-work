#include "MyClass.h"
#include <iostream>

using namespace std;

int main()
{
    RomanNumber n1 ("I"), n2 ("V"), n3;
    n3 = (((n1 + n2) * 3) - n2) / n2;
    cout << "n3 = " << (const char*) n3 << " " << RomanNumber::FromRoman ((const char*) n3) << endl;
    n3 = n3 + 10;
    cout << "n3 = " << (const char*) n3 << " " << RomanNumber::FromRoman ((const char*) n3) << endl;
    cout << "10 arabic = " << RomanNumber::FromArabic (10) << endl;
    for (int tr = 0; tr < n3.GetLen(); tr++)
    {
        cout << "Char[" << tr << "] = " << n3[tr] << endl;
    }
    RomanNumber n4 = {'X', 'I', 'X'};
    cout << "n4 = " << (const char*) n4 << " " << RomanNumber::FromRoman ((const char*) n4) << endl;
    return 0;
}
