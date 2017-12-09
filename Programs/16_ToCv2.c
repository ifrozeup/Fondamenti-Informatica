#include <stdio.h>
#include <stdlib.h>

typedef struct {
char mon;
int d1;
int d2;
} Game;

int main(){
    int dim=0, winner;

    FILE* tf;
    tf = fopen("D:\win.txt", "r");

    dim = dime(tf);

    fclose(tf);
    tf = fopen("D:\win.txt", "r");

    Game torneo[dim];
    carica(torneo, tf, dim);
    winner = vincitore(torneo, dim);

    if(winner != 0)
        printf("Il vincitore della partita e' il giocatore %d", winner);
    else
        printf("La partita termina con un pareggio.");

    pubblica(torneo, dim);

return 0;
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

void carica(Game* torneo, FILE* tf, int dim)
{
    int i;

    if(tf==NULL)
        printf("ERRORE\n");
    else
    {
        for(i=0; i<dim; i++)
        {
            Game partita;
            fscanf(tf, "%1c%1d%1d", &partita.mon, &partita.d1, &partita.d2);
            torneo[i] = partita;
        }
    }
}


int vincitore(Game* torneo, int dim)
{
    int i, cont1=0, cont2=0;

    for(i=0; i<dim; i++)
    {
        switch(torneo[i].mon)
        {
            case 't':
                if(torneo[i].d1 > torneo[i].d2)
                    cont1++;
                if(torneo[i].d1 < torneo[i].d2)
                    cont2++;
                break;
            case 'c':
                if(torneo[i].d1 < torneo[i].d2)
                    cont1++;
                if(torneo[i].d1 > torneo[i].d2)
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

void pubblica(Game* torneo, int dim)
{

}
