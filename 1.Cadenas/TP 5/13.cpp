#include <iostream>
#define LOG(x) std::cout << x << std::endl

void generar_vector_random(int vector[], int cantidad);   //Cargar el vector con numeros random de 0-500
void mostrar_vector_random(int vector[], int cantidad);   //Mostrar en pantalla los valores
void consultar_vector_random(int vector[], int cantidad); //ingresar por teclado valores 0-500 y dewcir si estan o no. termina ingresando un negativo.

int main(int argc, char const *argv[])
{
    int MAX = 5;
    int vector[MAX];
    generar_vector_random(vector, MAX);
    mostrar_vector_random(vector, MAX);
    consultar_vector_random(vector, MAX);
    return 0;
}

void generar_vector_random(int vector[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        vector[i] = rand() % 501;
    }
}

void mostrar_vector_random(int vector[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("%d\n", vector[i]);
    }
}

void consultar_vector_random(int vector[], int cantidad)
{
    int valor;
    bool encontrado;
    printf("Ingrese el valor a buscar:\t");
    scanf("%d", &valor);
    while (!feof(stdin))
    {
        encontrado = false;
        for (int i = 0; i < cantidad; i++)
        {
            if (valor == vector[i])
            {
                encontrado = true;
                break;
            }
        }
        if (encontrado)
        {
            printf("Valor encontrado!!\n");
        }
        else
        {
            printf("Valor NO encontrado :c\n");
        }
        printf("Ingrese el valor a buscar:\t");
        scanf("%d", &valor);
    }
}