#include <stdio.h>
#include "TDA/listas.h"

void insertar(cola *col, itemC x){
    NodoC *nuevo = crearNCola(x);
    if(isvoidC(*col)){
        col->ini = nuevo;
        col->fin = nuevo;
    }else{
        col->fin->sig = nuevo;
        col->fin = nuevo;
    }
}

int main(){
    cola a;
    crearCola(&a);
    printf("Cola creada\n");
    if(isvoidC(a)){
        int i = 1;
        while(i <= 5){
            insertarACola(&a,i);
            i++;
        }
    }
    printf("cola llena\n");
    printf("el tamaño es %d\n",tamanioCola(a));
    
    if(isvoidC(a)){
        printf("cola vacia\n");
    }
    else{
        while(!isvoidC(a)){
            printf("El elemento al principio es: %d\n",quitarDeCola(&a));
        }
        vaciarCola(&a);
    }
    
    if(isvoidC(a)){
        printf("Cola vacia\n");
    }
    else{
        printf("Cola no vacia\n");
    }
    return 0;
}