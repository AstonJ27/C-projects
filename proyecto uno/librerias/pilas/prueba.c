#include "pilas.h"
#include "../listas/listas.h"

typedef struct prueba{
    int valor;
    float flotant;
} prueba;

void mostrar_prueba(void *prueb){
    prueba a = *(prueba*)prueb;
    printf("(%d,%.1f)",a.valor,a.flotant);
}
int main(){
    // prueba con enteros
    pila int_p1;
    int_p1 = crear_pila(INT,sizeof(int),NULL);
    for(int i = 1; i <= 5; i++){
        apilar(&int_p1,&i,INT);
    }
    imprimir_pila(&int_p1);
    pila int_p2 = crear_pila(INT,sizeof(int),NULL);

    //nodo *aux = int_p1.cima;
    //nodo *aux2 = int_p2.cima;
    while(int_p1.cima != NULL){
        apilar(&int_p2,desapilar(&int_p1), INT);    
    }
    if(int_p2.cima != NULL){
        imprimir_pila(&int_p2);
    }
    eliminar_pila(&int_p2);

    eliminar_pila(&int_p1);
    //prueba con estructuras
    pila pila_struct = crear_pila(STRUCT,sizeof(prueba),&mostrar_prueba);
    float a = 1.0;
    for(int i = 1; i <= 5; i++){
        prueba p;
        p.valor = i;
        p.flotant = a;
        a += 0.1;
        apilar(&pila_struct,&p,STRUCT);

    }

    imprimir_pila(&pila_struct);
    
    eliminar_pila(&pila_struct);
    
    //prueba con listas
    
    
    return 0;
}