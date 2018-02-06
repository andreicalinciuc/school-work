#include <bits/stdc++.h>

using namespace std;

ifstream fin ("data1.in");
ifstream gin ("data2.in");
ofstream fout ("data.out");

double intpart10, fractpart10, intpart9, fractpart9, intpart8, fractpart8, intpart7, fractpart7, intpart6, fractpart6, intpart5, fractpart5;
int k, ok, n;
char s[100], cuv[100], *p;
char t1[]="trecut", t2[]="netrecut";

struct elevi
{
    char nume[100];
    int nota;
}elev[500], aux;

bool cmp (elevi A, elevi B)
{
    return A.nota > B.nota;
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
    while (gin.getline(s, 100))
    {
        aux.nume[0]=0; aux.nota=0;
        p = strtok (s, " ");
        while (p)
        {
            strcpy (cuv, p); n = strlen(cuv);
            ok=1;
            for (int i=0; i<n; i++)
            {
                if ((cuv[i]<'A' || cuv[i]>'Z') && cuv[i]!='-') ok = 0;
            }
            if (ok)
            {
                cuv[n]=' '; cuv[n+1]=0;
                strcat (aux.nume, cuv);
            }
            ok=1;
            for (int i=0; i<n; i++)
            {
                if (cuv[i]<'0' || cuv[i]>'9') ok = 0;
            }
            if (ok)
            {
                aux.nota += atoi(cuv);
            }
            p = strtok (NULL, " ");
        }
        for (int i=1; i<=k; i++)
        {
            if (strcmp(elev[i].nume, aux.nume)==0) elev[i].nota += aux.nota;
        }
    }
    sort (elev+1, elev+k+1, cmp);
    for (int i=1; i<=k; i++)
    {
        fout << i << ". " << elev[i].nume << " Puncte: " << elev[i].nota;
        fractpart10 = modf (213*0.05 , &intpart10);
        if (fractpart10>=0.5) intpart10++;

        fractpart9 = modf (213*0.15 , &intpart9);
        if (fractpart9>=0.5) intpart9++;

        fractpart8 = modf (213*0.35 , &intpart8);
        if (fractpart8>=0.5) intpart8++;

        fractpart7 = modf (213*0.65 , &intpart7);
        if (fractpart7>=0.5) intpart7++;

        fractpart6 = modf (213*0.90 , &intpart6);
        if (fractpart6>=0.5) intpart6++;

        fractpart5 = modf (213 , &intpart5);
        if (fractpart5>=0.5) intpart5++;

        if (i>=1 && i<=intpart10) fout << ", Nota: 10";
        else if (i>intpart10 && i<=intpart9) fout << ", Nota: 9";
        else if (i>intpart9 && i<=intpart8) fout << ", Nota: 8";
        else if (i>intpart8 && i<=intpart7) fout << ", Nota: 7";
        else if (i>intpart7 && i<=intpart6) fout << ", Nota: 6";
        else if (i>intpart6 && i<=intpart5) fout << ", Nota: 5";
        fout << "\n";

    }
}
