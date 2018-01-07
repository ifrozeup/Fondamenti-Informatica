#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void loadMatrix(int*** ptrMat, FILE* inFile, int* rig, int* col);
void printMatrix(int** mat, FILE* outFile, int rig, int col);

int main(){

    int** mat;
	int*** ptrMat = &mat;
	int rig, col;

    FILE * inFile;
	inFile = fopen ("D:\matrix.txt", "r");
    loadMatrix(ptrMat, inFile, &rig, &col);
    fclose(inFile);

    FILE * outFile;
	outFile = fopen ("D:\matrixOut.txt", "w");
    printMatrix(mat, outFile, rig, col);
    fclose(outFile);

    return 0;
}

void loadMatrix(int*** ptrMat, FILE* inFile, int* rig, int* col)
{
    int domi, i, k;
    char c;

    domi = fgetc (inFile) -'0';
    *rig = fgetc (inFile)-'0';
    *col = fgetc (inFile)-'0';

    *ptrMat = malloc((*rig)*sizeof(int*));

    for(i=0; i<(*rig); i++)
    {
        (*ptrMat)[i] = malloc((*col)*sizeof(int));

        for(k=0; k<(*rig); k++)
        {
            (*ptrMat)[i][k] = domi;
        }
    }

    c = fgetc (inFile);
    do{
            (*ptrMat)[fgetc (inFile)-'0'][fgetc (inFile)-'0'] = fgetc (inFile)-'0';

            c = fgetc (inFile);
    }while(c != EOF);
}

void printMatrix(int** mat, FILE* outFile, int rig, int col)
{
    int i, k;

    for(i=0; i<rig; i++)
    {
        for(k=0; k<col; k++)
        {
            fprintf(outFile, "%c ", mat[i][k]+'0');
        }
        fprintf(outFile, "\n");
    }

}
