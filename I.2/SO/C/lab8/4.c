#include <stdio.h>
#include <sys/wait.h>

int main (int argc, char** argv)
{
    int n, i, codterm, pid;
    printf ("Introduceti numarul de procese: ");
    scanf ("%d", &n);
    for (i=1; i<n; i++)
    {
        pid = fork();
        if (pid != 0)
        {
            wait (&codterm);
            printf ("Sunt procesul %d, avand PID-ul: %d, parintele are PID-ul: %d, iar fiul creat are PID-ul: %d si s-a terminat cu codul: %d.\n", i, getpid(), getppid(), pid, WEXITSTATUS(codterm));
            return i;
        }
        else if (pid == 0 && i == n-1)
        {
            printf ("Sunt procesul ultim, %d din lantul de procese, avand PID-ul: %d, iar parintele meu este procesul cu PID-ul: %d.\n", n, getpid(), getppid());
            return n;
        }
    }
}
