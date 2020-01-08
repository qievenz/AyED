/* comentario */
#include <stdio.h>
#include <stdlib.h>
#define LOG(x) printf(x)

typedef struct nodoInscripcion
{
    int codigo;
    int legajo;
    char nombre[30];
    struct nodoInscripcion *ptrSiguiente;
} NodoInscripcion, *ptrNodoInscripcion;

ptrNodoInscripcion eliminarAlumno(ptrNodoInscripcion const curso, int legajo);

int main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}

ptrNodoInscripcion eliminarAlumno(ptrNodoInscripcion const curso, int legajo)
{
    ptrNodoInscripcion tCurso = curso;
    ptrNodoInscripcion tAnterior = NULL;
    while (tCurso != NULL)
    {
        if (tCurso->legajo == legajo)
        {
            tAnterior->ptrSiguiente = tCurso->ptrSiguiente;
            free(tCurso);
            break;
        }
        tAnterior = tCurso;
        tCurso = tCurso->ptrSiguiente;
    }
}