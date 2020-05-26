#include "protoejercicios.h"


void ejecutarEj08()
{
    char frase[1000];
    char palabra[300];
    int tam_palabra_larga;
    int repeticiones_palabra_larga;

    printf("Ingrese una frase (se toma hasta el primer punto): ");
    fflush(stdin);
    gets(frase);
    reducir_hasta_punto(frase);

    printf("Frase: %s\n", frase);
    tam_palabra_larga = palabra_mas_larga(frase,palabra);
    printf("Palabra mas larga: %s - Largo: %d\n",palabra, tam_palabra_larga);
    printf("Cantidad de palabras: %d\n", cantidad_palabras(frase));

    repeticiones_palabra_larga = cantidad_repeticiones_palabra_mas_larga(frase, palabra);
    printf("Repeticiones de la palabra mas larga: %d", repeticiones_palabra_larga);



    printf("\n");
}


void reducir_hasta_punto(char *frase)
{
    size_t largo = 0;

    while(*frase!='\0')
    {
        if(*frase=='.')
            *frase='\0';
        else
        {
            frase++;
            largo++;
        }
    }
    frase-=largo;
}

int palabra_mas_larga(const char *frase, char *p)
{
    char palabra[100];
    size_t contador;

    strcpy(palabra,"");
    while(*frase!='\0' && *frase!='.')
    {
        contador=0;
        while(*frase!='\0' && *frase!=' ' && *frase!='.')
        {
            frase++;
            contador++;
        }

        if(strlen(palabra)<contador)
        {
             frase-=contador;
             strcpy(palabra,"");
             strncat(palabra, frase, contador);
             frase+=contador;
        }
        if(*frase!='\0' && *frase!='.')
            frase++;
    }

    strcpy(p, palabra);
    return strlen(palabra);
}

int cantidad_palabras(const char *frase)
{
    int contador=0, bandera=0;

    while(*frase!='\0' && *frase!='.')
    {
        while(*frase!=' ' && *frase!='\0' && *frase!='.')
        {
            frase++;
            bandera=1;
        }
        if(bandera)
        {
            contador++;
            bandera=0;
        }
        if(*frase=='\0')
            return contador;
        frase++;
    }
    return contador;
}


int cantidad_repeticiones_palabra_mas_larga(const char *frase, char *palabra)
{
    int repeticiones=0;
    char *inicio = palabra;


    while(*frase!='\0')
    {
        while((*palabra==*frase) && (*palabra!='\0' && *frase!='\0'))
        {
            palabra++;
            frase++;
        }

        if(*palabra=='\0')
        {
            if(*frase==' ')
            {
                repeticiones++;
                palabra=inicio;
                frase++;
            }
            else
            {
                if(*frase=='\0')
                {
                    repeticiones++;
                    return repeticiones;
                }
                else
                {
                    palabra=inicio;
                    while(*frase!=' ' || *frase!='\0')
                    {
                        frase++;
                    }
                    frase++;
                }
            }
        }
        else
        {
            if(*frase!='\0')
            {
                palabra=inicio;
                while(*frase!=' ' &&  frase!='\0')
                {
                    frase++;
                }
                if(*frase=='\0')
                    return repeticiones;
                frase++;
            }
            else
            {
                return repeticiones;
            }
        }
    }

    return repeticiones;
}
