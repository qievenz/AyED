/* Figura 12.3: fig12_03.c
   Operaci�n y mantenimiento de una lista */
#include <stdio.h>
#include <stdlib.h>

/* estructura auto_referenciada */
struct nodoLista
{
   char dato;                      /* cada nodoLista contiene un caracter */
   struct nodoLista *ptrSiguiente; /* apuntador al siguiente nodo */
};                                 /* fin de la estructura nodoLista */

typedef struct nodoLista NodoLista; /* sin�nimo para la estructura nodoLista */
typedef NodoLista *ptrNodoLista;    /* sin�nimo para de NodoLista* */

/* prototipos */
void insertar(ptrNodoLista *ptrS, char valor);
char eliminar(ptrNodoLista *ptrS, char valor);
int estaVacia(ptrNodoLista ptrS);
void imprimeLista(ptrNodoLista ptrActual);
void instrucciones(void);

int main()
{
   ptrNodoLista ptrInicial = NULL; /* inicialmente no existen nodos */
   int eleccion;                   /* eleccion del usuario */
   char elemento;                  /* car�cter introducido por el usuario */

   instrucciones(); /* despliega el men� */
   printf("? ");
   scanf("%d", &eleccion);

   /* repite mientras el usuario no elija 3 */
   while (eleccion != 3)
   {

      switch (eleccion)
      {

      case 1:
         printf("Introduzca un caracter: ");
         scanf("\n%c", &elemento);
         insertar(&ptrInicial, elemento); /* inserta el elemento en la lista */
         imprimeLista(ptrInicial);
         break;

      case 2:

         /* si la lista no esta vac�a */
         if (!estaVacia(ptrInicial))
         {
            printf("Introduzca un caracter para eliminar: ");
            scanf("\n%c", &elemento);

            /* si encuentra el caracter, lo remueve */
            if (eliminar(&ptrInicial, elemento))
            { /* elimina elemento */
               printf("caracter %c eliminado.\n", elemento);
               imprimeLista(ptrInicial);
            } /* fin de if */
            else
            {
               printf("no se encuentra el caracter %c.\n\n", elemento);
            } /* fin de else */

         } /* fin de if */
         else
         {
            printf("La lista esta vacia.\n\n");
         } /* fin de else */
      case 3:
         break;

      default:
         printf("Opcion invalida.\n\n");
         instrucciones();
         break;

      } /* fin de switch */

      printf("? ");
      scanf("%d", &eleccion);
   } /* fin de while */

   printf("Fin de la ejecucion.\n");

   return 0; /* indica terminaci�n exitosa */

} /* fin de main */

/* despliega las instrucciones del programa para el usuario */
void instrucciones(void)
{
   printf("Introduzca su eleccion:\n"
          "   1 para insertar un elemento en la lista.\n"
          "   2 para eliminar un elemento de la lista.\n"
          "   3 para terminar.\n");
          "   4 para mezclar.\n");
} /* fin de la funci�n instrucciones */

/* Inserta un nuevo valor dentro de la lista en orden  */
void insertar(ptrNodoLista *ptrS, char valor)
{
   ptrNodoLista ptrNuevo;    /* apuntador a un nuevo nodo */
   ptrNodoLista ptrAnterior; /* apuntador a un nodo previo de la lista */
   ptrNodoLista ptrActual;   /* apuntador al nodo actual de la lista */

   ptrNuevo = (NodoLista *)malloc(sizeof(NodoLista)); /* crea un nodo */

   if (ptrNuevo != NULL)
   {                                 /* es espacio disponible */
      ptrNuevo->dato = valor;        /* coloca el valor en el nodo */
      ptrNuevo->ptrSiguiente = NULL; /* el nodo no se liga a otro nodo */

      ptrAnterior = NULL;
      ptrActual = *ptrS;

      /* ciclo para localizar la ubicaci�n correcta en la lista */
      while (ptrActual != NULL && valor > ptrActual->dato)
      {
         ptrAnterior = ptrActual;             /* entra al ...   */
         ptrActual = ptrActual->ptrSiguiente; /* ... siguiente nodo */
      }                                       /* fin de while */

      /* inserta un nuevo nodo al principio de la lista */
      if (ptrAnterior == NULL)
      {
         ptrNuevo->ptrSiguiente = *ptrS;
         *ptrS = ptrNuevo;
      } /* fin de if */
      else
      { /* inserta un nuevo nodo entre ptrAnterior y ptrActual */
         ptrAnterior->ptrSiguiente = ptrNuevo;
         ptrNuevo->ptrSiguiente = ptrActual;
      } /* fin de else */

   } /* fin de if */
   else
   {
      printf("No se inserto %c. No hay memoria disponible.\n", valor);
   } /* fin de else */

} /* fin de la funci�n insertar */

