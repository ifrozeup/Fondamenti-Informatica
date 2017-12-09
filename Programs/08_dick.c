#include <stdio.h>

int main()
{
    char str[10];
    int i=0;
    int ctr;
    int ab;
    int dick;



    printf("inserisci una stringa ");
    gets(str);

    ctr=0;
    dick=1;

    for(i=0; i<10;i++)
    {
        if(str[i]=='[')
        {
            ctr++;
        }else if (str[i]==']')
        {
            ctr--;
        }

        if(ctr < 0)
        {
            dick = 0;
        }
    }

    if(dick==1 && ctr == 0)
        printf("\ne' dyck\n");
    return 0;
}
