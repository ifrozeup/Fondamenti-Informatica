#include <stdio.h>

int main()
{

int dec, bin, ott;

printf("inserire il numero decimale intero da convertire: ");
scanf("%d", &dec);

bin = toBinary(dec);

printf("\nil numero convertito in binario e': %d", bin);

ott = toOctal(dec);

printf("\nil numero convertito in binario e': %d", ott);

return 0;
}

int toBinary(int dec)
{
    int bin = 0;
    int mod = 0;
    int i = 1;

    while(dec>0){
        mod = dec%2;
        dec = dec/2;

        bin = bin + i*mod;
        i = i*10;
    }

    return bin;
}

int toOctal(int dec)
{
    int ott = 0;
    int mod = 0;
    int i = 1;

    while(dec>0){
        mod = dec%8;
        dec = dec/8;

        ott = ott + i*mod;
        i = i*10;

    }

    return ott;
}
