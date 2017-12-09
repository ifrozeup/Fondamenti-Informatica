#include <stdio.h>
#include <stdlib.h>

void READFile(int** mat, FILE* file, int ri, int co);
void dopp(int** mat, int ri, int co, int m);

int main(){

    int ri, co, i, k;
    void** mat;

    FILE * matfile;
	matfile = fopen ("D:\matfile.txt", "r");

	if (matfile == NULL)
		return 0;

    printf("Inserisci il numero di righe: ");
    scanf("%d", &ri);

    mat = (int**)malloc(ri*(sizeof(int*)));

    printf("Inserisci il numero di colonne: ");
    scanf("%d", &co);

    for(i=0; i<ri; i++)
    {
        mat[i]= (int*)malloc(co*(sizeof(int)));
    }

    READFile(((int**)mat), matfile, ri, co);

    dopp(mat, ri, co, 0);

return 0;
}

void dopp(int** mat, int ri, int co, int m){

    int i, cont=0;

    for(i=0; i<co; i++)
    {
        if(mat[m][i]==mat[m+1][i])
            cont++;
    }

    if(cont==co)
        printf("le righe %d e %d sono uguali\n", m, m+1);

    if(m+1 != ri-1)
        dopp(mat, ri, co, m+1);
}

void READFile(int** mat, FILE* file, int ri, int co){

    int i,k;
    char* c;

    for(i=0; i<ri; i++){
        k=0;

        do{

            mat[i][k]= fgetc(file) - '0';
            //printf("%d ", sud_pers[i][k]);
            c = fgetc (file);
            k++;

        }while(c != EOF && k<co);
    }
}

