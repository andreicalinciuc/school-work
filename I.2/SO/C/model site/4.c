#include <stdio.h>

int main()
{
    int p[2];
    pipe (p);
    if (fork() == 0)
    {
        FILE *fin = fdopen (p[0], "r");
        close (p[1]);
        //while citire != eof
        //calculare suma 1
    }
    else if (fork() == 0)
    {
        FILE *fout = fdopen (p[1], "w");
        close (p[0]);
        //while citire != eof
        //calculare suma 2
    }
    else
    {
        //citirea
        wait(NULL);
        wait(NULL);
        //suma 1
        //suma 2
        //suma sumelor
    }
}
