#include <stdio.h>
#include <stdbool.h>

void master_init (int n, char *f1, char *f2)
{
    int pid1, pid2;
    pid1 = fork();
    if (pid1 == 0)
    {
        slave_work (n, f1, 0);
        exit (0);
    }
    wait();
    pid2 = fork();
    if (pid2 == 0)
    {
        slave_work (n, f2, 1);
        exit (0);
    }
    wait();
}

void master_finish (int n, char *f1, char *f2)
{
    FILE *file1, *file2;
    int x, y, i;
    char c;
    file1 = fopen (f1, "r");
    file2 = fopen (f2, "r");
    for (i=1; i<=n; i++)
    {
        fscanf (file1, "%d %d ", &x, &y);
        fscanf (file2, "%c ", &c);
        if (c == '+') printf ("%d + %d = %d\n", x, y, x + y);
        else if (c == '-') printf ("%d - %d = %d\n", x, y, x - y);
        else if (c == '*') printf ("%d * %d = %d\n", x, y, x * y);
        else if (c == '/') printf ("%d / %d = %d\n", x, y, x / y);
    }
    fclose (file1);
    fclose (file2);
}

void slave_work (int n, char* file, bool usage)
{
    FILE *f;
    int i, x, y;
    char c;
    if (usage == 0)
    {
        printf("Introduceti %d perechi de operanzi:\n", n);
        f = fopen (file, "w");
        for (i=1; i<=n; i++)
        {
            scanf ("\n%d %d", &x, &y);
            fprintf (f, "%d %d ", x, y);
        }
        fclose (f);
    }
    else if (usage == 1)
    {
        printf ("Introduceti %d operatori:\n", n);
        f = fopen (file, "w");
        for (i=1; i<=n; i++)
        {
            scanf ("\n%c", &c);
            fprintf (f, "%c ", c);
        }
        fclose (f);
    }
}

int main (int argc, char** argv)
{
    int  n;
    const char *f1 = "operanzi.bin";
    const char *f2 = "operatori.txt";
    remove (f1);
    remove (f2);
    if (argc > 1)
    {
        n = atoi (argv[1]);
    }
    else
    {
        printf ("Introduceti numarul de operatii:\n");
        scanf ("%d", &n);
    }
    master_init (n, f1, f2);
    master_finish (n, f1, f2);
    return 0;
}
