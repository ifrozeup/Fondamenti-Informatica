
/*
Funzione che calcola il massimo comune divisore di due numeri reali utilizzando l'algoritmo di Euclide:
- a = |a|, b=|b|
- ordina a e b in modo che a >= b
- Se b=0 allora MCD(a,b)=a;
- altrimenti MCD(a,b)=MCD(b,a mod b)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mcd(int, int);

int main(){

    int a, b;
    int result;

    printf("Inserisci i due numeri di cui si vuole calcolare il massimo comune divisore: ");
    scanf("%d%d", &a,&b);

    result = mcd(a,b);

    printf("Il massimo comune divisore di %d e %d e' %d\n", a, b, result);

    return 0;
}

void ordina(int* a, int* b){

    if(b > a){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    return;
}

int mcd(int n1, int n2){

    n1 = abs(n1);
    n2 = abs(n2);

    ordina(&n1, &n2);

    if(n2 == 0)
        return n1;
    else
        return mcd(n2, n1%n2);
}
