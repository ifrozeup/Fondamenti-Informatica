#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9
#define CELL 3

int sudoku_corretto[N][N] = {{5,8,6,4,2,1,3,7,9},{3,2,7,9,6,5,4,8,1},{9,1,4,3,7,8,6,2,5},{1,6,3,5,8,4,7,9,2},{2,4,5,1,9,7,8,6,3},{8,7,9,6,3,2,5,1,4},{7,5,8,2,1,3,9,4,6},{6,3,1,7,4,9,2,5,8},{4,9,2,8,5,6,1,3,7}};

int sudoku_sbagliato[N][N] = {{5,8,6,4,2,1,3,7,9},{3,2,7,9,1,5,4,8,1},{9,1,4,3,7,8,6,2,5},{1,6,3,5,8,4,7,9,2},{2,4,5,1,9,7,8,6,3},{8,7,4,6,3,2,5,1,4},{7,5,8,2,1,3,9,4,6},{6,8,1,7,4,9,2,5,8},{4,9,2,8,5,2,1,3,7}};

// Per passare una matrice come parametro devo definire la dimensione di
// tutti gli array annidati a parte l'ultimo livello
void stampaSudoku(int sudoku[][N]) {
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      printf("%d ", sudoku[i][j]) ;
      // Pretty-printing della matrice
      if(j==2 || j==5)
        printf(" ") ;
    }
    printf("\n");
    if(i==2 || i==5)
      printf("\n") ;
  }
}

bool controllaNumeri(int sudoku[][N]) {
  // Flag booleana per tenere traccia dello stato del test corrente
  bool pass = true;

  // Se la condizione pass diventa falsa esco dai cicli for
  for(int i=0; i<N && pass; i++)
    for(int j=0; j<N && pass; j++)
      // Controllo se la variabile vale 0 per poter chiamare la funzione
      // anche su una matrice parzialmente riempita
      if(sudoku[i][j] != 0 && sudoku[i][j] < 1 || sudoku[i][j] > N)
        pass = false;
  return pass;
}

bool controllaRighe(int sudoku[][N]) {
  bool pass = true;

  // Verifica dei duplicati naive, complessità N*((N*N)/2) cubica
  for(int riga=0; riga<N && pass; riga++)
    for(int colonna=0; colonna<N-1 && pass; colonna++)
      for(int altra_colonna=colonna+1; altra_colonna<N && pass; altra_colonna++)
        if(sudoku[riga][colonna] != 0 &&
           sudoku[riga][altra_colonna] != 0 &&
           sudoku[riga][colonna] == sudoku[riga][altra_colonna])
          pass = false;
  return pass;
}

bool controllaColonne(int sudoku[][N]) {
  bool pass = true;

  // Verifica dei duplicati efficiente, complessità N*N*M cubica
  int numeri[N] = { 0 };
  for(int colonna=0; colonna<N && pass; colonna++) {
    // Azzeramento vettore conteggi
    for(int i = 0; i < N; i++)
      numeri[i] = 0;
    // Verifico che ogni numero compaia una sola volta
    for(int riga=0; riga<N && pass; riga++) {
      int num = sudoku[riga][colonna] - 1;
      numeri[num]++;
      if(numeri[num] >= 2)
        pass = false;
    }
  }
  return pass;
}

bool controllaBlocchi(int sudoku[][N]) {
  bool pass = true;

  // Enumero i blocchi da 0 a 8
  for(int blocco = 0; blocco < N; blocco++) {
    // Per ogni blocco ricavo le coordinate della prima cella (in alto a sx)
    int offset_riga = (blocco % CELL) * CELL;
    int offset_colonna = (blocco / CELL) * CELL;
    // Algoritmo naive per la ricerca dei duplicati
    for(int r1=offset_riga; r1<offset_riga+CELL; r1++)
      for(int c1=offset_colonna; c1<offset_colonna+CELL; c1++)
        for(int r2=offset_riga; r2<offset_riga+CELL; r2++)
          for(int c2=offset_colonna; c2<offset_colonna+CELL; c2++)
            if(((r1 != r2)||(c1 != c2)) &&
               sudoku[r1][c1] != 0 &&
               sudoku[r2][c2] != 0 &&
               sudoku[r1][c1] == sudoku[r2][c2])
              pass = false;
  }
  return pass;
}

bool leggiDaFile(int sudoku[][N]) {
  FILE *sudoku_file = fopen("sudoku.txt", "r");
  // Se il file non esiste fopen ritorna NULL, stampo errore e restituisco falso
  if(sudoku_file == NULL) {
    perror("Error");
    return false;
  }
  // Attenzione alla format string, deve contenere anche il delimitatore
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++) 
      fscanf(sudoku_file, "%d,", &sudoku[i][j]);

  // Chiudete sempre i vostri file!
  fclose(sudoku_file);
  return true;
}

int main() {
  printf("Verifica Sudoku\n");

  printf("Test 1/4 Sudoku corretto:\n");
  int (*sudoku)[N] = sudoku_corretto;
  stampaSudoku(sudoku);
  // Gli if sono cortocircuitati, se il primo test fallisce non eseguo gli altri
  if (controllaNumeri(sudoku) &&
      controllaRighe(sudoku) &&
      controllaColonne(sudoku) &&
      controllaBlocchi(sudoku))
    printf("Passato!\n\n");
  else
    printf("Fallito!\n\n");
    
  printf("Test 2/4 Sudoku sbagliato:\n");
  sudoku = sudoku_sbagliato;
  stampaSudoku(sudoku);
  if (controllaNumeri(sudoku) &&
      controllaRighe(sudoku) &&
      controllaColonne(sudoku) &&
      controllaBlocchi(sudoku))
    printf("Fallito!\n\n");
  else
    printf("Passato!\n\n");

  printf("Test 3/4 inserimento da terminale:\n");
  printf("Inserisci il sudoku da verificare riga per riga\n");
  int sudoku_utente[N][N] = { 0 };
  bool pass = true;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      // Posso eseguire i test elemento per elemento poichè i test
      // ignorano le celle della matrice non ancora inizializzate
      scanf("%d", &sudoku_utente[i][j]);
      pass &= controllaNumeri(sudoku_utente);
      pass &= controllaRighe(sudoku_utente);
      pass &= controllaColonne(sudoku_utente);
      pass &= controllaBlocchi(sudoku_utente);
    }
  }
  if(pass)
    printf("Il Sudoku inserito e' valido!\n\n");
  else
    printf("Il Sudoku inserito NON e' valido!\n\n");

  printf("Test 4/4 lettura da file:\n");
  int sudoku_file[N][N];
  if(!leggiDaFile(sudoku_file)) {
    printf("Fallito!\n\n");
    return -1;
  }
  stampaSudoku(sudoku_file);
  if (controllaNumeri(sudoku_file) &&
      controllaRighe(sudoku_file) &&
      controllaColonne(sudoku_file) &&
      controllaBlocchi(sudoku_file))
    printf("Passato!\n\n");
  else
    printf("Fallito!\n\n");
}
