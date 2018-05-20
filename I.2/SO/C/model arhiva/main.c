//TODO: REDO
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
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int n=atoi(argv[1]),status1;
    int p1[2];
    pipe(p1);
    FILE* fout=fdopen(p1[1],"w");
    FILE* fin=fdopen(p1[0],"r");
    if(fork()==0) {
        int p2[2],status;
        pipe(p2);
        FILE* fout1=fdopen(p2[1],"w");
        FILE* fin1=fdopen(p2[0],"r");
        fclose(fout);
        if(fork()==0) {
            int s=0;
            fclose(fin);
            fclose(fout1);
            char c1[256];
            while(fscanf(fin1,"%s",c1)!=EOF) {
                s++;
            }
            fclose(fin1);
            exit(s);
        }
        else {
            char c2[256];
            fclose(fout);
            fclose(fin1);
            while(fscanf(fin,"%s",c2)!=EOF) {
                if(c2[strlen(c2)-1]=='z') {
                    fprintf(fout1,"%s ",c2);
                    fflush(fout1);
                }
            }
            fclose(fin);
            fclose(fout1);
            wait(&status);
            exit(WEXITSTATUS(status));
        }
    }
    else {
        char c3[256];
        fclose(fin);
        for(int i=1;i<=n;i++) {
            scanf("%s",c3);
            if(c3[0]=='a') {
                fprintf(fout,"%s ",c3);
                fflush(fout);
            }
        }
        fclose(fout);
        wait(&status1);
        printf("%d",WEXITSTATUS(status1));
        
    }
    return 0;
}
