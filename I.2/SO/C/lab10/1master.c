#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int codterm, op1, op2;
    char arg1[10], arg2[10], semn[10];
    if (fork() == 0) execlp ("gcc", "gcc", "slave.c", "-w", "-o", "slave", NULL);
    wait (NULL);
    while (1)
    {
        scanf ("%d%d %s", &op1, &op2, &semn);
        sprintf (arg1, "%d", op1);
        sprintf (arg2, "%d", op2);
        if (fork() == 0) execl ("slave", "slave", arg1, arg2, semn, NULL);
        wait (&codterm);
        printf ("Rezultat: %d\n", WEXITSTATUS (codterm));
    }
}
