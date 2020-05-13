#include "protoejercicios.h"

void ejecutarEj05()
{
    ////////////////////////////////////////////////////////////////
    /// int sscanf(const char *cadena, const char *formato,...); ///
    ////////////////////////////////////////////////////////////////
    {
        char entrada[100];
        char nombre[95];
        int edad;
        int datos_procesados;

        fflush(stdin);
        printf("Nombre y edad: ");
        gets(entrada);

        datos_procesados = sscanf(entrada, "%s %d", nombre, &edad);

        printf("Nombre: %s\nEdad: %d\nDatos Procesados: %d\n", nombre, edad, datos_procesados);
    }


    //////////////////////////////////////////////////////////////////////////////////////////////
    ///  int sprintf (const char *destino, const char * formato[, argumento1, argumento2...]); ///
    //////////////////////////////////////////////////////////////////////////////////////////////
    {
        char mensaje[100];
        int edad;
        char nombre[95];

        fflush(stdin);
        printf("Escriba su edad: ");
        scanf("%d",&edad);

        fflush(stdin);
        printf("Escriba su nombre: ");
        scanf("%s",nombre);

        sprintf(mensaje, "Hola, vos te llamas %s y tenes %d\n", nombre, edad);
        printf("%s", mensaje);
        puts(mensaje);
    }
}
