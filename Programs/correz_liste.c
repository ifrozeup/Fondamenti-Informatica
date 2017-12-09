#include <stdio.h>
#include <stdlib.h>

typedef struct N{
    int dato;
    struct N* next;
}Nodo;

typedef Nodo* ptrNodo;

void printLista(ptrNodo ptr);
void ins(ptrNodo lista);

int main(){

    int num, pos;
    ptrNodo lista,mem;

    printf("\nInserisci il primo elemento (posizione 1): ");
    scanf("%d", &num);

    lista = malloc(sizeof(ptrNodo));
    lista->dato = num;
    lista->next = NULL;

    ins(lista);

    printLista(lista);

return 0;
}

void printLista(ptrNodo ptr)
{
    ptrNodo lista = ptr;

    while(lista->next != NULL)
    {
        printf(" %d->", lista->dato);
        lista = lista->next;
    }
    printf("%s %d Fine.", lista, lista->dato);
}


void ins(ptrNodo lista)
{
    int val, pos, i;
    ptrNodo ptr, mem;


    do{
        mem = lista;
        printf("\nInserire elemento (0 per concludere): ");
        scanf("%d", &val);

        if(val != 0)
        {
            printf("\nInserire la posizione: ");
            scanf("%d", &pos);

            if(pos==1)
            {

            }else{

                for(i=1; i<pos-1; i++)
                    lista=lista->next;

                ptr = malloc(sizeof(ptrNodo));
                ptr->dato = val;
                ptr->next = lista->next;
                lista->next=ptr;
            }
        }
      printLista(mem);
    }while(val != 0);

    lista = mem;
    printLista (lista);
}


