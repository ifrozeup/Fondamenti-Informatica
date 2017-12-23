#include <stdlib.h>
#include <stdio.h>

#define FALSE 0
#define TRUE 1
#define MAX_DIV 1000000000

typedef struct node{
  int value;
  struct node *next;
} IntNode;

typedef IntNode* IntList;

//prototipi funzioni
void printListHelper(IntList);
void printList(IntList);
void sortedInsert(IntList*, int);
int isPrime(int);
int isPTS(int);
IntList readAndStore(FILE*);




int main(int argc, char* argv[]) {
  if(argc < 2) {
    printf("Usage: ./pts INPUTFILE\n");
    exit(1);
  }
  FILE *inputFile = fopen(argv[1], "r");
  if(inputFile == NULL) {
    printf("Error: no such file or directory.\n");
    exit(1);
  }
  IntList ptsList = readAndStore(inputFile);
  printf("PTS List: ");
  printList(ptsList);
  exit(0);
}

IntList readAndStore(FILE *inputFile) {
  IntList list = NULL;
  int value = 0;
  int items = 0;

  items = fscanf(inputFile, "%d\n", &value);
  while(items != EOF) {
    printf("Evaluating %d\n", value);
    if(isPTS(value))
      sortedInsert(&list, value);
    items = fscanf(inputFile, "%d\n", &value);
  }
  return list;
}

//funzione ricorsiva che tramite moduli successivi valuta la condizione che n sia un PTS
int isPTS(int n) {
  if(n < 10)
    return isPrime(n);

  int divider = MAX_DIV;
  while(n % divider == n)
    divider /= 10;

  return (isPrime(n) && isPTS(n % divider));
}

int isPrime(int n) {
  if(n <= 1)
    return FALSE;
  else if(n <= 3)
    return TRUE;
  else if(n % 2 == 0 || n % 3 == 0)
    return FALSE;

  int i = 5;
  while(i * i <= n) {
    if(n % i == 0 || n % (i+2) == 0)
      return FALSE;
    i += 6;
  }
  return TRUE;
}

void sortedInsert(IntList *head, int value) {
  IntList index = *head;
  // Se la lista è vuota oppure sono il più piccolo, inserisco in testa
  if(index == NULL || index->value > value) {
    IntNode *newNode = (IntNode *)malloc(sizeof(IntNode));
    newNode->value = value;
    newNode->next = index;
    *head = newNode;
    return;
  }
  // Altrimenti scorro fino alla mia posizione
  if(index->next != NULL && index->value < value) {
    sortedInsert(&(index->next), value);
    return;
  }
  // Quindi inserisco in coda
  else {
    IntNode *newNode = (IntNode *)malloc(sizeof(IntNode));
    newNode->value = value;
    newNode->next = index->next;
    index->next = newNode;
    return;
  }
}


void printListHelper(IntList head) {
  if(head == NULL)
    return;
  if(head->next == NULL) {
    printf("%d", head->value);
    return;
  }
  printf("%d, ", head->value);
  printListHelper(head->next);
}

void printList(IntList head) {
  printf("[");
  printListHelper(head);
  printf("]\n");
}