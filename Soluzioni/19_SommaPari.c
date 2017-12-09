/*
Funzione che calcola la somma di tutti i numeri pari minori di un certo valore N
*/

#include <stdio.h>
#include <stdlib.h>


int sommaPari(int);

int main(){

    int n;
    int result;

    printf("Inserisci il valore di N: ");
    scanf("%d", &n);

    while(n < 0){
        printf("Il valore inserito e' negativo, inserire un valore positivo: ");
        scanf("%d", &n);
    }

    result = sommaPari(n);

    printf("La somma dei numeri pari minori di %d e' %d\n", n, result);

    return 0;
}

int sommaPari(int val){

    printf("%d\n", val);
    if(val == 0)
        return val;
    else
        if(val%2){
            return sommaPari(val-1);
        }
        else
            return val + sommaPari(val-2);
}
