#include <stdlib.h>
#include <stdio.h>

typedef struct N{
    int num;
    struct N* next;
}Nodo;

void PrintList(Nodo* lista);

void addLista(Nodo** ptrls, Nodo* nodo);
void subAddLista(Nodo* ls, Nodo* nodo);
void createEl(Nodo** ptrls);
void CreateList(Nodo** ptr);

void InsDalFondo(Nodo* ls, int* k, int val);

int main(){

    Nodo* lista = NULL;
    Nodo** ptr = &lista;
    int k = 2;

    CreateList(ptr);

    InsDalFondo(*ptr, &k, 99);

    PrintList(lista);

    return 0;
}


void InsDalFondo(Nodo* ls, int* k, int val) //sostituisce al k-esimo valore dal fondo il numero val
{
    if(ls->next != NULL)
        InsDalFondo(ls->next, k, val);

    (*k)--;

    if((*k) == 0)
        ls->num = val;
}

void CreateList(Nodo** ptr) //gestisce la creazione della lista
{
    int i = 0;

    do{
        createEl(ptr);
        i++;
    }while(i<5);
}

void addLista(Nodo** ptrls, Nodo* nodo)
{
    if(*ptrls == NULL) //caso 1: si sta inserendo il primo elemento della lista
        *ptrls = nodo;
    else
        subAddLista(*ptrls, nodo); //caso 2: si sta aggiungendo un nuovo nodo alla lista
}

void subAddLista(Nodo* ls, Nodo* nodo) //aggiunge in coda alla lista
{
    if(ls->next != NULL)
    {
        Nodo* app = ls;

        while(app->next != NULL)
            app = app->next;

        app->next = nodo;
    }
    else
        ls->next = nodo;
}

void createEl(Nodo** ptrls) //gestisce la creazione del nodo
{
    Nodo* nodo;

    nodo = malloc(sizeof(Nodo));

    printf("Inserisci il numero: ");
    scanf("%d", &(nodo->num));

    nodo->next=NULL;

    addLista(ptrls, nodo);
}

void PrintList(Nodo* lista)
{
    if(lista != NULL)
    {
        printf("%d - ", lista->num);
        PrintList(lista->next);
    }
}
