/*      Trabajo Practico 2 - Algoritmos y estructura de datos
 * 
 * Alumno:  Velazquez Ivan
 * Legajo:  147.300-1
 * Curso:   K1094
 * 
 * 
 * 
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Tregistro
{
    unsigned long codigo;
    unsigned short modelo;
    int cantidad_stock;
    unsigned int fecha;
    float precio;
    char descripcion[20];
};

struct Tinfo
{
    unsigned long codigo;
    unsigned short modelo;
};

struct Tnodo
{
    struct Tinfo info;
    struct Tnodo *sgt;
};

typedef Tnodo *pNodo;
typedef Tnodo *Lista;

//* Verifica que la lista no este vacia
int ListaVacia(Lista lista)
{
    return (lista == NULL);
}

//* Inserta un nuevo nodo en la lista
void Insertar(Lista *lista, Tinfo v)
{
    pNodo nuevo, anterior;

    /* Crear un nodo nuevo */
    nuevo = (pNodo)malloc(sizeof(Tnodo));
    nuevo->info = v;

    /* Si la lista está vacía */
    if (ListaVacia(*lista) || (*lista)->info.modelo > v.modelo)
    {
        /* Añadimos la lista a continuación del nuevo nodo */
        nuevo->sgt = *lista;
        /* Ahora, el comienzo de nuestra lista es en nuevo nodo */
        *lista = nuevo;
    }
    else
    {
        /* Buscar el nodo de valor menor a v */
        anterior = *lista;
        /* Avanzamos hasta el último elemento o hasta que el siguiente tenga 
         un valor mayor que v */
        while (anterior->sgt && anterior->sgt->info.modelo <= v.modelo)
            anterior = anterior->sgt;
        /* Insertamos el nuevo nodo después del nodo anterior */
        nuevo->sgt = anterior->sgt;
        anterior->sgt = nuevo;
    }
}

//* Ordena la lista por codigo de producto
void ordenarLista(Lista lista)
{
    Lista actual, siguiente;
    Tinfo t;

    actual = lista;
    while (actual->sgt != NULL)
    {
        siguiente = actual->sgt;
        while (siguiente != NULL)
        {
            if (actual->info.codigo > siguiente->info.codigo)
            {
                t = siguiente->info;
                siguiente->info = actual->info;
                actual->info = t;
            }
            siguiente = siguiente->sgt;
        }
        actual = actual->sgt;
        siguiente = actual->sgt;
    }
}

//* Imprime por pantalla el archivo ordenado
void MostrarLista(Lista lista, FILE *archivo)
{

    pNodo nodo = lista;
    struct Tregistro reg;
    fseek(archivo, 0, SEEK_SET);
    if (ListaVacia(lista))
        printf("Lista vacía\n");
    else
    {
        printf("     LISTADO RESULTANTE\n");
        printf("     ******************\n");
        printf("Alumno:  Ivan Velazquez\n");
        printf("Curso:   K1094\n");
        printf("Legajo:  147.300-1\n");
        printf("\nCodigo\t\t\tModelo\t\tFecha\t\t\tStock\t\t\t    Precio\t\t\tDescripcion\n");
        printf("******\t\t\t******\t\t*****\t\t\t*****\t\t    ******\t\t\t***********\n");
        fread(&reg, sizeof(struct Tregistro), 1, archivo);
        while (nodo)
        {

            if (nodo->info.codigo == reg.codigo && nodo->info.modelo == reg.modelo)
            {
                printf("%lu   \t%u   \t\t%i   \t\t%u   \t%f   \t\t%s\n", reg.codigo,
                       reg.modelo,
                       reg.cantidad_stock,
                       reg.fecha,
                       reg.precio,
                       reg.descripcion);
                nodo = nodo->sgt;
                fseek(archivo, 0, SEEK_SET);
            }
            else
                fread(&reg, sizeof(struct Tregistro), 1, archivo);
        }
    }
}

/*	PROGRAMA PRINCIPAL	*/
int main(int argc, char *argv[])
{
    Lista lista = NULL;
    struct Tregistro reg;
    struct Tinfo info_aux;

    FILE *archivo;
    archivo = fopen("/home/ivan/repuestos.dat", "r");
    fread(&reg, sizeof(struct Tregistro), 1, archivo);

    int cantidad_nodos = 0;
    while (!feof(archivo))
    {
        info_aux.codigo = reg.codigo;
        info_aux.modelo = reg.modelo;
        Insertar(&lista, info_aux); /*Inserta el nodo en la lista ordenando por modelo*/
        fread(&reg, sizeof(struct Tregistro), 1, archivo);
        cantidad_nodos += 1;
    }
    ordenarLista(lista);
    MostrarLista(lista, archivo);
    fclose(archivo);
    return 0;
}