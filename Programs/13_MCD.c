#include <stdio.h>
#include <math.h>

int main(){

    int num;
    num = mcd(10, 15);
    printf("il numero cercato e' %d \n", num);

return 0;
}

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
