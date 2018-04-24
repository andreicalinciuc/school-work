#include <stdio.h>
#include <sys/wait.h>

int n;

void creeaza_fiu (int i)
{
    int pid, codterm;
    if (i < n)
    {
        pid = fork();
        if (pid != 0)
        {
            wait (&codterm);
            printf("Sunt procesul %d, avand PID-ul: %d, parintele are PID-ul: %d, iar fiul creat are PID-ul: %d si s-a terminat cu codul: %d.\n", i, getpid(), getppid(), pid, WEXITSTATUS(codterm));
            exit (i);
        }
        else
        {
            creeaza_fiu (i+1);
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
    printf ("Introduceti numarul de procese: ");
    scanf ("%d", &n);
    creeaza_fiu (1);
}
