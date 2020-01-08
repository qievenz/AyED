/* Figura 12.19: fig12_19.c
   Crea un arbol binario y lo recorre en
   preorden, inorden, y en postOrden */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* estructura autoreferenciada */
struct nodoArbol { 
   struct nodoArbol *ptrIzq;  /* apuntador al sub�rbol izquierdo */
   int dato; /* valor del nodo */
   struct nodoArbol *prtDer; /* apuntador al sub�rbol derecho */
}; /* fin de la estructura nodoArbol */

typedef struct nodoArbol NodoArbol; /* sin�nimo de la estructura nodoArbol */
typedef NodoArbol *ptrNodoArbol; /* sin�nimo de NodoArbol* */

/* prototipos */
void insertaNodo( ptrNodoArbol *ptrArbol, int valor );
void inOrden( ptrNodoArbol ptrArbol );
void preOrden( ptrNodoArbol ptrArbol );
void postOrden( ptrNodoArbol ptrArbol );

/* la funci�n main comienza la ejecuci�n del programa */
int main()
{ 
   int i; /* contador para el ciclo de 1 a 10 */
   int elemento; /* variable para almacenar valores al azar */
   ptrNodoArbol ptrRaiz = NULL; /* �rbol inicialemnte vac�o */

   srand( time( NULL ) ); 
   printf( "Los numeros colocados en el arbol son:\n" );

   /* inserta valores al azar entre 1 y 15 en el �rbol */
   for ( i = 1; i <= 10; i++ ) { 
      elemento = rand() % 15;
      printf( "%3d", elemento );
      insertaNodo( &ptrRaiz, elemento );
   } /* fin de for */

   /* recorre el �rbol en preorden */
   printf( "\n\nEl recorrido en preorden es:\n" );
   preOrden( ptrRaiz );

   /* recorre el �rbol en in inorden */
   printf( "\n\nEl recorrido inorden es:\n" );
   inOrden( ptrRaiz );

   /* recorre el �rbol en postOrden */
   printf( "\n\nEl recorrido en postOrden es:\n" );
   postOrden( ptrRaiz );

   return 0; /* indica terminaci�n exitosa */

} /* fin de main */

/* inserta un nodo dentro del �rbol */
void insertaNodo( ptrNodoArbol *ptrArbol, int valor )
{ 
   
   /* si el �rbol esta vac�o */
   if ( *ptrArbol == NULL ) {   
      *ptrArbol = malloc( sizeof( NodoArbol ) );

      /* si la memoria est� asignada, entonces asigna el dato */
      if ( *ptrArbol != NULL ) { 
         ( *ptrArbol )->dato = valor;
         ( *ptrArbol )->ptrIzq = NULL;
         ( *ptrArbol )->prtDer = NULL;
      } /* fin de if */
      else {
         printf( "no se inserto %d. No hay memoria disponible.\n", valor );
      } /* fin de else */

   } /* fin de if */
   else { /* el �rbol no esta vac�o */

      /* el dato a insertar es menor que el dato en el nodo actual */
      if ( valor < ( *ptrArbol )->dato ) {
         insertaNodo( &( ( *ptrArbol )->ptrIzq ), valor );
      } /* fin de if */

      /* el dato a insertar es mayor que el dato en el nodo actual */
      else if ( valor > ( *ptrArbol )->dato ) {
         insertaNodo( &( ( *ptrArbol )->prtDer ), valor );
      } /* fin de else if */
      else { /* ignora el valor duplicado del dato */
         printf( "dup" );
      } /* fin de else */

   } /* fin de else */

} /* fin de la funci�n insertaNodo */

/* comienza el recorrido inorden del �rbol */
void inOrden( ptrNodoArbol ptrArbol )
{ 

   /* si el �rbol no esta vac�o, entonces rec�rrelo */
   if ( ptrArbol != NULL ) { 
      inOrden( ptrArbol->ptrIzq );
      printf( "%3d", ptrArbol->dato );
      inOrden( ptrArbol->prtDer );
   } /* fin de if */

} /* fin de la funci�n inOrden */

/* comienza el recorrido preorden del �rbol */
void preOrden( ptrNodoArbol ptrArbol )
{ 

   /* si el �rbol no esta vac�o, entonces rec�rrelo */
   if ( ptrArbol != NULL ) { 
      printf( "%3d", ptrArbol->dato );
      preOrden( ptrArbol->ptrIzq );
      preOrden( ptrArbol->prtDer );
   } /* fin de if */

} /* fin de la funci�n preOrden */

/* comienza el recorrido postOrden del �rbol */
void postOrden( ptrNodoArbol ptrArbol )
{ 

   /* si el �rbol no esta vac�o, entonces rec�rrelo */
   if ( ptrArbol != NULL ) { 
      postOrden( ptrArbol->ptrIzq );
      postOrden( ptrArbol->prtDer );
      printf( "%3d", ptrArbol->dato );
   } /* fin de if */

} /* fin de la funci�n postOrden */




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
