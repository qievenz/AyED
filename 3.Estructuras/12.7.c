/* Programa que mezcle dos listas ordenadas de enteros en una sola lista ordenada de enteros.
la funcion mezclar debe recibir apuntadores al primer nodo de cada lista y deovolver un apuntador
al primer nodo de la lista mezclada */
#include <stdio.h>
#include <stdlib.h>
#define LOG(x) printf(x)

typedef struct nodoLista
{
    int dato;
    struct nodoLista *ptrSiguiente;
} NodoLista, *ptrNodoLista;

ptrNodoLista mezclar(ptrNodoLista *ptrA, ptrNodoLista *ptrB);
void insertar(ptrNodoLista *ptrS, int valor);

main(int argc, char const *argv[])
{
    ptrNodoLista nodoA;
    nodoA = NULL;
    insertar(&nodoA, 1);
    insertar(&nodoA, 3);
    insertar(&nodoA, 4);
    insertar(&nodoA, 7);
    insertar(&nodoA, 9);

    ptrNodoLista nodoB;
    nodoB = NULL;
    insertar(&nodoB, 2);
    insertar(&nodoB, 5);
    insertar(&nodoB, 7);
    insertar(&nodoB, 8);
    insertar(&nodoA, 12);

    ptrNodoLista ptrMezcla;
    ptrMezcla = (ptrNodoLista)malloc(sizeof(NodoLista));
    ptrMezcla = mezclar(&nodoA, &nodoB);
    return 0;
}

ptrNodoLista mezclar(ptrNodoLista *ptrA, ptrNodoLista *ptrB)
{
    ptrNodoLista ptrResultado = NULL;
    ptrNodoLista ptrtemp;
    ptrNodoLista ptrActual;
    ptrNodoLista ptrSgte1;
    ptrNodoLista ptrSgte2;
    if ((*ptrA)->dato < (*ptrB)->dato)
    {
        ptrResultado = *ptrA;
        ptrSgte1 = (*ptrA)->ptrSiguiente;
        ptrSgte2 = *ptrB;
    }
    else
    {
        ptrResultado = *ptrB;
        ptrSgte2 = (*ptrB)->ptrSiguiente;
        ptrSgte1 = *ptrA;
    }
    ptrActual = ptrResultado;
    while (ptrSgte1 != NULL && ptrSgte2 != NULL)
    {
        if (ptrSgte1->dato < ptrSgte2->dato)
        {
            ptrActual->ptrSiguiente = ptrSgte1;
            ptrActual = ptrSgte1;
            ptrSgte1 = ptrSgte1->ptrSiguiente;
            if (ptrSgte1 == NULL && ptrSgte2 != NULL)
            {
                ptrActual->ptrSiguiente = ptrSgte2;
            }
        }
        else
        {
            ptrActual->ptrSiguiente = ptrSgte2;
            ptrActual = ptrSgte2;
            ptrSgte2 = ptrSgte2->ptrSiguiente;
            if (ptrSgte2 == NULL && ptrSgte1 != NULL)
            {
                ptrActual->ptrSiguiente = ptrSgte1;
            }
        }
    }
    return ptrResultado;
}

/* Inserta un nuevo valor dentro de la lista en orden  */
void insertar(ptrNodoLista *ptrS, int valor)
{
    ptrNodoLista ptrNuevo;    /* apuntador a un nuevo nodo */
    ptrNodoLista ptrAnterior; /* apuntador a un nodo previo de la lista */
    ptrNodoLista ptrActual;   /* apuntador al nodo actual de la lista */

    ptrNuevo = (NodoLista *)malloc(sizeof(NodoLista)); /* crea un nodo */

    if (ptrNuevo != NULL)
    {                                  /* es espacio disponible */
        ptrNuevo->dato = valor;        /* coloca el valor en el nodo */
        ptrNuevo->ptrSiguiente = NULL; /* el nodo no se liga a otro nodo */

        ptrAnterior = NULL;
        ptrActual = *ptrS;

        /* ciclo para localizar la ubicaci�n correcta en la lista */
        while (ptrActual != NULL && valor > ptrActual->dato)
        {
            ptrAnterior = ptrActual;             /* entra al ...   */
            ptrActual = ptrActual->ptrSiguiente; /* ... siguiente nodo */
        }                                        /* fin de while */

        /* inserta un nuevo nodo al principio de la lista */
        if (ptrAnterior == NULL)
        {
            ptrNuevo->ptrSiguiente = *ptrS;
            *ptrS = ptrNuevo;
        } /* fin de if */
        else
        { /* inserta un nuevo nodo entre ptrAnterior y ptrActual */
            ptrAnterior->ptrSiguiente = ptrNuevo;
            ptrNuevo->ptrSiguiente = ptrActual;
        } /* fin de else */

    } /* fin de if */
    else
    {
        printf("No se inserto %c. No hay memoria disponible.\n", valor);
    } /* fin de else */

} /* fin de la funci�n insertar */