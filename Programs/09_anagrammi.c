#include <stdio.h>
#include <string.h>

int main()
{
 char str1[100];
 char str2[100];
 int i,m;

 printf("\ninserisci la prima parola: ");
 gets(str1);

 printf("\ninserisci la seconda parola: ");
 gets(str2);

 if(strlen(str1)==strlen(str2))
 {
     for(i=0; i<(strlen(str1));i++)
     {
         for(m=0; m<(strlen(str1));m++)
         {
             if(str1[i]==str2[m])
             {
                 str1[i]='0';
                 str2[m]='0';
             }
         }

     }

     if(strcmp(str1, str2)==0)
        printf("\nanagrammi\n");
     else
        printf(("\nnon anagrammi\n"));
 }

 return 0;
}
