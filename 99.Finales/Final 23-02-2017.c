/* comentario */
#include <stdio.h>
#include <stdlib.h>
//#define LOG(x) printf(x)

typedef struct rNota
{
    int nota;
    struct rNota *ptrSiguiente;
};
typedef struct NodoNota
{
    struct rNota info;
    struct NodoNota *ptrSiguiente;
};

typedef struct rEstudiante
{
    int id;
    struct rNota notas[4];
};

typedef struct NodoEstudiante
{
    struct rEstudiante info;
    struct NodoEstudiante *ptrSiguiente;
};

typedef struct rCurso
{
    int id;
    int promocionados;
    int regularizados;
    int recursantes;
};
typedef struct NodoCurso
{
    struct rCurso info;
    struct NodoCurso *ptrSiguiente;
} NodoCurso;

void ProcesarNovedades(FILE *archivoNovedades, NodoCurso *ptrCursosInicio);

int main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}

void ProcesarNovedades(FILE *archivoNovedades, NodoCurso *ptrCursosInicio)
{
    archivoNovedades = fopen("archivo.dat", "r");
    fscanf(archivoNovedades, "")
}