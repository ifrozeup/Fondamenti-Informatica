#include <stdio.h>
#include <math.h>

int main()
{
    int temp[7];
    char isto[7][10];
    int max = 0;
    int i, m, diff;

    for(i=0; i<7; i++)
    {
        printf("inserisci la temperatura del giorno %d ", (i+1));
        scanf("%d", &temp[i]);
    }

    printf("\nGIORNO  TEMP    ISTOGRAMMA\n");

    for(i=0; i<7; i++)
    {
        diff = abs(temp[i] - 34);
        printf("%d \t %d \t ", i+1, temp[i]);
        for(m=0; m<10; m++)
        {
            if(m<diff)
                isto[i][m] = '*';
            else
                isto[i][m] = ' ';
            printf("%c", isto[i][m]);
        }
        printf("\n\n");
    }

    printf("\n\n");

    for(m=9; m>=0; m--)
    {
        for(i=0; i<7; i++)
        {
            printf("%c\t", isto[i][m]);
        }
        printf("\n");
    }

    for(i=0; i<7; i++)
        printf("%d\t", temp[i]);

    printf("\n");
    return 0;
}
