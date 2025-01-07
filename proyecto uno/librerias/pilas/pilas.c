#include "pilas.h"

//*******************************|    FUNCIONES DEL TIPO PILA    |*********************************//

// crea una pila
pila crear_pila(tipo_dato tipo, size_t tam ,void (*imprimir)(void*)){
    pila nueva;
    nueva.total = 0;
    nueva.dato_arbitrario = tipo;
    nueva.imprimir = imprimir;
    nueva.cima = NULL;
    nueva.tam = tam;
    return nueva;
}

// se encarga de agregar un dato a la pila
void apilar(pila *p, void *dato,tipo_dato tipo){
    if(p->dato_arbitrario != tipo){
        perror("dato no admitido\n");
        return;
    }
    
    //aqui se crea el item reservando memoria
    item nuevo_item = preparar(tipo, dato, p->tam);

    //aqui se crea el nodo reservando memoria
    nodo *nuevo_nodo = (nodo*)malloc(sizeof(nodo));
    if(nuevo_nodo == NULL){
        perror("error al asignar memoria a nodo de pila\n");
        exit(EXIT_FAILURE);
    }

    nuevo_nodo->contenido = nuevo_item;
    nuevo_nodo->siguiente = p->cima;
    p->cima = nuevo_nodo;
    p->total = p->total+1;
    return;
}

// se encarga de eliminar un dato de la pila
void *desapilar(pila *p){
    if(p->cima == NULL){
        perror("pila vacia\n");
    }else{
        //item item = p->cima->contenido;
        
        nodo *aux = p->cima;
        p->cima = p->cima->siguiente;
        /*arreglo estatico que guarda el dato sacado sin reservar
        memoria dinamica, IMPORTANTE: una vez retornado el dato, debe usarse
        antes de volver a desapilar
        */
        static char buffer[sizeof(int)];
        memcpy(buffer, aux->contenido.dato, p->tam);
        
        //libera la memoria dinamica asignada
        liberar_item(&(aux->contenido));
        free(aux);
        return buffer;
    }
}

// se encarga de eliminar todos los datos de la pila
void eliminar_pila(pila *p){
    while(p->cima != NULL){
        nodo *aux = p->cima;
        p->cima = p->cima->siguiente;
        liberar_item(&(aux->contenido));
        free(aux);
    }
    //reiniciar los campos
    p->total = 0;
    p->cima = NULL;
    p->imprimir = NULL;
}

// se encarga de imprimir todos los datos de la pila
//no se debe usar sino en casos de prueba
//dado que la manera de trabajarlo rompe con la definicion de pila
void imprimir_pila(pila *p){
    nodo *aux = p->cima;
    while(aux != NULL){
        mostrar_item(aux->contenido, p->imprimir);
        aux = aux->siguiente;
    }
    printf("\n");
}
