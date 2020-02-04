/* Whatsapp */
#include <stdio.h>
#include <stdlib.h>
//#define LOG(x) printf(x)
#define N 250

//1.Definir y declarar todas las estructuras
typedef struct usuario
{
    int idUsuario;
    int recibido; //1 recibido, 0 no recibido
    int entregado;
    char otrosDatos[N];
    //struct ptrUsuario *ptrSiguiente;
} Usuario, *ptrUsuario;

typedef struct nodoUsuario
{
    Usuario info;
    struct ptrUsuario *ptrSiguiente;
} NodoUsuario, ptrNodoUsuario;

typedef struct mensaje
{
    int fecha; //orden decreciente
    int idMensaje;
    int leido; //1 leido, 0 no leido
    char mensaje[N];
    //struct ptrMensaje *ptrSiguiente;
} Mensaje, *ptrMensaje;

typedef struct nodoMensaje
{
    struct ptrMensaje *info;
    struct ptrNodoMensaje *ptrSiguiente;
} NodoMensaje, *ptrNodoMensaje;

typedef struct laConversacion
{
    int idConversacion;
    int idEmisor;
    int idReceptor;
    int fecha;
    ptrMensaje *ptrMensajeEnviado;
    ptrMensaje *ptrMensajeRecibido;
    //struct ptrConversacion *ptrSiguiente;
} Conversacion, *ptrConversacion;

typedef struct nodoConversacion
{
    Conversacion info;
    struct ptrConversacion *ptrSiguiente;
} NodoConversacion, *ptrNodoConversacion;

ptrNodoConversacion insertarConversacionOrdenado(ptrNodoConversacion l, Conversacion x);
ptrNodoMensaje insertarMensajeOrdenado(ptrNodoMensaje *l, Mensaje x);
ptrConversacion *eliminarNodo(ptrConversacion *l, Conversacion x);
ptrConversacion *buscarEnLista(ptrConversacion *l, int x);
int fechaAEntero();  //Devuelve AAMMDDHHMM
int numeroMensaje(); //genera un nro unico para cada mensaje

//2.Declarar el prototipo de funcion LosMensajerRecibidos, para cumplir con lo que se requiere cueando llega un nuevo mensaje:
void LosMensajerRecibidos(int idConversacion, char Mensaje[N]);

int main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}

//3.COdificar la funcion anterior.
void LosMensajerRecibidos(int idConversacion, char Mensaje[N])
{
    ptrMensaje mensajeRecibido = (ptrMensaje)malloc(sizeof(Mensaje));
    ptrNodoMensaje nodoMensajeRecibido = (ptrNodoMensaje)malloc(sizeof(NodoMensaje));
    mensajeRecibido->fecha = fechaAEntero();
    mensajeRecibido->idMensaje = numeroMensaje();
    *mensajeRecibido->mensaje = Mensaje;
    mensajeRecibido->leido = 0;
    //Buscar la conversacion
    //Obtenes el ptr a mensajes recibidos
    //insertas el Mensaje al final de el ptr MensajesRecibidos
    insertarMensajeOrdenado(nodoMensajeRecibido, *mensajeRecibido);
}