/* Elimina un elemento de la lista */
char eliminar(ptrNodoLista *ptrS, char valor)
{
   ptrNodoLista ptrAnterior; /* apuntador a un nodo previo de la lista */
   ptrNodoLista ptrActual;   /* apuntador al nodo actual de la lista */
   ptrNodoLista tempPtr;     /* apuntador a un nodo temporal */

   /* elimina el primer nodo */
   if (valor == (*ptrS)->dato)
   {
      tempPtr = *ptrS;               /* almacena el nodo a eliminar */
      *ptrS = (*ptrS)->ptrSiguiente; /* desata el nodo */
      free(tempPtr);                 /* libera el nodo desatado */
      return valor;
   } /* fin de if */
   else
   {
      ptrAnterior = *ptrS;
      ptrActual = (*ptrS)->ptrSiguiente;

      /* ciclo para localizar la ubicaci�n correcta en la lista */
      while (ptrActual != NULL && ptrActual->dato != valor)
      {
         ptrAnterior = ptrActual;             /* entra al ...   */
         ptrActual = ptrActual->ptrSiguiente; /* ... siguiente nodo */
      }                                       /* fin de while */

      /* elimina el nodo de ptrActual */
      if (ptrActual != NULL)
      {
         tempPtr = ptrActual;
         ptrAnterior->ptrSiguiente = ptrActual->ptrSiguiente;
         free(tempPtr);
         return valor;
      } /* fin de if */

   } /* fin de else */

   return '\0';

} /* fin de la funci�n eliminar */

/* Devuelve 1 si la lista esta vac�a, de lo contrario, 0  */
int estaVacia(ptrNodoLista ptrS)
{
   return ptrS == NULL;

} /* fin de la funci�n function estaVacia */

/* Imprime la lista */
void imprimeLista(ptrNodoLista ptrActual)
{

   /* si la lista esta vac�a */
   if (ptrActual == NULL)
   {
      printf("La lista esta vacia.\n\n");
   } /* fin de if */
   else
   {
      printf("La lista es:\n");

      /* mientras no sea el final de la lista */
      while (ptrActual != NULL)
      {
         printf("%c --> ", ptrActual->dato);
         ptrActual = ptrActual->ptrSiguiente;
      } /* fin de while */

      printf("NULL\n\n");
   } /* fin de else */

} /* fin de la funci�n imprimeLista */

ptrNodoLista mezclar(ptrNodoLista *ptrA, ptrNodoLista *ptrB)
{
   ptrNodoLista ptrResultado;
   ptrResultado = (ptrNodoLista)malloc(sizeof(NodoLista));
   ptrNodoLista ptrtemp;
   ptrNodoLista ptrActA;
   ptrActA = *ptrA;
   ptrNodoLista ptrActB;
   ptrActB = *ptrB;

   if (ptrActA->dato < ptrActB->dato)
   {
      ptrActA->ptrSiguiente = ptrActB;
      ptrActA = ptrActA->ptrSiguiente;
   }
   else
   {
      ptrActB->ptrSiguiente = ptrActA;
      ptrActB = ptrActB->ptrSiguiente;
   }

   return ptrResultado;
}
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
