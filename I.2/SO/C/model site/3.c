//Fie programul C de mai jos. El contine (macar) 3 erori sintactice si o greseala logica. Corectati-le, astfel incat programul sa poata fi executat si sa produca la executie afisarea pe ecran de catre procesul fiu a textului primit de la parinte.

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
  char w=0, *text;
  int p,q[2];
  pipe(q);
  p=fork();
  if(p==-1) exit(2);
  if(!p)
  { 
    dup2(q[0],0);
    close(q[1]);
    while( read(0,&w,1) != 0)
    printf("%c",w);
    close(q[0]);
  }
  else
  {
    close(q[0]);
    text="salutari!";
    write(q[1],text,strlen(text));
    close(q[1]);
    wait(NULL);
  }
  return 0;
}
