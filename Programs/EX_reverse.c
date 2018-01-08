#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int ins, rev=0, i, pot=10, tronc;

    printf("Inserisci il numero da ribaltare: ");
    scanf("%d", &ins);
    
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
