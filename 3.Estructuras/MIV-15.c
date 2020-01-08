#include <stdio.h>
#include <stdlib.h>
#define LOG(x) printf(x)

typedef struct nodoInscripcion
{
    int codigo;
    int legajo;
    struct nodoInscripcion *ptrSiguiente;
} NodoInscripcion, *ptrNodoInscripcion;

ptrNodoInscripcion apareo(ptrNodoInscripcion const ptrA, ptrNodoInscripcion const ptrB);
ptrNodoInscripcion apareo(ptrNodoInscripcion const ptrA, ptrNodoInscripcion const ptrB)
{
    ptrNodoInscripcion ptrResultado = NULL;
    ptrNodoInscripcion nodo;
    ptrNodoInscripcion ptrAnterior = NULL;
    ptrNodoInscripcion ptrAA = ptrA;
    ptrNodoInscripcion ptrBB = ptrB;
    //Se suponen que ambas listas tienen la misma cantidad de nodos
    while (ptrAA != NULL)
    {
        if (ptrAA->codigo == ptrBB->codigo && ptrAA->legajo == ptrBB->legajo)
        {
            nodo = malloc(sizeof(ptrNodoInscripcion));
            if (ptrAnterior != NULL)
            {
                ptrAnterior->ptrSiguiente = nodo;
            }
            else
            {
                ptrResultado = ptrAnterior;
            }

            nodo->codigo = ptrAA->codigo;
            nodo->legajo = ptrAA->legajo;
            ptrAnterior = nodo;
        }
    }

    return ptrResultado;
}