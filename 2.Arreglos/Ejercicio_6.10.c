//6.10
#include <stdio.h>

int salarios_semanales(int[], int);
int calcular_comision(int);

int main()
{
    int contador_por_rangos[9]; //Contador de vendedorees, [0] = a, [1] = b..
    int suma_semanal;
    scanf("%d", &suma_semanal);
}

int salarios_semanales(int *ventas, int tamanio_ventas)
{
    int comision = 0;
    int contador[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < tamanio_ventas; i++)
    {
        comision = calcular_comision(ventas[i]);
        if (comision >= 200 && comision <= 299)
        {
            contador[0] += 1;
        }
    }
    return contador;
}

int calcular_comision(int imp_venta)
{
    int resultado = 0;
    resultado = (imp_venta * 9) / 100 + 200;
    return resultado;
}