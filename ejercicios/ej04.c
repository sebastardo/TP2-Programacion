#include "protoejercicios.h"


void ejecutarEj04()
{
    char s[33];
    printf("atoi positivo: %d\n", atoi_s("123"));
    printf("atoi negativo: %d\n", atoi_s("-123"));


    printf("itoa con return: %s\n",itoa_s(-1234,s,10));
    printf("itoa usando la cadena: %s\n",s);

    ///TODO: los demas, ni ganas
}


///Conversión de tipos

int atoi_s(const char *str)
{
    //atoi (ascii to integer) | cadena de caracteres a entero

    int signo = 1;
    char *fin;
    int numero=0;
    int peso = 1;

    if(*str=='-')
    {
        signo = -1;
        str++;
    }

    fin = str+(strlen(str)-1);


    while(fin>=str)
    {
        numero+=(((*fin)-48)*peso);
        peso*=10;
        fin--;
    }

    return numero*signo;
}
/*
double atof_s(const char *str)
{
    //atof (ascii to float) | cadena de caracteres a coma flotante
}


long int atol_s(const char *str)
{
    //atol (C Standard Library)]] (ascii to long) | cadena de caracteres a entero tamaño largo
}

double strtod_s(const char *str, char **endptr)
{
    //strtod (string to double) | cadena de caracteres a coma flotante tamaño doble
}

long int strtol_s(const char *str, char **endptr, int base)
{
    //strtol (string to long) | cadena de caracteres a entero largo
}

unsigned long int strtoul_s(const char *str, char **endptr, int base)
{
    //strtoul (string to unsigned long) | cadena de caracteres a entero largo sin signo (positivo)
}

*/
char *  itoa_s(int valor, char *str, int base )
{
    // Convert integer to string (non-standard function)<
    char *ini = str, *fin, aux;
    unsigned numero;
    static char digi[] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    if(valor<0)
    {
        *ini = '-';
        ini++;
        valor=-valor;
    }

    fin = ini;
    numero =(unsigned)valor;

    do
    {
        *fin = digi[numero%base];
        fin++;
        numero /=base;
    }while(numero);

    *fin = '\0';
    fin--;

    while(ini<fin)
    {
        aux=*ini;
        *ini=*fin;
        *fin=aux;
        fin--;
        ini++;
    }

    return str;
}

