#include <stdio.h>
#define MAX 10

int main(){
int j;
int* v = malloc(MAX*sizeof(int));

        for(j=0; j<MAX; j++) //genero casualmente
        {
            v[j] = rand()%1000;
            printf("%d - ", v[j]);
        }

        subSeq(v);

return 0;
}

void subSeq(int* v)
{
    int i, j, len;

    for(i=0; i<(MAX-1);)
    {
        len = 1;
        if(i<(MAX-1) && v[i]<v[i+1])
        {
            len += findLen(v, i, MAX)-i;
            printf("\nlen: %d\n", len);

            for(j=i; j<(i+len); j++)
            {
                printf("%d, ",v[j]);
            }
        }
        i+=len;
    }
}

int findLen(int* v, int i, int max)
{
    if(i<max && v[i+1]>v[i])
    {
        i++;
        return findLen(v, i, max);
    }
    return i;
}
