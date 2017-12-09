#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pref(int m, char* esp);

int main(){

    int dim, i, ris;
    void* esp;
    char temp, k;

    printf("Inserisci la lunghezza dell'espressione: ");
    scanf("%d", &dim);

    esp = (char*)malloc(dim*(sizeof(char)));

    printf("Inserisci l'espressione:\n");

    for(i=0; i<dim; i++)
    {
        scanf("%c", &k);
        scanf("%c", &temp);
        ((char*)esp)[i]= temp;
    }

    ris = pref(dim-2, ((char*)esp));

    printf("\nIl risultato dell'espressione e': %d\n\n", ris);
    return 0;
}

int pref(int m, char* esp)
{
    if(m==1)
        return ((int)(esp[m])-48 +(int)(esp[m+1])-48);
    else
    {
        if(esp[m-1] == '+')
            esp[m-1] = 48+((int)(esp[m])-48 +(int)(esp[m+1])-48);
        else
            esp[m-1] = 48+(((int)(esp[m])-48)*((int)(esp[m+1])-48));

        return pref(m-2, esp);
    }
}
