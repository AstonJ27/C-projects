#include "cartas.h"
#include "../colores/colores.h"

int main(){
    carta A;
    A = crear_carta("+4","comodin",true);
    //printf("carta creada\n");
    mostrar_carta(A);
    carta B = crear_carta("2","rojo",false);
    mostrar_carta(B);
    if(es_jugable(B,A)){
        printf("la carta A es jugable\n");
    }
    if(strcmp(A.color, "comodin")==0){
        comodin(&A);
        printf("es comodin\n");
    }
    if(!es_carta_nula(A)){
        printf("la carta no es nula\n");
    }
    mostrar_carta(A);
    return 0;
}

