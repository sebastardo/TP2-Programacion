#include "prototipos.h"

int main()
{
    char opcion;
    char opciones[] = {"ABCDEFGHIJKLMNOPQRSTUX"};

    ///esto es de vago
    char tope[] = {201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187,'\0'};
    char piso[] = {200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188,'\0'};

    printf("%s\n", tope);
    printf("%c%s%c\n", 186,"\tTRABAJO PARACTICO 2\t",186);
    printf("%s\n", piso);
    ///

    do
    {
        opcion = menu_ejercicios("Elija un ejercicio para ejecutar (1 a 21 y 0 para finalizar): ", opciones);

        ejercicio(opcion);

    }while(opcion!='X');

    return 0;
}

