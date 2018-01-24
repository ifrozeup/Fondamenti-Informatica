#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COD 4
#define ESA 3

int main()
{
    char* appInv[ESA];
    char* appEst[ESA];
    int i;

    for(i=0; i<ESA; i++)
    {
        appInv[i] = malloc(COD*sizeof(char));
        printf("\n(Inverno)Inserisci codice esame: ");
        gets(appInv[i]);
    }

    for(i=0; i<ESA; i++)
    {
        appEst[i] = malloc(COD*sizeof(char));
        printf("\n(Estate)Inserisci codice esame: ");
        gets(appEst[i]);
    }

    return dopp(appInv, appEst);;
}

int dopp(char** appInv, char** appEst)
{
    int i, ris = 0;

    for(i=0; i<ESA; i++)
    {
        if(firstOcc(appInv, i) && isIn(appInv[i], appEst))
                ris++;
    }
    return ris;
}

int isIn(char* string, char** v)
{
    int i;

    for(i=0; i<ESA; i++)
    {
        if(!strcmp(string, v[i]))
            return 1;
    }
    return 0;
}

int firstOcc(char** v, int i)
{
    int k;
    for(k=0; k<ESA; k++)
    {
        if((!strcmp(v[k], v[i]))&&(k<i))
            return 0;
    }
    return 1;
}
