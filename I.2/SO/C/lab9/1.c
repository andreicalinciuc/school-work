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

//cod de la Alexandru Rusu care inca nu merge (bucla infinita?) dar pare ok
/*
#include <stdio.h>

int main()
{
	int pid;
	pid = fork();

/*	if (pid == 0)
	{
		sleep(3);
		printf("Copil %d", getpid());
		printf("\n");
	}
	else
	{
		printf("Parinte %d", pid);
		printf("\n");
	}
	*/

	if (pid == 0)
	{
		com ("fisier.txt", "fisier2.txt"); //com ("fiu", "parinte");
		//printf("\n");
	}
	else
	{
		com ("fisier2.txt", "fisier.txt"); //com ("parinte", "fiu");
		//printf("\n");
	}
}

void com(char *fisier, char *other)
{
	FILE *f1=fopen(fisier, "r");
	char l[250];
	char flag[20];

	while (!feof(f1))
	{
		do 
		{
			FILE *f=fopen("fisier3.txt", "r");
			fgets(flag, 20, f);
			close(f);
		}while(strcmp(flag, fisier));

		fgets(l, 250, f1);
		printf ("%s \n", l);
		//sleep(1);
		FILE *f=fopen ("fisier3.txt", "w");
		fprintf("%s\n", other);
		fclose(f);
	}

}
*/
