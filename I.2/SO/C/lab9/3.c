#include <stdio.h>

int main (int argc, char** argv)
{
    int n, i, pid;
    printf("Introduceti numarul de fii: ");
    scanf("%d", &n);
    printf("Sunt procesul initial cu PID-ul: %d, iar parintele meu este procesul cu PID-ul: %d.\n", getpid(), getppid());
    for (i=1; i<=n; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            printf("Sunt procesul fiu %d, avand PID-ul: %d, iar parintele meu este procesul cu PID-ul: %d.\n", i, getpid(), getppid());
            return 0;
        }
    }
    for (i=1; i<=n; i++) wait ();
    return 0;
}
