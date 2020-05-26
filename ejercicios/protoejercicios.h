#ifndef PROTOEJERCICIOS_H_INCLUDED
#define PROTOEJERCICIOS_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



///Ejercicio 01
void ejecutarEj01();
char menu(const char *mensaje, const char *opciones);
int crearArray(float **ppvec, int ce);
void mostrar(float *, int);
float minimo_elemento(float *, int elementos);
float promedio_valores_orden_par(float *, int);
void mostrar_inverso(float *, int);


///Ejercicio 02
void ejecutarEj02();
size_t posicion(int *,int, int);


///Ejercicio 03
typedef struct
{
    float promedio;
    long sumatoria;
}calculo;

void ejecutarEj03();
void crearArray_int(int **, int e);
float promedio_a(int *v, int e, long *s);
void promedio_b(int *v, int e, calculo *c);



///Ejercicio 04
void ejecutarEj04();
int atoi_s(const char *str);
char *itoa_s(int, char *, int);


///Ejercicio 05
void ejecutarEj05();


///Ejercicio 06
void ejecutarEj06();
int comparador(int a, int b);
void cambiazo(int *a, int *b);

///Ejercicio 07
enum booleano{falso, verdadero};
void ejecutarEj07();
enum booleano abrir_archivo(FILE **f, char *nombre, char *modo);


///Ejercicio 08
void ejecutarEj08();
void reducir_hasta_punto(char *);
int palabra_mas_larga(const char *, char *);
int cantidad_palabras(const char *);
int cantidad_repeticiones_palabra_mas_larga(const char *, char *);




#endif // PROTOEJERCICIOS_H_INCLUDED
