#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1024

// La funzione strtok ha bisogno di argomenti diversi per la prima chiamata
// quindi devo tenere traccia di quando sto estraendo il primo token
bool first_token = true;

int compute(char input_string[MAX_LEN]) {
  char * token;
  int op1, op2;

  // Leggi un token dalla stringa di input
  // Alla prima chiamata, strtok prende la stringa in input ed un delimitatore
  // e restituisce un puntatore al primo token (puntatore alla stringa di
  // input stessa).
  if (first_token) {
    token = strtok(input_string, " ");
    first_token = false;
  } else
  // Alle chiamate successive bisogna passare NULL come input string e strtok
  // restituira' i token successivi
    token = strtok(NULL, " ");
  // Quando tutti i token sono stati letti, strtok restituisce NULL
  if(token == NULL) {
    fprintf(stderr, "Error: not enough parameters!\n");
    return 0;
  }
  // Digitate `man strtok` in una shell per avere più informazioni

  // Seleziona l'operazione in base al primo carattere del token
  switch(token[0]) {
    case '+':
      op1 = compute(input_string);
      op2 = compute(input_string);
      return op1 + op2;
    case '-':
      op1 = compute(input_string);
      op2 = compute(input_string);
      return op1 - op2;
    case '*':
      op1 = compute(input_string);
      op2 = compute(input_string);
      return op1 * op2;
    case '/':
      op1 = compute(input_string);
      op2 = compute(input_string);
      return op1 / op2;
    case '%':
      op1 = compute(input_string);
      op2 = compute(input_string);
      return op1 % op2;
    // Se il carattere non è nessuno dei precedenti dovrà essere un numero
    default:
      return atoi(token);
  }
}

int main() {
  char input_string[MAX_LEN];
  bool exit = false;

  printf("PrefixCalc v.1.0 \nType ':wq' to exit\n");
  do {
    fgets(input_string, MAX_LEN, stdin);
    if (strncmp(input_string, ":wq", 3) == 0)
      exit = true;
    else {
      first_token = true;
      int result = compute(input_string);
      printf("%d\n", result);
    }
  } while(!exit);
}
