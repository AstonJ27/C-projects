#ifndef _ITEM_H
#define _ITEM_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef enum{
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
    STRING,
    STRUCT
} tipo_dato;

typedef  struct{
    tipo_dato tipo;
    void* dato;
} item;

//*******************************|    FUNCIONES DEL TIPO ITEM    |*********************************//
// convierte un tipo de dato en item para empaquetarlo y usarlo
item preparar(tipo_dato tipo, void *valor, size_t tam);
// libera la memoria asignada del tipo item
void liberar_item(item *entrada);

//muestra el item, si es una estructura, pasar el puntero a la funcion
//que la muestra, caso contrario poner NULL 
void mostrar_item(item entrada, void (*imprimir)(void *));

#endif