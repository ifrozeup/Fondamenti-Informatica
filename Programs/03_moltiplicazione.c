#include <stdio.h>

int main()
{

int a,b, i, ris;

ris = 0;

printf("devo moltiplicare ... ");
scanf("%d", &a);
printf("per ... ");
scanf("%d", &b);

for(i=0; i<b; i++)
{
    ris = ris + a;
}

printf("\nil risultato e': %d ", ris);

return 0;
}
