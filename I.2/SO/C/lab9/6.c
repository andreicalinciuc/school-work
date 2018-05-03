#include <stdio.h>
#include <sys/wait.h>

int n, k, count = 1;

void creeaza_fii (int i)
{   
    int pid[101], codterm[101], j;
    if (i < n)
    {
        for (j=1; j<=k; j++)
        {
            pid[j] = fork();
            if (pid[j] == 0)
            {
                count = j;
                break;
            }
            else wait (&codterm[j]);
        }
        if (j == k+1)
        {
            printf ("Sunt procesul %d de pe nivelul %d, PID: %d, PID parinte: %d, PID fii: ", count, i, getpid(), getppid());
            for (int q=1; q<=k; q++) printf ("%d, ", pid[q]);
            printf ("si s-au terminat cu codurile: ");
            for (int q=1; q<=k; q++) printf ("%d, ", WEXITSTATUS (codterm[q]));
            printf ("\n");
            exit (count);
        }
        else
        {
            creeaza_fii (i+1);
        } 
    }
    else
    { 
        printf ("Sunt procesul fara fii %d de pe nivelul %d, PID: %d, PID parinte: %d\n", count, i, getpid(), getppid());
        exit (count);
    }
}

int main (int argc, char** argv)
{
    printf ("Introduceti numarul de fii si de nivele: ");
    scanf ("%d%d", &k, &n);
    creeaza_fii (1);
}
