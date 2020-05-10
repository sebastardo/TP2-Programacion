#include "protoejercicios.h"

void ejecutarEj01()
{
    char opciones[] = {"1234"};
    char opc;

    float *vector;
    int cantidad_maxima_componentes;
    int cantidad_ingresados;

    printf("Cantidad maxima de componentes del vector: ");
    fflush(stdin);
    scanf("%d", &cantidad_maxima_componentes);

    cantidad_ingresados = crearvector(&vector, cantidad_maxima_componentes);
    mostrar(vector, cantidad_ingresados);


    do
    {
        opc = menu("\nElija una opcion\n"
                   "1-Buscar el minimo elemento\n"
                   "2-Calcular el promedio de los valores de las posiciones pares\n"
                   "3-Mostrarlo en orden inverso\n"
                   "4-Salir\n"
                   "Opcion: "
                   , opciones);

        switch(opc)
        {
            case('1'):
                printf("\nMinimo elemento del vector: %.2f\n", minimo_elemento(vector, cantidad_ingresados));
                break;
            case('2'):
                printf("\nPromedio de los pares: %.2f\n", promedio_valores_orden_par(vector, cantidad_ingresados));
                break;
            case('3'):
                printf("\nArray de fin a comienzo: ");
                mostrar_inverso(vector, cantidad_ingresados);
                printf("\n");
                break;
            default:
                //
                printf("\t\t-----Adios!-----\n\n");
        }
    }while(opc!='4');

    free(vector);
}





int crearvector(float **ppvec, int ce)
{
    float *v, *fin;
    int ingresados=0;
    float dato=1;

    *ppvec = (float *)malloc(sizeof(float)*ce);


    if(*ppvec == NULL)
    {
        printf("Sin memoria");
        return 0;
    }

    v = *ppvec;
    fin = v+ce;

    printf("Datos del vector (0 para terminar)\n");
    while(v<fin && dato)
    {
        printf("Ingrese dato: ");
        fflush(stdin);
        scanf("%f", &dato);

        if(dato)
        {
            ingresados++;
            *v = dato;
        }
        v++;
    }

    v = fin - ce;

    return ingresados;
}


char menu(const char *mensaje, const char *opciones)
{
    char opcion;
    int primeraVez = 1;
    do
    {
        if(primeraVez)
        {
            printf("%s", mensaje);
            primeraVez = 0;
        }
        else
        {
            printf("No es una opcion valida\nElija nuevamente: ");

        }
        fflush(stdin);

        scanf("%c", &opcion);

    }while(!strchr(opciones, opcion));

    return opcion;
}


void mostrar(float *vector, int tam)
{
    float *v = vector;

    printf("\nvector en funcion = %p", vector);

    for(int i = 0; i<tam; i++)
    {
        printf("\nDato en funcion: %.2f - %p", *v, v);
        v++;
    }
    printf("\n");
}


float minimo_elemento(float *vector, int elementos)
{
    float minimo;
    float *fin = vector+elementos;

    minimo = *vector;

    while(vector<fin)
    {
        if(*vector<minimo)
            minimo = *vector;
        vector++;
    }
    return minimo;
}

float promedio_valores_orden_par(float *vector, int elementos)
{
    float promedio=0;
    float *fin = vector+elementos;

    if(elementos==0 || elementos/2 == 0)
        return 0;

    vector++;
    while(vector<fin)
    {
        promedio+=*vector;
        vector++;
        vector++;
    }

    return promedio/(elementos/2);
}


void mostrar_inverso(float *vector, int elementos)
{
    float *fin = vector+elementos-1;

    while(fin>=vector)
    {
        printf("%.2f ", *fin);
        fin--;
    }
}
