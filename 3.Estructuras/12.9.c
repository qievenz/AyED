/* Genere una lista ligada de 10 caracteres 
y que despues genere una copia de la lista en orden inverso */
#include <stdio.h>
#include <stdlib.h>
#define LOG(x) printf(x)
#define MAX 4

typedef struct nodoLista
{
    char caracter;
    struct nodoLista *ptrSiguiente;
} NodoLista, *ptrNodoLista;

void imprimirListaNodo(ptrNodoLista ptrA);

int main(int argc, char const *argv[])
{
    //ptrNodoLista nodoInicial;
    NodoLista arrNodos[MAX];
    //ptrNodoLista nodo = (ptrNodoLista)malloc(sizeof(NodoLista));
    //nodoInicial = nodo;
    //ptrNodoLista nodoAnt = NULL;
    char car;
    for (int i = 0; i < MAX; i++)
    {
        scanf(" %c", &car);
        //if (nodoAnt != NULL)
        //{
        //arrNodos[i].caracter = car;
        //nodoAnt->ptrSiguiente = nodo;
        //}
        //nodo->caracter = car;
        //nodo->ptrSiguiente = NULL;
        //nodoAnt = nodo;
        //nodo = (ptrNodoLista)malloc(sizeof(NodoLista));
        arrNodos[i].caracter = car;
        if (i == MAX - 1)
        {
            arrNodos[i].ptrSiguiente = NULL;
        }
        else
        {
            arrNodos[i].ptrSiguiente = arrNodos + i + 1;
        }

        //arrNodos[i].ptrSiguiente = &arrNodos + 1;
    }
    imprimirListaNodo(arrNodos);
    //ptrNodoLista nodoInverso = (ptrNodoLista)malloc(sizeof(NodoLista));
    //nodoInverso = &nodo[MAX - 1];
    NodoLista arrInverso[MAX];
    for (int i = 0; i < MAX; i++)
    {
        //nodoInverso[i].caracter = nodo[MAX - i - 1].caracter;
        //nodoInverso[i].ptrSiguiente = &nodo[MAX - i - 1];
        //nodo = (ptrNodoLista)malloc(sizeof(NodoLista));
        arrInverso[i].caracter = arrNodos[MAX - i - 1].caracter;
        if (i == MAX - 1)
        {
            arrInverso[i].ptrSiguiente = NULL;
        }
        else
        {
            arrInverso[i].ptrSiguiente = arrInverso + i + 1;
        }
    }
    imprimirListaNodo(arrInverso);
    return 0;
}

void imprimirListaNodo(ptrNodoLista ptrA)
{
    printf("Iprimiendo: %d\n", ptrA);
    ptrNodoLista ptr = ptrA;
    while (ptr != NULL)
    {
        printf("Memoria actual: %d\tValor: %c\tMemoria siguiente: %d\n", ptr, ptr->caracter, ptr->ptrSiguiente);
        ptr = ptr->ptrSiguiente;
    }
}