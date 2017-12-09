#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nomefileu "D:\torneo.txt"

typedef struct {
char moneta;
int dadoGiocatore1;
int dadoGiocatore2;
} Partita;

void creavett(int dim, Partita* vett);
int vincita(Partita* vett, int dim);
int dime(FILE* torneofile);

int main(){

    Partita* vett;
    int ris=0;
    int dim = 2;

    creavett(dim, vett);
    printf("\ndentro ");
    printf("%c %d %d", vett[0].moneta, vett[0].dadoGiocatore1,vett[0].dadoGiocatore2);
    printf("%c %d %d", vett[1].moneta, vett[1].dadoGiocatore1,vett[1].dadoGiocatore2);


    ris = vincita(vett, dim);

    printf("il vincitore e' il giocatore %d", ris);

return 0;
}

int vincita(Partita* vett, int dim)
{
    int i, cont1=0, cont2=0;

    for(i=0; i<dim; i++)
    {
        switch(vett[i].moneta)
        {
            case 't':
                if(vett[i].dadoGiocatore1 > vett[i].dadoGiocatore2)
                    cont1++;
                if(vett[i].dadoGiocatore1 < vett[i].dadoGiocatore2)
                    cont2++;
                break;
            case 'c':
                if(vett[i].dadoGiocatore1 < vett[i].dadoGiocatore2)
                    cont1++;
                if(vett[i].dadoGiocatore1 > vett[i].dadoGiocatore2)
                    cont2++;
                break;
            default:
                break;
        }
    }

    if(cont1>cont2)
        return 1;
    if(cont2>cont1)
        return 2;
    if(cont2==cont1)
        return 0;
}


void creavett(int dim, Partita* vett)
{
    FILE* torneofile;
    //char* nomefile;
    int i;
    char c;

    printf("inserisci il nome del file: ");
    //scanf("%s", &nomefile);

	torneofile = fopen ("D:\torneo.txt", "r");

	dim = 2;//dime(torneofile);

	//fclose(torneofile);
	//torneofile = fopen ("D:\torneo.txt", "r");

	Partita vettp[dim];

	for(i=0; i<(dim); i++)
    {
        vettp[i].moneta = fgetc(torneofile);
        c = fgetc(torneofile);
        vettp[i].dadoGiocatore1 = fgetc(torneofile);
        c = fgetc(torneofile);
        vettp[i].dadoGiocatore2 = fgetc(torneofile);
    }

    fclose(torneofile);

    printf("%c %d %d\n", vettp[0].moneta, vettp[0].dadoGiocatore1,vettp[0].dadoGiocatore2);
    printf("%c %d %d", vettp[1].moneta, vettp[1].dadoGiocatore1,vettp[1].dadoGiocatore2);


    vett = vettp;
}

int dime(FILE* torneofile)
{
    int cont;
    char a;
    for(cont=0; a!= EOF; cont++){
        a = fgetc(torneofile);
    }
    return cont/3;
}
