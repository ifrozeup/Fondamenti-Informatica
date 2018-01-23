#include <stdio.h>

int main(){

    int massimo = max(123851214);

    printf("\n%d", massimo);

    return 0;
}

int max(int n)
{

    int mass;
    mass = n%10;

        while(n>10)
        {
            n = n/10;
            printf("\n%d", n);
            if(mass<n%10)
               return max(n);
        }
    return mass;
}
