/*
 * Politecnico di Milano
 * Dipartimento di Elettronica e Informazione
 * Fondamenti di Informatica
 *
 * --------------------------------
 *    BubbleSortFusione.c
 * --------------------------------
 *
 * Scrivere un programma che:
 * - chiede due volte all'utente di inserire N valori interi, e li salva in due
 *   array di dimensione N;
 * - ordina quindi ciascun array utilizzando il metodo Bubble Sort;
 * - effettua la fusione dei due array, in modo che l'array risultante
 *   mantenga l'ordinamento;
 * - stampa il vettore dopo la fusione.
*/

#include <stdlib.h>
#include <stdio.h>

#define N 10

void bubble_sort(int*, int);
void stampaVettore(int* , int);
void fusioneArray(int*, int*, int*, int, int, int);

int swapCount;
int confrontoCount;

int main(){

	setbuf(stdout, NULL);
  // Dichiarazione delle variabili
  int numbers1[N];
  int numbers2[N];
  int fusione[N+N];
  int i;

  // Lettura dei valori inseriti dall'utente
  for(i=0; i<N; i++){
  	printf("Inserisci il valore dell'elemento %d del primo vettore: ", i);
    scanf("%d",&numbers1[i]);
  }
  for(i=0; i<N; i++){
  	printf("Inserisci il valore dell'elemento %d del secondo vettore: ", i);
  	scanf("%d",&numbers2[i]);
  }

  printf("I vettori inseriti sono i seguenti: \n");
  stampaVettore(numbers1, N);
  stampaVettore(numbers2, N);

  bubble_sort(numbers1, N);
  printf("Il vettore ordinato è il seguente: \n");
  stampaVettore(numbers1, N);
  printf("Sono stati eseguiti %d confronti e %d swap\n",
         confrontoCount, swapCount);

  bubble_sort(numbers2, N);
  printf("Il vettore ordinato è il seguente: \n");
  stampaVettore(numbers2, N);
  printf("Sono stati eseguiti %d confronti e %d swap\n",
         confrontoCount, swapCount);

  fusioneArray(numbers1, numbers2, fusione, N, N, N+N);
  printf("Il vettore ottenuto dalla fusione è: \n");
  stampaVettore(fusione, N+N);

  return 0;
}

void fusioneArray(int v1[], int v2[], int res[], int l1, int l2, int L){

	int i = 0, j = 0, k = 0;

	// Fino a che nessuno dei due array è stato tutto copiato
    // confronto gli elementi da copiare e riempio il nuovo array
	while (i < l1 && j < l2){
		if (v1[i] < v2[j]){
			res[k] = v1[i];
			i++;
		}
		else{
			res[k] = v2[j];
			j++;
		}
		k++;
	}
	// Finchè ci sono ancora elementi in v1 da copiare
	while (i < l1){
		res[k] = v1[i];
		i++;
		k++;
	}
	// Finchè ci sono ancora elementi in v2 da copiare
	while (j < l2){
		res[k] = v2[j];
		j++;
		k++;
	}
	return;
}

// Funzione che scambia due variabili
void swap(int* p1, int* p2){
	  int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    return;
}

// Funzione che ordina un vettore di data lunghezza
// in modo crescente usando l'algoritmo BubbleSort
void bubble_sort(int vettore[], int lunghezza) {
    swapCount = 0;
    confrontoCount = 0;
    for (int i = lunghezza-1; i > 0; i--){
        // Ad ogni iterazione sposto il valore più grande nell'ultima posizione
        // non ancora assegnata (che ha come indice il valore di i)
        for (int j = 1; j <= i; j++){
	       	confrontoCount++;
            if (vettore[j-1] > vettore[j]){
                // Scambia l'elemento nella posizione j
                // con l'elemento nella posizione j-1
                swap(&(vettore[j-1]), &(vettore[j]));
                swapCount++;
            }
        }
    }
    return;
}

void stampaVettore(int vettore[], int lunghezza){
    printf("[");
    for(int i=0; i<lunghezza; i++){
        if(i<lunghezza-1)
            printf("%d, ", vettore[i]);
        else
            printf("%d]\n", vettore[i]);
    }
}
