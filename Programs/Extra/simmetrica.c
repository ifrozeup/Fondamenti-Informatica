#include <stdlib.h>
#include <math.h>

int n = 4;

int main(){
    int i, j;

    int** matrix = malloc(n*sizeof(int*));
    for(i=0; i<n; i++)
    {
        matrix[i]=malloc(n*sizeof(int));

        for(j=0; j<n; j++) //genero casualmente
        {
            if(i!=j)
            {
                matrix[i][j] = rand()%1000;
            }else{
                matrix[i][j] = 0;
            }
        }
    }

    for(i=0; i<n; i++) //rendo simmetrica
    {
        for(j=0; j<n; j++)
        {
            if(i!=j)
                matrix[i][j] = matrix[j][i];
        }
    }

    int ris = simm(matrix);

    return ris;
}

int simm(int** mat){

    int i,j, ok = 1;

    for(i=0; i<n; i++)
    {
        if(mat[n-1][i] != mat[i][n-1])
            ok = 0;
    }

    if(ok && n>1)
    {
        n--;
        return simm(mat);
    }
    else if(ok)
        return 1;
    else
        return 0;
}
