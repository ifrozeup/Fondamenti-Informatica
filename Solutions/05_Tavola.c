/*
 * Politecnico di Milano
 * Dipartimento di Elettronica e Informazione
 * Fondamenti di Informatica
 * Laboratorio 1
 * --------------------------------
 *    Tavola.c
 * --------------------------------
 *
 *	Scrivere un programma che stampa la tavola dei quadrati e dei cubi dei numeri da 0 a 10.
 *  	Stampare la tavola per colonne con intestazione "numero	quadrato cubo" allineando i valori relativi secondo le seguenti regole:
*	- la prima colonna viene stampata come numeri interi allineati a destra,
	- la seconda colonna conterrà numeri con due cifre decimali allineati a destra,
	- la terza colonna deve contenere numeri con una cifra decimale allineati a sinistra.
 *
 * Esempio:
 * 	numero		quadrato	cubo
	       0		    0.00	0.0
	       1		    1.00	1.0
	       2		    4.00	8.0
	       3		    9.00	27.0
*/

#include <stdio.h>

int main() {

	//Stampa intestazione
	printf("Numero\tQuadrato\tCubo\n");

	//Stampa tabella
	float x = 0;
	printf("%6.0f\t%8.2f\t%.1f\n", x, x*x, x*x*x);

	x = 1;
	printf("%6.0f\t%8.2f\t%.1f\n", x, x*x, x*x*x);

	x = 2;
	printf("%6.0f\t%8.2f\t%.1f\n", x, x*x, x*x*x);

	x = 3;
	printf("%6.0f\t%8.2f\t%.1f\n", x, x*x, x*x*x);

	x = 4;
	printf("%6.0f\t%8.2f\t%.1f\n", x, x*x, x*x*x);

	x = 5;
	printf("%6.0f\t%8.2f\t%.1f\n", x, x*x, x*x*x);

	x = 6;
	printf("%6.0f\t%8.2f\t%.1f\n", x, x*x, x*x*x);

	x = 7;
	printf("%6.0f\t%8.2f\t%.1f\n", x, x*x, x*x*x);

	x = 8;
	printf("%6.0f\t%8.2f\t%.1f\n", x, x*x, x*x*x);

	x = 9;
	printf("%6.0f\t%8.2f\t%.1f\n", x, x*x, x*x*x);

	x = 10;
	printf("%6.0f\t%8.2f\t%.1f\n", x, x*x, x*x*x);

	// Terminazione corretta
	return 0;
}
