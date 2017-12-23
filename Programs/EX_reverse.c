#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int ins, rev=0, i, pot=10, tronc;

    printf("Inserisci il numero da ribaltare: ");
    scanf("%d", &ins);

    /*
    for(i=0; ins-rev>10; i++)
    {
        pot = pot*10;
        rev = rev*10;
        tronc = (ins%pot)/(pot/10);
        rev = rev + tronc;
    }
    */

    rev = reverse(ins, pot, rev);
    printf("\nIl numero ribaltato e': %d", rev);

return 0;
}

int reverse(int ins, int pot, int rev){

    rev = rev + (ins%pot)/(pot/10);
    if(ins - rev<10)
        return rev;
    else
        rev = reverse(ins, pot*10, rev*10);
}



/*
int reverse(int num){

int rev, pot;

if(num-rev>10)

else
    return rev;
}
*/
