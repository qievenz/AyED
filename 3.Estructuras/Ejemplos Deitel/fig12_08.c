/* Figura 12.8: fig12_08.c
   programa de pila din�mica */
#include <stdio.h>
#include <stdlib.h>

/* estructura auto-referenciada */
struct nodoPila {   
   int dato;                  /* define un dato como int */
   struct nodoPila *ptrSiguiente; /* apuntador a nodoPila */
}; /* fin de la estructura nodoPila */

typedef struct nodoPila NodoPila; /* sin�nimo de la estructura nodoPila */
typedef NodoPila *ptrNodoPila; /* sin�nimo para NodoPila* */

/* prototipos */
void empujar( ptrNodoPila *ptrCima, int info );
int sacar( ptrNodoPila *ptrCima );
int estaVacia( ptrNodoPila ptrCima );
void imprimePila( ptrNodoPila ptrActual );
void instrucciones( void );

/* la funci�n main comienza la ejecuci�n del programa */
int main()
{ 
   ptrNodoPila ptrPila = NULL; /* apunta al tope de la pila */
   int eleccion; /* elecci�n de men� del usuario */
   int valor;  /* entrada int del usuario */
 
   instrucciones(); /* despliega el men� */
   printf( "? " );
   scanf( "%d", &eleccion );

   /* mientras el usuario no introduzca 3 */
   while ( eleccion != 3 ) { 

      switch ( eleccion ) { 

         /* empuja el valor dentro de la pila */
         case 1:      
            printf( "Introduzca un entero: " );
            scanf( "%d", &valor );
            empujar( &ptrPila, valor );
            imprimePila( ptrPila );
            break;

         /* saca el valor de la pila */
         case 2:      

            /* si la pila no esta vac�a */
            if ( !estaVacia( ptrPila ) ) {
               printf( "El valor sacsdo es %d.\n", sacar( &ptrPila ) );
            } /* fin de if */

            imprimePila( ptrPila );
            break;

         default:
            printf( "Eleccion no valida.\n\n" );
            instrucciones();
            break;

      } /* fin de switch */

      printf( "? " );
      scanf( "%d", &eleccion );
   } /* fin de while */

   printf( "Fin del programa.\n" );

   return 0; /* indica terminaci�n exitosa */

} /* fin de main */

/* despliega las instrucciones del programa para el usuario */
void instrucciones( void )
{ 
   printf( "Introduzca su eleccion:\n"
      "1 para empujar un valor dentro de la pila\n"
      "2 para sacar un valor dwe la pila\n"
      "3 para terminar el programa\n" );
} /* fin de la funci�n instrucciones */

/* Inserta un nodo en la cima de la pila */
void empujar( ptrNodoPila *ptrCima, int info )
{ 
   ptrNodoPila ptrNuevo; /* apuntador al nuevo nodo */

   ptrNuevo = malloc( sizeof( NodoPila ) );

   /* inserta el nodo en la cima de la pila */
   if ( ptrNuevo != NULL ) {   
      ptrNuevo->dato = info;
      ptrNuevo->ptrSiguiente = *ptrCima;
      *ptrCima = ptrNuevo;
   } /* fin de if */
   else { /* no queda espacio disponible */
      printf( "%d no se inserto. Memoria insuficiente.\n", info );
   } /* fin de else */

} /* fin de la funci�n empujar */

/* Elimina un nodo de la cima de la pila */
int sacar( ptrNodoPila *ptrCima )
{ 
   ptrNodoPila ptrTemp; /* apuntador a un nodo temporal */
   int valorElim; /* valor del nodo */

   ptrTemp = *ptrCima;
   valorElim = ( *ptrCima )->dato;
   *ptrCima = ( *ptrCima )->ptrSiguiente;
   free( ptrTemp );

   return valorElim;

} /* fin de la funci�n sacar */

/* Imprime la pila */
void imprimePila( ptrNodoPila ptrActual )
{ 

   /* si la pila esta vac�a */
   if ( ptrActual == NULL ) {
      printf( "La pila esta vacia.\n\n" );
   } /* fin de if */
   else { 
      printf( "La pila es:\n" );

      /* mientras no sea el final de la pila */
      while ( ptrActual != NULL ) { 
         printf( "%d --> ", ptrActual->dato );
         ptrActual = ptrActual->ptrSiguiente;
      } /* fin de while */

      printf( "NULL\n\n" );
   } /* fin de else */

} /* fin de la funci�n imprimePila */

/* Devuelve 1 si la pila est� vac�a, de lo contrario 0 */
int estaVacia( ptrNodoPila ptrCima )
{ 
   return ptrCima == NULL;

} /* fin de la funci�n estaVacia */



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
