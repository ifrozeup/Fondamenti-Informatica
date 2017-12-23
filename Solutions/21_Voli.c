/*
 * Politecnico di Milano
 * Dipartimento di Elettronica e Informazione
 * Fondamenti di Informatica
 *
 * --------------------------------
 *    Voli.c
 * --------------------------------
 * Scrivere un programma per la gestione di un aeroporto.
 * Il programma definisce la struttura Volo, costituita da un codice (intero), una destinazione (array di 3 caratteri), un'ora di partenza prevista e un
 * minuto di partenza prevista, un'ora di partenza effettiva e un minuto di partenza effettiva, il numero di passeggeri.
 * Il programma, implementando opportune funzioni, deve caricare la lista dei voli da effettuare da file binario e salvare il contenuto in una apposita struttura dati.
 * Deve poi stampare la lista completa dei voli.
 * Definire una funzione "decolla" che ricevuta la lista dei voli, il codice di un volo specifico e ora e minuto di decollo, aggiorna i dati relativi del volo indicato.
 * Fare decollare dal main i seguenti voli:
 * 		- Volo 3497 alle 11:30
 * 		- Volo 2193 alle 11:53
 * 		- Volo 4284 alle 11:07
 *
 * Trovare a stampare la lista dei voli che hanno più di 200 passeggeri
 * Trovare e stampare la lista dei voli che hanno più di 5 minuti di ritardo e quella dei voli che hanno più di 30 minuti di ritardo.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nome del file su cui salvare/da cui leggere i voli
#define FILE_NAME "ListaVoli.bin"

typedef struct Volo{
    int codice;
    char destinazione[3];
    int oraPartenza;
    int minutoPartenza;
    int oraPartenzaEffettiva;
    int minutoPartenzaEffettiva;
    int numeroPasseggeri;
} Volo;


typedef struct Voli {
    Volo volo;
    struct Voli *next;
} ListaVoli;


Volo creaVolo(int codice, char *destinazione, int oraPartenza, int minutoPartenza, int numeroPasseggeri);
void inserisciVolo(ListaVoli **listaVoli, Volo voloDaInserire);
int caricaVoliDaFile(ListaVoli **listaVoli, char *nomeFile);
void decolla(ListaVoli *listaVoli, int codiceVolo, int oraDecollo, int minutoDecollo);
void stampaVoliRitardo(ListaVoli *listaVoli, int minutiRitardo);
void stampaVoliPasseggeri(ListaVoli *listaVoli, int numPasseggeri);

/*** UTILITIES ***********************************************************************************/

void stampaVolo(Volo volo);
int checkRitardo(Volo volo, int minutiRitardo);
int differenzaOrari(int oraInizio, int minutoInizio, int oraFine, int minutoFine);

/*** MAIN ***********************************************************************************/

int main(int argc, const char * argv[]) {
    // Dichiarazione ed inizializzazione della lista dei voli
    ListaVoli *listaVoli = NULL;

    //  Caricamento dei voli da file
    printf("Caricamento voli da file... ");
    int nVoliCaricati = caricaVoliDaFile(&listaVoli, FILE_NAME);
    // Se il file non viene trovato carica dei voli di default
    if (nVoliCaricati == 0) {
    	printf("File mancante o vuoto, creo voli di default. ");
    	return 1;
    }
    else {
    	printf("Caricati %d voli.\n",nVoliCaricati);
    }

    // Stampa dei voli in lista
    ListaVoli *curr = listaVoli;

    printf("\nLista dei voli:\n");
    while (curr != NULL) {
    	stampaVolo(curr->volo);
    	curr = curr->next;
    }

    // Decollo dei voli con diversi valori di ritardo
    decolla(listaVoli, 3497, 11, 30);
    decolla(listaVoli, 2193, 11, 53);
    decolla(listaVoli, 4284, 11, 07);

    stampaVoliPasseggeri(listaVoli, 200);

    // Stampa voli in ritardo
    stampaVoliRitardo(listaVoli, 5);

    stampaVoliRitardo(listaVoli, 30);

    return 0;
}

/*** FUNCTIONS ***********************************************************************************/


/***
 * La funzione creaVolo è il costruttore di Volo: crea e restituisce un oggetto di tipo Volo.
 *
 * Parametri:
 *  - int codice          codice identificativo dei voli
 *  - char *descrizione   sigla dell'aeroporto di destinazione
 *  - int oraPartenza     ora a cui e' prevista la partenza dell'aereo
 *  - int minutoPartenza  minuto a cui e' prevista la partenza dell'aereo
 */
Volo creaVolo(int codice, char destinazione[], int oraPartenza, int minutoPartenza, int numeroPasseggeri) {
    Volo *nuovoVolo = malloc(sizeof(Volo));
    nuovoVolo->codice = codice;
    strcpy(nuovoVolo->destinazione, destinazione);
    nuovoVolo->oraPartenza = oraPartenza;
    nuovoVolo->minutoPartenza = minutoPartenza;
    nuovoVolo->oraPartenzaEffettiva = -1;
    nuovoVolo->minutoPartenzaEffettiva = -1;
    nuovoVolo->numeroPasseggeri = numeroPasseggeri;

    return *nuovoVolo;
}

/***
 * La funzione inserisciVolo inserisce un volo nella lista dei voli.
 *
 * Parametri:
 *  - ListaVoli **listaVoli  la lista dei voli
 *  - Volo voloDaInserire    il volo da inserire
 */
