#include <stdio.h>
#define MAX_DIGITS 512

int main() {
  printf("Convertitore v2.0\n\n");
  printf("Inserire un valore (base 10):");

  int base10;
  char base2[MAX_DIGITS];
  char base8[MAX_DIGITS];
  char base16[MAX_DIGITS];

  scanf("%d", &base10);
  printf("Il numero inserito è: %d in base 10\n", base10);

  // Conversione in base 2
  int dividendo = base10;
  int i = 0;
  for (i = 0; dividendo != 0; i++) {
    base2[i] = dividendo % 2 + '0'; 
    dividendo /= 2;
  }
  printf("                      ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%c", base2[j]);
  }
  printf(" in base 2\n");

  // Conversione in base 8
  dividendo = base10;
  i = 0;
  for (i = 0; dividendo != 0; i++) {
    base8[i] = dividendo % 8 + '0'; 
    dividendo /= 8;
  }
  printf("                      ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%c", base8[j]);
  }
  printf(" in base 8\n");

  // Conversione in base 16
  dividendo = base10;
  i = 0;
  for (i = 0; dividendo != 0; i++) {
    int resto = dividendo % 16; 
    if (resto < 10)
      base16[i] = resto + '0';
    else {
      resto -= 10;
      base16[i] = resto + 'a';
    }
    dividendo /= 16;
  }
  printf("                      ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%c", base16[j]);
  }
  printf(" in base 16\n");
}
