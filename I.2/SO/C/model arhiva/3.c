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
