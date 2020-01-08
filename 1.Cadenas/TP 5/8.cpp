#include <iostream>
#define LOG(x) std::cout << x << std::endl

float mayor_sueldo2(TREG vec[], int i);

typedef struct
{
    int leg;
    float suel;
} TREG;

main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}

float mayor_sueldo2(TREG vec[], int i)
{
    float resultado = vec[0].suel;
    for (int contador = 0; contador < i; contador++)
    {
        if (vec[contador].suel > resultado)
        {
            resultado = vec[contador].suel;
        }
    }
    return resultado;
}