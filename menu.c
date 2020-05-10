#include "prototipos.h"

int menu_ejercicios(const char *mensaje, const char *opciones)
{
    char opcion;
    int primeraVez=1;
    int aux;
    do
    {
        if(primeraVez)
        {
            printf("%s", mensaje);
            primeraVez = 0;
        }
        else
        {
            printf("Error - opcion inexistente.\n"
                   "Elija nuevamente: ");
        }
        fflush(stdin);

        scanf("%d", &aux);
        opcion = aux?(char)aux+64:'X';

    }while(!strchr(opciones, opcion));

    return opcion;
}


void ejercicio(char opcion)
{
    switch(opcion)
    {
        case 'A':
            ejecutarEj01();
            break;
        case 'X':
            printf("\n\t\t-----Chau!-----\n");
            break;
        default:
            printf("no se\n");
    }
}
