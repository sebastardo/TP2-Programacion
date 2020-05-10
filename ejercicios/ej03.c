#include "protoejercicios.h"

void ejecutarEj03()
{
    int cantidad_de_elementos;
    int *vector_variable;
    long suma_de_elementos;
    float promedio;

    calculo promediazo;

    printf("Cantidad a elementos que tendra el array: ");
    fflush(stdin);
    scanf("%d",&cantidad_de_elementos);

    crearArray_int(&vector_variable, cantidad_de_elementos);


    printf("\nCalculo con opcion A\n");
    promedio = promedio_a(vector_variable, cantidad_de_elementos, &suma_de_elementos);
    printf("Promedio opcion A: %.2f\n", promedio);
    printf("Suma opcion A: %ld\n", suma_de_elementos);

    printf("\nCalculo con opcion B\n");
    promedio_b(vector_variable, cantidad_de_elementos, &promediazo);
    printf("Promedio opcion B: %.2f\n", promediazo.promedio);
    printf("Suma opcion B: %ld\n", promediazo.sumatoria);

    free(vector_variable);
}

void crearArray_int(int **vector, int e)
{
    int i= 1;
    int *v, *fin;
    *vector = (int *)malloc(sizeof(int)*e);
    v = *vector;
    fin = v+e;

    while(v<fin)
    {
        *v=i++;
        v++;
    }
    v = fin - e;
}

float promedio_a(int *v, int e, long *s)
{
    int *fin = v+e;

    *s=0;

    while(v<fin)
    {
        *s+=*v;
        v++;
    }

    v = fin - e;

    return (float)*s/(float)e;
}


void promedio_b(int *v, int e, calculo *c)
{
    int *fin = v+e;

    c->sumatoria=0;

    while(v<fin)
    {
        c->sumatoria+=*v;
        v++;
    }

    v = fin - e;

    c->promedio = (float)c->sumatoria/(float)e;
}
