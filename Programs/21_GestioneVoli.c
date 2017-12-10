//NON FUNZIONANTE 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //probabilmente non necessario
#define dim 4

typedef struct V{

    int codice;
    char destinazione[3];
    int oraPrev;
    int minPrev;
    int oraEff;
    int minEff;
    int passeggeri;

}Vo;

typedef Vo* Vol;

typedef struct P{

    Vol Volo;
    struct P* next;

}Partenza;

typedef Partenza* Partenze;

void checkRitardo(Partenze lista, int num);
void checkPasseggeri(Partenze lista, int num);
void decolla(Partenze lista, int codPers, int oraPers, int minPers);
void printVoli(Partenze lista);
void loadVoli(Partenze lista, FILE* filebin);
void loadVoliVett (Vol voli[dim], FILE* filebin); //alternativa "vettoriale" funzionante
void printVoliVett(Vol voli[dim]); //alternativa "vettoriale" funzionante

int a = 0;

int main(){

    Partenze lista;
    //Vol voli[dim];
    int i, codPers, oraPers, minPers;

    FILE* filebin;
    filebin = fopen("D:\listaVoli.bin", "r");

    loadVoli(lista, filebin);

    printVoli(lista);

    //loadVoliVett(voli, filebin);
    //printVoliVett(voli);

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

void loadVoliVett (Vol voli[dim], FILE* filebin){
    int c;
    for(c=0; c<dim; c++)
    {
        voli[c]= malloc(sizeof(Vo));
        fread(voli[c], sizeof(Vo), 1, filebin);
    }

}

void loadVoli(Partenze lista, FILE* filebin){ //è come se non concatenasse la lista

    lista = malloc(sizeof(Partenza));
    lista->Volo = malloc(sizeof(Vo));
    lista->next = NULL;
    fread(lista->Volo, sizeof(Vo), 1, filebin);
    a++;
    if(a<dim)
        loadVoli(lista->next, filebin);
}

void printVoli(Partenze lista){

    printf("\nCODICE VOLO: %d", lista->Volo->codice);
    printf("\nDestinazione: %c%c%c", lista->Volo->destinazione[0], lista->Volo->destinazione[1], lista->Volo->destinazione[2]);
    printf("\nOra prevista: %d", lista->Volo->oraPrev);
    printf("\nMinuti previsti: %d", lista->Volo->minPrev);
    printf("\nOra effettiva: %d", lista->Volo->oraEff);
    printf("\nMinuti effettivi: %d", lista->Volo->minPrev);
    printf("\nNumero di passeggeri: %d\n", lista->Volo->passeggeri);

    if(lista->next != NULL)
        printVoli(lista->next);
}

void printVoliVett(Vol voli[dim]){
    
        int c;
        for(c=0; c<dim; c++)
        {
            printf("\nCODICE VOLO: %d", voli[c]->codice);
            printf("\nDestinazione: %c%c%c", voli[c]->destinazione[0], voli[c]->destinazione[1], voli[c]->destinazione[2]);
            printf("\nOra prevista: %d", voli[c]->oraPrev);
            printf("\nMinuti previsti: %d", voli[c]->minPrev);
            printf("\nOra effettiva: %d", voli[c]->oraEff);
            printf("\nMinuti effettivi: %d", voli[c]->minPrev);
            printf("\nNumero di passeggeri: %d\n", voli[c]->passeggeri);

        }
}

void decolla(Partenze partenza, int codPers, int oraPers, int minPers){

    if((partenza->Volo->codice) != codPers)
        decolla(partenza->next, codPers, oraPers, minPers);

    partenza->Volo->oraEff = oraPers;
    partenza->Volo->minEff = minPers;
    printf("\nVolo decollato!\n");

}

void checkPasseggeri(Partenze lista, int num){


}

void checkRitardo(Partenze lista, int num){


}
