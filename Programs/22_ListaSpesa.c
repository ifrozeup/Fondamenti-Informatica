#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pr{
    char nome[3]; //da aggiornare
    int qta;
    int costo;
    struct pr* next;
}Pro;

void insProd(Pro** ptrls);
void addLista(Pro** ptrls, Pro* nodo);
void subAddLista(Pro* ls, Pro* nodo);
int udQta(Pro* ls, Pro* nodo);
void stampa(Pro* ls);
void del();
int totale(Pro* ls);

int main(){

    Pro* ptr = NULL;
    Pro** ptrls = &ptr;

    int scelta;

    do{
        printf("\nInserisci 1 per inserire un elemento alla lista della spesa\n");
        printf("Inserisci 2 per eliminare l'ultimo elemento della lista\n");
        printf("Inserisci 3 per visualizzare il totale della spesa\n");
        printf("Inserisci 4 per stampare la lista della spesa\n");
        printf("Inserisci 5 per terminare il programma\n");
        scanf("%d", &scelta);

        if(scelta==1)
            insProd(ptrls);
        if(scelta==2)
            del();
        if(scelta==3)
            printf("\nIl prezzo totale e': %d", totale(*ptrls));
        if(scelta==4)
            stampa(*ptrls);

    }while(scelta != 5);

    return 0;
}

void addLista(Pro** ptrls, Pro* nodo)
{
    if(*ptrls == NULL) //caso 1: si sta inserendo il primo elemento della lista
    {
        *ptrls = nodo;
    }
    else if(udQta(*ptrls, nodo))
        {

        }
        else
        {
        subAddLista(*ptrls, nodo); //caso 3: si sta aggiungendo un nuovo nodo alla lista
        }
}

void subAddLista(Pro* ls, Pro* nodo) //aggiunge in coda alla lista
{
    if(ls->next != NULL)
    {
        Pro* app = ls;

        while(app->next != NULL)
            app = app->next;

        app->next = nodo;
    }
    else
    {
        ls->next = nodo;
    }
}

int udQta(Pro* ls, Pro* nodo) //aggiorna la quantità ricorsivamente
{
    if(!strcmp(ls->nome, nodo->nome)) //caso 2: si sta aggiornando la quantità di un prodotto già presente
    {
        ls->qta += nodo->qta;
        return 1;
    }
    else if(ls->next != NULL) //controlla che l'elemento non sia già nella lista
        {
            return udQta(ls->next, nodo);
        }
        else
        {
            return 0;
        }
}

void insProd(Pro** ptrls) //gestisce la creazione del nodo
{
    Pro* nodo;

    nodo = malloc(sizeof(Pro));

    printf("Inserisci il nome del prodotto\n");
    scanf("%s", nodo->nome);
    printf("Inserisci la quantita del prodotto\n");
    scanf("%d", &(nodo->qta));
    printf("Inserisci il prezzo del prodotto\n");
    scanf("%d", &(nodo->costo));

    nodo->next=NULL;

    addLista(ptrls, nodo);
}

void stampa(Pro* ls)
{
    printf("\nNome: %s\n", ls->nome);
    printf("Quantita: %d\n", ls->qta);
    printf("Prezzo: %d\n", ls->costo);

    if(ls->next != NULL)
        stampa(ls->next);
}

void del() //elimina l'ultimo nodo della lista
{

}

int totale(Pro* ls) //calcola l'importo totale
{
    if(ls->next != NULL)
        return (ls->qta)*(ls->costo) + totale(ls->next);
    else
        return (ls->qta)*(ls->costo);
}

