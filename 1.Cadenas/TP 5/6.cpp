#include <iostream>

//a. funcion ingresar
void ingresar(float vec[]);
//b. funcion del ejercicio 4
void maxmin(float *numeros, int &cantmax, int &cantmin);

//
void imprimirmaxmin();

int main()
{
    float array[100];
    int maximo, minimo;
    ingresar(array);
    maxmin(array, maximo, minimo);
    std::cout << "maximo: " << maximo << std::endl;
    std::cout << "minimo: " << minimo << std::endl;
    return 0;
}