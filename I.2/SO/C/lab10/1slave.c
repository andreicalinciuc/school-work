#include <string.h>

int main (int argc, char** argv)
{
    int a, b;
    char semn;
    if (argc < 2) exit (1); //incorrect usage
    a = atoi (argv[1]);
    b = atoi (argv[2]);
    semn = argv[3][0];
    if (semn == '+')
    {
        exit (a+b);
    }
    else if (semn == '-')
    {
        exit (a-b);
    }
}
