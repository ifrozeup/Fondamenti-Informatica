#include <stdio.h>
#include <string.h>

#define N 9

//int sudoku_corretto[N][N] = {{5,8,6,4,2,1,3,7,9},{3,2,7,9,6,5,4,8,1},{9,1,4,3,7,8,6,2,5},{1,6,3,5,8,4,7,9,2},{2,4,5,1,9,7,8,6,3},{8,7,9,6,3,2,5,1,4},{7,5,8,2,1,3,9,4,6},{6,3,1,7,4,9,2,5,8},{4,9,2,8,5,6,1,3,7}};

//int sudoku_sbagliato[N][N] = {{5,8,6,4,2,1,3,7,9},{3,2,7,9,1,5,4,8,1},{9,1,4,3,7,8,6,2,5},{1,6,3,5,8,4,7,9,2},{2,4,5,1,9,7,8,6,3},{8,7,4,6,3,2,5,1,4},{7,5,8,2,1,3,9,4,6},{6,8,1,7,4,9,2,5,8},{4,9,2,8,5,2,1,3,7}};

int ctr[N] = {1,2,3,4,5,6,7,8,9}; //vettore di controllo

int main() {

	FILE * sudfile;
	sudfile = fopen ("D:\sudoku1.txt", "r");

	if (sudfile == NULL)
		return 0;

    int contok =0;
    int lincol = 0;
    int sud_pers[N][N];

    //LOADSud(sud_pers);
    READFile(sud_pers, sudfile);
    fclose(sudfile);

    contok = CTRLine(contok, lincol, sud_pers);
    lincol++;
    contok = CTRLine(contok, lincol, sud_pers);
    lincol++;
    contok = CTRQuad (contok, sud_pers);

    if(contok == 243){
        printf("\nIl sudoku inserito e' giusto!");
    } else {
        printf("\nIl sudoku inserito e' sbagliato!");
    }

	return 0;
}

//legge il file contenente il sudoku
void READFile(int sud_pers[N][N], FILE* sudfile){

    int i,k;
    char* c;

    for(i=0; i<N; i++){
        k=0;

        do{
            sud_pers[i][k]= fgetc(sudfile) - '0';

            //printf("%d ", sud_pers[i][k]);
            c = fgetc (sudfile);

            k++;
        }while(c != EOF && k<N);
    }
}

//gestisce l'inserimento complessivo del sudoku da terminale
void LOADSud(int sud_pers[N][N]){

    int i, k;
    printf("\nINSERIMENTO SUDOKU\n");
    printf("(premere invio dopo ogni inserimento)\n");

    for(i=0; i<N; i++)
    {
        printf("\nInserisci la riga numero %d: \n", (i+1));

        INSLine(sud_pers[i]);
    }

}

//inserimento di una riga da terminale
void INSLine (int array[N]){

    int i =0;

    while(i<N){
        scanf("%d",&array[i]);
        i++;
    }

}

//controlla tutte le linee/tutte le colonne
int CTRLine (int contok, int lincol, int extsud[N][N]){

    int i, k, m;

    for(i=0; i<N; i++){

        int ctr[N] = {1,2,3,4,5,6,7,8,9};

        for(k=0; k<N; k++){

            for(m=0; m<N; m++){

                if (lincol == 0){
                    CTRArray(extsud[i], ctr, k, m);
                } else {
                    CTRArray(extsud[k], ctr, i, m);
                }
            }
        }
        contok = CTRCTR(contok, ctr);
    }

return contok;
}

//controlla i numeri di un singolo array rispetto a CTR
void CTRArray (int* array, int* ctr, int e, int r){

    if(array[e] == ctr[r]){
        ctr[r]=0;
    }
}

//incrementa il contatore di controllo
int CTRCTR (int contok, int* ctr){

    int w;

    for(w=0; w<N; w++){

        if(ctr[w]==0)
            contok++;
    }
return contok;
}

//controlla i quadrati interni
int CTRQuad (int contok, int extsud[N][N]){

    int q[N];
    int x, i, h, j, k, a, b;

    for(x=0; x<3; x++){

        for(i=0; i<3; i++){

            int ctr[N] = {1,2,3,4,5,6,7,8,9};
            h = 0;

            for(j=(3*x); j<(3*(x+1)); j++){

                for(k=(3*i); k<(3*(i+1)); k++){

                    q[h]=extsud[j][k];
                    h++;
                }
            }

            for(a=0; a<N; a++){

                for(b=0; b<N; b++){
                    CTRArray(q, ctr, a, b);
                }
            }
            contok = CTRCTR(contok, ctr);
        }
    }

    return contok;
}
