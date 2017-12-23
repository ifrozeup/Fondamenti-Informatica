
#include "FunzioniListe.h"

/*
 * Inserisce un elemento alla posizione indicata da indice.
 * Se indice e' maggiore della dimensione della lista inserisce in coda.
 * Se indice e' 0 inserisce in testa.
 */
void inserisciElemento(ListaNodi* lista, int numero, int indice) {
    int posizione = 0;
    Nodo* currNodo = *lista;
    Nodo* tempNodo;

    tempNodo = (Nodo *) malloc (sizeof (Nodo));

    if (tempNodo == NULL){
            printf ("\nerrore di allocazione della memoria!");
            return;
    }

    tempNodo->valore=numero;

    // Inserimento in testa o lista vuota
    if( currNodo == NULL || indice == 0 ) {

    	tempNodo->next = *lista;
        *lista = tempNodo;
    }
    // Inserimento in posizione e in coda
    else {
        // Posizionamento per inserimento all'indice, se maggiore di 0.
            while ( (posizione < indice-1) && currNodo->next != NULL ) {
                currNodo = currNodo->next;
                posizione++;
            }

        tempNodo->next = currNodo->next;
        currNodo->next = tempNodo;
    }
}

/*
 * Cancella l'elemento alla posizione indicata da indice.
 * Se indice e' maggiore della dimensione della lista elimina quello in coda.
 * Se indice e' 0 elimina quello in testa.
 */
void cancellaElemento(ListaNodi* lista, int indice){
    int posizione = 0;
    Nodo* currNodo = *lista;
    Nodo* tempNodo = NULL;

    if(currNodo == NULL) return;

    // Se indice e' 0 elimina quello in testa
    if( indice == 0 && currNodo->next != NULL) {
    	*lista = currNodo->next;
    	free(currNodo);
    }
    // Altrimenti elimina quello in posizione
    else {
        // Posizionamento per inserimento all'indice, se maggiore di 0.
        while ( (posizione < indice-1) && currNodo->next->next != NULL ) {
            currNodo = currNodo->next;
            posizione++;
        }

        tempNodo = currNodo->next;

        if( tempNodo != NULL ) {
            currNodo->next = tempNodo->next;
        }
        // Eliminazione in coda
        else {
            currNodo->next = NULL;
        }
        free(tempNodo);
    }

    return;
}



//funzione che calcola la lunghezza di una lista dato il primo elemento
int lunghezzaLista(ListaNodi lista) {
    int posizione = 0;
    Nodo* nodo = lista;
    
    if(nodo==NULL){
        return 0;
    }
    while ( nodo->next != NULL ) {
        nodo = nodo->next;
        posizione++;
    }
    return posizione+1;
}

void printLista(ListaNodi lista){
    Nodo* nodo = lista;
    
    if(nodo != NULL) {
        printf("[%d", nodo->valore);
        
        while ( nodo->next != NULL ) {
            nodo = nodo->next;
            
            printf(",%d", nodo->valore);
        }
        printf("]\n");
    }
    else {
        printf("[]\n");
    }
}
