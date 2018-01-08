#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <wchar.h>

int main(){

    char** c[25][25];
    int i, k, m;
    system("COLOR 9E");
    hidecursor();

    for(i=0; i<25; i++)
    {
        for(k=0; k<25; k++)
        {
            c[i][k]=' ';
        }
    }

    for(m=0; m<25; m++)
    {
        c[24-m][m]='O';

        for(i=0; i<25; i++)
        {

            for(k=0; k<25; k++)
            {
                printf("%c ", c[i][k]);
            }
            printf("\n");
        }

        usleep(40000);
        system("CLS");

        c[24-m][m]=' ';
    }
    return 0;
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
