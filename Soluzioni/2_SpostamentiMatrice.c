/*
 * Politecnico di Milano
 * Dipartimento di Elettronica e Informazione
 * Fondamenti di Informatica
 *
 * --------------------------------
 *    SpostamentiMatrice.c
 * --------------------------------
 *
 * Si scriva un programma che, una volta inizializzate le strutture dati M e A,
 * calcoli e restituisca come valore di ritorno la somma degli elementi della
 * matrice visitati seguendo le mosse memorizzate in A. Nel caso di mosse che
 * portano a posizioni non lecite (cioè oltre i limiti imposti dalle dimensioni
 * della matrice) il programma notifica che la mossa non è valida.
 */

#include <stdio.h>

#define N 4
#define K 3

typedef struct{
    int mossaRiga;
    int mossaColonna;
} Mossa;

int somma(int[][N], Mossa[]);
void stampaMatrice(int[][N]);

int main(void){
   int M[N][N] = {{1,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4}};
   Mossa A[K] = {{1,1},{1,-1},{1,1}};
   int sum = 0;
   printf("La matrice iniziale e':\n");
   stampaMatrice(M);
   sum = somma(M, A);

   if(sum == -1)
    printf("La mossa non e' valida\n");
   else
    printf("La somma degli elementi visitati è pari a %d\n", sum);

   return 0;
}

int somma(int M[][N], Mossa A[]) {
    int somma, i, x = 0, y = 0;
    somma = M[0][0];
    for (i=0; i<K; i++) {
        printf("Mossa: %d %d\n", A[i].mossaRiga, A[i].mossaColonna);
        if (x+A[i].mossaRiga<0 || x+A[i].mossaRiga>=N ||
            y+A[i].mossaColonna<0 || y+A[i].mossaColonna>=N)
            return -1;
        else {
            x += A[i].mossaRiga;
            y += A[i].mossaColonna;
            somma += M[x][y];
        }
    }
    return somma;
}

void stampaMatrice(int matrice[][N]){
  int i, j;
  for (i = 0; i < N; i++){
    for (j = 0; j < N; j++){
      printf("%3d",matrice[i][j]);
    }
    printf("\n");
  }
}
