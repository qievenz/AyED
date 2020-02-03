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
//#define LOG(x) printf(x)

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
    int instancia;
    int nota;
    char texto[50];
    struct ptrInstanciaAlumno *ptrSiguiente;
} InstanciaAlumno, *ptrInstanciaAlumno;

void inicializarArrInstancia(InstanciaAlumno arrInstancia[7]);

int main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}

void recursantes(FILE *archivo)
{ //Se considera el archivo abierto y con datos
    ptrInstanciaAlumno ptrResultado = NULL;
    ptrInstanciaAlumno ptrAlumno;
    ptrInstanciaAlumno ptrRecursante = NULL;
    InstanciaParcial instancia;
    ptrInstanciaAlumno ptrAlumnoAValidarInicio;
    ptrAlumno = (ptrInstanciaAlumno)malloc(sizeof(InstanciaAlumno));
    fscanf(archivo, "%d %s %d %d %s", ptrAlumno->numeroLegajo, ptrAlumno->apellidoNombre, ptrAlumno->instancia, ptrAlumno->nota, ptrAlumno->texto);
    ptrAlumno->ptrSiguiente = NULL;
    //ptrRecursantes = ptrAlumno;
    ptrAlumnoAValidarInicio = ptrAlumno;
    ptrInstanciaAlumno ptrAlumnoAnterior;
    ptrAlumnoAnterior = ptrAlumno;
    int aprobo_parcial_1 = 0;
    int aprobo_parcial_2 = 0;

    while (feof(archivo))
    {
        ptrAlumno = (ptrInstanciaAlumno)malloc(sizeof(InstanciaAlumno));
        fscanf(archivo, "%d %s %d %d %s", ptrAlumno->numeroLegajo, ptrAlumno->apellidoNombre, ptrAlumno->instancia, ptrAlumno->nota, ptrAlumno->texto);

        if (ptrAlumno->instancia == 1)
        {
            instancia.parcial_1 = ptrAlumno->nota;
        }
        else if (ptrAlumno->instancia == 11)
        {
            instancia.parcial_1_rec_1 = ptrAlumno->nota;
        }
        else if (ptrAlumno->instancia == 12)
        {
            instancia.parcial_1_rec_2 = ptrAlumno->nota;
        }
        else if (ptrAlumno->instancia == 2)
        {
            instancia.parcial_2 = ptrAlumno->nota;
        }
        else if (ptrAlumno->instancia == 21)
        {
            instancia.parcial_2_rec_1 = ptrAlumno->nota;
        }
        else if (ptrAlumno->instancia == 22)
        {
            instancia.parcial_1_rec_2 = ptrAlumno->nota;
        }

        if (ptrAlumnoAnterior->numeroLegajo != ptrAlumno->numeroLegajo)
        {
            //Validar instancias
            if (instancia.parcial_1 >= 6 || instancia.parcial_1_rec_1 >= 6 || instancia.parcial_1_rec_2 >= 6)
            {
                aprobo_parcial_1 = 1;
            }
            if (instancia.parcial_2 >= 6 || instancia.parcial_2_rec_1 >= 6 || instancia.parcial_2_rec_2 >= 6)
            {
                aprobo_parcial_2 = 1;
            }
            if (aprobo_parcial_1 == 0 && aprobo_parcial_2 == 0)
            {
                if (ptrResultado == NULL)
                {
                    ptrResultado = ptrAlumno;
                    ptrResultado->ptrSiguiente = NULL;
                    ptrRecursante = ptrResultado;
                }
                else
                {
                    ptrRecursante->ptrSiguiente = ptrAlumno;
                    ptrRecursante = ptrAlumno;
                }
            }
        }
        ptrAlumnoAnterior->ptrSiguiente = ptrAlumno;
        ptrAlumnoAnterior = ptrAlumno;
    }
}

/*
fscanf(archivo, "%d %s %d %d %s", &alumno[i].numeroLegajo, alumno[i].apellidoNombre, &alumno[i].instancia, &alumno[i].nota, alumno[i].texto);
fscanf(archivo, "%d %s %d %d %s", &alumno.numeroLegajo, alumno.apellidoNombre, &alumno.instancia, &alumno.nota, alumno.texto);
*/