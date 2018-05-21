/****************************************************************************************
Enunt a doua problema:

Programul de mai jos contine trei erori sintactice (adica, detectabile la compilare), si ar trebui sa ofere
urmatoarea functionalitate: Procesul principal creaza un fiu; Procesul fiu se reacopera cu comanda ls - l;
Procesul parinte asteapta procesul fiu sa termine, si apoi afiseaza un mesaj;

Corectati in programul de mai jos cele trei erori introduse voluntar in asa fel incat sa obtineti un program corect.
Dupa linia pe care ati facut o corectie, includeti si o explicatie ca si comentariu pentru a obtine punctajul integral.


NOTA: pastrati enuntul in acest comentariu si scrieti rezolvarea mai jos.
****************************************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h> //nu era, trebuie pentru wait
#include <sys/types.h> //nu era, trebuie pentru wait

int main(int argc, char* argv[])
{

        int pid3;

        pid3 = fork();

        if(pid3 == -1)
        {
                perror("failed to create  child process");
                return -1;
        }

        if(pid3 != 0) //era pid, nu era declarat, trebuia pid3
        {
                wait(NULL);
                printf("Procesul fiu a executat comanda ls -l\n"); //era print, trebuia printf, nu exista functia print

        }
        else
        {

                char* parametru[] = {"ls","-l",NULL};

                execvp("ls", parametru);

                return -1;
        }

        return 0; //era return perror, perror este o functie care acceseaza variabila errno, nu are sens la return
}  
