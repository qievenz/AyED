#include <iostream>
#include <stdlib.h>
#define LOG(x) std::cout << x << std::endl

void mostrar_cantidad(int *vector, int tamanio);

int main(int argc, char const *argv[])
{
    int numeros[] = {2, 2, 3, 4, 5, 6, 6, 6, 6};
    mostrar_cantidad(numeros, 9);
    return 0;
}

void mostrar_cantidad(int *vector, int tamanio)
{
    int veces = 1;
    int numero = vector[0];
    printf("Numero\tVeces\n");
    for (int i = 1; i < tamanio; i++)
    {
        if (numero == vector[i])
        {
            veces++;
        }
        else
        {
            printf("%d\t%d\n", numero, veces);
            numero = vector[i];
            veces = 1;
        }
    }
    printf("%d\t%d\n", numero, veces);
}