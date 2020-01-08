/* dada una palabra como una sec de caracteres imprima en orden inverso */
#include <stdio.h>
#include <stdlib.h>
#define LOG(x) printf(x)

typedef struct nodoPila
{
    int dato;
    struct nodoPila *ptrSiguiente;
} NodoPila, *ptrNodoPila;

//MIV-1
void imprimirPalabraInverso(char cadena[], int max);
//MIV-2
void eliminarPrimerosCuatro(ptrNodoPila ptrTop, NodoPila valor);
//MIV-3
void insertarTercero(ptrNodoPila ptrTop, NodoPila valor);
//MIV-4
int existeValorEnPosicion(ptrNodoPila ptrTop, int valorX, int posicion);
//MIV-5
ptrNodoPila reemplazaXporY(ptrNodoPila ptrTop, int valorX, int valorY);
//MIV-6

int main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}
//MIV-1
void imprimirPalabraInverso(char cadena[], int max)
{
    for (int i = 0; i < max; i++)
    {
        printf(&cadena[max]);
    }
}
//MIV-2
void eliminarPrimerosCuatro(ptrNodoPila ptrTop, NodoPila valor)
{
    ptrNodoPila ptrTemp;
    ptrNodoPila ptrValor = (ptrNodoPila)malloc(sizeof(NodoPila));
    for (int i = 0; i < 4; i++)
    {
        ptrTemp = ptrTop;
        ptrTop = ptrTemp->ptrSiguiente;
        free(ptrTemp);
    }
    ptrValor->dato = valor.dato;
    ptrValor->ptrSiguiente = ptrTop;
    ptrTop = ptrValor;
}
//MIV-3
void insertarTercero(ptrNodoPila ptrTop, NodoPila valor)
{
    ptrNodoPila ptrValor = (ptrNodoPila)malloc(sizeof(NodoPila));
    ptrNodoPila ptrSegundo = ptrTop->ptrSiguiente;
    ptrNodoPila ptrTemp;
    ptrValor->dato = valor.dato;
    ptrTemp = ptrSegundo->ptrSiguiente;
    ptrValor->ptrSiguiente = ptrSegundo->ptrSiguiente;
    ptrSegundo->ptrSiguiente = ptrValor;
}
//MIV-4
int existeValorEnPosicion(ptrNodoPila ptrTop, int valorX, int posicion)
{
    int resultado = 0;
    int i = 0;
    ptrNodoPila ptrActual = ptrTop;
    while (ptrActual != NULL && i < posicion)
    {
        ptrActual = ptrActual->ptrSiguiente;
    }
    if (ptrActual->dato == valorX)
    {
        resultado = 1;
    }

    return resultado;
}
//MIV-5
ptrNodoPila reemplazaXporY(ptrNodoPila ptrTop, int valorX, int valorY)
{
    ptrNodoPila ptrResultado;
    ptrNodoPila ptrActual = ptrTop;
    while (ptrActual != NULL)
    {
        if (ptrActual->dato == valorX)
        {
            ptrActual->dato == valorY;
            ptrResultado = ptrActual;
        }
        ptrActual = ptrActual->ptrSiguiente;
    }
    return ptrResultado;
}