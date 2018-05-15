#include <stdio.h>

int main()
{
    if (fork() == 0)
    {
        fiu1
    }
    else if (fork() == 0)
    {
        fiu2
    }
    else
    {
        tata
    }
}
