
/*
Programma che implementa la funzione potenza che calcola la potenza p di un numero n in modo ricorsivo
*/

#include <stdio.h>
#include <stdlib.h>

int potenzaRecur(int, int);

int main(){

    int n = 2;
    int p = 8;

    int recur = potenzaRecur(n,p);

    printf("Il risultato e': %d\n",recur);

}

int potenzaRecur(int base, int esponente){
     // caso base: condizione di terminazione
     if (esponente == 0){
        // qualunque numero alla potenza zero da come risultato 1
        return 1;
     }
     return base*potenzaRecur(base, --esponente);
}
