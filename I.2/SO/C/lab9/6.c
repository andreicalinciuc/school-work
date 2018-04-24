#include <stdio.h>
#include <sys/wait.h>

int n, k;

void creeaza_fii (int i)
{   
    int pid, codterm;
    if (i < n)
    {
        printf("Sunt procesul %d, avand PID-ul: %d, parintele are PID-ul: %d, iar fiul creat are PID-ul: %d si s-a terminat cu codul: %d.\n", i, getpid(), getppid(), pid, WEXITSTATUS(codterm));
        for (int j=1; j<=k; j++)
        {
            pid = fork();
            if (pid != 0)
            {
                //for (int q=1; q<=k; q++) wait (&codterm);
            }
            else
            {
                creeaza_fii (i+1);
                break;
            }
        }
    }
    else
    {
        printf ("Sunt procesul ultim, %d din lantul de procese, avand PID-ul: %d, iar parintele meu este procesul cu PID-ul: %d.\n", n, getpid(), getppid());
        exit (n);
    }
}

int main (int argc, char** argv)
{
    printf ("Introduceti numarul de fii si de nivele: ");
    scanf ("%d%d", &k, &n);
    creeaza_fii (1);
}
