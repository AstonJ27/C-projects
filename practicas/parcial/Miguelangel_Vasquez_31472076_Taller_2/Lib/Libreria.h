#ifndef _OWN_LPC_H_
#define _OWN_LPC_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo
{
    int info;
    struct nodo *prox;
};
typedef struct nodo nodo;

/*----------------------------------------LISTAS SIMPLEMENTE ENLAZADAS-------------------------------------------*/

nodo *createList();
//inicia el primer elemento de la lista como una cabecera

nodo *addEndList(nodo *pointer, int data);
//agrega un elemento al final de la lista

nodo *addStartList(nodo *pointer, int data);
//agrega un elemento al principio de la lista

nodo *ElementList(nodo *pointer, int position);
//extrae en un nodo con cabecera el elemento indicado de la lista

int lenghtList(nodo *pointer);
//muestra la longitud de la lista

nodo *deleteElementList(nodo *pointer, int pos);
//elimina en base a la posicion un elemento de la lista

nodo *deleteList(nodo *pointer);
//elimina completamente la lista dada

void showList(nodo *pointer);
//muestra todos los elementos de la lista

nodo *mergeList(nodo *lista1, nodo *lista2);
//le agrega a la lista1 la lista2 en secuencia para funcionarlas

void splitList(nodo *lista, nodo *split1, nodo *split2, int divide);
//divide la lista original en dos splits en base a la posicion mitad indicada

nodo *quickSortList(nodo *pointer);
//ordena los elementos de la lista

int searchList(nodo *pointer, int num, int pos);
//busca un elemento en una lista obligatoriamente ordenada

void uniqueList(nodo *pointer);
//elimina los elementos repetidos de una lista

/*----------------------------------------PILAS---------------------------------------------------------*/

nodo *createPill(int data);
//crea una pila

nodo *addEndPill(nodo *pill, int data);
//añade un valor al final de la pila

nodo *addStartTail(nodo *pill, int data);
//añade un valor al principio de la pila

nodo *deleteEndPill(nodo *pill);
//elimina el ultimo elemento de la Pila

int lenghtPill(nodo *pointer);
//muestra la longitud de la Pila

nodo *deletePill(nodo *pill);
//elimina la pila

int climbElementPill(nodo *pill);
//explusa el ultimo elemento de la pila

int extratClimbPill(nodo *pill);
//extrae el ultimo elemento de la pila y lo elimina

void showPill(nodo *pill);
//muestra todos los elementos de la Pila

/*----------------------------------------COLAS--------------------------------------------------------*/

nodo *createTail(int data);
//crea una Cola

int lenghtTail(nodo *pointer);
//muestra la longitud de la Cola

nodo *addEndTail(nodo *tail, int data);
//añade un valor al final de la Cola

nodo *deleteStartTail(nodo *tail);
//elimina el ultimo elemento de la Cola

nodo *deleteTail(nodo *tail);
//elimina la Cola

int climbElementTail(nodo *tail);
//explusa el primer elemento de la Cola

int extratClimbTail(nodo *tail);
//extrae el primer elemento de la cola y lo elimina de la misma 

void showTail(nodo *tail);
//muestra todos los elementos de la Cola

#endif