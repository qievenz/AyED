/* Ej. MIV-19: Dado el siguiente enunciado
/*Una biblioteca necesita un programa que efectúe las altas en el archivo maestro de libros. Para ello cuenta con:
/*a) LIBROS.dat, archivo maestro de libros ordenado por código de libro, con un registro por cada libro, con el siguiente diseño:
/*a.1 código de libro (8 caracteres)
/*a.2  título del libro (30 caract)
/*a.3 apellido del autor (15 caracteres)                         
/*a.4 cantidad de ejemplares (2 dígitos)
/*a.5 nacionalidad  (6 dígitos)
/*a.6 otros datos (100 caracteres)
/*
/*b) NOVEDADES.dat, archivo con los libros a dar de alta  sin ningún orden, con el mismo diseño del archivo maestro.
/*
/*Se pide realizar la metodología necesaria para que el programa:
/*1) Genere un nuevo archivo LIBROSACT.dat, con el mismo diseño y orden que el maestro y con las altas incorporadas. 
/*
/*2) Emitir el siguiente listado, agrupado por nacionalidad y ordenado ascendente por cantidad total de autores:
/*              Nacionalidad...................................   Cantidad Total de autores: 999
/*		Apellido del Autor             Cantidad total de títulos  
/*		……......................	                    99
/*
/* Recursos y Restricciones: 
/*    • Optimización: dado que el uso de ciclos afecta el tiempo de ejecución de un proceso, se evaluará la eficiencia en el uso de los mismos.
/*    • Máximo de Nacionalidades: 100
/*    • Memoria para arrays: 1.000 bytes.
/*    • Memoria dinámica:  nodo de 17 bytes * cantidad de registros del archivo de novedades + nodo de 21 bytes * cantidad de autores.
/*    • Memoria en disco: solo para la grabación del nuevo archivo
/*    • Accesos a disco: 2 accesos a cada registro de Novedades, un solo recorrido del archivo de Libros y al nuevo archivo-*/
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