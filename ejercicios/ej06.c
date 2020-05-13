#include "protoejercicios.h"
#define REDONDEO(x) (x)<((float)((int)x))+0.5?(int)(x):(int)(x+1)
#define MENOR(x, y) (x)<(y)?(x):(y)
#define CAMBIAZAZO(x,y) ({int z=(x);\
                        (x)=(y);\
                        (y)=z;\
                        })

void ejecutarEj06()
{
    printf("Redondeo menor: %d\n",REDONDEO(5.1));
    printf("Redondeo mayor: %d\n",REDONDEO(5.5));


    printf("Menor(funcion) entre %d y %d: %d\n", 1,2,comparador(1,2));
    printf("Menor(funcion) entre %d y %d: %d\n", 2,1,comparador(1,2));
    printf("Menor (MACRO) entre %d y %d: %d\n", 1,2,MENOR(1,2));
    printf("Menor (MACRO) entre %d y %d: %d\n", 2,1,MENOR(2,1));

    {
        int a = 3;
        int b = 6;

        printf("Original: %d - %d\n", a,b);

        cambiazo(&a,&b);

        printf("Cambiazo: %d - %d\n", a,b);
        CAMBIAZAZO(a,b);
        printf("Cambiazazo: %d - %d\n", a,b);
    }



}



int comparador( int a, int b)
{
    if(a<b)
    {
        return a;
    }
    return b;
}


void cambiazo(int *a, int *b)
{
    int aux = *a;
    *a=*b;
    *b= aux;
}
