#include "listas.h"


//*******************************|    FUNCIONES DEL TIPO LISTA    |*********************************//

// funcion constructora encargada de definir una lista y el tipo que esta puede almacenar, en caso de ser una estructura definir tambien una funcion
// para poder imprimirla, caso contrario, poner NULL
lista crear_lista(tipo_dato tipo, size_t tam ,void (*imprimir)(void*)){
    lista l;
    l.dato_arbitrario = tipo;
    l.imprimir = imprimir;
    l.total = 0;
    l.primero = NULL;
    l.tam = tam;
    return l;
}

// guarda un item a la lista, si el item no es permitido se detiene la operacion sin agregarse nada
void agregar(lista *l, void *entrada, tipo_dato tipo){
    if(l->dato_arbitrario != tipo){
        perror("tipo de dato no soportado\n");
        return;
    }else{
        //crear el item
        item nuevo = preparar(l->dato_arbitrario, entrada, l->tam);

        //crear el nodo
        LISTA_nodo *nuevo_nodo = (LISTA_nodo *)malloc(sizeof(LISTA_nodo));
        if(nuevo_nodo == NULL){
            perror("error al asignar memoria a nodo\n");
            exit(EXIT_FAILURE);
        }
        
        if(l->primero == NULL){
            nuevo_nodo->contenido = nuevo;
            nuevo_nodo->siguiente = l->primero;
            l->primero = nuevo_nodo;

        }else{
            LISTA_nodo *aux = l->primero;
            while(aux->siguiente != NULL){
                aux = aux->siguiente;
            }
            
            aux->siguiente = nuevo_nodo;
            nuevo_nodo->contenido = nuevo;
            nuevo_nodo->siguiente = NULL;
            
        }
        
        l->total = l->total+1;

    }
}

//muestra los elementos de la lista
void mostrar_lista(lista l){
    LISTA_nodo *aux = l.primero;
    switch (l.dato_arbitrario){
        case INT:
            while(aux != NULL){
                printf("%d ", *(int*)aux->contenido.dato);
                aux = aux->siguiente;
            }
        
        break;

        case FLOAT:
            while(aux != NULL){
                printf("%f ", *(float*)aux->contenido.dato);
                aux = aux->siguiente;
            }

        break;
        
        case CHAR:
            while(aux != NULL){
                printf("%c ", *(char*)aux->contenido.dato);
                aux = aux->siguiente;
            }
            
        break;
        
        case DOUBLE:
            while(aux != NULL){
                printf("%f ", *(double*)aux->contenido.dato);
                aux = aux->siguiente;
            }
            
        break;

        case STRING:
            while(aux != NULL){
                printf("%s ", (char*)aux->contenido.dato);
                aux = aux->siguiente;
            }
            
        break;

        case STRUCT:
            /*
                NOTA:   es importante que el programador defina una funcion para imprimir
                el tipo de estructura que va a utilizar y  poner la funcion al inicializar
                la lista.
                ejemplo:
                typedef struct carta{
                    int valor;
                    char palo;
                } carta;

                void mostrar_carta(void *dato){
                    carta *c = (carta*)dato;
                    printf("Valor: %d, Palo: %c\n", c->valor, c->palo);
                }
                lista l = crear_lista(STRUCT, &mostrar_carta);
            */
            
            while(aux != NULL){
                l.imprimir(aux->contenido.dato);
                aux = aux->siguiente;
            }
            
        break;

        default:
        break;
    }
    printf("\n");

}

//quita un elemento de la lista
void quitar(lista *l, int posicion){
    if(l->primero == NULL){
        printf("La lista esta vacia\n");
        return;
    }
    
    if(posicion <= 0 || posicion > l->total){
        printf("La posicion no existe\n");
        return;
    }
    
    if(posicion == 1){
        LISTA_nodo *aux = l->primero;
        l->primero = l->primero->siguiente;
        l->total = l->total -1;
        
        liberar_item(&(aux->contenido));
        free(aux);
        return;
    }else{
        LISTA_nodo *aux = l->primero;
        int i = 1;
        while(aux->siguiente != NULL && i < posicion-1){
            aux = aux->siguiente;
            i++;
        }
        
        if(aux->siguiente == NULL){
            printf("La posicion no existe\n");
            return;
        }else{
            LISTA_nodo *aux2 = aux->siguiente;
            aux->siguiente = aux->siguiente->siguiente;
            l->total = l->total -1;
            liberar_item(&(aux2->contenido));
            free(aux2);
            return;
        }
    }
}

//operacion destructora que elimina la lista por completo liberando el espacio reservado del item y el espacio reservado del nodo
void eliminar_lista(lista *l){
    while(l->primero != NULL){
        LISTA_nodo *aux = l->primero;
        l->primero = l->primero->siguiente;
        liberar_item(&(aux->contenido));
        free(aux);
        l->total--;
    }
    l->imprimir = NULL;

    if(l->total != 0){
        printf("error al borrar la lista\n");

    }else{
        l->primero = NULL;
        printf("lista eliminada\n");
    }
    return;
}
