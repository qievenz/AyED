#include <iostream>

int negativos(int *arr, int tam)
{
    int resultado = 0;
    for (int i = 0; i < tam; i++)
    {
        if (arr[i] < 0)
        {
            resultado++;
        }
    }
    return resultado;
}
int main()
{
    int tamanio = 3;
    int arr[tamanio];
    arr[0] = 3;
    arr[1] = -2;
    int a = negativos(arr, tamanio);
    return 0;
}
