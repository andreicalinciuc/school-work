/*******************************************************************************************************
Enunt prima problema:

a) Care este semnificatia celui de-al doilea parametru al functiei execv() ?
b) Dati un exemplu de apel al functiei execv() ce apeleaza fisierul executabil "calculator" cu parametrii
"21", "*" si "7".

NOTA: pastrati enuntul in acest comentariu si scrieti rezolvarea mai jos.
*******************************************************************************************************/

//a)
//Este un vector de pointeri la siruri de caractere care reprezinta lista de argumente pentru comanda care urmeaza sa fie executata.
//Ultimul argument din vector trebuie sa fie NULL, iar primul, prin conventie ar trebui sa fie numele comenzii.

//b)
const char* param[] = {"calculator", "21", "*", "7", NULL};
execv ("calculator", param);
