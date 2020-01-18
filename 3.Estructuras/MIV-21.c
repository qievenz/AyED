//Una empresa de micros de larga distancia necesita armar  la frecuencia necesaria para satisfacer la demanda de pasajeros.  En un archivo se tienen  las paradas-estaciones  con sus nombres  junto con los movimientos de pasajeros en lo que hace a  ascenso  y descenso en cada una de ellas en ambas direcciones.
//Un micro de 50 asientos sale desde el origen al destino pasando por las paradas y retorna  al origen.
//Indicar en que estaciones y sentido se verá saturado.
#include <stdio.h>
#include <stdlib.h>
#define LOG(x) printf(x)

typedef struct estacion
{
    char nombre[30];
    char direccion[1]; //Hacia el destino: 'D'. Hacia el origen: 'O'
    int cantAscenso;
    int cantDescenso;
    struct estacion *ptrSiguiente;
} Estacion, *ptrEstacion;

int main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}

void imprimirDondeSeSatura(ptrEstacion ptrInicial)
{
    int totalAsientos = 50;
    int cantPasajeros = 0;
    ptrEstacion ptrEstacionActual = ptrInicial;
    while (ptrEstacionActual != NULL)
    {
        cantPasajeros = cantPasajeros + ptrEstacionActual->cantAscenso - ptrEstacionActual->cantDescenso;
        if (cantPasajeros > totalAsientos)
        {
            printf("Saturacion en estacion: %s\n", ptrEstacionActual->nombre);
            printf("Cantidad de pasajeros: %d\n", cantPasajeros);
            if (ptrEstacionActual->direccion[0] == 'D')
            {
                printf("Direccion: llendo al destino\n");
            }
            else
            {
                printf("Direccion: llendo al origen\n");
            }
        }
        ptrEstacionActual = ptrEstacionActual->ptrSiguiente;
    }
}