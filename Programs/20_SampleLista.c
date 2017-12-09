#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{

    int dato;
    struct nodo* next;

}el;

typedef el* elnodo;

void ins(elnodo lista, int num, int pos);
int dim(elnodo lista);
void cancrip(elnodo lista);

int cont = 0;

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

            ins(lista, num, pos);
        }

    }while(num != 0);

    mem = lista;

    num = dim(lista);
    printf("\nLa dimensione della lista e': %d\n\n", num);

    stampalista(lista);

    lista = mem;

    printf("\n\nOra cancello le ripetizioni:\n");
    cancrip(lista);
    stampalista(lista);

    lista = mem;

    num = dim(lista);
    printf("\nLa dimensione della lista e': %d\n\n", num);

    return 0;
}

void sommalista(elnodo lista)
{

}

void cancrip(elnodo lista)
{
    elnodo mem;
    if(lista->next != NULL)
    {
        cont = 0;
        mem = lista;
        subcanc(mem, mem->dato);
        cancrip(lista->next);
    }
}

void subcanc(elnodo lista, int dato)
{
    if (lista->next != NULL)
    {
        if(dato == lista->next->dato)
        {
            lista->next = lista->next->next;
            cont++;
            subcanc(lista, dato);
        }
        subcanc(lista->next, dato);
    }
}


void stampalista(elnodo lista)
{
    while(lista->next != NULL)
    {
        printf(" %d->", lista->dato);
        lista = lista->next;
    }
    printf("%s %d Fine.", lista, lista->dato);
}

void ins(elnodo lista, int num, int pos)
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

int dim(elnodo lista)
{
    int dim =0;

    for(dim =0; lista->next != NULL; dim++)
    {
        lista = lista->next;
    }

    return dim+1;
}
