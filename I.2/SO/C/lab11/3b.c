#include <stdio.h>
#include <fcntl.h>

int main()
{
    int p[2], size = 0;
    char c = 0;
    pipe (p);
    FILE *fin = fdopen (p[0], "r");
    FILE *fout = fdopen (p[1], "w");
    fcntl (p[1], F_SETFL, O_NONBLOCK);
    while (1)
    {
        if (fprintf (fout, "%c", c) == -1)
        {
            break;
        }
        else
        {
            size++;
        }
    }
    printf ("%d", size);
    return 0;
}
