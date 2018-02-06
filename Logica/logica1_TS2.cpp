#include <bits/stdc++.h>

using namespace std;

ifstream fin ("data.in");
ofstream fout ("data.out");

int k, ok, n;
char s[100], cuv[100], *p;

struct elevi
{
    char nume[100];
    int nota;
}elev[500];

bool cmp (elevi A, elevi B)
{
    return A.nota < B.nota;
}

int main()
{
    while (fin.getline(s, 100))
    {
        k++;
        p = strtok (s, " ");
        while (p)
        {
            strcpy (cuv, p); n = strlen(cuv);
            if (isdigit(cuv[0]) && isalpha(cuv[1]) && isdigit(cuv[2])) {elev[k].nume[0]=0; k--; break;}
            ok=1;
            for (int i=0; i<n; i++)
            {
                if ((cuv[i]<'A' || cuv[i]>'Z') && cuv[i]!='-') ok = 0;
            }
            if (ok)
            {
                cuv[n]=' '; cuv[n+1]=0;
                strcat (elev[k].nume, cuv);
            }
            ok=1;
            for (int i=0; i<n; i++)
            {
                if (cuv[i]<'0' || cuv[i]>'9') ok = 0;
            }
            if (ok)
            {
                elev[k].nota += atoi(cuv);
            }
            p = strtok (NULL, " ");
        }
    }
    sort (elev+1, elev+k+1, cmp);
    for (int i=k; i>=1; i--)
    {
        fout << elev[i].nume << " " << elev[i].nota << "\n";
    }
}
