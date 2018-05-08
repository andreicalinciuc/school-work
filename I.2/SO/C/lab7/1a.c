#include <stdio.h>
#include <fcntl.h>

int numara_caractere (char* filename)
{
    int aparitii[256], fd, i, flag;
    unsigned char c;
    for (i=0; i<256; i++)
    {
        aparitii[i] = 0;
    }
    fd = open (filename, 0, O_RDONLY);
    if (fd == -1) return 0; //eroare la deschidere
    while ((flag = read (fd, &c, 1)) > 0)
    {
        aparitii[c]++;
    }
    if (flag == -1) return 0; //eroare la citire
    flag = close (fd);
    if (flag == -1) return 0; //eroare la inchidere
    for (i=0; i<256; i++)
    {
        if (aparitii[i])
        {
            printf ("%c %d\n", i, aparitii[i]);
        }
    }
    return 1;
}

char* citeste_tastatura()
{
    printf ("Introduceti numele fisierului:\n");
    unsigned char c;
    char *str, *tmp;
    str = (char *) malloc (100);
    int poz = 0, maxsize = 100;
    while (1)
    {
        read (0, &c, 1);
        if (c == '\n')
        {
            break;
        }
        if (maxsize - poz < 10)
        {
            maxsize += 100;
            tmp = (char *) malloc (maxsize);
            memcpy (str, tmp, poz);
            free (str);
            str = tmp;
        }
        str[poz++]=c;
    }
    str[poz] = 0;
    return str;
}

void main (int argc, char** argv)
{
    if (argc < 2)
    {
        numara_caractere (citeste_tastatura());
    }
    else
    {
        numara_caractere (argv[1]);
    }
}
