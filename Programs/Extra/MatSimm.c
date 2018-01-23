#include <stdlib.h>
#include <math.h>
#define N 4

int simm(int** mat, int n);

int main(){
    int i, j;

    int** matrix = malloc(N*sizeof(int*));
    for(i=0; i<N; i++)
    {
        matrix[i]=malloc(N*sizeof(int));

        for(j=0; j<N; j++) //genero casualmente
        {
            if(i!=j)
                matrix[i][j] = rand()%1000;
        }
    }

    for(i=0; i<N; i++) //rendo simmetrica
    {
        for(j=0; j<N; j++)
        {
            if(i!=j)
                matrix[i][j] = matrix[j][i];
        }
    }
    
    int ris = simm(matrix, N);

    return ris;
}

int simm(int** mat, int n){

    int i,j, ok = 1;

    for(i=0; i<n; i++)
    {
        if(mat[n-1][i] != mat[i][n-1])
            ok = 0;
    }

    if(ok && n>1)
    {
        n--;
        return simm(mat, n);
    }
    else if(ok)
        return 1; //simmetrica
    else
        return 0; //non simmetrica
}
