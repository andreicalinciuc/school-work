#include <iostream>
#include <cstring>

using namespace std;

char s[21], a[101][21];
int i, j, found, done[101], n, m, inplus, nefacute;

int main()
{
    cin >> n; cin.get();
    for (i=1; i<=n; i++)
    {
        cin.getline (a[i], 21);
    }
    cin >> m; cin.get();
    for (i=1; i<=m; i++)
    {
        cin.getline (s, 21);
        found = 0;
        for (j=1; j<=n && !found; j++)
        {
            if (strcmp (s, a[j])==0)
            {
                found = 1;
                done[j]=1;
            }
        }
        if (!found) inplus++;
    }
    for (i=1; i<=n; i++)
    {
        if (done[i]==0) nefacute++;
    }
    cout << nefacute << " " << inplus;
}
