/*
  Questo file implementa una semplice calcolatrice a notazione prefissa
  che lavora con numeri interi.

  "Notazione prefissa" significa che l'operatore viene espresso prima degli
  operandi anziché in mezzo:
  1+2*(3+4) diventa + 1 * 2 + 3 4

  Così si evita l'uso delle parentesi.

  Tutti gli operatori sono binari (per calcolare 1+2+3 bisogna scrivere (1+2)+3
  ossia + + 1 2 3).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calcola();

int main() {
   printf("Calcolatrice a notazione prefissa. \n Premi INVIO dopo aver digitato un'espressione per calcolarla.\n CTRL+C per uscire\n\n");

   while (1) {
      printf("> "); //prompt
      printf("%d\n", calcola()); //stampa il risultato
   }

   return 0;
}


/*
  Questa funzione calcola il risultato della prossima sotto-espressione.
*/
int calcola() {
   // Buffer di lettura
   char buffer;
   // I due operandi
   int op1, op2;

   //Scrivere una costante numerica esplicitamente è concettualmente
   //sbagliato, ma bisognerebbe usare funzioni più complesse di scanf.
   //Invece, leggere una stringa senza specificare la lunghezza massima
   //è un errore grave
   scanf("%c", &buffer);

   if (buffer == '+') { //addizione
      //Leggo e calcolo la prima sottoespressione
      op1 = calcola();

      //Leggo e calcolo la seconda sottoespressione
      op2 = calcola();

      //Restituisco la somma
      return op1 + op2;
   }

   else if (buffer == '-') { //sottrazione
      //Analogamente
      op1 = calcola();
      op2 = calcola();

      return op1 - op2;
   }
   else if (buffer == '*') { //moltiplicazione
      op1 = calcola();
      op2 = calcola();

      return op1 * op2;
   }
   else if (buffer == '/') { //divisione
      op1 = calcola();
      op2 = calcola();

      return op1 / op2;
   }
   else if (buffer == '%') { //modulo
      op1 = calcola();
      op2 = calcola();

      return op1 % op2;
   }

   else if (buffer == ' ' || buffer == '\n'){
     return calcola();
   }
   else {
      //se non è un operatore, è un numero, che restituisco direttamente
      return (int)buffer - '0';
   }
}
