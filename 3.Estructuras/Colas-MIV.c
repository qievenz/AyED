/* comentario */
#include <stdio.h>
#include <stdlib.h>
#define LOG(x) printf(x)

typedef struct nodoCola
{
    int dato;
    struct nodoCola *ptrNodoSgte;
} NodoCola, *ptrNodoCola;

void crearCola(ptrNodoCola ptrInicio, ptrNodoCola ptrFin);
void encolar(ptrNodoCola ptrFin, int dato);
void dequeue(ptrNodoCola ptrInicio, ptrNodoCola ptrFin);
int estaVacia(ptrNodoCola ptrInicio, ptrNodoCola ptrFin);
//MIV-8
int eliminarPrimerosCuatro(ptrNodoCola ptrInicio, ptrNodoCola ptrFin);

int main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}

void crearCola(ptrNodoCola ptrInicio, ptrNodoCola ptrFin)
{
    ptrNodoCola ptrInicio;
    ptrNodoCola ptrFin;
    ptrInicio = (ptrNodoCola)malloc(sizeof(NodoCola));
    ptrFin = (ptrNodoCola)malloc(sizeof(NodoCola));
    ptrInicio->ptrNodoSgte = ptrFin;
}
void encolar(ptrNodoCola ptrFin, int dato)
{
    ptrNodoCola ptrNuevoNodo = (ptrNodoCola)malloc(sizeof(NodoCola));
    ptrNuevoNodo->dato = dato;
    ptrFin->ptrNodoSgte = ptrNuevoNodo;
}
void dequeue(ptrNodoCola ptrInicio, ptrNodoCola ptrFin)
{
    ptrNodoCola ptrTemp;
    if (ptrInicio->ptrNodoSgte != ptrFin)
    {
        ptrTemp = ptrInicio;
        ptrInicio = ptrInicio->ptrNodoSgte;
    }
    free(ptrTemp);
}
int estaVacia(ptrNodoCola ptrInicio, ptrNodoCola ptrFin)
{
    int resultado = 0;
    if (ptrInicio->ptrNodoSgte == ptrFin)
    {
        resultado = 1;
    }
    return resultado;
}