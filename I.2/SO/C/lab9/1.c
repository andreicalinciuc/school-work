#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

void dialog_tata()
{

}

void dialog_fiu()
{

}

int main()
{
    int pid;
    pid = fork();
    if (pid == 0)
    {
        dialog_fiu();
    }
    else
    {
        dialog_tata();
    }
    return 0;
}
