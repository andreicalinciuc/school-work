#include "Forme.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    Forma *a[3];
    a[0] = new Dreptunghi (4, 5);
    a[1] = new Cerc (3);
    a[2] = new Triunghi (2, 3, 1, 1, 4, 0);
    for (unsigned int i=0; i<3; ++i)
    {
        cout << a[i]->GetName() << " " << a[i]->ComputeArea() << "\n";
    }
}
