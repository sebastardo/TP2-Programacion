#include "prototipos.h"

int main()
{
    char opcion;
    char opciones[] = {"ABCDEFGHIJKLMNOPQRSTUX"};

    do
    {
        opcion = menu_ejercicios("Elija un ejercicio para ejecutar (1 a 21 y 0 para finalizar): ", opciones);

        ejercicio(opcion);

    }while(opcion!='X');

    return 0;
}

