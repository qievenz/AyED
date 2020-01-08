#include <iostream>
#include <stdlib.h>
#define LOG(x) std::cout << x << std::endl

typedef struct
{
    int articulo;
    float precio;
} TREG;

float precio(TREG vec[], int i, int articulo);
void leer_articulos(TREG vec[], int cant_registros);
void buscar_articulo(TREG vec[], int cant_registros);
void grabar_articulos(int cant_registros);

int main(int argc, char const *argv[])
{
    int MAX_REGISTROS = 3;
    TREG vector[MAX_REGISTROS];
    grabar_articulos(MAX_REGISTROS);
    leer_articulos(vector, MAX_REGISTROS);
    buscar_articulo(vector, MAX_REGISTROS);
    return 0;
}

void leer_articulos(TREG vec[], int cant_registros)
{
    FILE *archivo = fopen("PumaNike.bin", "r");
    for (int i = 0; i < cant_registros; i++)
    {
        fscanf(archivo, "%d%f", &vec[i].articulo, &vec[i].precio);
    }
    fclose(archivo);
}

void buscar_articulo(TREG vec[], int cant_registros)
{
    int id_articulo;
    printf("Ingrese id del articulo:\n");
    scanf("%d", &id_articulo);
    while (id_articulo != 0)
    {
        float precio = 0;
        for (int i = 0; i < cant_registros; i++)
        {
            if (id_articulo == vec[i].articulo)
            {
                precio = vec[i].precio;
                break;
            }
        }
        if (precio != 0)
        {
            printf("Precio:\n$%f\n", precio);
        }
        else
        {
            printf("Articulo inexistente\n");
        }
        scanf("%d", &id_articulo);
    }
}

void grabar_articulos(int cant_registros)
{
    FILE *archivo = fopen("PumaNike.bin", "w");
    TREG elemento;
    for (int i = 0; i < cant_registros; i++)
    {
        printf("Articulo:\t");
        scanf("%d", &elemento.articulo);
        printf("Precio:\t");
        scanf("%f", &elemento.precio);
        fprintf(archivo, "%d %f\n", elemento.articulo, elemento.precio);
    }
    fclose(archivo);
}