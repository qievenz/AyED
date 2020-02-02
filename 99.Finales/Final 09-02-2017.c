/* 

estructura enlazada (InstanciaAlumno) -> array [7] (instancia 1..2...7)
|
v
estructura enlazada -> array [7]
|
v
estructura enlazada -> array [7]

*/
#include <stdio.h>
#include <stdlib.h>
#define LOG(x) printf(x)

typedef struct instancia
{
    int parcial_1;
    int parcial_1_rec_1;
    int parcial_1_rec_2;
    int parcial_2;
    int parcial_2_rec_1;
    int parcial_2_rec_2;
} InstanciaParcial;

typedef struct instanciaAlumno
{
    int numeroLegajo;
    char apellidoNombre[30];
    InstanciaParcial instancia;
    int nota;
    char texto[50];
    ptrInstanciaAlumno ptrSiguiente;
} InstanciaAlumno, *ptrInstanciaAlumno;

void inicializarArrInstancia(InstanciaAlumno arrInstancia[7]);

int main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}

void recursantes(FILE *archivo, ptrInstanciaAlumno ptrRecursantes)
{ //Se considera el archivo abierto y con datos
    InstanciaAlumno alumno;
    InstanciaAlumno alumnoAnterior;
    InstanciaAlumno arrAlumno[7];

    int i = 0;
    inicializarArrInstancia(arrAlumno);
    //fscanf(archivo, &arrAlumno[i]);
    fscanf(archivo, "%d %s %d %d %s", &alumno.numeroLegajo, alumno.apellidoNombre, &alumno.instancia.parcial_1, &alumno.nota, alumno.texto);
    while (feof(archivo))
    {
        i = 0;
        alumnoAnterior = arrAlumno[i];
        while (arrAlumno[i].numeroLegajo == alumnoAnterior.numeroLegajo)
        {
            alumnoAnterior = arrAlumno[i];
            i++;
            fscanf(archivo, &arrAlumno[i]);
        }
        //Validar notas
        int promedio = 0;
        for (int j = 0; j < i; j++)
        {
        }

        //Resetear array
        alumnoAnterior = arrAlumno[i];
        inicializarArrInstancia(arrAlumno);
        arrAlumno[0] = alumnoAnterior;
    }
}

/*
fscanf(archivo, "%d %s %d %d %s", &alumno[i].numeroLegajo, alumno[i].apellidoNombre, &alumno[i].instancia, &alumno[i].nota, alumno[i].texto);
fscanf(archivo, "%d %s %d %d %s", &alumno.numeroLegajo, alumno.apellidoNombre, &alumno.instancia, &alumno.nota, alumno.texto);
*/