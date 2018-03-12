#include "Forme.h"
#include <bits/stdc++.h>

Dreptunghi::Dreptunghi (int lungime, int latime)
{
    Lungime = lungime;
    Latime = latime;
}

double Dreptunghi::ComputeArea()
{
    return 1.0*Lungime*Latime;
}

const char* Dreptunghi::GetName()
{
    return "Dreptunghi";
}

Cerc::Cerc (int raza)
{
    Raza = raza;
}

double Cerc::ComputeArea()
{
    return 3.14*Raza*Raza;
}

const char* Cerc::GetName()
{
    return "Cerc";
}

Triunghi::Triunghi (int x1, int y1, int x2, int y2, int x3, int y3)
{
    X1 = x1;
    Y1 = y1;
    X2 = x2;
    Y2 = y2;
    X3 = x3;
    Y3 = y3;
}

double Triunghi::ComputeArea()
{
    return 0.5*abs(1.0*(X1-X3)*(Y2-Y1)-1.0*(X1-X2)*(Y3-Y1));
}

const char* Triunghi::GetName()
{
    return "Triunghi";
}
