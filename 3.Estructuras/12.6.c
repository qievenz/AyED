/*Un pgm que concatene dos listas ligadas de caracteres.
Debe incluir la funcion cancatenar que tome como argumentos apuntadores a ambas listas, 
y que concatene la segunda a la primera.
*/
#include <stdio.h>
#include <stdlib.h>
#define LOG(x) std::cout << x << std::endl

typedef struct nodoLista
{
    char caracter;
    struct nodoLista *ptrSiguiente;
} NodoLista, *ptrNodoLista;

ptrNodoLista concatenar(ptrNodoLista *ptrA, ptrNodoLista *ptrB);

int main(int argc, char const *argv[])
{
    ptrNodoLista nodoA;
    nodoA = (ptrNodoLista)malloc(sizeof(NodoLista));
    nodoA->caracter = 'F';
    nodoA->ptrSiguiente = NULL;
    ptrNodoLista nodoB;
    nodoB = (ptrNodoLista)malloc(sizeof(NodoLista));
    nodoB->caracter = 'h';
    nodoB->ptrSiguiente = NULL;
    ptrNodoLista nodoConcatenado;
    nodoConcatenado = (ptrNodoLista)malloc(sizeof(NodoLista));
    nodoConcatenado = concatenar(&nodoA, &nodoB);
    return 0;
}

ptrNodoLista concatenar(ptrNodoLista *ptrA, ptrNodoLista *ptrB)
{
    ptrNodoLista ptrNuevo;
    ptrNuevo = (ptrNodoLista)malloc(sizeof(NodoLista));
    ptrNuevo->caracter = (*ptrA)->caracter;
    ptrNuevo->ptrSiguiente = (*ptrB);
    free(*ptrA);
    free(*ptrB);
    return ptrNuevo;
}