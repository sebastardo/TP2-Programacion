#include "protoejercicios91011.h"

void ejecutarEj91011()
{
    FILE *archivoTexto;
    char nombre_archivo[100];
    char ingresar;

    printf("Ingrese el nombre del archivo: ");
    fflush(stdin);
    gets(nombre_archivo);

    strcat(nombre_archivo, ".txt");

    if(!abrir(&archivoTexto, nombre_archivo, "wt"))
    {
        printf("NOOK");
        return;
    }


    do
    {
        insertar_numero_en_txt(archivoTexto);

        /// TODO: automatizar filas de ingresos
        printf("\nDesea ingresar otra tanda de numeros (S/N)?: ");
        fflush(stdin);
        scanf("%c",&ingresar);
    }while(tolower(ingresar)=='s');


    fclose(archivoTexto);
}


int abrir(FILE **archivo, const char *nombre, const char *modo)
{
    *archivo = fopen(nombre, modo);

    if(*archivo==NULL)
        return 0;
    return 1;
}

void insertar_numero_en_txt(FILE *archivoTexto)
{
    char agregar;
    short int numero;
    int cantidad = 0;
    char strNumero[6];


    printf("Desea agregar un numero (S/N)?: ");
    fflush(stdin);
    scanf("%c", &agregar);


    ///TODO: automatizar columnas de ingresos (7 max)

    while(tolower(agregar)=='s' && cantidad<7)
    {
        printf("Ingrese el numero de -32768 a 32767: ");
        fflush(stdin);
        scanf("%d", &numero);

        convertir_string(numero, strNumero);
        //agregar al txt
        fprintf(archivoTexto,strNumero);

        printf("\nAgregar otro numero (S/N)?: ");
        fflush(stdin);
        scanf("%c", &agregar);

        cantidad++;
        if(tolower(agregar)=='s' && cantidad<7)
        {
            fprintf(archivoTexto," ");
        }
    }
    fprintf(archivoTexto,"\n");
}

void convertir_string(short int numero, char *strNumero)
{

    char *n = strNumero;
    int numero_aux = numero;
    char signo = ' ';

    if(numero_aux<0)
    {
        signo = '-';
        numero_aux = numero *(-1);
    }

    n+=6;
    *n = '\0';
    n--;
    while(numero_aux>0)
    {
        *n = (char)(numero_aux%10)+48;
        n--;
        numero_aux /=10;
    }

    while(n>strNumero)
    {
        *n=signo;
        signo=' ';
        n--;
    }
    *n=signo;
}
