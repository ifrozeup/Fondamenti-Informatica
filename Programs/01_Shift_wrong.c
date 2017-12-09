#include <stdio.h>

/*
 Correggere il seguente programma affinche':
 - legga il valore delle tre variabili intere: "a", "b" e "c"
 - faccia lo shift circolare del contenuto delle tre variabili, cioË:
 - metta il contenuto di a in b
 - metta il contenuto di b in c
 - metta il contenuto di c in a
 - stampi il valore delle tre variabili
 */

int main()
{
	int a, b, c;
	int memb, memc;
	a=0;
	b=0;
	c=0;

	printf("Inserire il valore di a: ");
	scanf("%d", &a);

	printf("\nInserire il valore di b: ");
	scanf("%d", &b);

	printf("\nInserire il valore di c: ");
	scanf("%d", &c);

	/* Adesso faccio lo shift */
	memc= c;
    memb= b;

    b = a;
    c = memb;
    a = memc;

	 printf("\nIl valore di a e': %d", a);
	 printf("\nIl valore di b e': %d", b);
	 printf("\nIl valore di c e': %d\n", c);

	 return 0;
}
