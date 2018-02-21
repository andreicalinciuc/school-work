#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

FILE *fisier = fopen ("data.in", "r");

int n, v[100];

char s[100];

int main()
{
	while (fgets (s, 100, fisier) != NULL)
	{
		v[++n] = atoi(s);
	}
	sort (v+1, v+n+1);
	for (int i=1; i<=n; i++)
	{
		printf ("%d ", v[i]);
	}
}
