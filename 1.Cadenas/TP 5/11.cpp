#include <iostream>
#define LOG(x) std::cout << x << std::endl

float precio(TREG vec[], int i, int articulo);

typedef struct
{
    int articulo;
    float precio;
} TREG;

int main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}

float precio(TREG vec[], int i, int articulo)
{
    float resultado;
    for (int indice = 0; indice < i; indice++)
    {
        if (vec[indice].articulo == articulo)
        {
            resultado = vec[indice].precio;
            break;
        }
    }
    return resultado;
}