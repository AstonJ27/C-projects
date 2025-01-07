#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int item; //dato para las listas simplemente enlazadas
typedef int itemD; //dato para las listas doblemente enlazadas
typedef int itemSC; //dato para las listas simplemente enlazadas circularmente
typedef int itemDC; //dato para las listas doblemente enlazadas circularmente

typedef int itemP; //dato para las pilas
typedef int itemC; //dato para las colas

//---------------preparacion para trabajar con datos de tipo string---------
#define stringS //return strcmp(*(item *)a, *(item *)b); //para strings
#define stringD //return strcmp(*(itemD *)a, *(itemD *)b); //para strings
#define stringSC //return strcmp(*(itemSC *)a, *(itemSC *)b); //para strings
#define stringDC //return strcmp(*(itemDC *)a, *(itemDC *)b); //para strings

//prepara un string para ingresarlo a un  nodo cualquiera
char *prepare(char buff[]);


//---------------------------------LISTAS SIMPLEMENTE ENLAZADAS-------------------------------

// tipo de dato NodoSimple utilizado para crear listas simplemente enlazadas
typedef struct NodoSimple {
    item elem;
    struct NodoSimple *prox;
} NodoSimple;

typedef NodoSimple* lista;

//crea una lista vacia
lista crearS();

//crea un nodo con elemento que puede ser insertado a la lista
lista crearNS(item x);

//comprueba si una lista esta vacia o no
int isvoidS(lista lista);

//inserta un elemento al inicio de la lista
void insertarIniS(lista *lista, item x);

// inserta un elemento en una posicion valida (no nula)
void insertarS(lista *lista, item x, int pos);

//Recorre a una posicion de la lista y retorna esa sublista
//si la posicion es invalida retorna NULL
lista recorrerS(lista lista, int pos);

//muestra todos los elementos de la lista
void imprimirS(lista lista, char *type);

//Consulta si un elemento existe en la lista y retorna su posicion
//si no existe retorna 0 (false)
int existeS(lista lista, item x);

//Retorna la cantidad de elementos de la lista si esta vacia retorna 0 (false)
int tamanioS(lista lista);

//elimina una lista por completo
void eliminarS(lista *lista);

//elimina un elemento en una posicion si la posicion es 0 retorna NULL
lista eliminarPosS(lista lista, int pos);

//ordena una lista de manera ascendente
void ordenarS(lista lista);

//---------------------------------LISTAS DOBLEMENTE ENLAZADAS-------------------------------

typedef struct NodoDoble {
    itemD elem;
    struct NodoDoble *prox;
    struct NodoDoble *ant;
} NodoDoble;
typedef NodoDoble* listaD;
//crea una lista vacia
listaD crearD();

//inserta un elemento en la lista
listaD crearND(itemD x);

//comprueba si una lista esta vacia o no
int isvoidD(listaD lista);

//inserta un elemento al inicio de la lista
void insertarIniD(listaD *lista, itemD x);

// inserta un elemento en una posicion valida (no nula)
void insertarD(listaD *lista, itemD x, int pos);

//Recorre a una posicion de la lista y retorna esa sublista
//si la posicion es invalida retorna NULL
listaD recorrerD(listaD lista, int pos);

//muestra todos los elementos de la lista
void imprimirD(listaD lista, char *type);

//Consulta si un elemento existe en la lista y retorna su posicion
//si no existe retorna 0 (false)
int existeD(listaD lista, itemD x);

//Retorna la cantidad de elementos de la lista si esta vacia retorna 0 (false)
int tamanioD(listaD lista);

//elimina una lista por completo
void eliminarD(listaD *lista);

//elimina un elemento en una posicion si la posicion es 0 retorna NULL
listaD eliminarPosD(listaD lista, int pos);

//ordena una lista de manera ascendente
void ordenarD(listaD lista);

//---------------------------------LISTAS SIMPLEMENTE ENLAZADAS CIRCULARMENTE-------------------------------

typedef struct NodoSimpleC {
    itemSC elem;
    struct NodoSimpleC *prox;
} NodoSimpleC;

typedef NodoSimpleC * listaSC;

//crea una lista vacia
listaSC crearSC();

//crea un nodo con elemento qu apunta a si mismo
listaSC crearNSC(itemSC x);

