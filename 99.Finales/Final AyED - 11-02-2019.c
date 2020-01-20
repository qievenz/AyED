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
    float impTC;
    int cantCuponesTD;
    float impTD;
    int cantTickets;
    float impTickets;
    struct cliente *ptrClienteAsignado;
} Caja, *ptrCaja;

typedef struct carrito
{
    float efectivo;
    float impTC;
    float impTD;
    float impTickets;
} Carrito;

void queue(ptrCliente ptrFinal);
void unQueue(ptrCliente ptrInicial);
ptrCaja CajasHabilitadas(FILE *archivo);
void nuevoCliente(ptrCliente ptrInicio, ptrCliente ptrFinal, int nroCarrito);
void AtenderCliente(Caja cajas[], int nroCaja, ptrCliente ptrClienteInicio);
void reasignarCaja(int nroCajaActual, int nroCajaDestino, Caja cajas[]);

int main(int argc, char const *argv[])
{
    /*Pruebas*/
    ptrCliente ptrClientesInicio = NULL;
    ptrCliente ptrClientesFinal = NULL;
    nuevoCliente(ptrClientesInicio, ptrClientesFinal, 1);
    return 0;
}
//2.
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
//3.
void nuevoCliente(ptrCliente ptrInicio, ptrCliente ptrFinal, int nroCarrito)
{
    ptrCliente ptrNuevo = (ptrCliente)malloc(sizeof(Cliente));
    ptrNuevo->nroCarrito = nroCarrito;
    if (ptrInicio == NULL && ptrFinal == NULL)
    {
        ptrInicio = ptrNuevo;
        ptrFinal = ptrNuevo;
    }
    else
    {
        ptrFinal->ptrSiguiente = ptrNuevo;
        ptrFinal = ptrNuevo;
    }
}
//4.
void AtenderCliente(Caja cajas[], int nroCaja, ptrCliente ptrClienteInicio)
{
    ptrCaja ptrCajaAtencion = cajas + nroCaja + 1;
    ptrCajaAtencion->ptrClienteAsignado = ptrClienteInicio;
    Carrito calcularImportes(int nroCarrito);
    Carrito carritoCliente;
    //carritoCliente = calcularImportes(ptrClienteInicio->nroCarrito);
    ptrCajaAtencion->efectivo = ptrCajaAtencion->efectivo + carritoCliente.efectivo;
    ptrCajaAtencion->impTC = ptrCajaAtencion->impTC + carritoCliente.impTC;
    ptrCajaAtencion->impTD = ptrCajaAtencion->impTD + carritoCliente.impTD;
    ptrCajaAtencion->impTickets = ptrCajaAtencion->impTickets + carritoCliente.impTickets;
}
//5.
void reasignarCaja(int nroCajaActual, int nroCajaDestino, Caja cajas[])
{
    cajas[nroCajaDestino].ptrClienteAsignado = cajas[nroCajaActual].ptrClienteAsignado;
    cajas[nroCajaActual].ptrClienteAsignado = NULL;
}