#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_LEN 100

typedef char* String;

//definizione della struct Item
typedef struct {
    String alimento;
    int quantita;
    double prezzo;
} Item;


//definizione di un nodo della lista della spesa
typedef struct ElemNodo {
    Item Valore;
    struct ElemNodo* Successore;
} Nodo;

//definizione di una lista della spesa
typedef Nodo* ListaNodi;


//prototipi delle funzioni
void InizializzaLista (ListaNodi* L);
void aggiungiElemento(ListaNodi* l, String el, int q, double);
void cancellaElemento(ListaNodi* L);
double valoreLista(ListaNodi* L);
void salvaFile(ListaNodi L, String nomeFile);
void stampaLista(ListaNodi L);

int main() {

    int menuVal;
    int flag = 0;
    char buffer[MAX_CHAR_LEN];
    ListaNodi L;
    InizializzaLista(&L);

    do {
        printf("Scegli una voce del Menu:\n");
        printf("[1]\tInserire un nuovo elemento nella lista della spesa\n");
        printf("[2]\tEliminare ultimo elemento dalla lista della spesa\n");
        printf("[3]\tCalcolare l'importo totale della spesa\n");
        printf("[4]\tStampare la lista su file\n");
        printf("[5]\tEsci\n");
        printf("\n");

        scanf("%d", &menuVal);

        //processo la scelta dell'utente
        switch(menuVal) {
        //inserisco un nuovo elemento
        case 1: {
            int q;
            double p;
            printf("Inserire il nome, la quantita' e il prezzo dell'alimento da aggiungere alla lista: ");
            scanf("%s%d%lf", buffer, &q, &p);
            String nome = (String) malloc(strlen(buffer) * sizeof(char));
            strncpy(nome, buffer, strlen(buffer));
            aggiungiElemento(&L, nome, q, p);
            stampaLista(L);
            break;
        }

        //elimino l'ultimo elemento
        case 2: {
            cancellaElemento(&L);
            stampaLista(L);
            break;
        }
        //calcolo l'importo totale della spesa
        case 3: {
            printf("L'importo totale della spesa e' di %f euro\n", valoreLista(&L));
            break;
        }
        //stampo la lista della spesa su file
        case 4: {
            String n = (String) malloc(MAX_CHAR_LEN*sizeof(char));
            printf("Inserisci il nome del file sul quale stampare la lista: ");
            scanf("%s", n);
            salvaFile(L, n);
            break;
        }
        //termino il programma
        case 5:
            flag =1;
            printf("\nUscita dal Programma");
            break;

        default: // Se l'utente inserisce un valore non valido si mostra nuovamente il MENU
            printf("\n");
            printf("Scelta non corretta, scegliere tra una delle opzioni disponibili...\n");
            break;
        }

    } while(flag != 1);

    return 0;
}

//funzione per inizializzare a NULL una qualsiasi lista di nodi
void InizializzaLista (ListaNodi* L) {
    *L = NULL;
}

//funzione che inserisce un nuovo elemento nella lista datone il valore
void InserisciInTesta(ListaNodi* L, Item i) {
    Nodo * temp;
    temp = (Nodo *) malloc (sizeof (Nodo));
    if (temp == NULL) {
        printf ("\nerrore di allocazione della memoria!");
        return;
    }

    temp->Valore=i;
    temp->Successore = *L;

    *L = temp;
}

//funzione che, dato nom e, quantita' e costo, aggiunge un nuovo elemento alla lista
void aggiungiElemento(ListaNodi* l, String el, int q, double p) {
    int cont = 0;
    Nodo* n = *l;

    while(n != NULL) {
        //se l'elemento e' gia' presente ne modifico quantita' e costo
        if(strcmp((n->Valore).alimento,el)==0) {
            (n->Valore).quantita+=q;
            (n->Valore).prezzo=p;
            return;
        }
        else {
            n = n->Successore;
        }
    }
    Item a;
    a.alimento = el;
    a.quantita = q;
    a.prezzo = p;
    InserisciInTesta(l, a);
    return;
}

//funzione che cancella l'ultimo elemento della lista (elemento nell'ultima posizione)
void cancellaElemento(ListaNodi* L) {
    Nodo* n = *L;
    Nodo* nodoPrec = NULL;

    if(n==NULL) return;

    while(n->Successore!=NULL) {
        nodoPrec = n;
        n = n->Successore;

    }
    nodoPrec->Successore = NULL;
    free(n);
    return;
}

//funzione che calcola l'importo totale della lista della spesa
double valoreLista(ListaNodi* L) {
    if(*L == NULL) {
        return 0;
    }
    else {
        Item i = (*L)->Valore;
        return (i.quantita*i.prezzo) + valoreLista(&(*L)->Successore);
    }
}


//funzione che salva la lista della spesa su file
void salvaFile(ListaNodi L, String nomeFile) {
    //creo una variabile di tipo file
    FILE* f;
    Nodo *n = L;

    //apro il file e verifico che non ci siano stati errori
    f=fopen(nomeFile,"w");
    if (f==NULL) {
        printf("Errore di apertura del file\n");
        return;
    }
    //stampo la lista riga per riga
    while(n != NULL) {
        Item i = n->Valore;
        fprintf(f, "%s %d %.2f\n", i.alimento, i.quantita, i.prezzo);
        n = n->Successore;
    }
    //stampo l'importo totale della spesa
    fprintf(f, "TOTALE: %.2f", valoreLista(&L));

    //chiudo il file una volta ternimata la scrittura e verifico che non ci siano errori
    if (fclose(f)==EOF) {
        printf("Errore di chiusura del file\n");
        return;
    }
}

void stampaLista(ListaNodi L) {

    Nodo *n = L;

    //stampo la lista riga per riga
    while(n != NULL) {
        Item i = n->Valore;
        printf("%s %d %.2f\n", i.alimento, i.quantita, i.prezzo);
        n = n->Successore;
    }
    return;
}
