#include <stdlib.h>
#define M 100 //maggiorante

typedef struct N{

    int x;
    struct N* next;

}Interi;

void createSL(Interi* lista, int dim);
void findSL(Interi* lista);
int findDimSL(Interi* lista, int* dim);

int main(){

    //chiamata dal main: findSL(lista);

    return 0;
}

void findSL(Interi* lista){ //scorre la lista e controlla la suddivisione in sottoliste
        int dim = 1, i;

        if(lista->x < M)
            createSL(lista, dim);
        //output sottolista

        if(lista->next != NULL)
        {
            if(lista->x + lista->next->x < M)
            {
                dim = findDimSL(lista, &dim);

                for(i=0; i<dim; i++) //crea tutte le sottoliste minori
                {
                    createSL(lista, i);
                    //output sottolista
                }
            }

            findSL(lista->next);
        }
}

int findDimSL(Interi* lista, int* dim) //trova ricorsivamente la dimensione MASSIMA della sottolista, che è composta da elementi consecutivi
{
    if(lista->x + lista->next->x > M)
        return *dim;
    else
    {
        dim++;
        findDimSL(lista->next, dim);
    }
}

void createSL(Interi* lista, int dim){ //ricevuti per parametro le teste di lista e la dimensione, crea la sottolista;
    int i;
    Interi* sottolista;

    for(i=0; i<dim; i++)
    {
        sottolista = malloc(sizeof(Interi));

        sottolista = lista;
        sottolista->next = NULL;

        lista = lista->next;
        sottolista = sottolista->next;
    }
}
