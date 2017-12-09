#include <stdio.h>

int main(){

int pot;

pot = potenza(2,3);
printf("il numero cercato e' %d \n", pot);

return 0;
}

int potenza(int base, int exp)
{
    if(exp > 0)
        return base*potenza(base, exp-1);
    else
        return 1;
}
