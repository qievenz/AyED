/* Whatsapp */
#include <stdio.h>
#include <stdlib.h>

typedef struct representante
{
    char nombre[15];
    int lista;
    double votos;
} Representante;

Representante Docentes[15];
Representante Graduados[4];
Representante Estudiantes[6];

Representante *GenrarListaConsejerosDocentes(Representante docentes[15]);
void OrdenarVector(Representante lista[], int tam); //ordena por votos de forma decreciente

main(int argc, char const *argv[])
{
    Docentes[0].votos = 50.0;
    Docentes[0].lista = 1;
    Docentes[1].votos = 25.0;
    Docentes[1].lista = 1;
    Docentes[2].votos = 16.6;
    Docentes[2].lista = 1;
    Docentes[3].votos = 12.5;
    Docentes[3].lista = 1;
    Docentes[4].votos = 10.0;
    Docentes[4].lista = 1;
    Docentes[5].votos = 35.0;
    Docentes[5].lista = 2;
    Docentes[6].votos = 17.5;
    Docentes[6].lista = 2;
    Docentes[7].votos = 11.6;
    Docentes[7].lista = 2;
    Docentes[8].votos = 8.7;
    Docentes[8].lista = 2;
    Docentes[9].votos = 7.0;
    Docentes[9].lista = 2;
    Docentes[10].votos = 15.0;
    Docentes[10].lista = 3;
    Docentes[11].votos = 7.5;
    Docentes[11].lista = 3;
    Docentes[12].votos = 5.0;
    Docentes[12].lista = 3;
    Docentes[13].votos = 3.7;
    Docentes[13].lista = 3;
    Docentes[14].votos = 3.0;
    Docentes[14].lista = 3;
    GenrarListaConsejerosDocentes(Docentes);
    return 0;
}

Representante *GenrarListaConsejerosDocentes(Representante docentes[15])
{
    int resultado_tam = 5;
    Representante resultado[resultado_tam];
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (docentes[i].votos > resultado[j].votos)
            {
                resultado[j] = docentes[i];
            }
        }
    }
    //    OrdenarVector(resultado, resultado_tam);
    return resultado;
}