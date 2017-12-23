#ifndef FUNZIONILISTE_H
#define FUNZIONILISTE_H

#include <stdio.h>
#include <stdlib.h>

//definizione dell'elemento che compone la lista
typedef struct ElemNodo{
	int valore;
	struct ElemNodo* next;
} Nodo;

//definizione di una lista composta da elementi di tipo Nodo
typedef Nodo* ListaNodi;

void inserisciElemento(ListaNodi* lista, int numero, int indice);

void cancellaElemento(ListaNodi* lista, int indice);

int lunghezzaLista(ListaNodi lista);

void printLista(ListaNodi lista);


#endif // FUNZIONILISTE_H_INCLUDED
