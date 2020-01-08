#include <iostream>
#include <stdlib.h>
#define LOG(x) std::cout << x << std::endl

void grabar_enteros();

int main(int argc, char const *argv[])
{
    //grabar_enteros();
    FILE *archivo = fopen("data.bin", "r");
    int entero;
    while (!feof(archivo))
    {
        fscanf(archivo, "%d", &entero);
        printf("%d", entero);
    }

    fclose(archivo);
    return 0;
}

void grabar_enteros()
{
    int numero;
    FILE *archivo = fopen("data.bin", "w");
    scanf("%d", &numero);
    while (!feof(stdin)) //CTRL+D CTRL+D
    {
        fprintf(archivo, "%d\n", numero);
        scanf("%d", &numero);
    }
    fclose(archivo);
}