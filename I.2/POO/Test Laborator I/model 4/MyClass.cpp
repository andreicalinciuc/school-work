#include "MyClass.h"

map <string, int> RomanNumber::m ={ { "I", 1 }, { "II", 2 }, { "III", 3 }, { "IV", 4 }, { "V", 5 }, { "VI", 6 }, { "VII", 7 }, { "VIII", 8 }, { "IX", 9 }, { "X", 10 },{ "XI", 11 }, { "XII", 12 }, { "XIII", 13 }, { "XIV", 14 }, { "XV", 15 }, { "XVI", 16 }, { "XVII", 17 }, { "XVIII", 18 }, { "XIX", 19 }, { "XX", 20 }, { "XXI", 21 }, { "XXII", 22 }, { "XXIII", 23 }, { "XXIV", 24 }, { "XXV", 25 }, { "XXVI", 26 }, { "XXVII", 27 }, { "XXVIII", 28 }, { "XXIX", 29 }, { "XXX", 30 } };

RomanNumber::RomanNumber ()
{

}

RomanNumber::RomanNumber (string s)
{
    this->s = s;
}

RomanNumber::RomanNumber (initializer_list <char> args)
{
    for (initializer_list <char>::iterator it = args.begin(); it != args.end(); ++it)
    {
        s += *it;
    }
}

int RomanNumber::FromRoman (const char* number)
{
    string aux = number;
    return m.find(aux)->second;
}

const char* RomanNumber::FromArabic (int number)
{
    for (map <string, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        if (it->second == number) return it->first.c_str();
    }
    return nullptr;
}

RomanNumber::operator const char* ()
{
    return s.c_str();
}

int RomanNumber::GetLen()
{
    return s.length();
}

char RomanNumber::operator [] (int index)
{
    return s[index];
}

RomanNumber operator + (RomanNumber N1, int n2)
{
    int n1 = RomanNumber::FromRoman (N1.s.c_str());
    RomanNumber aux (RomanNumber::FromArabic (n1+n2));
    return aux;
}

RomanNumber operator + (RomanNumber N1, RomanNumber N2)
{
    int n1 = RomanNumber::FromRoman (N1.s.c_str());
    int n2 = RomanNumber::FromRoman (N2.s.c_str());
    RomanNumber aux (RomanNumber::FromArabic (n1+n2));
    return aux;
}

RomanNumber operator - (RomanNumber N1, int n2)
{
    int n1 = RomanNumber::FromRoman (N1.s.c_str());
    RomanNumber aux (RomanNumber::FromArabic (n1 - n2));
    return aux;
}

RomanNumber operator - (RomanNumber N1, RomanNumber N2)
{
    int n1 = RomanNumber::FromRoman (N1.s.c_str());
    int n2 = RomanNumber::FromRoman (N2.s.c_str());
    RomanNumber aux (RomanNumber::FromArabic (n1 - n2));
    return aux;
}

RomanNumber operator * (RomanNumber N1, int n2)
{
    int n1 = RomanNumber::FromRoman (N1.s.c_str());
    RomanNumber aux (RomanNumber::FromArabic (n1 * n2));
    return aux;
}

RomanNumber operator * (RomanNumber N1, RomanNumber N2)
{
    int n1 = RomanNumber::FromRoman (N1.s.c_str());
    int n2 = RomanNumber::FromRoman (N2.s.c_str());
    RomanNumber aux (RomanNumber::FromArabic (n1 * n2));
    return aux;
}

RomanNumber operator / (RomanNumber N1, int n2)
{
    int n1 = RomanNumber::FromRoman (N1.s.c_str());
    RomanNumber aux (RomanNumber::FromArabic (n1 / n2));
    return aux;
}

RomanNumber operator / (RomanNumber N1, RomanNumber N2)
{
    int n1 = RomanNumber::FromRoman (N1.s.c_str());
    int n2 = RomanNumber::FromRoman (N2.s.c_str());
    RomanNumber aux (RomanNumber::FromArabic (n1 / n2));
    return aux;
}
