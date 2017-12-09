#include <stdio.h>
#include <string.h>

#define N 9
#define K 2

//definizione tipo MOSSA
typedef struct {
        int mossaRiga;
        int mossaColonna;
} Mossa;

int main(){

    FILE * matfile;
    Mossa path[K];
    int i, k;

	matfile = fopen ("D:\sudoku.txt", "r");

	if (matfile == NULL)
		return 0;

    int mat[N][N];

    READFile(mat, matfile);
    fclose(matfile);

    /*
    for(i=0; i<N; i++){
        for(k=0; k<N; k++){
            printf("%d ", mat[k][i]);
        }
        printf("\n");
    }
    */

    InsMosse(path);
    CalcPos(path, mat);

return 0;
}

void CalcPos(Mossa path[K], int mat[N][N]){
    int i;
    Mossa PosFinale;

    PosFinale.mossaColonna=0;
    PosFinale.mossaRiga=0;

    for(i=0; i<K; i++){
        PosFinale.mossaColonna += path[i].mossaColonna;
        PosFinale.mossaRiga += path[i].mossaRiga;
    }

    if((PosFinale.mossaColonna >N) || (PosFinale.mossaRiga >N))
        printf("Hai inserito spostamenti non validi");
    else
        printf("%d", mat[PosFinale.mossaRiga][PosFinale.mossaColonna]);
}

void InsMosse(Mossa path[K]){
    int i;

    for(i=0; i<K; i++)
    {
        printf("\nMossa N%d :\n", (i+1));
        printf("Spostamento sulla riga: ");
        scanf("%d", &path[i].mossaRiga);
        printf("Spostamento sulla colonna: ");
        scanf("%d", &path[i].mossaColonna);
    }
}

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
