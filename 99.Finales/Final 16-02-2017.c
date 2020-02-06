/* Regularizacion */
#define N 12
#include <stdio.h>
#include <stdlib.h>
//#define LOG(x) printf(x)

//1.
typedef struct rExamen
{
    int fecha;
    int instancia;
    int nota;
    struct ptrExamen *ptrSiguiente;
} infoExamen, *ptrExamen;

typedef struct rAlumno
{
    int legajo;
    char apeNom[20];
    ptrExamen *examenes;
} infoAlumno;

typedef struct nodoAlumno
{
    infoAlumno info;
    struct ptrNodoAlumno *ptrSiguiente;
} NodoAlumno, *ptrNodoAlumno;

typedef struct colaAlumno
{
    ptrNodoAlumno *ptrNodoInicio;
    ptrNodoAlumno *ptrNodoFin;
} ColaAlumno;

unsigned GetCurso(unsigned unIndice);
int IsPromocionado(ptrExamen examenes);
ptrNodoAlumno *desencolar(ColaAlumno curso); //devuelve el alumno de la cola
void InsertarOrdenado(ptrNodoAlumno *lista, NodoAlumno nuevo);

//2.
ColaAlumno cursos[N];

//3.
void InformarPromocionados(ColaAlumno cursos[N]);

main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}

//4.
void InformarPromocionados(ColaAlumno cursos[N])
{
    FILE *archivo = fopen("archivo.dat", "wb");
    ptrNodoAlumno alumnoActual;
    //TODO:crear una lista para que grabe ordenado por legajo
    //ptrNodoAlumno listaPromocionados;
    int promociono;
    int curso;
    for (int i = 0; i < N; i++)
    {
        curso = GetCurso(i);
        alumnoActual = desencolar(cursos[i]);
        while (alumnoActual != NULL)
        {
            promociono = IsPromocionado(alumnoActual->info.examenes);
            if (promociono = 1)
            {
                //InsertarOrdenado(listaPromocionados, *alumnoActual);
                fprintf(archivo, "%d %s %d\n", alumnoActual->info.legajo, alumnoActual->info.legajo, curso);
            }
            alumnoActual = desencolar(cursos[i]);
        }
    }
    fclose(archivo);
}