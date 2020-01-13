/*Una biblioteca necesita un programa que efectúe las altas en el archivo maestro de libros. Para ello cuenta con:
a) LIBROS.dat, archivo maestro de libros ordenado por código de libro, con un registro por cada libro, con el siguiente diseño:
a.1 código de libro (8 caracteres)
a.2  título del libro (30 caract)
a.3 apellido del autor (15 caracteres)                         
a.4 cantidad de ejemplares (2 dígitos)
a.5 nacionalidad  (6 dígitos)
a.6 otros datos (100 caracteres)

b) NOVEDADES.dat, archivo con los libros a dar de alta  sin ningún orden, con el mismo diseño del archivo maestro.

Se pide realizar la metodología necesaria para que el programa:
1) Genere un nuevo archivo LIBROSACT.dat, con el mismo diseño y orden que el maestro y con las altas incorporadas. 

2) Emitir el siguiente listado, agrupado por nacionalidad y ordenado ascendente por cantidad total de autores:
              Nacionalidad...................................   Cantidad Total de autores: 999
		Apellido del Autor             Cantidad total de títulos  
		……......................	                    99

 Recursos y Restricciones: 
    • Optimización: dado que el uso de ciclos afecta el tiempo de ejecución de un proceso, se evaluará la eficiencia en el uso de los mismos.
    • Máximo de Nacionalidades: 100
    • Memoria para arrays: 1.000 bytes.
    • Memoria dinámica:  nodo de 17 bytes * cantidad de registros del archivo de novedades + nodo de 21 bytes * cantidad de autores.
    • Memoria en disco: solo para la grabación del nuevo archivo
    • Accesos a disco: 2 accesos a cada registro de Novedades, un solo recorrido del archivo de Libros y al nuevo archivo- 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LOG(x) printf(x)

typedef struct tLibros
{
    char codigo[8];
    char titulo[30];
    char apellido[15];
    int cantidad;
    int nacionalidad;
} Libro, *ptrLibro;

typedef struct tNodo
{
    struct tLibros info;
    struct tNodo *ptrSiguiente;
} NodoLibro, *ptrNodoLibro;

ptrNodoLibro generarIncorporados(FILE *archivo);
void insertarNodoOrdenado(ptrNodoLibro ptrInicio, Libro info);
void imprimirListado(ptrNodoLibro ptrInicio);
void crearLibro();

int main(int argc, char const *argv[])
{
    crearLibro();
    return 0;
}

ptrNodoLibro generarIncorporados(FILE *archivo)
{
    ptrNodoLibro ptrInicial;
    ptrNodoLibro ptrNodo;
    Libro registro;
    archivo = fopen("NOVEDADES.TXT", "r");
    fread(&registro, sizeof(Libro), 1, archivo);
    while (feof(archivo))
    {
        ptrNodo->info = registro;

        fread(&registro, sizeof(Libro), 1, archivo);
    }
    return ptrInicial;
}

void insertarNodoOrdenado(ptrNodoLibro ptrInicio, Libro info)
{
    ptrNodoLibro ptrNuevoNodo;
    ptrNodoLibro ptrActual = ptrInicio;
    ptrNodoLibro ptrAnterior = NULL;
    ptrNuevoNodo = (ptrNodoLibro)malloc(sizeof(NodoLibro));
    ptrNuevoNodo->info = info;
    ptrNuevoNodo->ptrSiguiente = NULL;
    while (ptrActual != NULL && ptrNuevoNodo->info.codigo > ptrActual->info.codigo)
    {
        ptrAnterior = ptrActual;
        ptrActual = ptrActual->ptrSiguiente;
    }
    if (ptrAnterior == NULL)
    {
        ptrNuevoNodo->ptrSiguiente = ptrInicio;
        ptrInicio = ptrNuevoNodo;
    }
    else
    {
        ptrAnterior->ptrSiguiente = ptrNuevoNodo;
        ptrNuevoNodo->ptrSiguiente = ptrActual;
    }
}

void imprimirListado(ptrNodoLibro ptrInicio)
{
    ptrNodoLibro ptrPasada = ptrInicio;
    ptrNodoLibro ptrSubPasada = ptrInicio;
    ptrNodoLibro ptrNacionalidad = NULL;
    ptrNodoLibro ptrNuevoNodo;
    ptrNodoLibro ptrAnteriorNac;
    ptrNodoLibro ptrAnteriorSubPasada;
    int nacionalidadActual = 0;
    int contNacionalidades;
    while (ptrPasada != NULL)
    {
        contNacionalidades = 0;
        nacionalidadActual = ptrPasada->info.nacionalidad;
        ptrSubPasada = ptrPasada;
        ptrNacionalidad = NULL;
        while (ptrSubPasada != NULL)
        {
            //Si la nacionalidad es igual a la del puntero, saco el nodo y lo grabo en el otro
            if (nacionalidadActual == ptrSubPasada->info.nacionalidad)
            {
                ptrNuevoNodo = (ptrNodoLibro)malloc(sizeof(NodoLibro));
                ptrNuevoNodo->info = ptrSubPasada->info;
                if (ptrNacionalidad == NULL)
                {
                    ptrNacionalidad = ptrNuevoNodo;
                }
                else
                {
                    ptrAnteriorNac->ptrSiguiente = ptrNuevoNodo;
                }
                ptrAnteriorNac = ptrNuevoNodo;
                ptrAnteriorSubPasada = ptrSubPasada->ptrSiguiente;
                if (ptrPasada == ptrSubPasada)
                {
                    ptrPasada = ptrAnteriorSubPasada;
                }
                free(ptrSubPasada);
                ptrSubPasada = ptrAnteriorSubPasada;

                contNacionalidades++;
            }
            //Si la nacionalidad es diferente leo el siguiente nodo
            else
            {
                ptrAnteriorSubPasada = ptrSubPasada;
                ptrSubPasada = ptrSubPasada->ptrSiguiente;
            }
        }
        //Imprimir resultado para la nacionalidad actual
        if (ptrPasada != NULL)
        {
            ptrPasada = ptrPasada->ptrSiguiente;
        }
    }
}
void crearLibro()
{
    void ingresarDatos(ptrLibro ptrReg);
    FILE *archivo;
    Libro registro;
    ingresarDatos(&registro);
    archivo = fopen("./3.Estructuras/LIBROS.dat", "w");
    while (strcmp(registro.codigo, "asd") != 0)
    {
        fprintf(archivo, "%s %s %s %d %d\n", registro.codigo, registro.titulo, registro.apellido, &registro.cantidad, &registro.nacionalidad);
        ingresarDatos(&registro);
    }
    fclose(archivo);
}
void ingresarDatos(ptrLibro ptrReg)
{
    printf("\nCodigo[8]: ");
    scanf("%s", ptrReg->codigo);
    if (strcmp(ptrReg->codigo, "asd") == 0)
    {
        return;
    }
    printf("\nTitulo[30]: ");
    scanf("%s", ptrReg->titulo);
    printf("\nApellido[15]: ");
    scanf("%s", ptrReg->apellido);
    printf("\nCantidad: ");
    scanf("%d", &(*ptrReg).cantidad);
    printf("\nNacionalidad: ");
    scanf("%d", &(*ptrReg).nacionalidad);
}
