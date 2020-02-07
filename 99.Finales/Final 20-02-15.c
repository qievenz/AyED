/* comentario */
#include <stdio.h>
#include <stdlib.h>
#define LOG(x) printf(x)
#define CANTJUGADORES 10
#define IDMIN 2

typedef struct gol
{
    unsigned jugadorId;
    unsigned partidoId;
    unsigned minuto;
} Gol;

int leerGol(FILE *archivo, Gol unGol);

int main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}

int getIndice(int unId, Gol arrGol[], int maxGol)
{
    int resultado;
    for (int i = 0; i < maxGol; i++)
    {
        if (arrGol[i].jugadorId == unId)
        {
            resultado = (i - IDMIN) / 2;
            break;
        }
    }
    return resultado;
}

int getId(int unIndice, Gol arrGol[], int maxGol)
{
    int resultado;
    resultado = 2 * arrGol[unIndice].jugadorId + IDMIN;
    return resultado;
}

void cargarDatosEnMemoria(Gol arrGol[], FILE *archivo)
{
    Gol golLectura;
    golLectura = leerGol(archivo);

}