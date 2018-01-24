#include <stdio.h>

typedef struct n{
    int dato;
    struct n* next;
}nodo;

typedef struct r{
    int dato;
    int rep;
    struct r* next;
}repe;

void createList(nodo** list);
void printList(nodo* list);
void createCtrNode(repe** ctr, int num);
void countRep(nodo** ls);
void printCtr(repe* ls);

int main(){

    int i;

    nodo* list = NULL;
    nodo** ptrls = &list;

    createList(ptrls);
    printList(*ptrls);

    countRep(ptrls);

    return 0;
}

void printCtr(repe* ls)
{
    if(ls)
    {
        printf("\nDato: %d", ls->dato);
        printf("\nRep: %d", ls->rep);
        printCtr(ls->next);
    }
}

void countRep(nodo** ls)
{
    repe* c = NULL;
    repe** ctr = &c;
    nodo* app = *ls;
    printf("\n\n");

    do 
    {
        createCtrNode(ctr, app->dato);
        app = app->next;
    } while(app);

    printCtr(*ctr);
}

void createCtrNode(repe** ctr, int num)
{
    repe* ptr;
    repe* nuovo;

    ptr = *ctr;

    if(!ptr) //primo della lista
    {
        (*ctr) = (repe*)malloc(sizeof(repe));
        (*ctr)->dato = num;
        (*ctr)->rep = 1;
        (*ctr)->next = NULL;
    }
    else //elementi successivi
    {
        for(;(ptr->next) && (ptr->dato!=num); ptr = ptr->next); //scorro lista fino alla prima posizione utile

        if(ptr->dato == num) //aggiungo ripetizioni
        {
            ptr->rep = ptr->rep + 1;
        }
        else //nuovo elemento
        {
            nuovo = NULL;
            nuovo = (repe*)malloc(sizeof(repe));
            nuovo->dato = num;
            nuovo->rep = 1;
            nuovo->next = NULL;
            ptr->next = nuovo;
        }
    }
}

void createList(nodo** list)
{
    int ins;

    nodo* ptr;
    nodo* nuovo;

    ptr = *list;

    printf("\nInserisci dato: ");
    scanf("%d", &ins);

    if(ins)
    {
        if(!ptr) //primo della lista
        {
            (*list) = (nodo*)malloc(sizeof(nodo));
            (*list)->dato = ins;
            (*list)->next = NULL;
            createList(list);
        }
        else //elementi successivi
        {
            nuovo = NULL;
            nuovo = (nodo*)malloc(sizeof(nodo));

            for(; ptr->next != NULL; ptr = ptr->next);

            nuovo->dato = ins;
            nuovo->next = NULL;
            ptr->next = nuovo;
            createList(list);
        }
    }
}

void printList(nodo* list)
{
    if(list)
    {
        printf("\nDato: %d", list->dato);
        printList(list->next);
    }
}
