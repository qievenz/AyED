/* Un pgm que inserte en orden 25 enteros al azar, del 0 al 100, en una lista ligada.
El pgm debe calcular la suma de los elementos y el promedio en pto flotante. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LOG(x) printf(x)
#define MAX 25

typedef struct nodoLista
{
    int dato;
    struct nodoLista *ptrSiguiente;
} NodoLista, *ptrNodoLista, arrNodoLista[MAX];

int sumar(ptrNodoLista ptrA);
float promediar(ptrNodoLista ptrA);
void insertatOrdenado(ptrNodoLista ptrA, int cant);
void ordenarLista(ptrNodoLista ptrA, int cant);

int main(int argc, char const *argv[])
{
    arrNodoLista arrNodos;

    insertatOrdenado(arrNodos, MAX);

    //printf("%d", sumar(arrNodos));
    //printf("%f", promediar(arrNodos));

    return 0;
}
//Generar el random
//compararlo con los demas
//recorrer hasta que sea menor o null e insertarlo a continuacion
void insertatOrdenado(ptrNodoLista ptrA, int cant)
{
    ptrNodoLista anterior;
    ptrNodoLista actual = ptrA;
    ptrNodoLista recorro2;
    int random = rand() % 101;
    actual->dato = random;
    int cantInsertados = 1;
    while (cantInsertados < cant)
    {
        actual++;
        random = rand() % 101;
        recorro2 = ptrA;
        for (int i = 0; i < cantInsertados; i++)
        {
            if (random < recorro2->dato)
            {
                /* code */
            }

            recorro2++;
        }

        actual->dato = random;
        cantInsertados++;
    }
}
void ordenarLista(ptrNodoLista ptrA, int cant)
{
    ptrNodoLista ptrTemp;
    ptrNodoLista ptrI;
    ptrNodoLista ptrJ;
    for (int i = 0; i < cant; i++)
    {
        ptrI = ptrA + i;
        for (int j = 0; j < cant; j++)
        {
            if (ptrI->dato > ptrJ->dato)
            {
                ptrTemp = ptrJ;
            }
        }
    }

    /*
    ptrNodoLista ptrTemp = NULL;
    for (int i = 0; i < MAX; i++)
    {
        int j = 0;
        ptrTemp = &ptrA[i];
        while (j > 0 && ptrTemp->dato < (&ptrA[j - 1])->dato)
        {
            ptrA[j] = ptrA[j - 1];
            j--;
        }
        ptrA[j] = ptrTemp;
    }*/
}