#include "util.h"
#include <math.h>
#include <stdio.h>

int mcd(int a, int b)
{
    int c = 0;

    a = abs(a);
    b = abs(b);

    if(b>a)
    {
        c = b;
        b = a;
        a = c;
    }

    if( b==0)
        return a;
    else
    {
        return mcd(b, a%b);
    }
}

int potenza(int base, int exp)
{
    if(exp > 0)
        return base*potenza(base, exp-1);
    else
        return 1;
}

