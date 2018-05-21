*******************************************************************************************************
Enunt a treia problema:

Sa se scrie un program C care va primi ca argument la linia de comanda o valoarea numerica N,
va citi N numere de la tastatura si va calcula numarul de numere divizibile cu 4,
implementand urmatorii pasi:
1. procesul initial (P0) va crea un proces fiu P1 si ii va transmite toate numerele pare
din secventa de numere citita de la tastatura; transmiterea datelor se va realiza  prin
intermediul unui canal de comunicatie anonima;
2. procesul fiu P1 va crea la randul sau un nou proces fiu P2, va imparti fiecare numar
primit de la P0 la 2 si ii va transmite procesului P2 doar valorile calculate ce sunt pare;
transmiterea datelor de la P1 la P2 va fi realizata prin intermediul unui canal de comunicatie
anonima;
3. procesul P2 va calcula numarul de numere pare din cele primite de la procesul P1 si
va transmite valoarea calculata procesului P1, prin intermediul codului de retur (apel exit()
sau instructiune return);
4. procesul P1 va transmite procesului P0 valoarea primita de la procesul P2 prin
intermediul codului de retur (apel exit() sau instructiune return);
5. procesul P0 va afisa la final valoarea primita de la procesul P1.

OBSERVATIE: Utilizarea de fisiere obisnuite in locul canalelor de comunicatie anonime
va fi penalizata cu trei puncte.

NOTA: pastrati enuntul in acest comentariu si scrieti rezolvarea mai jos.
*******************************************************************************************************/

#include <stdio.h>
#include <sys/wait.h>

int p1[2], p2[2];

int main (int argc, int** argv)
{
    pipe (p1); pipe (p2);
    FILE* fin1 = fdopen (p1[0], "r");
    FILE* fout1 = fdopen (p1[1], "w");
    FILE* fin2 = fdopen (p2[0], "r");
    FILE* fout2 = fdopen (p2[1], "w");
    if (fork() == 0)
    {
        if (fork() == 0)
        {
            //P2
            fclose (fin1); fclose (fout1);
            fclose (fout2);
            int x, count = 0;
            while (fscanf (fin2, "%d", &x) != EOF)
            {
                if (x % 2 == 0) count++;
            }
            fclose (fin2);
            exit (count);
        }
        else
        {
            //P1
            fclose (fout1);
            fclose (fin2);
            int x, codterm;
            while (fscanf (fin1, "%d", &x) != EOF)
            {
                x = x / 2;
                if (x % 2 == 0)
                {
                    fprintf (fout2, "%d ", x);
                    fflush (fout2);
                }
            }
            fclose (fin1);
            fclose (fout2);
            wait (&codterm);
            exit (WEXITSTATUS (codterm));
        }
    }
    else
    {
        //P0
        fclose (fin1);
        fclose (fin2); fclose (fout2);
        int i, n, x, codterm;
        n = atoi (argv[1]);
        for (i = 1; i <= n; ++i)
        {
            scanf ("%d", &x);
            if (x % 2 == 0)
            {
                fprintf (fout1, "%d ", x);
                fflush (fout1);
            }
        }
        fclose (fout1);
        wait (&codterm);
        printf ("%d", WEXITSTATUS (codterm));
    }
}
