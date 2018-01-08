#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct T{
    char* word;
    struct T* next;
}Word;

void loadWords(Word** ptrls, FILE* text);
void printErr(char* str, FILE* errs);
void createEl(Word** ptrls, char* str);
void addLista(Word** ptrls, Word* nodo);
void subAddLista(Word* ls, Word* nodo);
void scanList(Word* lista, FILE* errs);
int checkWord(char* str);

int main(){

    Word* ls = NULL;
	Word** ptrls = &ls;

    FILE * text;
	text = fopen ("D:\ltext.txt", "r");
    loadWords(ptrls, text);
    fclose(text);



    FILE * errs;
	errs = fopen ("D:\lerrors.txt", "w");
    scanList(ls, errs);
    fclose(errs);

    return 0;
}

void loadWords(Word** ptrls, FILE* text)
{
    int len;
    char* str;
    char c;

    do{
        str = malloc(100*sizeof(char));
        c = fgetc (text);
        len = 0;

        do{
            len++;
            str[len-1] = c;
            c = fgetc (text);
        }while(c != ' ' && c != EOF);
        str[len] = '\0';

        createEl(ptrls, str);

    }while(c!= EOF);
}

void createEl(Word** ptrls, char* str) //gestisce la creazione del nodo
{
    Word* nodo;
    nodo = malloc(sizeof(Word));
    nodo->word = malloc(sizeof(char*));

    nodo->next = NULL;
    nodo->word = str;

    addLista(ptrls, nodo);
}

void addLista(Word** ptrls, Word* nodo)
{
    if(*ptrls == NULL) //caso 1: si sta inserendo il primo elemento della lista
        *ptrls = nodo;
    else
        subAddLista(*ptrls, nodo); //caso 2: si sta aggiungendo un nuovo nodo alla lista
}

void subAddLista(Word* ls, Word* nodo) //aggiunge in coda alla lista
{
    if(ls->next != NULL)
        subAddLista(ls->next, nodo);
    else
        ls->next = nodo;
}

void scanList(Word* lista, FILE* errs)
{
    if(lista != NULL)
    {
        if(checkWord(lista->word))
            printErr(lista->word, errs);
        scanList(lista->next, errs);
    }
}

/*
- Gli	unici	caratteri	che	possono	essere	usati	per	comporre	le	parole	di	L	sono	{a, b, c}.	Quindi,	la
sequenza	dbbcac non	è	una	parola	del	linguaggio	perché	contiene	il	carattere	d;
- La	lettera	b deve	sempre	comparire	in	(sotto-)sequenze	formate	da	un	numero	pari	di	b in	successione.
Per	esempio, le	sequenze bbcac e	abbbb sono	parole	valide	del	linguaggio.	Le	sequenze cabc e	baba
non	lo	sono.
- La	lettera	c deve	comparire al	massimo	due	volte	in	ogni	parola,	non	importa	in	quale	posizione
*/

int checkWord(char* str)
{
    int i, cc = 0, bb=0;

    for(i=0; i<strlen(str) && (str[i] == 'a' || str[i] == 'b' || str[i] == 'c') && cc<2 && bb == 0; i++)
    {
        if(str[i] == 'c')
            cc++;

        if(str[i] == 'b' && str[i+1] == 'b')
            i+=2;
        else if(str[i] == 'b' && str[i+1] != 'b')
            bb = 1;
    }

    if(i!=strlen(str))
        return 1;
    else
        return 0;
}

void printErr(char* str, FILE* errs)
{
    printf("\nErrore in %s", str);
    fprintf(errs, str);
    fprintf(errs, "\n");
}
