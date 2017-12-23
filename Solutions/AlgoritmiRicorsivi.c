/*
 * AlgoritmiRicorsivi.c
 *
 * Implementazione delle funzioni dichiarate nel file AlgoritmiRicorsivi.h
 */

#include "AlgoritmiRicorsivi.h"

/*funzione che ricevuta una lista ne modifica il contenuto in modo che ogni elemento sia uguale alla somma tra
se stesso e tutti gli elementi successivi.*/
void sommaLista(ListaNodi L){
	if(L == NULL || L-> next == NULL){
		return;
	}

	sommaLista(L->next);
	L-> valore = L-> valore + (L->next)->valore;

	return;
}

//funzione che cancella tutte le ripetizioni di un elemento da una lista
void cancellaValore(ListaNodi* L, int number){
	//la lista è vuota, termino
	if(*L == NULL){
		return;
	}
	//l'elemento deve essere cancellato
	if((*L)->valore == number){
		Nodo* nodoCanc = *L;
		*L = (*L)->next;
		free(nodoCanc);
		cancellaValore(L, number);
	}
	else
		cancellaValore(&((*L)->next), number);
}


void cancellaRipetizioni(ListaNodi* L){
	if(*L == NULL){
		return;
	}
	cancellaValore(&((*L)->next), (*L)-> valore);
	cancellaRipetizioni(&((*L)->next));
}