#include <iostream>

int cuantasmayus(char *letras, int tamanio);

int main()
{
    char cadena[4] = {'a', 'G', 'V', 'w'};
    int a = cuantasmayus(cadena, 4);
    return 0;
}

int cuantasmayus(char *letras, int tamanio)
{
    int resultado = 0;

    for (int i = 0; i < tamanio; i++)
    {
        if (isupper(letras[i]))
        {
            resultado++;
        }
    }
    return resultado;
}