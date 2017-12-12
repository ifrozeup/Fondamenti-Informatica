/*
LA LISTA NON FUNZIONA
non riesce a fare lista = lista->next
con i vettori funziona ma fa schifo

COME SI CALCOLA LA DIMENSIONE DI UN FILE BINARIO?
*/

#include <stdio.h>
#include <stdlib.h>
#define dim 4 //da aggiornare

typedef struct V{

    int codice;
    char destinazione[3];
    int oraPrev;
    int minPrev;
    int oraEff;
    int minEff;
    int passeggeri;

}infoVolo;

typedef struct P{

    infoVolo* Volo;
    struct P* next;

}Partenza;

void checkRitardo(Partenza* lista, int num);
void checkPasseggeri(Partenza* lista, int num);
void decolla(Partenza* lista, int codPers, int oraPers, int minPers);
void printVoli(Partenza* lista);
void loadVoli(Partenza* lista, FILE* filebin);

int cont = 0; 

int main(){

    Partenza* lista;
    Partenza* mem;
    int i, codPers, oraPers, minPers;

    FILE* filebin;
    filebin = fopen("D:\listaVoli.bin", "r");

    //loadVoli(lista, filebin);

    lista = malloc(sizeof(Partenza));
    lista->Volo = malloc(sizeof(infoVolo));
    lista->next = NULL;
    fread(lista->Volo, sizeof(infoVolo), 1, filebin);

    lista->next = malloc(sizeof(Partenza));
    lista->next->Volo = malloc(sizeof(infoVolo));
    lista->next->next = NULL;
    fread(lista->next->Volo, sizeof(infoVolo), 1, filebin);

    lista->next->next = malloc(sizeof(Partenza));
    lista->next->next->Volo = malloc(sizeof(infoVolo));
    lista->next->next->next = NULL;
    fread(lista->next->next->Volo, sizeof(infoVolo), 1, filebin);

    lista->next->next->next = malloc(sizeof(Partenza));
    lista->next->next->next->Volo = malloc(sizeof(infoVolo));
    lista->next->next->next->next = NULL;
    fread(lista->next->next->next->Volo, sizeof(infoVolo), 1, filebin);

    printVoli(lista);

    for(i=0; i<3; i++)
    {
        printf("\nInserisci il codice del volo che deve decollare: ");
        scanf("%d", &codPers);
        printf("\nInserisci l'ora del decollo: ");
        scanf("%d", &oraPers);
        printf("\nInserisci il minuto del decollo: ");
        scanf("%d", &minPers);

        decolla(lista, codPers, oraPers, minPers);
    }

    printVoli(lista);

    printf("Controllo i voli che hanno piu' di 200 passeggeri...\n");
    checkPasseggeri(lista, 200);

    printf("Controllo i voli che hanno piu' di 5 minuti di ritardo...\n");
    checkRitardo(lista, 5);

    printf("Controllo i voli che hanno piu' di 30 minuti di ritardo...\n");
    checkRitardo(lista, 30);

    fclose(filebin);

    return 0;
}

void loadVoli(Partenza* lista, FILE* filebin){
    if(cont<dim)
    {
        lista = malloc(sizeof(Partenza));
        lista->Volo = malloc(sizeof(infoVolo));
        lista->next = NULL;
        fread(lista->Volo, sizeof(infoVolo), 1, filebin);
        cont++;
        loadVoli(lista->next, filebin);
    }
}

void printVoli(Partenza* lista){ //dato un puntatore stampa l'elemento e tutti i successivi

    printf("\nCODICE VOLO: %d", lista->Volo->codice);
    printf("\nDestinazione: %c%c%c", lista->Volo->destinazione[0], lista->Volo->destinazione[1], lista->Volo->destinazione[2]);
    printf("\nOra prevista: %d", lista->Volo->oraPrev);
    printf("\nMinuti previsti: %d", lista->Volo->minPrev);
    printf("\nOra effettiva: %d", lista->Volo->oraEff);
    printf("\nMinuti effettivi: %d", lista->Volo->minEff);
    printf("\nNumero di passeggeri: %d\n", lista->Volo->passeggeri);

    if(lista->next != NULL)
        printVoli(lista->next);
}

void decolla(Partenza* lista, int codPers, int oraPers, int minPers){ //modifica l'orario effettivo di partenza di un volo

    if((lista->Volo->codice) != codPers)
    {
       decolla(lista->next, codPers, oraPers, minPers);

    }else{

        lista->Volo->oraEff = oraPers;
        lista->Volo->minEff = minPers;
        printVoli(lista);
    }
}

void checkPasseggeri(Partenza* lista, int num){ //facile


}

void checkRitardo(Partenza* lista, int num){ //facile


}
