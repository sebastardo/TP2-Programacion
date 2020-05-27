#include "protoejercicios91011.h"

void ejecutarEj10()
{
    printf("32767 - %d\n", esShortInt("32767"));
    printf("-32768 - %d\n", esShortInt("-32768"));
    printf("-32769 - %d\n", esShortInt("-32769"));
    printf("32768 - %d\n", esShortInt("32768"));
}

int capicua(const char *numero)
{
    int capicua = 1;
    char *inicio = numero;
    char *fin = numero + strlen(numero)-1;

    if(*inicio=='-')
        inicio++;

    while(capicua && inicio < fin)
    {
        if(*inicio!=*fin)
            capicua = 0;
        inicio++;
        fin--;
    }
    return capicua;
}


int multiplo5(const char *numero)
{
    char *fin = numero + strlen(numero)-1;

    return (*fin=='0' || *fin == '5');
}


int multiplo6(const char *numero)
{
    char *inicio = numero;
    char *fin = numero + strlen(numero)-1;

    if(*inicio=='-')
        inicio++;

    if(*fin=='0' || *fin=='2' || *fin=='4' || *fin=='6' || *fin=='8')
    {
        int r = 0;
        while(inicio<=fin)
        {
            r+=(*inicio - 48);
            inicio++;
        }
        return r%3 == 0;
    }

    return 0;
}


int multiplo11(const char *numero)
{
    char *inicio = numero;
    char *fin = numero + strlen(numero)-1;
    int n = 0;
    int decimal = 1;

    while(inicio<=fin)
    {
        n += (*fin -48)* decimal;
        decimal*=10;
        fin--;
    }

    return n%11==0;
}


int mayorque100(const char *numero)
{
    int num=0;

    if(*numero=='-')
        return 0;

    while(*numero)
    {
        num+=*numero;
        numero++;
    }

    return num>('1'+'0'+'0');
}


int mayor_que(const char *numero, const char *tope)
{
    int negativo;
    if(*numero=='-' && *tope!='-')
        return 0;

    if(*numero!='-' && *tope=='-')
        return 1;


    if(strlen(numero)!=strlen(tope))
    {
        if(*numero=='-' && *tope=='-')
        {
            // ejemplo: 3 cifras vs 2
            if(strlen(numero)>strlen(tope))
                return 0;

            // ejemplo: 2 cifras vs 3
            //if(strlen(numero)<strlen(tope))
            else
                return 1;
        }
        else
        {
             // ejemplo: 3 cifras vs 2
            if(strlen(numero)>strlen(tope))
                return 1;
            // ejemplo: 2 cifras vs 3
            // if(strlen(numero)<strlen(tope))
            else
                return 0;
        }
    }

    // misma cantidad de cifras
    negativo=(*numero=='-');


    while(numero)
    {
        if(*numero<*tope)
        {
            if(negativo)
                return 1;
            else
                return 0;
        }
        if(*numero>*tope)
        {
            if(!negativo)
                return 1;
            else
                return 0;
        }
        numero++;
        tope++;
    }
    return 0;
}



int esShortInt(const char *numero)
{
    int coso = '3'+'2'+'7'+'6'+'7';
    int total=0;

    if(*numero=='-')
    {
        coso++;
        numero++;
    }


    while(*numero)
    {
        total+=*numero;
        numero++;
    }

    return total<=coso;
}
