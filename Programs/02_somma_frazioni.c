#include <stdio.h>

int main()
{

int i, num1, num2, den1, den2, denris, numris;

do{

    printf("inserisci il numeratore della prima frazione positiva ");
    scanf("%d", &num1);

    printf("inserisci il denominatore della prima frazione positiva");
    scanf("%d", &den1);

    if(num1*den1 <= 0)
    {
        printf("la frazione non e' positiva, riprovare \n");
    }

}while(num1*den1 <= 0);

do{

    printf("inserisci il numeratore della seconda frazione positiva ");
    scanf("%d", &num2);

    printf("inserisci il denominatore della seconda frazione positiva ");
    scanf("%d", &den2);

    if(num2*den2 <= 0)
    {
        printf("la frazione non e' positiva, riprovare \n");
    }

}while(num2*den2 <= 0);

denris = den1*den2;

numris = num1*den2 + num2*den1;

printf("\n il risultato della somma tra le due frazioni e': %d / %d", numris, denris);

return 0;

}