//comprueba si una lista esta vacia
int isvoidSC(listaSC list);

//inserta en la primera posicionnecesita un puntero que guarde la posicion final
void insertarIniSC(listaSC *list, itemSC x, listaSC ult);

//inserta el elemento en la posicion pos%(tamaño+1)
void insertarSC(listaSC *list, itemSC x, int pos);

// retorna la posicion%(tam+1)
//recorrer(tamanio(l)) = posicion final
listaSC recorrerSC(listaSC list, int pos);

//imprime la lista
void imprimirSC(listaSC list, char *type);


//comprueba si un elemento existe y devuelve su posicion
int existeSC(listaSC list, itemSC x);

//retorna la cantidad de elementos de la lista
int tamanioSC(listaSC list);

// elimina la lista por completo y la hace nula
void eliminarSC(listaSC *list);

// elimina un elemento de la lista
listaSC eliminarPosSC(listaSC list, int pos);

//ordena la lista
void ordenarSC(listaSC list);

//---------------------------------LISTAS DOBLEMENTE ENLAZADAS CIRCULARMENTE-------------------------------

typedef struct NodoDobleC {
    itemDC elem;
    struct NodoDobleC *ant;
    struct NodoDobleC *prox;
} NodoDobleC;

typedef NodoDobleC * listaDC;

//crea una lista vacia
listaDC crearDC();

//crea un nodo que se apunta a si mismo en sus 2 direcciones
listaDC crearNDC(itemDC x);

//comprueba si esta vacio
int isvoidDC(listaDC list);

//inserta un elemento en la primera posicion
void insertarIniDC(listaDC *list, itemDC x);

//inserta un elemento en una posicion dada, 
//si la posicion es mayor al tamaño+1 insertara en posicion%(tamanio(list+)+1)
void insertarDC(listaDC *list, itemDC x, int pos);

//recorre la lista y retorna la lista desde esa posicion
listaDC recorrerDC(listaDC list, int pos);

//imprime la lista
void imprimirDC(listaDC list, char* type);

//comprueba si un elemento existe en la lista y retorna su posicion
int existeDC(listaDC list, itemDC x);

//retorna la cantidad de elementos que tiene la lista
int tamanioDC(listaDC list);

//elimina la lista entera
void eliminarDC(listaDC *list);

//elimina una posicion de la lista
listaDC eliminarPosDC(listaDC list, int pos);

//ordena los elementos de la lista
void ordenarDC(listaDC list);

//---------------------------------PILAS-------------------------------

typedef struct NodoP { 
    itemP elem;
    struct NodoP *sig;
}NodoP;

typedef NodoP * pila;

//crea una pila vacia
pila crearPila();

//comprueba si la pila esta vacia
int isvoidP(pila pil);

//retorna el elemento en la cima de la pila
itemP cima(pila pil);

//inserta un nuevo elemento a la cima de la pila
void insertarCima(pila *pil, itemP x);

//elimina un elemento de la cima
void eliminarCima(pila *pil);

//quita un elemento de la cima y guarda su valor
itemP quitarCima(pila *pil);

//vacia la pila
void vaciarPila(pila *pil);

//devuelve el tamaño de la pila
int tamanioPila(pila pil);

//---------------------------------COLAS-------------------------------
//tipo de nodo usado
typedef struct NodoCola{
    itemC elem;
    struct NodoCola *sig;
}NodoC;

//el tipo de dato definido
typedef struct{
    NodoC *ini;
    NodoC *fin;
}cola;

//crea una cola vacia
void crearCola(cola *col);

//comprueba si la cola esta vacia
int isvoidC(cola col);

//crea un nodo para una cola
NodoC *crearNCola(itemC x);

//inserta un elemento a una cola si esta vacia al inicio, sino al final
void insertarACola(cola *col, itemC x);

//devuelve el elemento que esta al inicio de la fila
itemC frenteCola(cola col);

//elimina el elemento que esta al inicio de la fila
void eliminarDeCola(cola *col);

//quita un elemento de la cola y retorna su valor
itemC quitarDeCola(cola *col);

//vacia una cola completa
void vaciarCola(cola *col);

// devuelve el tamaño de una cola
int tamanioCola(cola col);


#endif
