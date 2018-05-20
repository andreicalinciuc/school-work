/*******************************************************************************************************
Sa se scrie un program C care va primi ca argument la linia de comanda o valoare numerica N, 
va citi N cuvinte de la tastatura si va calcula numarul de cuvinte din secventa citita  
ce au prima litera 'a' si ultima litera 'z', implementand urmatorii pasi:
1. procesul initial (P0) va crea un proces fiu P1 si ii va transmite toate cuvintele din secventa 
citita de la tastatura ce incep cu litera 'a'; cuvintele vor fi separate prin caracterul spatiu; 
transmiterea datelor se va realiza prin intermediul unui canal de comunicatie anonima;
2. procesul fiu P1 va crea la randul sau un nou proces fiu P2 si ii va transmite toate cuvintele  
din secventa primita de la procesul P0 care au ultima litera 'z'; cuvintele vor fi separate prin 
caracterul spatiu; transmiterea datelor se va realiza prin intermediul unui canal de comunicatie 
anonima;
3. procesul P2 va calcula numarul de cuvinte primite de la procesul P1 si ii va transmite 
procesului P1 valoarea calculata prin intermediul codului de retur (apel exit() sau instructiune 
return); 
4. procesul P1 va transmite procesului P0 valoarea primita de la procesul P2 prin intermediul 
codului de retur (apel exit() sau instructiune return);
5. procesul P0 va afisa, la final, valoarea primita de la procesul P1.*/

#include <stdio.h>
#include <stdlib.h>

int p1[2], p2[2];

int main (int argc, int** argv)
{
    pipe (p1);
    FILE* fin1 = fdopen (p1[0], "r");
    FILE* fout1 = fdopen (p1[1], "w");
    if (fork() == 0)
    {
        pipe (p2);
        FILE* fin2 = fdopen (p2[0], "r");
        FILE* fout2 = fdopen (p2[1], "w");
        if (fork() == 0)
        {
            //al doilea fiu
            int count = 0;
            char buffer[256];
            fclose (fin1); fclose (fout1);
            fclose (fout2);
            while (fscanf (fin2, "%s", &buffer) != EOF)
            {
                count++;
            }
            fclose (fin2);
            exit (count);
        }
        else
        {
            //primul fiu
            int codterm2;
            char buffer[256];
            fclose (fout1);
            fclose (fin2);
            while (fscanf (fin1, "%s", &buffer) != EOF)
            {
                if (buffer[strlen(buffer)-1] == 'z')
                {
                    fprintf (fout2, "%s ", buffer);
                    fflush (fout2);
                }
            }
            fclose (fin1);
            fclose (fout2);
            wait (&codterm2);
            exit (WEXITSTATUS (codterm2));
        }
    }
    else
    {
        //tatal
        int i, n, codterm1;
        char buffer[256];
        fclose (fin1);
        n = atoi (argv[1]);
        for (i = 1; i <= n; ++i)
        {
            scanf ("%s", &buffer);
            if (buffer[0] == 'a')
            {
                fprintf (fout1, "%s ", buffer);
                fflush (fout1);
            }
        }
        fclose (fout1);
        wait (&codterm1);
        printf ("%d", WEXITSTATUS (codterm1));
        return 0;
    }
}
