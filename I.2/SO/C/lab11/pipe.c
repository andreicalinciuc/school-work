#include <stdio.h>

int main()
{
    int p[2];
    char c;
    pipe(p);
    FILE *fin = fdopen (p[0], "r");
    FILE *fout = fdopen (p[1], "w");
    fprintf (fout, "a");
    fflush (fout);
    fscanf (fin, "%c", &c);
    printf ("%c", c);
}
