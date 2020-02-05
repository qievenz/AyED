/* Whatsapp */
#define MAX 250
#include <stdio.h>
#include <stdlib.h>
//#define LOG(x) printf(x)

//1.Definir y declarar todas las estructuras
typedef struct usuario
{
    int idUsuario;
    int recibido; //1 recibido, 0 no recibido
    int entregado;
    char otrosDatos[MAX];
    //struct ptrUsuario *ptrSiguiente;
} Usuario, *ptrUsuario;

typedef struct nodoUsuario
{
    Usuario info;
    struct ptrUsuario *ptrSiguiente;
} NodoUsuario, *ptrNodoUsuario;

typedef struct mensaje
{
    int fecha; //orden decreciente
    int idMensaje;
    int leido; //1 leido, 0 no leido
    char mensaje[MAX];
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
ptrNodoConversacion buscarEnListaConversacion(ptrNodoConversacion l, int x);
ptrNodoUsuario buscarEnListaUsuario(ptrNodoUsuario l, int x);
int fechaAEntero();  //Devuelve AAMMDDHHMM
int numeroMensaje(); //genera un nro unico para cada mensaje

//2.Declarar el prototipo de funcion LosMensajerRecibidos, para cumplir con lo que se requiere cueando llega un nuevo mensaje:
void LosMensajerRecibidos(ptrNodoConversacion conversaciones, ptrNodoUsuario usuarios, int idConversacion, char Mensaje[MAX]);

int main(int argc, char const *argv[])
{
    /*codigo*/
    return 0;
}

//3.COdificar la funcion LosMensajerRecibidos.
void LosMensajerRecibidos(ptrNodoConversacion conversaciones, ptrNodoUsuario usuarios, int idConversacion, char Mensaje[MAX])
{
    //crear el nuevo mensaje
    ptrMensaje mensajeRecibido = (ptrMensaje)malloc(sizeof(Mensaje));
    mensajeRecibido->fecha = fechaAEntero();
    mensajeRecibido->idMensaje = numeroMensaje();
    *mensajeRecibido->mensaje = Mensaje;
    mensajeRecibido->leido = 0;
    //Buscar la conversacion
    ptrNodoConversacion conversacionActual = buscarEnListaConversacion(conversaciones, idConversacion);
    //Obtenes el ptr a mensajes recibidos
    ptrMensaje mensajesRecibidos;
    mensajesRecibidos = conversacionActual->info.ptrMensajeRecibido;
    //insertas el Mensaje al final de el ptr MensajesRecibidos
    insertarMensajeOrdenado(mensajesRecibidos, *mensajeRecibido);
    //Notificar al usuario que lo envio que el mensaje fue recibido. idEmisor . usuario.recibido = 1
    ptrNodoUsuario ptrUsuarioEmisor = buscarEnListaUsuario(usuarios, conversacionActual->info.idEmisor);
    ptrUsuario usuarioEmisor = &ptrUsuarioEmisor->info;
    usuarioEmisor->recibido = 1;
    //Colocar la conversacion al inicio de la lista
    //ptrNodoConversacion conversacionAux = conversaciones;
    conversacionActual->ptrSiguiente = conversaciones;
    conversaciones = conversacionActual;
}