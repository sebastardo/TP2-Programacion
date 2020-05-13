#include "protoejercicios.h"
#define ABRIRARCHIVO(x,y,z) ({(x) = fopen((y),(z));\
                             (x)==NULL?falso:verdadero;})

void ejecutarEj07()
{
    char nombre[] = {"ej07.txt"};
    char modo[] = {"rt"};
    FILE *f;

    if(abrir_archivo(&f,nombre,modo))
    {
        printf("Abrio - funcion\n");
    }
    fclose(f);

    if(ABRIRARCHIVO(f,nombre,modo))
    {
        printf("Abrio - MACRO\n");
    }
    else
        fprintf(stderr, "stderr - MACRO");
    fclose(f);
}

enum booleano abrir_archivo(FILE **f, char *nombre, char *modo)
{
    *f = fopen(nombre,modo);
    if(*f==NULL)
    {
        fprintf(stdout, "stdout\n");
        fprintf(stderr, "stderr\n" );
        return falso;
    }
    return verdadero;
}
