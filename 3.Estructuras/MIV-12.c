/* comentario */
#include <stdio.h>
#include <stdlib.h>
#define LOG(x) printf(x)

typedef struct nodoLista
{
	char dato;
	struct nodoLista *ptrSiguiente;
} NodoLista, *ptrNodoLista;

int cantNodos(ptrNodoLista *ptrA);

int main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}

int cantNodos(ptrNodoLista *ptrA)
{
	int resultado = 0;
	ptrNodoLista ptrActual = *ptrA;
	while(ptrActual != NULL)
	{
		resultado++;
		ptrActual = ptrActual->ptrSiguiente;
	}
	return resultado;
}
