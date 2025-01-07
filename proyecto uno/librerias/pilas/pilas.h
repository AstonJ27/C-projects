/********************************************************************|
|    esta libreria tiene como finalidad trabajar el TDA lista        |
|    para cualquier tipo de dato nativo o estructurado.              |
|********************************************************************/
#ifndef _PILAS_H
#define _PILAS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../item/item.h"

//*******************************|    TIPOS DE DATOS    |*********************************//

typedef struct nodo{
    item contenido;
    struct nodo *siguiente;
} nodo;

typedef struct pila{
    tipo_dato dato_arbitrario;
    nodo *cima;
    int total;
    void (*imprimir)(void*);
    size_t tam;
} pila;




//*******************************|    FUNCIONES DEL TIPO PILA    |*********************************//

// se encarga de crear una pila vacia
pila crear_pila(tipo_dato tipo, size_t tam ,void (*imprimir)(void*)); //check

// se encarga de agregar un dato a la pila
void apilar(pila *p, void *dato, tipo_dato tipo);

// se encarga de eliminar un dato de la pila
void *desapilar(pila *p);

// se encarga de eliminar todos los datos de la pila
void eliminar_pila(pila *p);

// se encarga de imprimir todos los datos de la pila
//no se debe usar sino en casos de prueba
void imprimir_pila(pila *p);


#endif

