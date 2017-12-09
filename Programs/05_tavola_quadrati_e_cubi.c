#include <stdio.h>

int main()
{
    int num =1;
    int i=0;
    float quad, cu;

    printf("Numero \t Quadrato \t Cubo\n");

    for(i=0; i<10; i++)
    {
        quad = num*num;
        cu = quad*num;
        printf("%d \t %.2f \t\t %.1f\n", num, quad, cu);
        num= num+1;
    }

    return 0;
}
