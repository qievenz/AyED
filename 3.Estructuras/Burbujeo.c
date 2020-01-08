//Ordenamiento de enteros
void ordenaMBurbuja(int *const array, const int tamanio)
{
    void intercambiar(int *ptrElemento1, int *ptrElemento2);
    for (int pasada = 0; pasada < tamanio - 1; pasada++)
    {
        for (int j = 0; j < tamanio - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                intercambiar(&array[j], &array[j + 1]);
            }
        }
    }
}
void intercambiar(int *ptrElemento1, int *ptrElemento2)
{
    int almacena = *ptrElemento1;
    *ptrElemento1 = *ptrElemento2;
    *ptrElemento2 = almacena;
}