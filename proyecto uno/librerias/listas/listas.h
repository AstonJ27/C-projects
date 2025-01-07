/********************************************************************|
|    esta libreria tiene como finalidad trabajar el TDA lista        |
|    para cualquier tipo de dato nativo o estructurado.              |
|********************************************************************/
#ifndef _LISTAS_H
#define _LISTAS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../item/item.h"

//*******************************|    TIPOS DE DATOS    |*********************************//


typedef struct LISTA_nodo{
    item contenido;
    struct LISTA_nodo *siguiente;
}LISTA_nodo;

typedef struct lista{
    int total;
    LISTA_nodo *primero;
    tipo_dato dato_arbitrario;
    void (*imprimir)(void*); //puntero a funcion para poder imprimir estructuras definidas por algun usuario
    size_t tam;
} lista;

//*******************************|    FUNCIONES DEL TIPO LISTA    |*********************************//


/*
    funcion constructora encargada de definir una lista y el tipo que esta puede almacenar, en caso de ser una estructura
    definir tambien una funcion para poder imprimirla, caso contrario, poner NULL
*/
lista crear_lista(tipo_dato tipo, size_t tam ,void (*imprimir)(void*));


// guarda un item a la lista, si el item no es permitido se detiene la operacion sin agregarse nada
// ejemplo con tipo entero:
//int i = 0; 
//agregar(&l,&i,INT);

void agregar(lista *l, void *item, tipo_dato tipo);

//muestra los elementos de la lista
void mostrar_lista(lista l);

//quita un elemento de la lista
void quitar(lista *l, int posicion);

//operacion destructora que elimina la lista por completo liberando el espacio reservado del item y el espacio reservado del LISTA_nodo
void eliminar_lista(lista *l);

#endif
