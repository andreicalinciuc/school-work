#include "MyClass.h"

using namespace std;

int main()
{
    ListaCumparaturi L;
    (L += L.Cumparaturi("paine", 5)) += L.Cumparaturi("peste", 2);
    L.Print(); // Afiseaza "paine : 5, peste : 2"
    L -= "peste";
    L.Print(); // Afiseaza "paine: 5"
    ListaCumparaturi L2;
    (L2 += L.Cumparaturi("lapte", 4)); L2 += L.Cumparaturi("paine", -2);
    (L | L2).Print(); // Afiseaza "lapte: 4, paine: 3"
    return 0;
}
