//Scrieti un mic program C care sa execute comanda "cat -n -E /etc/passwd" folosind un apel din familia exec(), iar la final sa afiseze codul ei de terminare.

#include <stdio.h>
#include <sys/wait.h>

int main()
{
    if (fork() == 0)
    {
        execlp ("cat", "cat", "-n", "-E", "/etc/passwd", 0);
    }
    else
    {
        int codterm;
        wait (&codterm);
        printf ("%d", WEXITSTATUS (codterm));
    }
}
