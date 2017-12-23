#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct N{
    int pts;
    struct N* next;
}Num;

int isPrime(int num);
int isPTS(int num);

int main(){

    FILE* filepts;
    Num* list = NULL;

    //readFile(filepts, list);

    //printList(list);

    return 0;
}

void printList(Num* list){

    printf("Numero pts: %d\n", list->pts);
    if(list->next!= NULL)
        printList(list->next);
}

void readFile(FILE* filepts, Num* list){ //da completare

    int num;

    if(isPrime(num))
        if(isPTS(num));
            addToList(num, list);
}

int isPTS(int num){

    int c = 10;

    while(num%c <= num)
    {
        printf("\n%d\n", num%c);
        if(!isPrime(num%c))
            return 0;
        c *= 10;
    }
    return 1;
}

int isPrime(int num){

    int divi = 2;

    for(divi= 2; divi < (num/2); divi++)
    {
        if(num%divi == 0)
            return 0;
    }

    return 1;
}

void addToList(int num, Num* list){

}
