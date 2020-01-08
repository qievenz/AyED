#include <iostream>
#define LOG(x) std::cout << x << std::endl

void invertir_enteros(int *vector, int tamanio);

int main(int argc, char const *argv[])
{
    int array[] = {6, 2, 7, 0};
    invertir_enteros(array, 4);
    return 0;
}
void invertir_enteros(int *vector, int tamanio)
{
    int aux_vector;
    for (int i = 0; i < tamanio / 2; i++)
    {
        aux_vector = vector[i];
        vector[i] = vector[tamanio - i - 1];
        vector[tamanio - i - 1] = aux_vector;
    }
    /*
    for (int i = 0; i < tamanio; i++)
    {
        LOG(vector[i]);
    }*/
}
/*
void invertir_enteros(int *vector, int tamanio)
{
    int aux_vector[tamanio];
    for (int i = 0; i < tamanio; i++)
    {
        //*(aux_vector + (tamanio - i - 1)) = *(vector + (i));
        aux_vector[tamanio - i - 1] = vector[i];
    }

    for (int i = 0; i < tamanio; i++)
    {
        //*vector = aux_vector[i];
        vector[i] = aux_vector[i];
        //vector++;
    }
}*/