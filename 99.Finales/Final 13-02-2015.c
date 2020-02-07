/* comentario */
#include <stdio.h>
#include <stdlib.h>
//#define LOG(x) printf(x)

typedef struct rNomina
{
    int idJugador;
    char nombre[50];
    int fecha;
    char pais[50];
    int cantGoles;
} Nomina;

typedef struct nodoNomina
{
    Nomina info;
    struct ptrNodoNomina *ptrSiguiente;
} NodoNomina, *ptrNodoNomina;

typedef struct rSeleccion
{
    int idJugador;
    char pais[50];
} Seleccion;

typedef struct nodoSeleccion
{
    Seleccion info;
    struct ptrNodoSeleccion *ptrSiguiente;
} NodoSeleccion, *ptrNodoSeleccion;

void cargarDatosEnMemoria(FILE *archivoNomina, FILE *archivoSeleccion, ptrNodoSeleccion ptrSeleccion, ptrNodoNomina ptrNomina);
//2. bool
int jugoEnOtraSeleccion(ptrNodoSeleccion *ptrNodoInicio, int idJugador);

int main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}

void cargarDatosEnMemoria(FILE *archivoNomina, FILE *archivoSeleccion, ptrNodoSeleccion ptrSeleccion, ptrNodoNomina ptrNomina)
{
    ptrSeleccion = NULL;
    ptrNodoNomina ptrNominaActual;
    ptrNodoNomina ptrNominaAnterior;
    ptrNomina = NULL;
    archivoNomina = fopen("Nomina.dat", "r");
    archivoSeleccion = fopen("Seleccion.dat", "r");
    Nomina nominaLeido;
    fscanf(archivoNomina, "%d %s %d %s %d", &nominaLeido.idJugador, nominaLeido.nombre, &nominaLeido.fecha, &nominaLeido.cantGoles);
    while (!feof(archivoNomina))
    {
        ptrNominaActual = (ptrNodoNomina)malloc(sizeof(NodoNomina));
        ptrNominaActual->info = nominaLeido;
        if (ptrNomina == NULL)
        {
            ptrNomina = ptrNominaActual;
        }
        else
        {
            ptrNominaAnterior->ptrSiguiente = ptrNominaActual;
            ptrNominaAnterior = ptrNominaActual;
        }

        fscanf(archivoNomina, "%d %s %d %s %d", &nominaLeido.idJugador, nominaLeido.nombre, &nominaLeido.fecha, &nominaLeido.cantGoles);
    }
}

//3.
void puedeSerCitado()