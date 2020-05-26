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
    short int numero;
    int cantidad;
    char strNumero[7];
    int coso;


    printf("Cantidad de numeros a ingresar: ");
    fflush(stdin);
    scanf("%d", &cantidad);

    if(cantidad>7)
        cantidad=7;

    coso= cantidad;
    while(cantidad)
    {
        printf("Ingrese el numero de -32768 a 32767: ");
        fflush(stdin);
        scanf("%d", &numero);

        cantidad--;
        convertir_string(numero, strNumero);
        fprintf(archivoTexto,strNumero);


        if(cantidad)
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
