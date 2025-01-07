#include <stdio.h>
#include "TDA/listas.h"


int main(){
    /*itemDC x;
    x=6;*/
    listaDC aux,l = crearDC();
    //l = crearNDC(x);
    //aux = l;
    for(int i = 1;i <= 5;i++){

        insertarDC(&l, i, tamanioDC(l)+1);
    }
    printf("lista inicial:\n");
    imprimirDC(l, "%d");
    

    printf("lista ordenada:\n");
    ordenarDC(l); //check
    imprimirDC(l, "%d");
    printf("tamaño\n");
    printf("%d\n",tamanioDC(l));//check-------------------------
    
    
    printf("agregado 47 al final y en la tercera posicion:\n");
    insertarDC(&l, 47,tamanioDC(l)+1);
    imprimirDC(l, "%d");
    insertarDC(&l, 47,tamanioDC(l)+3);
    imprimirDC(l, "%d"); //check

    aux = recorrerDC(l,tamanioDC(l)+4);

    if(aux == NULL){
        printf("no existe sublista en la posicion dada\n");
    }else{
        printf("sublista en la posicion 4\n");
        imprimirDC(aux, "%d");
    }
    
    printf("lista desde la posicion final\n");
    listaDC f = recorrerDC(l,tamanioDC(l));//final(l);
    imprimirDC(f, "%d");

    if(existeDC(l, 47)){
        printf("el numero 47 existe en la posicion: %d ya no estara ahi\n",existeDC(l, 47));
        l = eliminarPosDC(l, existeDC(l,47));
        imprimirDC(l, "%d");
    }
    
    if(!existeDC(l, 47)){
        printf("el 47 ya no existe\n");
    }else{
        printf("el numero 47 existe en la posicion: %d ya no estara ahi\n",existeDC(l, 47));
        l = eliminarPosDC(l, existeDC(l,47));
        imprimirDC(l, "%d");
    }
    
    printf("insertado 7 al inicio\n");
//    f = recorrerDC(l,tamanioDC(l));//final(l);
    insertarIniDC(&l,7);
    imprimirDC(l, "%d");
    

    eliminarDC(&l);
    crearDC(aux);
    printf("lista eliminada correctamente\n");
    imprimirDC(l, "%d");
    return 0;

}