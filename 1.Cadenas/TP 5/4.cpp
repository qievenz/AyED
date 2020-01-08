#include <iostream>
#define TAMANIO 4

//Prototipo
void maxmin(double *array, int tam, double &max, double &min);

int main()
{
    double arr[TAMANIO] = {0, 3, -5, 4};
    double maximo, minimo;
    maxmin(arr, TAMANIO, maximo, minimo);
    return 0;
}

void maxmin(double *array, int tam, double &max, double &min)
{
    max = min = 0;
    for (int i = 0; i < tam; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }
}