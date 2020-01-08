/* comentario */
#include <stdio.h>
#include <stdlib.h>
#define LOG(x) printf(x)

typedef struct nodoInfraccion
{
    char patente[6];
    char fecha[6];
    int codigo;
    struct nodoInfraccion *ptrInfraccionSgte;
} NodoInfraccion, *ptrNodoInfraccion;

ptrNodoInfraccion leerArchivo(FILE *archivo);
void ordenarPorCodigoDescRepetidos(ptrNodoInfraccion ptrInicio);
void imprimirPatentes(ptrNodoInfraccion ptrInicio);

int main(int argc, char const *argv[])
{
    return 0;
}

ptrNodoInfraccion leerArchivo(FILE *archivo)
{
    ptrNodoInfraccion nuevoNodo;
    ptrNodoInfraccion ptrResultado = NULL;
    ptrNodoInfraccion ptrAnterior = NULL;
    fopen(archivo, "r");
    while (feof(archivo))
    {
        nuevoNodo = (ptrNodoInfraccion)malloc(sizeof(NodoInfraccion));
        fscanf(archivo, "%c %c %d", nuevoNodo->patente, nuevoNodo->fecha, &nuevoNodo->codigo);
        if (ptrAnterior != NULL)
        {
            ptrAnterior->ptrInfraccionSgte = nuevoNodo;
        }
        else
        {
            ptrResultado = nuevoNodo;
        }
        ptrAnterior = nuevoNodo;
    }
    return ptrResultado;
}
void ordenarPorCodigoDescRepetidos(ptrNodoInfraccion ptrInicio)
{
    ptrNodoInfraccion ptrPasada = NULL;
    ptrNodoInfraccion ptrComparacion = NULL;

    void intercambiar(ptrNodoInfraccion ptrElemento1, ptrNodoInfraccion ptrElemento2);
    int ordenado;
    int contador;
    do
    {
        ordenado = 0;
        contador = 1;
        ptrPasada = ptrInicio;
        while (ptrPasada->ptrInfraccionSgte != ptrComparacion)
        {
            if (ptrPasada->codigo < ptrPasada->ptrInfraccionSgte->codigo)
            {
                intercambiar(ptrPasada, ptrPasada->ptrInfraccionSgte);
                ordenado = 1;
            }
            if (ptrComparacion != NULL && ptrComparacion->codigo == ptrPasada->codigo && ptrComparacion->patente)
            {
                contador++;
            }
            ptrPasada = ptrPasada->ptrInfraccionSgte;
        }
        if (ptrComparacion != NULL && ptrComparacion->codigo == ptrPasada->codigo && ptrComparacion->patente)
        {
            contador++;
        }
        if (ptrComparacion != NULL && contador == 1)
        {
            //sacar el elemento de la lista
            ptrPasada->ptrInfraccionSgte = NULL;
            free(ptrComparacion);
        }
        ptrComparacion = ptrPasada;
    } while (ordenado);
}
void intercambiar(ptrNodoInfraccion ptrElemento1, ptrNodoInfraccion ptrElemento2)
{
    int tPatente = ptrElemento1->patente;
    int tFecha = ptrElemento1->fecha;
    int tCodigo = ptrElemento1->codigo;
    *ptrElemento1->patente = ptrElemento2->patente;
    *ptrElemento1->fecha = ptrElemento2->fecha;
    ptrElemento1->codigo = ptrElemento2->codigo;
    *ptrElemento2->patente = tPatente;
    *ptrElemento2->fecha = tFecha;
    ptrElemento2->codigo = tCodigo;
}
void imprimirPatentes(ptrNodoInfraccion ptrInicio)
{
    ptrNodoInfraccion ptrActual = ptrInicio;
    int codigoActual;
    while (ptrActual != NULL)
    {
        codigoActual = ptrActual->codigo;
        printf("Codigo de infraccion: %d\n", codigoActual);
        while (ptrActual != NULL && ptrActual->codigo == codigoActual)
        {
            printf("%c\n", ptrActual->patente);
            ptrActual = ptrActual->ptrInfraccionSgte;
        }
    }
}