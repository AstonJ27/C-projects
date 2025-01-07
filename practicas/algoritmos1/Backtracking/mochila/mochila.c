#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
//bromita
#define class typedef struct
#define total_objetos 5
#define total_peso 15

/*
    Este algoritmo tiene como finalidad resolver el problema de optimizacion
    de la mochila utilizando backtracking
*/

class objeto{
    int peso,costo;
    bool en_bolso;
}objeto;

class mochila{
    objeto stack[total_objetos];
    int peso_max, peso_actual;
    int valor_total;
}mochila;

void mostrar_bolso(mochila bolso){
    for(int i=0;i < total_objetos-1;i++){
        printf("(%d,%d) ",bolso.stack[i].peso,bolso.stack[i].costo);
    }
    printf("\n");
}

// ultimo controla el ultimo objeto metido en el bolso
void llenar_con_mayor_costo(objeto mesa[total_objetos],mochila *bolso, int *ultimo, int *sol_op){
    //inicializar alternativas
    int i = -1; // iterador de mesa
    while(i < total_objetos-1){
        i++;
        // si es valida
        if(mesa[i].peso <= bolso->peso_max - bolso->peso_actual && !(mesa[i].en_bolso)){
            bolso->stack[*ultimo] = mesa[i];
            bolso->peso_actual += mesa[i].peso;
            bolso->valor_total += mesa[i].costo;
            mesa[i].en_bolso = true;
            *ultimo = *ultimo + 1;
            // si es solucion
            if( i == total_objetos || bolso->peso_actual == bolso->peso_max){
                //si es mejor que la anterior
                if(bolso->valor_total > *sol_op){
                    *sol_op = bolso->valor_total;
                }
            }else{
                //si no es solucion
                //llamar recursivamente
                llenar_con_mayor_costo(mesa,bolso,ultimo,sol_op);
            }
            //si no es solucion
            //desmarcar
            bolso->peso_actual -= mesa[i].peso;
            bolso->valor_total -= mesa[i].costo;
            mesa[i].en_bolso = false;
            *ultimo = *ultimo - 1;
            
        }
    }
}


int main(){
    srand(time(NULL));
    
    objeto mesa[total_objetos]={{12,4,false},{1,2,false},{4,10,false},{1,1,false},{2,2,false}};
    mochila bolso;
    bolso.peso_max = total_peso;
    bolso.peso_actual = 0;
    bolso.valor_total = 0;
    int sol_op = 0;
    int ultimo = 0;
    llenar_con_mayor_costo(mesa,&bolso,&ultimo,&sol_op);
    printf("sol_op:%d\n",sol_op);
    mostrar_bolso(bolso);
    return 0;
}