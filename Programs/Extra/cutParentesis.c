#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void addStr(char* str1, int a, int b, char* str2);
void par(char* str);
void cutStr(char* str, int a, int b);


int main()
{
    char* str = "ab(acg)bea(xx)fii(o)aa(aaaaa)a";

    par(str);

    return 0;
}

void par(char* str)
{
    printf("Stringa iniziale: %s\n\n", str);
    int i, a, b;

    for(i=0; i<strlen(str);i++)
    {
        a = strchr(&(str[i]), '(') - str; //trova man mano le posizioni delle parentesi aperte

        if(a<strlen(str))
        {
            b = (strchr(&(str[i]), ')') - str); //trova man mano le posizioni delle parentesi chiuse
            cutStr(str, a, b);
        }
    }

    printf("Nuova stringa: %s\n\n", str);

}

void cutStr(char* str, int a, int b) //taglia gli elementi nell'intervallo a-b di str, sostituendoli con *
{

}

void addStr(char* str1, int a, int b, char* str2) //copia in coda a str2 gli elementi nell'intervallo a-b di str1
{
    for(; a<b; a++)
    {
        str2[strlen(str2)] = str1[a];
    }
}
