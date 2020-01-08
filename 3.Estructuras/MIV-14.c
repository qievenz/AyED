/*una funcion quie dadp un codigo de materia y una lista enlazada de inscripciones 
ordenada por codigo de materia, cuyos nodos contienen el nro d legajo y coodigo de materia, 
genere otra lista ordenada por legajo que contenga los legajos de los alumnos 
que se inscribieron en dicha materia*/

#include <stdio.h>
#include <stdlib.h>
#define LOG(x) printf(x)

typedef struct nodoInscripcion
{
    int codigo;
    int legajo;
    struct nodoInscripcion *ptrSiguiente;
} NodoInscripcion, *ptrNodoInscripcion;

ptrNodoInscripcion coiparPtr(ptrNodoInscripcion ptrA);
ptrNodoInscripcion ordenaLegajosMateria(ptrNodoInscripcion const ptrA, int codigoMateria);

int main(int argc, char const *argv[])
{
    NodoInscripcion nodo1;
    NodoInscripcion nodo2;
    NodoInscripcion nodo3;
    nodo1.codigo = 1;
    nodo2.codigo = 2;
    nodo3.codigo = 3;
    nodo1.legajo = 2;
    nodo2.legajo = 3;
    nodo3.legajo = 1;
    nodo1.ptrSiguiente = &nodo2;
    nodo2.ptrSiguiente = &nodo3;
    nodo3.ptrSiguiente = NULL;

    return 0;
}

ptrNodoInscripcion coiparPtr(ptrNodoInscripcion ptrA)
{
    ptrNodoInscripcion ptrResultado = NULL;
    ptrNodoInscripcion ptrNodo = NULL;
    ptrNodoInscripcion ptrAnterior = NULL;
    ptrNodoInscripcion ptrCopia = ptrA;
    while (ptrCopia != NULL)
    {
        ptrNodo = (ptrNodoInscripcion)malloc(sizeof(NodoInscripcion));

        if (ptrAnterior != NULL)
        {
            ptrAnterior->ptrSiguiente = ptrNodo;
        }
        else
        {
            ptrResultado = ptrNodo;
        }

        ptrNodo->codigo = ptrCopia->codigo;
        ptrNodo->legajo = ptrCopia->legajo;

        ptrAnterior = ptrNodo;
        ptrCopia = ptrCopia->ptrSiguiente;
    }
    ptrAnterior->ptrSiguiente = NULL;
    return ptrResultado;
}

ptrNodoInscripcion ordenaLegajosMateria(ptrNodoInscripcion const ptrA, int codigoMateria)
{
    ptrNodoInscripcion ptrCopia;
    ptrCopia = coiparPtr(ptrA);
    ptrNodoInscripcion ptrPasada = NULL;
    ptrNodoInscripcion ptrComparacion = NULL;

    void intercambiar(ptrNodoInscripcion ptrElemento1, ptrNodoInscripcion ptrElemento2);
    int ordenado;
    do
    {
        ordenado = 0;
        ptrPasada = ptrCopia;
        while (ptrPasada->ptrSiguiente != ptrComparacion)
        {
            if (ptrPasada->legajo > ptrPasada->ptrSiguiente->legajo)
            {
                intercambiar(ptrPasada, ptrPasada->ptrSiguiente);
                ordenado = 1;
            }
            ptrPasada = ptrPasada->ptrSiguiente;
        }
        ptrComparacion = ptrPasada;
    } while (ordenado);
    return ptrCopia;
}
void intercambiar(ptrNodoInscripcion ptrElemento1, ptrNodoInscripcion ptrElemento2)
{
    int tCodigo = ptrElemento1->codigo;
    int tLegajo = ptrElemento1->legajo;
    ptrElemento1->codigo = ptrElemento2->codigo;
    ptrElemento1->legajo = ptrElemento2->legajo;
    ptrElemento2->codigo = tCodigo;
    ptrElemento2->legajo = tLegajo;
}
