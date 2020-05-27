#include "protoejercicios91011.h"


void ejecutarEj11()
{
    FILE *leerArchivo, *escrbirArchivo;
    char linea[50];
    char numeros[7][7];
    int datos;
    int m5 = 0;
    int m6 = 0;
    int m11 = 0;
    char coso[8];

    if(!abrir(&leerArchivo, "ej09.txt", "rt"))
    {
        return;
    }

    if(!abrir(&escrbirArchivo, "ej11.txt", "wt"))
    {
        fclose(leerArchivo);
        return;
    }


    while(fgets(linea, sizeof(linea), leerArchivo))
    {
        datos = trabajar_linea(linea, numeros);

        for(int i = 0; i<datos;i++)
        {
            m5+=multiplo5(numeros[i]);
            m6+=multiplo6(numeros[i]);
            m11+=multiplo11(numeros[i]);

            if(mayorque100(numeros[i]))
            {

                fprintf(escrbirArchivo,numeros[i]);
                fprintf(escrbirArchivo, "\n");
            }
        }
    }

    printf("Cantidad de multiplos de 5: %d\n", m5);
    printf("Cantidad de multiplos de 6: %d\n", m6);
    printf("Cantidad de multiplos de 11: %d\n", m11);

    fclose(leerArchivo);
    fclose(escrbirArchivo);
}


int trabajar_linea(char *linea, char numeros[7][7])
{
    char dato[7];
    int bandera=0;
    int pos=0;
    int nDato=0;

    while(*linea)
    {
        if (*linea==' ' || *linea=='\n')
        {
            if(bandera)
            {
                dato[pos]='\0';
                bandera=0;
                pos=0;
                strcpy(numeros[nDato], dato);
                nDato++;
            }
            linea++;
        }
        else
        {
           dato[pos]=*linea;
           linea++;
           pos++;
           bandera=1;
        }
    }

    if(bandera)
    {
        dato[pos]='\0';
        strcpy(numeros[nDato], dato);
        nDato++;
    }
    return nDato;
}
