#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct E{
    char nome[3]; //da aggiornare
    int qta;
    int costo;
    struct E* next;
}el;

typedef el* spesa;

spesa addLista(spesa lista, spesa nodo);
spesa insProd(spesa lista); //non void per il compilatore, altrimenti perde la lista quando torna nel main
void stampa(spesa lista);
void del(spesa lista);
int totale(spesa lista);

spesa lista = NULL; //globale altrimenti il compilatore fa casino

int main(){

    int scelta = 0;

    do{
        printf("\nInserisci 1 per inserire un elemento alla lista della spesa\n");
        printf("Inserisci 2 per eliminare l'ultimo elemento della lista\n");
        printf("Inserisci 3 per visualizzare il totale della spesa\n");
        printf("Inserisci 4 per stampare la lista della spesa\n");
        printf("Inserisci 5 per terminare il programma\n");
        scanf("%d", &scelta);

        if(scelta==1)
            lista = insProd(lista);
        if(scelta==2)
            del(lista);
        if(scelta==3)
            printf("\nIl prezzo totale e': %d", totale(lista));
        if(scelta==4)
            stampa(lista);

    }while(scelta != 5);

    return 0;
}

void stampa(spesa lista)
{
    printf("\nNome: %s\n", lista->nome);
    printf("Quantita: %d\n", lista->qta);
    printf("Prezzo: %d\n", lista->costo);

    if(lista->next != NULL)
        stampa(lista->next);
}

spesa insProd(spesa lista) //crea un nodo con i dati inseriti da input
{
    spesa nodo;
    int num;
    char id[3];

    nodo = malloc(sizeof(el));

    printf("Inserisci il nome del prodotto\n");
    scanf("%s", nodo->nome);
    printf("Inserisci la quantita del prodotto\n");
    scanf("%d", &num);
    nodo->qta = num;
    printf("Inserisci il prezzo del prodotto\n");
    scanf("%d", &num);
    nodo->costo = num;

    nodo->next=NULL;

    lista = addLista(lista, nodo);
    return lista;
}

spesa addLista(spesa lista, spesa nodo) //inserisce il nodo creato nella posizione corretta
{
    if(lista == NULL) //caso 1: si sta inserendo il primo elemento della lista
    {
        lista = nodo;
        return lista;
    }

    if(!strcmp(lista->nome, nodo->nome)) //caso 2: si sta aggiornando la quantità di un prodotto già presente
    {
        lista->qta += nodo->qta;
        return lista;
    }

    if(lista->next != NULL) //controlla che l'elemento non sia già nella lista
        return addLista(lista->next, nodo);

    lista->next = nodo; //caso 3: si sta aggiungendo un nuovo nodo alla lista
    return lista;
}

void del(spesa lista) //elimina l'ultimo elemento inserito
{

}

int totale(spesa lista) //calcola l'importo totale
{
    if(lista->next != NULL)
        return (lista->qta)*(lista->costo) + totale(lista->next);
    else
        return (lista->qta)*(lista->costo);
}
