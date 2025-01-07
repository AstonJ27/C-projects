#include "item.h"

//*******************************|    FUNCIONES DEL TIPO ITEM    |*********************************//

item preparar(tipo_dato tipo, void *valor, size_t tam){
    item nuevo;
    nuevo.tipo = tipo;
    nuevo.dato = malloc(tam);
    if(nuevo.dato == NULL){
        perror("error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    memcpy(nuevo.dato, valor, tam);
    return nuevo;
}

void liberar_item(item *entrada){
    if(entrada->dato != NULL){
        free(entrada->dato);
        entrada->dato = NULL;
    }
}

//muestra el item, si es una estructura, pasar el puntero a la funcion
//que la muestra, caso contrario poner NULL 
void mostrar_item(item entrada, void (*imprimir)(void *)){
    switch(entrada.tipo){
        case INT:
            printf("%d ", *(int*)entrada.dato);
        break;
        case FLOAT:
            printf("%f ", *(float*)entrada.dato);
        break;
        case CHAR:
            printf("%c ", *(char*)entrada.dato);
        break;
        case DOUBLE:
            printf("%f ", *(double*)entrada.dato);
        break;
        case STRING:
            printf("%s ", (char*)entrada.dato);
        break;
        case STRUCT:
            if(imprimir != NULL){
                imprimir(entrada.dato);
            }else{
                perror("no hay funcion definida para imprimir el dato\n");
                exit(1);
            }
        break;
        default:
        break;
    }    
    
}