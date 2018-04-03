#include <bits/stdc++.h>

using namespace std;

bool out;
int sum;
char s[20];

//ifstream fin ("input.in");

int main()
{
    for (int i=1; i<=9; i++)
    {
        sum = 45;
        cin.getline (s, 20);
        int n = strlen (s);
        for (int j=0; j<n; j++)
        {
            if (s[j] >= '0' && s[j] <= '9') sum-=(s[j]-'0');
            if (s[j] == '?') out=1;
        }
        if (out)
        {
            cout << sum;
            break;
        }
    }
}
