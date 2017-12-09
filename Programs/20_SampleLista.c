#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    int dato;
    struct nodo* next;
}el;

typedef el* elnodo;

void inserisciElemento(elnodo lista, int num, int pos);
int lunghezzaLista(elnodo lista);
void cancellaRipetizioni(elnodo lista);
void printLista(elnodo lista);
void subcanc(elnodo lista, int dato);
void sommaLista(elnodo lista);
void subsomma(elnodo lista, int* somma);

int main(){

    int num, pos;
    elnodo lista,mem;

    printf("\nInserisci il primo elemento (posizione 1): ");
    scanf("%d", &num);

    lista = malloc(sizeof(el));
    lista->dato = num;
    lista->next = NULL;

    do{

        printf("\nInserisci un elemento della lista: ");
        scanf("%d", &num);

        if(num!=0)
        {
            printf("\nInserisci la posizione in cui inserire il nodo: ");
            scanf("%d", &pos);

            inserisciElemento(lista, num, pos);
        }

        printLista(lista);


    }while(num != 0);

    mem = lista;

    num = lunghezzaLista(lista);
    printf("\nLa dimensione della lista e': %d\n\n", num);

    printLista(lista);

    lista = mem;

    printf("\n\nOra cancello le ripetizioni:\n");
    cancellaRipetizioni(lista);
    printLista(lista);

    lista = mem;

    num = lunghezzaLista(lista);
    printf("\nLa dimensione della lista e': %d\n\n", num);

    lista = mem;

    printf("\n\nOra sommo la lista:\n");
    sommaLista(lista);
    printLista(lista);

    printf("\n\n\n\n\n");

    return 0;
}

void sommaLista(elnodo lista) //per ogni dato a partire dal primo avvia la funzione che calcola la somma di tutti i successivi
{
    if(lista->next != NULL)
    {
        int somma = 0;
        subsomma(lista, &somma);
        lista->dato = somma;
        sommaLista(lista->next);
    }
}

void subsomma(elnodo lista, int* somma) //dato un numero e una lista, calcola la somma di tutti i dati successivi a quella posizione, e la salva in una variabile per indirizzo
{
    *somma += lista->dato;
    if(lista->next != NULL)
        subsomma(lista->next, somma);
}

void cancellaRipetizioni(elnodo lista) //per ogni dato a partire dal primo avvia la funzione che elimina tutti i doppi nelle posizioni successive
{
    elnodo app;
    if(lista->next != NULL)
    {
        app = lista;
        subcanc(app, app->dato);
        cancellaRipetizioni(lista->next);
    }
}

void subcanc(elnodo lista, int dato) //dato un numero e una lista, elimina tutti i doppi di quel numero nelle posizioni successive della lista
{
    if (lista->next != NULL)
    {
        if(dato == lista->next->dato)
        {
            lista->next = lista->next->next;
            if(lista->next != NULL)
                subcanc(lista, dato);
        }
        if(lista->next != NULL)
            subcanc(lista->next, dato);
    }
}

void printLista(elnodo lista) //stampa la lista
{
    while(lista->next != NULL)
    {
        printf(" %d->", lista->dato);
        lista = lista->next;
    }
    printf("%s %d Fine.", lista, lista->dato);
}

void inserisciElemento(elnodo lista, int num, int pos) //dato un dato e la posizione all'interno della lista, crea un nodo contenente quel dato nella posizione specificata
{
    elnodo ptr;

    int i;
    for(i=1; i<pos-1; i++)
        lista=lista->next;

    ptr = malloc(sizeof(el));
    ptr->dato = num;
    ptr->next = lista->next;
    lista->next=ptr;
}

int lunghezzaLista(elnodo lista) //restituisce la dimensione della lista
{
    int dim =0;

    for(dim =0; lista->next != NULL; dim++)
    {
        lista = lista->next;
    }
    return dim+1;
}
