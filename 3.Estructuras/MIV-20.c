/*Un restaurant desea manejar en forma computarizada las adiciones de sus mesas. Para ello dispone de los siguientes datos:
//    a) un archivos de platos y bebidas, ordenado por código de plato con el siguiente diseño:
//   a.1 código de plato (1..200)    a.2 descripción del plato (40 caracteres)
//   a.3 precio unitario (real)         a.4 otros datos (100 caract)
//
//    b) número de factura inicial y fecha del día
//
//    c) Por cada producto servido se ingresan por teclado la siguiente información:
//   c.1 número de mesa (1..48)                       b.2 código de operación (‘A’, ‘B’, ‘F’)
//   c.3 código de plato (1..200)                       b.4 unidades pedidas (2 dígitos)
//
//   Operación A: significa plato servido
//   Operación B: significa devolución del plato
//   Operación F: fin del pedido, emitir la adición y el campo de código de plato contiene el   número del mozo (1..10) que atendió  esa mesa.
//
//Cuando se ingrese nro de mesa igual a 0 indica fin del día. En caso de que queden adiciones pendientes, informar una leyenda.
//
//Se pide realizar un programa que:
//    1) Imprima la factura de cada mesa que fue ocupada:
//Restaurant                             Fecha :..................          Factura:.......................
//      Cant               Descripción                Precio Unitario              Importe
//       .......               ...................                      ............                      ............
//Mozo: ....                                                                   Total:........................
//Los platos deben estar ordenados por código de plato y acumuladas las unidades en caso de repetición.
//    2) Grabar un archivo de facturación con los siguientes datos: fecha, número de factura, mesa, mozo, e importe
//    3) Al final del día emitir un listado con el total a cobrar por cada mozo, ordenado por número de mozo (cobran el 1% sobre cada adición)
//
// Recursos y Restricciones:
//    • Optimización: dado que el uso de ciclos afecta el tiempo de ejecución de un proceso, se evaluará la eficiencia en el uso de los mismos.
//    • Máximo de Mozos: 10
//    • Memoria para arrays: 250 bytes.
//    • Memoria dinámica:  nodo maximo de 6 bytes.
//    • Memoria en disco: solo para la grabación del nuevo archivo
//    • Accesos a disco: optimice las búsquedas en el archivo de platos.
*/
#include <stdio.h>
#include <stdlib.h>
#define LOG(x) printf(x)

void generarIncorporados(FILE *archivo);
void imprimirListado();

typedef struct tLibros
{
    char codigo[8];
    char titulo[30];
    char apellido[15];
    int cantidad;
    struct tLibros *ptrNodoSgte;
} Libro, *ptrLibro;

int main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}

/*funcion*/