#include "MyClass.h"
#include <iostream>

using namespace std;

int main()
{
    Punct p1 (-2, -2), p2 (2, -3), p3 (1, 1), p4 (8, 8), p5 (1, 1), p6 (1, 12), p7 (2, 4);
    Multime M, M2 = {p5, p6, p7};
    (((M += p1) += p2) += p3) += p4;
    double d = p1 | p3;
    cout << d << endl;
    M.Distanta_maxima_intre_puncte();
    M -= p4;
    M.Distanta_maxima_intre_puncte();
    cout << endl;
    M += M2;
    M.Afisare();
    return 0;
}
