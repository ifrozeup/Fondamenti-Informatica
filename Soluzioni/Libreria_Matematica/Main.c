/*
* Programma che richiama le funzioni contenute nella libreria matematica e calcola la potenza e il massimo comunq divisore dei parametri passati da riga di comando.
*/

//importo la libreria custom
#include "LibreriaMatematica.h"

//importo le librerie standard
#include <stdio.h>

int main (int argc, char *argv[]){

  int p1, p2, potenza, massimo_com_div;

  if (argc < 3){
	printf ("I parametri passati non sono sufficienti\n");
	return -1;
  }

  p1 = strtol(argv[1], NULL, 10);
  p2 = strtol(argv[2], NULL, 10);

  potenza = potenzaRecur(p1, p2);

  massimo_com_div = mcd(p1, p2);

  printf("La potenza e' pari a %d\n", potenza);
  printf("Il massimo comune divisore e' pari a %d\n", massimo_com_div);

  return 0;
}
