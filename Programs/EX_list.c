#include <stdio.h>

typedef struct E{
    int dato;
    struct E* next;
} El;

void sommalista(El* list){

   if(list->next != NULL)
   {
       (list->next)->dato = list->dato + (list->next)->dato;
       sommalista(list->next);
   }
}
