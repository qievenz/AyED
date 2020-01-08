#include <iostream>
#include <stdlib.h>
#define LOG(x) std::cout << x << std::endl

/*prototipo*/

int main(int argc, char const *argv[])
{
    int cont_votos[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int candidato;
    FILE *archivo = fopen("votos.bin", "r");
    while (!feof(archivo))
    {
        fscanf(archivo, "%d", &candidato);
        cont_votos[candidato - 1]++;
    }
    fclose(archivo);
    printf("Candidato\tVotos\n");
    for (int i = 0; i < 15; i++)
    {
        printf("%d\t%d\n", i + 1, cont_votos[i]);
    }

    return 0;
}

/*funcion*/