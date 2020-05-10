#include "protoejercicios.h"
#define TAM 14

void ejecutarEj02()
{
    int elementos[TAM] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    size_t pos;
    int busqueda;
    printf("Numero a buscar: ");
    fflush(stdin);
    scanf("%d",&busqueda);
    pos = posicion(&elementos, TAM, busqueda);
    if(pos==0)
        printf("Posicion de %d: NULL\n", busqueda);
    else
        printf("Posicion de %d: %x\n", busqueda, pos);
}



size_t posicion(int *elementos, int cantidad_elementos, int busqueda)
{
    int *fin = elementos + cantidad_elementos;
    while(elementos<fin)
    {
        if(*elementos == busqueda)
            return elementos;
        elementos++;
    }
    return NULL;
}
