#include <iostream>
#define LOG(x) std::cout << x << std::endl

typedef struct
{
    char nombre[30];
    int anio;
    int division;
    int promedio;
} TREG;

main(int argc, char const *argv[])
{
    TREG registro;
    FILE *archivo = fopen("alumnos", "r");
    int cont_anio_division[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cont_anio_division[i][j] = 0;
        }
    }

    while (!feof(archivo))
    {
        fscanf(archivo, "%c %d %d %d", registro.nombre, registro.anio, registro.division, registro.promedio);
        cont_anio_division[registro.anio - 1][registro.division - 1]++;
    }

    return 0;
}

/*funcion*/