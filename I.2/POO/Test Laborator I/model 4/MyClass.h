#include <map>
#include <vector>

using namespace std;

class RomanNumber
{
    string s;
    static map <string, int> m;
    static bool InitializedVector;
    static vector <string> v;
  public:
    RomanNumber();
    RomanNumber (string s);
    RomanNumber (initializer_list <char>);
    static int FromRoman (const char*);
    static const char* FromArabic (int);
    operator const char* ();
    int GetLen();
    char operator [] (int);
    friend RomanNumber operator + (RomanNumber, int);
    friend RomanNumber operator + (RomanNumber, RomanNumber);
    friend RomanNumber operator - (RomanNumber, int);
    friend RomanNumber operator - (RomanNumber, RomanNumber);
    friend RomanNumber operator * (RomanNumber, int);
    friend RomanNumber operator * (RomanNumber, RomanNumber);
    friend RomanNumber operator / (RomanNumber, int);
    friend RomanNumber operator / (RomanNumber, RomanNumber);
};
