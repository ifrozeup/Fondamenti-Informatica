#include <stdlib.h>
#include <math.h>

#define N 10 //dimensione matrice in cui cercare
#define M 3 //dimensione matrice da trovare

int random_int(int min, int max);

int main(){

    int** mat1;
    int** mat2;
    int i, k;

    mat1 = malloc(N*sizeof(int*));
    for(i=0; i<N; i++)
    {
        mat1[i] = malloc(N*sizeof(int));

        for(k=0; k<N; k++)
        {
            mat1[i][k]=random_int(0,1); //genero casualmente matrice maggiore fatta solo da 0 e 1
            printf("%d ", mat1[i][k]);
        }
        printf("\n");
    }

    printf("\n");

    mat2 = malloc(M*sizeof(int*));
    for(i=0; i<M; i++)
    {
        mat2[i] = malloc(M*sizeof(int));

        for(k=0; k<M; k++)
        {
            mat2[i][k]= 1; //cerco una matrice MxM composta solo da 1
            printf("%d ", mat2[i][k]);
        }
        printf("\n");
    }

    isMinor(mat1, mat2); //controlla se mat2 è contenuta in mat1

    return 0;
}

int random_int(int min, int max) //genera un numero casuale tra un minimo e un massimo inclusi
{
   return min + rand() % (max+1 - min);
}

void isMinor(int** mat1, int** mat2)
{
    int i, k, j, ris=0;

    for(i=0; i<N; i++)
    {
        for(k=0; k<N; k++)
        {
            if(mat1[i][k] == mat2[0][0] && (k<(N-M)) && (i<(N-M))) //controlla anche di non essere su un bordo
            {
                ris=1; 
                for(j=0; j<M && ris; j++)
                    ris = isIn(mat1[i+j], k, M, mat2[0+j]);

                if(ris)
                    printf("\n\nSUCCESSO! coordinate: %d %d\n", i, k);
            }

        }
    }
}

int isIn(int* v1, int k, int n, int* v2) //controlla che il sottoinsieme di n elementi a partire da v1[k] sia uguale a v2
{
    int i, ris=1;
    for(i=k; i<(k+n) && ris; i++)
    {
        if(v1[i] != v2[i-k])
            ris = 0;
    }
    return ris;

}
