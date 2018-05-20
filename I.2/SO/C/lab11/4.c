#include <stdio.h>

int p1[2], p2[2], p3[2], pf[2];

void master_work()
{
    int suma_partiala1, suma_partiala2, suma_partiala3, flag = 0, nr = 0;
    while (1)
    {
        scanf ("%d", &nr);
        if (nr == 0) break;
        flag++;
        if (flag == 4) flag = 1;
        if (flag == 1) write (p1[1], &nr, sizeof (int));
        if (flag == 2) write (p2[1], &nr, sizeof (int));
        if (flag == 3) write (p3[1], &nr, sizeof (int));
    }
    close (p1[1]); close (p2[1]); close (p3[1]);
    read (pf[0], &suma_partiala1, sizeof (int));
    read (pf[0], &suma_partiala2, sizeof (int));
    read (pf[0], &suma_partiala3, sizeof (int));
    close (pf[0]);
    printf ("%d\n", suma_partiala1 + suma_partiala2 + suma_partiala3);
}

void slave_work (int fdi, int fdo)
{
    int suma_partiala = 0, nr = 0;
    while (read (fdi, &nr, sizeof (int)) != 0) // EOF?
    {
        suma_partiala += nr;
    }
    close (fdi);
    write (fdo, &suma_partiala, sizeof (int));
    close (fdo);
    printf ("%d\n", suma_partiala);
}

int main()
{
    pipe (p1);
    pipe (p2);
    pipe (p3);
    pipe (pf);
    if (fork() == 0)
    {
        close (p1[1]);
        close (p2[0]); close (p2[1]);
        close (p3[0]); close (p3[1]);
        close (pf[0]);
        slave_work (p1[0], pf[1]);
        return 0;
    }
    if (fork() == 0)
    {
        close (p1[0]); close (p1[1]);
        close (p2[1]);
        close (p3[0]); close (p3[1]);
        close (pf[0]);
        slave_work (p2[0], pf[1]);
        return 0;
    }
    if (fork() == 0)
    {
        close (p1[0]); close (p1[1]);
        close (p2[0]); close (p2[1]);
        close (p3[1]);
        close (pf[0]);
        slave_work (p3[0], pf[1]);
        return 0;
    }
    close (p1[0]); close (p2[0]); close (p3[0]); close (pf[1]);
    master_work();
    return 0;
}
