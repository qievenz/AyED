#include <iostream>
#define LOG(x) std::cout << x << std::endl
#define MAXIMO 7

void mostrar_sumatoria_diagonal(int matriz[][MAXIMO]);
void mostrar_sumatoria_fila(int matriz[][MAXIMO]);
void mostrar_sumatoria_columna(int matriz[][MAXIMO]);

int main(int argc, char const *argv[])
{
    int matriz[MAXIMO][MAXIMO];
    for (int i = 0; i < MAXIMO; i++)
    {
        for (int j = 0; j < MAXIMO; j++)
        {
            matriz[i][j] = (rand() % 9) + 1;
        }
    }
    mostrar_sumatoria_diagonal(matriz);
    mostrar_sumatoria_fila(matriz);
    mostrar_sumatoria_columna(matriz);
    return 0;
}

void mostrar_sumatoria_diagonal(int matriz[][MAXIMO])
{
    int sumatoria = 0;
    for (int i = 0; i < MAXIMO; i++)
    {
        sumatoria += matriz[i][i];
    }
    printf("Sumatoria de la diagonal: %d\n", sumatoria);
}

void mostrar_sumatoria_fila(int matriz[][MAXIMO])
{
    int fila, sumatoria;
    printf("Ingrese la fila: ");
    scanf("%d", &fila);
    while (!feof(stdin) && fila < 7)
    {
        sumatoria = 0;
        for (int i = 0; i < MAXIMO; i++)
        {
            sumatoria += matriz[fila][i];
        }
        printf("Sumatoria: %d\n", sumatoria);
        printf("Ingrese la fila: ");
        scanf("%d", &fila);
    }
}

void mostrar_sumatoria_columna(int matriz[][MAXIMO])
{
    int columna, sumatoria;
    printf("Ingrese la columna: ");
    scanf("%d", &columna);
    while (!feof(stdin) && columna < 7)
    {
        sumatoria = 0;
        for (int i = 0; i < MAXIMO; i++)
        {
            sumatoria += matriz[i][columna];
        }
        printf("Sumatoria: %d\n", sumatoria);
        printf("Ingrese la columna: ");
        scanf("%d", &columna);
    }
}