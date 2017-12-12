#include <stdlib.h>
#include <string.h>

typedef char* string;

//PERA-PANE-EGO-ROSA-ALA restituisce 1 perché le iniziali delle ultime parole sono quelle della prima parola, nella sequenza corretta

int main(){

    //check = Iniziali(str, 0);
    return 0;
}

int Iniziali(string str, int i){

    int c = 0, contParola = -1;

    for(c=0; c<strlen(str); c++)
    {
        if(c== '-')
            contParola++; //controlla di essere nel carattere precedente a una parola

        if(contParola == i) //controlla di essere appena prima della parola giusta
            if(str[c+1+i] != str[i]) //confronta l'iniziale della parola con il carattere corrispondente nella chiave
                return 0;
    }

    if(str[i] != '-') //controllo di non essere alla fine della chiave
        return Iniziali(str, i++);
    else
        return 1;
}

