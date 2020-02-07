/* comentario */
#define MAX 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define LOG(x) printf(x)

typedef struct rNumeroAfortunado
{
    char dia[MAX];
    char color[MAX];
    char caracteristica[MAX];
} NumeroAfortunado;

NumeroAfortunado AFORTUNADOS[MAX];
char DIAS[9][MAX] = {"Sabado", "Domingo", "Jueves", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Lunes"};
char COLORES[9][MAX] = {"Negro", "Amarillo", "Blanco", "Rojo", "Verde", "Gris", "Violeta", "Celeste", "Azul"};
char CARACTERISTICAS[MAX][MAX] = {"Emprended", "Pasivo", "Optimista", "Practico", "Inestable", "Confiable", "Culto", "Organizad", "Decente"};
void cargarAfortunados(NumeroAfortunado AFORTUNADOS[]);
void CargarNombre(char vec[], int len);

main(int argc, char const *argv[])
{
    cargarAfortunados(AFORTUNADOS);
    char nombre[10];
    CargarNombre(nombre, 10);
    return 0;
}

void cargarAfortunados(NumeroAfortunado AFORTUNADOS[])
{
    for (int i = 0; i < MAX; i++)
    {
        strcpy(AFORTUNADOS[i].dia, DIAS[i]);
        strcpy(AFORTUNADOS[i].color, COLORES[i]);
        strcpy(AFORTUNADOS[i].dia, CARACTERISTICAS[i]);
    }
}

void CargarNombre(char vec[], int len)
{
    fgets(vec, sizeof(vec), stdin);
}