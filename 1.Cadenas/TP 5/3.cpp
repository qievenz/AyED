#include <iostream>
#define TAMANIO 4

//Prototipo
int maximo(int *array, int tam);

int main()
{
    int arr[TAMANIO] = {0, 3, -5, 4};
    int a = maximo(arr, TAMANIO);
    return 0;
}

int maximo(int *array, int tam)
{
    int resultado = 0;
    for (int i = 0; i < tam; i++)
    {
        if (array[i] > resultado)
        {
            resultado = array[i];
        }
    }

    return resultado;
}