void inserisciVolo(ListaVoli **listaVoli, Volo voloDaInserire) {
    ListaVoli *voloCorrente = *listaVoli;

    ListaVoli *nuovoNodo = malloc(sizeof(ListaVoli));
    nuovoNodo->volo = voloDaInserire;
    nuovoNodo->next = NULL;

    // Se lista e' vuota
    if (voloCorrente == NULL)
        *listaVoli = nuovoNodo;
    // Se ci sono elementi nella lista
    else {
        while (voloCorrente->next != NULL) {
            voloCorrente = voloCorrente->next;
        }
        voloCorrente->next = nuovoNodo;
    }
}

/***
 * La funzione caricaVoliDaFile carica una lista di voli da un file binario.
 *
 * Parametri:
 *  - ListaVoli **listaVoli  la lista dei voli
 *  - char* nomeFile         il nome del file
 */
int caricaVoliDaFile(ListaVoli **listaVoli, char *nomeFile) {
    FILE *fp = fopen(nomeFile, "rb");
    int nVoliLetti = 0;
    size_t leggiAncora = 1;

    if (fp != NULL) {
        Volo *nuovoVolo = malloc(sizeof(Volo));
	leggiAncora = fread(nuovoVolo, sizeof(Volo), 1, fp);
         while (leggiAncora){
            inserisciVolo(listaVoli, *nuovoVolo);
            nVoliLetti++;
	    leggiAncora = fread(nuovoVolo, sizeof(Volo), 1, fp);
        }

        fclose(fp);
    }
    else {
        printf("caricaVoliDaFile(): Errore apertura file.\n");
    }

    return nVoliLetti;
}

/***
 * La funzione decolla fa decollare un aereo
 *
 * Parametri:
 *  - ListaVoli *listaVoli  la lista dei voli
 *  - int codiceVolo        il codice del volo
 *  - int oraDecollo        l'ora in cui l'aereo decolla
 *  - int minutoDecollo     il minuto in cui l'aereo decolla
 */
void decolla(ListaVoli *listaVoli, int codiceVolo, int oraDecollo, int minutoDecollo) {
    ListaVoli *curr = listaVoli;
    while (curr != NULL) {
        if(curr->volo.codice == codiceVolo) {

            if (curr->volo.oraPartenza > oraDecollo || (curr->volo.oraPartenza == oraDecollo && curr->volo.minutoPartenza > minutoDecollo)) {
                printf("Il volo %d non puo' decollare in anticipo!\n", codiceVolo);
                return;
            }

            curr->volo.oraPartenzaEffettiva = oraDecollo;
            curr->volo.minutoPartenzaEffettiva = minutoDecollo;

            printf("Il volo %d e' decollato!\n", codiceVolo);

            return;
        }

        curr = curr->next;
    }
}

void stampaVoliPasseggeri(ListaVoli *listaVoli, int numPasseggeri){
	ListaVoli *curr = listaVoli;
	printf("\nLista voli con piu' di %d passeggeri:\n", numPasseggeri);
        while (curr != NULL) {
            Volo voloCorrente = curr->volo;
            if(voloCorrente.numeroPasseggeri >= numPasseggeri)
              stampaVolo(voloCorrente);
            curr = curr->next;
       }

}

/***
 * La funzione stampaVoliRitardo stampa ivoli che hanno
 * volato con un ritardo superiore ai minuti passati come parametro
 *
 * Parametri:
 *  - ListaVoli *listaVoli  la lista dei voli
 *  - int minutiRitardo     il numero di minuti di ritardo
 */
void stampaVoliRitardo(ListaVoli *listaVoli, int minutiRitardo) {
    ListaVoli *curr = listaVoli;

    printf("\nLista voli in ritardo per piu' di %d minuti:\n", minutiRitardo);
    while (curr != NULL) {
        Volo voloCorrente = curr->volo;
        if(checkRitardo(voloCorrente, minutiRitardo))
            stampaVolo(voloCorrente);
        curr = curr->next;
    }
}

int checkRitardo(Volo volo, int minutiRitardo) {
    if(volo.oraPartenzaEffettiva != -1 && volo.minutoPartenzaEffettiva != -1)
        if (differenzaOrari(volo.oraPartenza, volo.minutoPartenza,
                            volo.oraPartenzaEffettiva, volo.minutoPartenzaEffettiva) >= minutiRitardo)
            return 1;
    return 0;
}

int differenzaOrari(int oraInizio, int minutoInizio, int oraFine, int minutoFine) {
    int diffMinuti = minutoFine - minutoInizio;
    int diffOre = oraFine - oraInizio;

    if (diffMinuti < 0) {
        diffMinuti = 60 - diffMinuti;
        diffOre--;
    }

    return diffMinuti + 60 * diffOre;
}


void stampaVolo(Volo volo) {
    printf("Volo %d: %3s %d:%d", volo.codice, volo.destinazione, volo.oraPartenza, volo.minutoPartenza);
    printf(" (");

    // Controllo per time partenza effettivo non presente
    if(volo.oraPartenzaEffettiva > 0 && volo.minutoPartenzaEffettiva > 0)
        printf("%d:%d",volo.oraPartenzaEffettiva, volo.minutoPartenzaEffettiva);
    else
        printf("N/D"); // N/D sta per non disponibile
    printf(") - %d passeggeri\n", volo.numeroPasseggeri);
}
