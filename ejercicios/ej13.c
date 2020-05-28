#include "protoejercicios.h"


typedef struct
{
    int dni;
    char apellido[20];
    char nombre[20];
    double sueldo;
}Empleado;


typedef struct
{
    int dni;
    char apellido[20];
    char nombre[20];
    float promedio;
}Estudiante;


void ejecutarEj13()
{
    FILE *fEmpleado;
    FILE *fEstudiante;

    if(!abrir13(&fEmpleado, "ej13Empleado.spr","rb+"))
    {
        return;
    }
    if(!abrir13(&fEstudiante, "ej13Estudiante.spr","rb"))
    {
        fclose(fEmpleado);
        return;
    }

    ///MUESTRA EMPLEADOS, NI GANAS DE FUNCION/////////////////////////////////////////////
    {
        printf("\nANTES\n");
        Empleado emp;
        Estudiante est;
        fread(&emp, sizeof(Empleado),1,fEmpleado);
        while(!feof(fEmpleado))
        {
            printf("%d - %s - %s - %.2lf\n", emp.dni, emp.apellido, emp.nombre, emp.sueldo);
            fread(&emp, sizeof(Empleado),1,fEmpleado);
        }
        rewind(fEmpleado);
    }
    ///FIN MUESTRA EMPLEADOS, NI GANAS DE FUNCION/////////////////////////////////////////////

    editar_archivos(fEmpleado,fEstudiante);

    ///MUESTRA EMPLEADOS, NI GANAS DE FUNCION/////////////////////////////////////////////

    {
        printf("\nDESPUES\n");
        Empleado emp;
        Estudiante est;

        rewind(fEmpleado);
        fread(&emp, sizeof(Empleado),1,fEmpleado);
        while(!feof(fEmpleado))
        {
            printf("%d - %s - %s - %.2lf\n", emp.dni, emp.apellido, emp.nombre, emp.sueldo);
            fread(&emp, sizeof(Empleado),1,fEmpleado);
        }
    }
    ///FIN MUESTRA EMPLEADOS, NI GANAS DE FUNCION/////////////////////////////////////////////

    fclose(fEmpleado);
    fclose(fEstudiante);
}


int abrir13(FILE **f, const char *n, const char *m)
{
    *f = fopen(n, m);

    if(!*f)
    {
        fprintf(stderr, "Error: %s\n", n);
        return 0;
    }
    return 1;
}


void editar_archivos(FILE *fEmpleado, FILE *fEstudiante)//, double porcentaje_sueldo)
{
    Empleado emp;
    Estudiante est;
    size_t posicion = 0;
    double x;

    fread(&est, sizeof(Estudiante),1,fEstudiante);
    while(!feof(fEstudiante))
    {
        if(est.promedio>7)
        {
            fseek(fEmpleado,sizeof(Empleado)*posicion,SEEK_SET);
            emp.dni = est.dni;
            strcpy(emp.nombre, est.nombre);
            strcpy(emp.apellido, est.apellido);
            //si promedio >7 =>  sueldo + 7.28%
            emp.sueldo = 8.28; //no me salio y tengo sueño


            fwrite(&emp, sizeof(Empleado),1, fEmpleado);
        }
        fread(&est, sizeof(Estudiante),1,fEstudiante);
        posicion++;
    }
}
