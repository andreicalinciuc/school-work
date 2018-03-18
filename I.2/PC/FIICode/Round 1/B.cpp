#include <iostream>
#include <cstring>

using namespace std;

long long n, t, i, mt, a[100001], b[100001], s, d, m, mtaux, h, j, ate, kmin=1000000001, found, ori;

int main()
{
    cin >> n >> t;
    for (i=1; i<=n; i++)
    {
        cin >> a[i];
        mt+=a[i];
    }
    s=1; d=1000000000;
    while (s<=d)
    {
        m=(s+d)/2;
        memcpy (b, a, sizeof a);
        mtaux=mt;
        h=0;
        j=1;
        while (mtaux>0)
        {
            while (b[j]<=0 && j<n) j++;
            if (j==n+1) break;
            if (b[j]>=m)
            {
                while (b[j]>=m)
                {
                    ori=b[j]/m;
                    b[j]=b[j]%m;
                    mtaux-=m*ori;
                    h+=ori;
                    b[j]+=ori;
                    mtaux+=ori;
                }
            }
            else if (b[j]<m)
            {
                mtaux-=b[j];
                b[j]=-1;
                h++;
            }
        }
        if (h<=t && mtaux==0)
        {
            if (m < kmin) kmin=m;
        }
        if (h<=t) d=m-1;
        else s=m+1;
    }
    cout << kmin;
}
