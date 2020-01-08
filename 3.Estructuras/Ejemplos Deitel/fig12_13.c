/* Figura 12.13: fig12_13.c
   Operaci�n y mantenimiento de una cola */

#include <stdio.h>
#include <stdlib.h>

/* estructura autoreferenciada */
struct nodoCola {   
   char dato;                 /* define dato como un char */
   struct nodoCola *ptrSiguiente; /* apuntador nodoCola */
}; /* fin de la estructura nodoCola */

typedef struct nodoCola NodoCola;
typedef NodoCola *ptrNodoCola;

/* prototipos de las funciones */
void imprimeCola( ptrNodoCola ptrActual );
int estaVacia( ptrNodoCola ptrCabeza );
char retirar( ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon );
void agregar( ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon, 
              char valor );
void instrucciones( void );

/* la funci�n main comienza la ejecuci�n del programa */
int main()
{ 
   ptrNodoCola ptrCabeza = NULL; /* incializa ptrCabeza */
   ptrNodoCola ptrTalon = NULL;  /* incializa ptrTalon */
   int eleccion;                 /* elecci�n de men� del usuario */
   char elemento;                /* entrada char del usuario */

   instrucciones(); /* despliega el men� */
   printf( "? " );
   scanf( "%d", &eleccion );

   /* mientras el usuario no introduzca 3 */
   while ( eleccion != 3 ) { 

      switch( eleccion ) { 

         /* agrega el valor */
         case 1:
            printf( "Introduzca un caracter: " );
            scanf( "\n%c", &elemento );
            agregar( &ptrCabeza, &ptrTalon, elemento );
            imprimeCola( ptrCabeza );
            break;

         /* retira el valor */
         case 2:

            /* si la cola no est� vac�a */
            if ( !estaVacia( ptrCabeza ) ) { 
               elemento = retirar( &ptrCabeza, &ptrTalon );
               printf( "se desenfilo %c.\n", elemento );
            } /* fin de if */

            imprimeCola( ptrCabeza );
            break;

         default:
            printf( "Eleccion no valida.\n\n" );
            instrucciones();
            break;

      } /* fin de switch */

      printf( "? " );
      scanf( "%d", &eleccion );
   } /* fin de while */

   printf( "Fin de programa.\n" );
   
   return 0; /* indica terminaci�n exitosa */

} /* fin de main */

/* despliega las instrcciones del programa para el usuario */
void instrucciones( void )
{ 
   printf ( "Introuzca su elecci�n:\n"
           "   1 para retirar un elemento a la cola\n"
           "   2 para eliminar un elemento de la cola\n"
           "   3 para terminar\n" );
} /* fin de la funci�n instrucciones */

/* inserta un nodo al final de la cola */
void agregar( ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon, 
              char valor )
{ 
   ptrNodoCola ptrNuevo; /* apuntador a un nuevo nodo */

   ptrNuevo = malloc( sizeof( NodoCola ) );

   if ( ptrNuevo != NULL ) { /* es espacio disponible */ 
      ptrNuevo->dato = valor;
      ptrNuevo->ptrSiguiente = NULL;

      /* si esta vac�a inserta un nodo en la cabeza */
      if ( estaVacia( *ptrCabeza ) ) {
         *ptrCabeza = ptrNuevo;
      } /* fin de if */
      else {
         ( *ptrTalon )->ptrSiguiente = ptrNuevo;
      } /* fin de else */

      *ptrTalon = ptrNuevo;
   } /* fin de if */
   else {
      printf( "no se inserto %c. No hay memoria disponible.\n", valor );
   } /* fin de else */

} /* fin de la funci�n agregar */

/* elimina el nodo de la cabeza de la cola */
char retirar( ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon )
{ 
   char valor;           /* valor del nodo */
   ptrNodoCola tempPtr; /* apuntador a un nodo temporal */

   valor = ( *ptrCabeza )->dato;
   tempPtr = *ptrCabeza;
   *ptrCabeza = ( *ptrCabeza )->ptrSiguiente;

   /* si la cola est� vac�a */
   if ( *ptrCabeza == NULL ) {
      *ptrTalon = NULL;
   } /* fin de if */

   free( tempPtr );

   return valor;

} /* fin de la funci�n retirar */

/* Devuelve 1 si la cola est� vac�a, de lo contrario devuelve 0 */
int estaVacia( ptrNodoCola ptrCabeza )
{ 
   return ptrCabeza == NULL;

} /* fin de la funci�n estaVacia */

/* Imprime la cola */
void imprimeCola( ptrNodoCola ptrActual )
{ 

   /* si la cola esta vac�a */
   if ( ptrActual == NULL ) {
      printf( "La cola esta vacia.\n\n" );
   } /* fin de if */
   else { 
      printf( "La cola es:\n" );

      /* mientras no sea el final de la cola */
      while ( ptrActual != NULL ) { 
         printf( "%c --> ", ptrActual->dato );
         ptrActual = ptrActual->ptrSiguiente;
      } /* fin de while */

      printf( "NULL\n\n" );
   } /* fin de else */

} /* fin de la funci�n imprimeCola */



/**************************************************************************
 * (C) Copyright 1992-2004 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
