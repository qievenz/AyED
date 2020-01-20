/* comentario */
#include <stdio.h>
#include <stdlib.h>
#define LOG(x) printf(x)

typedef struct cliente
{
    int nroCarrito;
    struct cliente *ptrSiguiente;
} Cliente, *ptrCliente;

typedef struct caja
{
    int numeroCaja;
    float efectivo;
    int cantCuponesTC;
    int impTC;
    int cantCuponesTD;
    struct cliente *ptrClienteAsignado;
} Caja, *ptrCaja;

void queue(ptrCliente ptrFinal);
void unQueue(ptrCliente ptrInicial);

int main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}

ptrCaja CajasHabilitadas(FILE *archivo)
{
    Caja cajas[40];
    archivo = fopen("Cajas.dat", "r");
    for (int i = 0; i < 40; i++)
    {
        fscanf(archivo, "%d %d", &cajas[i].numeroCaja, &cajas[i].efectivo);
        cajas[i].ptrClienteAsignado = NULL;
    }
    fclose(archivo);
    return cajas;
}

void nuevoCliente(ptrCliente ptrFinal, int nroCarrito)
{
    ptrCliente ptrNuevo = (ptrCliente)malloc(sizeof(Cliente));
    ptrNuevo->nroCarrito = nroCarrito;
    ptrFinal->ptrSiguiente = ptrNuevo;
    ptrFinal = ptrNuevo;
}

void AtenderCliente(Caja cajas[], int nroCaja, ptrCliente ptrClienteInicio)
{
    cajas[nroCaja].ptrClienteAsignado = ptrClienteInicio;
    void calcularImportes(int nroCarrito, int efectivo, int tc, int td, int ticket);
}