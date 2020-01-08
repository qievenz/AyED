#include <iostream>
#include <stdlib.h>
#define LOG(x) std::cout << x << std::endl

/*prototipo*/

int main(int argc, char const *argv[])
{
    FILE *archivo = fopen("ruleta.bin", "r");
    int cont_numeros[37];
    int numero;
    for (int i = 0; i < 37; i++)
    {
        cont_numeros[i] = 0;
    }
    while (!feof(archivo))
    {
        fscanf(archivo, "%d", &numero);
        cont_numeros[numero]++;
    }
    fclose(archivo);

    printf("Numero\tVeces\n");
    for (int i = 0; i < 37; i++)
    {
        printf("%d\t%d\n", i, cont_numeros[i]);
    }
    return 0;
}

/*funcion*/