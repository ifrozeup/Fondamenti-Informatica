/*
 * LibreriaMatematica.c
 *
 * Implementazione delle funzioni dichiarate in LibreriaMatematica.h
 */

#include "LibreriaMatematica.h"


//funzione di supporto al calcolo mcd che ordina a e b
void ordina(int* a, int* b){

    if(b > a){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    return;
}

//funzione che calcola il mcd di due numeri n1 e n2 usando il metodo di Euclide
int mcd(int n1, int n2){

    n1 = abs(n1);
    n2 = abs(n2);

    ordina(&n1, &n2);

    if(n2 == 0)
        return n1;
    else
        return mcd(n2, n1%n2);
}

//funzione che calcola la potenza in modo ricorsivo
int potenzaRecur(int base, int esponente){
      // caso base: condizione di terminazione
     if (esponente==0){
         // qualunque numero elevato alla potenza zero da come risultato 1
        return 1;
     }
     return base*potenzaRecur(base,esponente-1);
}
