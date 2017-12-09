/*
 * Politecnico di Milano
 * Dipartimento di Elettronica e Informazione
 * Fondamenti di Informatica
 *
 * --------------------------------
 *    Partite.c
 * --------------------------------
 *
 *  In una partita tra due giocatori, ogni giocatore lancia un dado e una moneta:
 *   - Se nel lancio della moneta esce testa, la partita è vinta
 *     dal giocatore con il punteggio più alto nel lancio del proprio dado.
 *   - Se nel lancio della moneta esce croce, la partita è vinta
 *     dal giocatore con il punteggio più basso.
 *   - Se i dadi hanno lo stesso valore la partita è un pareggio.
 *
 *  Si consideri la seguente definizione di tipo:
 *
 *      typedef struct {
 *          char moneta;
 *          int dadoGiocatore1;
 *          int dadoGiocatore2;
 *      } Partita;
 *
 *  che rappresenta il risultato dei lanci associati ad una singola partita.
 *  I campi dadoGiocatore1 e dadoGiocatore2 rappresentano i valori
 *  (compresi tra 1 e 6) conseguiti da giocatore1 e giocatore2
 *  nel lancio del dado. Il campo moneta ha valore ’t’ o ’c’
 *  a seconda che nel lancio della moneta sia uscita testa o croce
 *  rispettivamente.
 *
 *  Si scriva:
 *
 *  1) una funzione che, dati come parametri un vettore di partite e
 *     la sua dimensione, restituisca:
 *      - 1 se il giocatore1 ha vinto più partite del giocatore2
 *      - 2 se il giocatore2 ha vinto più partite del giocatore 1
 *      - 0 in caso di un numero pari di vittorie.
 *  2) una funzione che salva su un file binario i dati delle partite giocate
 *  3) una funzione che carica da file binario i risultati di una partita.
 *  5) un *** Main di prova *** che:
 *      - chiede all'utente di inserire il nome del file da cui caricare le partite.
 *      - se non viene specificato nessun nome di file o se il file non esiste carica dei
 *        risultati di default arbitrariamente definiti nel corpo del main stesso e li salva
 *        in un file binario, altrimenti carica i dati dal file indicato
 *      - calcola il vincitore del torneo e ne stampa il risultato
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PARTITE 5

//definizione del nuovo tipo dati Partita
typedef struct {
	char moneta;
	int dadoGiocatore1;
	int dadoGiocatore2;
} Partita;

//prototipi delle funzioni definite nel programma
int calcolaVincitore(Partita[], int);
void salvaPartiteBin(char*, Partita[], int);
int caricaPartite(char*, Partita*);

int main() {

	int numeroPartite = NUM_PARTITE;
	int vincitore = -1;
	Partita torneo[NUM_PARTITE];
	char nomeFile[100];

  setbuf(stdout, NULL);

	printf("Inserisci il nome del file: ");
	scanf("%s", nomeFile);


	numeroPartite = caricaPartite(nomeFile, torneo);
	// Se non trova il file carica il default e usa il nome passato per salvarlo
	if( numeroPartite == -1) {
		torneo[0].moneta = 't';
		torneo[0].dadoGiocatore1 = 1;
		torneo[0].dadoGiocatore2 = 4;

		torneo[1].moneta = 'c';
		torneo[1].dadoGiocatore1 = 3;
		torneo[1].dadoGiocatore2 = 6;

		torneo[2].moneta = 't';
		torneo[2].dadoGiocatore1 = 3;
		torneo[2].dadoGiocatore2 = 1;

		torneo[3].moneta = 'c';
		torneo[3].dadoGiocatore1 = 4;
		torneo[3].dadoGiocatore2 = 4;

		torneo[4].moneta = 'c';
		torneo[4].dadoGiocatore1 = 3;
		torneo[4].dadoGiocatore2 = 1;

		numeroPartite = NUM_PARTITE;

		salvaPartiteBin(nomeFile, torneo, NUM_PARTITE);

	}
	if( numeroPartite == 0) {
		printf("ATTENZIONE: nessuna partita nel file.\n");
		return -1;
	}

	vincitore = calcolaVincitore(torneo, numeroPartite);

	//stampo il risultato della partita
	if(vincitore == 0)
		printf("La partita è patta :-(\n");
	else if(vincitore == 1)
		printf("Vince il giocatore 1!\n");
	else if(vincitore == 2)
		printf("Vince il giocatore 2!\n");
	else if (vincitore == -1)
		printf("ERRORE: calcolo non eseguito\n");

	return 0;
}

//funzione che salva i dati di un torneo su un file binario
void salvaPartiteBin(char* nomeFile, Partita torneo[], int numeroPartite) {
	size_t nElScritti;
	FILE* fp = fopen(nomeFile, "wb");
	if (fp != NULL) {
		nElScritti = fwrite(torneo, sizeof(Partita), numeroPartite, fp);
		if (nElScritti < numeroPartite) {
			printf("ERRORE durante la scrittura del file, scritti %zd elementi su %d\n",nElScritti, numeroPartite);
		}
	}
	fclose(fp);
}


//funzione che legge i dati di un torneo da un file binario e li salva nel vettore torneo
int caricaPartite(char* nomeFilePartite, Partita torneo[]) {
	FILE* fp;
	int numPartite = -1;
	int nonFinito = 0;

	fp = fopen(nomeFilePartite, "rb");
	Partita p;
	if (fp != NULL) {
		numPartite++;
		while(!feof(fp)){
			nonFinito = (int)fread(&p, sizeof(Partita), 1, fp);
			if(nonFinito){
				torneo[numPartite] = p;
				numPartite++;
			}
		}
		fclose(fp);
	}

	return numPartite;
}


int calcolaVincitore(Partita torneo[], int numeroPartite) {
	int i;
	int puntiGiocatore1 = 0;
	int puntiGiocatore2 = 0;

	for( i=0; i<numeroPartite; i++ ) {
		printf("Calcolo vincitore per partita %d\n", i);
		printf("  Moneta: %c\n", torneo[i].moneta);
		printf("  Dado giocatore 1: %d\n", torneo[i].dadoGiocatore1);
		printf("  Dado giocatore 2: %d\n", torneo[i].dadoGiocatore2);

		if( torneo[i].dadoGiocatore1 > torneo[i].dadoGiocatore2 ) {
			if( torneo[i].moneta == 't' ) {
				puntiGiocatore1++;
			}
			else if( torneo[i].moneta == 'c' ) {
				puntiGiocatore2++;
			}
			else {
				printf("Errore nella struttura dati: il valore della moneta può essere solo 't' o 'c'.\n");
				return -1;
			}
		}
		else if ( torneo[i].dadoGiocatore1 < torneo[i].dadoGiocatore2 ) {
			if( torneo[i].moneta == 't' ) {
				puntiGiocatore2++;
			}
			else if( torneo[i].moneta == 'c' ) {
				puntiGiocatore1++;
			}
			else {
				printf("Errore nella struttura dati: il valore della moneta può essere solo 't' o 'c'.\n");
				return -1;
			}
		}
	}
	if( puntiGiocatore1 > puntiGiocatore2 )
		return 1;
	else if( puntiGiocatore1 < puntiGiocatore2 )
		return 2;
	else if( puntiGiocatore1 == puntiGiocatore2 )
		return 0;
	else
		return -1;
}
