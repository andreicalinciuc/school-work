#include <stdio.h>
#include <sys/wait.h>

int main (int argc, char** argv)
{
    int n, k, i, j, count = 1, codterm[101], pid[101];
    printf ("Introduceti numarul de fii si de nivele: ");
    scanf ("%d%d", &n, &k);
    for (i=1; i<n; i++)
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
            return count;
        }
        else if (j < k+1 && i == n-1)
        {
            printf ("Sunt procesul fara fii %d de pe nivelul %d, PID: %d, PID parinte: %d\n", count, i, getpid(), getppid());
            return count;
        }
    }
}
