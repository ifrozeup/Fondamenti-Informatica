/*
 * Politecnico di Milano
 * Dipartimento di Elettronica e Informazione
 * Fondamenti di Informatica
 *
 * --------------------------------
 *    RigheMat.c
 * --------------------------------
 *
 *  Scrivere un programma che verifichi in modo ricorsivo se due righe successive di una matrice sono uguali e stampa a schermo gli indici delle righe uguali.
 */

#include <stdio.h>

#define N 3

int righeUguali(int[][N],int, int);

int main(){

	int matrice[N][N] = {{10,12,14}, {23,30,46}, {23,35,46}};

	int res = righeUguali(matrice, 0,0);

	if(!res)
		printf("La matrice analizzata non contiene righe uguali.\n");
	else
		printf("Le righe %d e %d della matrice sono uguali.\n", res, res+1);
}

//funzione che verifica ricorsivamente se la matrice contiene due righe successive identiche
int righeUguali(int a[][N],int riga, int colonna){

	//ho finito le righe, non ci sono righe uguali
	if (riga > N-1)
		return 0;
	//ho terminato le colonne, le righe sono uguali
	if (colonna > N-1)
		return riga;
	//se gli elementi sono diversi passo alla riga successiva
	if (a[riga][colonna] != a[riga+1][colonna])
		return righeUguali(a, riga + 1, 0);
	//se gli elementi sono uguali controllo la colonna successiva
	return righeUguali(a, riga, colonna+1);
}
