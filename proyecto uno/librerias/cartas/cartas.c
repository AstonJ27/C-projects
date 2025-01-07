#include "cartas.h"
//*******************************|    FUNCIONES BASICAS   |*********************************//
// crea una carta a partir de ciertos datos
carta crear_carta(char valor[3], char colores[MIN_ARREGLO], bool especial){
    carta A;
    //dar valor
    reestablecer(A.valor,sizeof(A.valor));
    
    strcpy(A.valor, valor);
    strcpy(A.color,colores);
    
    //dar color
    if(strcmp(colores,"rojo")==0){
        formatear(A.valor,sizeof(A.valor),ROJO,NULL,NEGRITA);

    }else if(strcmp(colores,"verde")==0){
        formatear(A.valor,sizeof(A.valor),VERDE,NULL,NEGRITA);

    }else if(strcmp(colores,"azul")==0){
        formatear(A.valor,sizeof(A.valor),AZUL,NULL,NEGRITA);

    }else if(strcmp(colores,"amarillo")==0){
        formatear(A.valor,sizeof(A.valor),AMARILLO,NULL,NEGRITA);

    }else if(strcmp(colores,"comodin")==0){
        formatear(A.valor,sizeof(A.valor),BLANCO,NULL,NEGRITA);
    }else{
        A.color[0] = '\0';
    }
    //asignar si es especial
    A.especial = especial;
    
    return A;
}

// se encarga de mostrar la carta
void mostrar_carta(carta A){
    printf("%s\n",A.valor);
}

// si una carta es comodin cambia su color al color escogido por el usuario
void comodin(carta *A){
    if(strcmp(A->color,"comodin") != 0 && !A->especial){
        printf("la carta no es un comodin\n");
        return;
    }else{
        printf("ingrese el color que quiere que tenga el comodin\n");
        char color[10];
        color[0] = '\0';
        
        do{
            scanf("%s",color);
            *A = crear_carta(A->valor,color,true);

        }while(A->color[0] == '\0');
    }

}

// verifica si una carta es nula o no
bool es_carta_nula(carta A){
    carta B = CARTA_NULA;
    bool salida;
    salida = false;
    if(strcmp(A.valor,B.valor)==0 || A.color == B.color){
        salida = true;
    }
    return salida;
}

// verifica si una carta puede ponerse sobre otra (si es jugable)

bool es_jugable(carta actual, carta nueva){
    bool salida;
    salida = false;
    if(strcmp(actual.valor,nueva.valor) == 0 || strcmp(actual.color,nueva.color) == 0){
        salida = true;
    }else if(strcmp(nueva.color, "comodin") == 0){
        salida = true; // si es comodin puede ponerse sobre cualquier carta
    }
    return salida;
}