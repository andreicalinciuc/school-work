#include <fcntl.h>

int main()
{
    int p[2], size = 0;
    char c = 0;
    pipe (p);
    fcntl (p[1], F_SETFL, O_NONBLOCK);
    while (1)
    {
        if (write (p[1], &c, 1) == -1)
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
