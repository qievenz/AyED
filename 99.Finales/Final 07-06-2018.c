/* comentario */
#define MAX 9
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define LOG(x) printf(x)

//1.
typedef struct rNodoNombre
{
    char letra;
    struct rNodoNombre *ptrSiguiente;
} NodoNombre, *ptrNodoNombre;

typedef struct rNumeroAfortunado
{
    char dia[MAX];
    char color[MAX];
    char caracteristica[MAX];
} Afortunado;

Afortunado AFORTUNADOS[MAX];
char *DIAS[9] = {"Sabado", "Domingo", "Jueves", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Lunes"};
char *COLORES[9] = {"Negro", "Amarillo", "Blanco", "Rojo", "Verde", "Gris", "Violeta", "Celeste", "Azul"};
char *CARACTERISTICAS[9] = {"Emprended", "Pasivo", "Optimista", "Practico", "Inestable", "Confiable", "Culto", "Organizad", "Decente"};
//TEST
void cargarAfortunados();
//void CargarNombre(char vec[], int len);
ptrNodoNombre CargarNombre();
unsigned NumeroAfortunado(char vec[], int len);
void MostrarResultado(unsigned afortunado);

main(int argc, char const *argv[])
{
    cargarAfortunados();
    char nombre[50];
    //CargarNombre(nombre, 50);
    ptrNodoNombre nodo = CargarNombre();
    //NumeroAfortunado(nombre, MAX);
    MostrarResultado(NumeroAfortunado(nombre, 50));
    return 0;
}

void cargarAfortunados()
{
    for (int i = 0; i < MAX; i++)
    {
        strcpy(AFORTUNADOS[i].dia, DIAS[i]);
        strcpy(AFORTUNADOS[i].color, COLORES[i]);
        strcpy(AFORTUNADOS[i].caracteristica, CARACTERISTICAS[i]);
    }
}
//2.
/*
void CargarNombre(char vec[], int len)
{
    fgets(vec, sizeof(vec), stdin);
}
*/
ptrNodoNombre CargarNombre()
{
    ptrNodoNombre nuevo;
    ptrNodoNombre anterior = nuevo;
    ptrNodoNombre resultado = nuevo;
    char dato;
    printf("Ingrese letra a letra el nombre:\n");
    scanf("%c", dato);
    while (!feof(stdin))
    {
        nuevo = (ptrNodoNombre)malloc(sizeof(NodoNombre));
        nuevo->letra = dato;
        anterior->ptrSiguiente = nuevo;
        anterior = nuevo;
        scanf("%c", dato);
    }

    return resultado;
}
//3.
unsigned NumeroAfortunado(char vec[], int len)
{
    unsigned resultado = 0, temp, suma = 0, faltante;
    for (int i = 0; i < len; i++)
    {
        if (vec[i] == '\n')
        {
            break;
        }
        else
        {
            resultado += vec[i] - 'A' + 1;
            printf("LOG: %d\n", vec[i] - 'A' + 1);
        }
    }
    printf("Suma del nombre: %d\n", resultado);
    while (resultado > 9)
    {
        temp = resultado;
        suma = 0;
        while (temp != 0)
        {
            faltante = temp % 10;
            suma = suma + faltante;
            temp = temp / 10;
        }
        resultado = suma;
    }
    return resultado;
}
//4.
void MostrarResultado(unsigned afortunado)
{
    printf("Dia: %s\n", AFORTUNADOS[afortunado - 1].dia);
    printf("Color: %s\n", AFORTUNADOS[afortunado - 1].color);
    printf("Caracteristica: %s\n", AFORTUNADOS[afortunado - 1].caracteristica);
}