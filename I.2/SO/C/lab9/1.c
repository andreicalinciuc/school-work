#include <stdio.h>

void dialog (char* this, char* other)
{
    FILE *f1, *f2;
    char s[256], flag[256];
    f1 = fopen (this, "r");
    while (!feof (f1))
    {
        do
        {
            f2 = fopen ("selector.txt", "r");
            fgets (flag, 256, f2);
            fclose (f2);
        } while (strcmp (flag, this));
        fgets (s, 256, f1);
        s[strcspn(s, "\n")] = 0; //smecheria da? da ma da
        printf ("%s (%s)\n", s, this);
        f2 = fopen ("selector.txt", "w");
        fprintf (f2, "%s", other);
        fclose (f2);
    }
}

int main()
{
    FILE *f = fopen ("selector.txt", "w");
    fprintf (f, "fisier1.txt");
    fclose (f);
    int pid;
    pid = fork();
    if (pid == 0)
    {
        dialog ("fisier1.txt", "fisier2.txt");
    }
    else
    {
        dialog ("fisier2.txt", "fisier1.txt");
    }
    return 0;
}
