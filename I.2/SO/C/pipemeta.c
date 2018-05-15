#include <stdio.h>

int main()
{   
    int p[2];
    pipe (p);
    if (fork() == 0)
    {   
        close (p[1]);
    }
    else
    {
        close (p[0]);
    }
} 
