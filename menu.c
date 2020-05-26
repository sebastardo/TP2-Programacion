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
            titulo("Ejercicio 1");
            ejecutarEj01();
            break;
        case 'B':
            titulo("Ejercicio 2");
            ejecutarEj02();
            break;
        case 'C':
            titulo("Ejercicio 3");
            ejecutarEj03();
            break;
        case 'D':
            titulo("Ejercicio 4");
            ejecutarEj04();
            break;
        case 'E':
            titulo("Ejercicio 5");
            ejecutarEj05();
            break;
        case 'F':
            titulo("Ejercicio 6");
            ejecutarEj06();
            break;
        case 'G':
            titulo("Ejercicio 7");
            ejecutarEj07();
            break;
        case 'H':
            titulo("Ejercicio 8");
            ejecutarEj08();
            break;
        case 'I':
            titulo("Ejercicio 9");
            ejecutarEj9();
            break;
        case 'J':
            titulo("Ejercicio 10");
            ejecutarEj10();
            break;
        case 'X':
            printf("\n\t\t-----Chau!-----\n");
            break;
        default:
            printf("Nu se\n");
    }
    printf("\n");
}


void titulo(char *s)
{
    char tope[] = {201,205,205,205,205,205,205,205,205,205,205,205,205,187,'\0'};
    char piso[] = {200,205,205,205,205,205,205,205,205,205,205,205,205,188,'\0'};

    printf("\n%s\n", tope);
    if(strlen(s) == 11)
        printf("%c%s%c%c\n", 186,s,' ',186);
    else
        printf("%c%s%c\n", 186,s,186);
    printf("%s\n", piso);
}
