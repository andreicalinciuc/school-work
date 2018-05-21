#include <stdio.h>

int p1[2], p2[2], pf[2];

void master_work()
{
    int suma_partiala1 = 0, suma_partiala2 = 0, nr = 0;
    while (scanf ("%d", &nr) != EOF)
    {
        if (nr < 0) write (p1[1], &nr, sizeof (int));
        if (nr > 0) write (p2[1], &nr, sizeof (int));
    }
    close (p1[1]); wait (NULL); read (pf[0], &suma_partiala1, sizeof (int));
    close (p2[1]); wait (NULL); read (pf[0], &suma_partiala2, sizeof (int));
    close (pf[0]);
    printf ("Sunt procesul tata cu PID %d si am primit sumele partiale %d si %d, iar suma lor este %d\n", getpid(), suma_partiala1, suma_partiala2, suma_partiala1 + suma_partiala2);
}

void slave_work (int fdi, int fdo)
{
    int suma_partiala = 0, numar[100], k = 0, nr = 0, i;
    while (read (fdi, &nr, sizeof (int)))
    {
        numar[++k] = nr;
        suma_partiala += nr;
    }
    close (fdi);
    printf ("Sunt procesul fiu cu PID %d si am secventa ", getpid());
    for (i = 1; i <= k; ++i) printf ("%d ", numar[i]);
    printf ("si suma partiala %d\n", suma_partiala);
    write (fdo, &suma_partiala, sizeof (int));
    close (fdo);
}

int main()
{
    pipe (p1);
    pipe (p2);
    pipe (pf);
    if (fork() == 0)
    {
        close (p1[1]);
        close (p2[0]); close (p2[1]);
        close (pf[0]);
        slave_work (p1[0], pf[1]);
        return 0;
    }
    if (fork() == 0)
    {
        close (p1[0]); close (p1[1]);
        close (p2[1]);
        close (pf[0]);
        slave_work (p2[0], pf[1]);
        return 0;
    }
    close (p1[0]); close (p2[0]); close (pf[1]);
    master_work();
    return 0;
}
