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
}objeto;

class mochila{
    int stack[total_objetos]; //se inicializa en -1, si no se tomó es 0 y si se tomó es 1
    int peso_max, peso_actual;
    int valor_total;
}mochila;

void mostrar_bolso(mochila bolso, objeto obj[total_objetos]){
    for(int i = 0;i<total_objetos;i++){
        if(bolso.stack[i] == 1){
            printf("(%dk,%d$) ",obj[i].peso,obj[i].costo);
        }
    }
    printf("\n");
}
//pega en b lo que hay en a
void preparar_salida(mochila a, mochila *b){
    b->peso_actual = a.peso_actual;
    b->valor_total = a.valor_total;
    for(int i = 0;i<total_objetos;i++){
        b->stack[i] = a.stack[i];    
    }
}

// ultimo controla el ultimo objeto metido en el bolso
void llenar_con_mayor_costo(objeto mesa[total_objetos],mochila bolso,mochila *salida, int etapa, int *sol_op){
    //inicializar alternativas
    int i = -1;
    while (i < 1){
        i++;
        // alternativa valida
        if(mesa[etapa].peso <= bolso.peso_max - bolso.peso_actual /*|| i == 0*/){
            //dar el paso
            bolso.stack[etapa] = i;
            if(i == 1){
                bolso.peso_actual += mesa[etapa].peso;
                bolso.valor_total += mesa[etapa].costo;
            }
            etapa++;
            //si es solucion
            if(etapa == total_objetos){
                //si es la mas optima
                if(bolso.valor_total > *sol_op){
                    //actualizar salida 
                    *sol_op = bolso.valor_total;
                    preparar_salida(bolso, salida);

                }
            }else{
                llenar_con_mayor_costo(mesa,bolso,salida,etapa,sol_op);
            }
            
            //borrar paso
            etapa--;
            if(etapa == -1){
                printf("error de etapa\n");
            }
            if(bolso.stack[etapa] == 1){
                bolso.peso_actual -= mesa[etapa].peso;
                bolso.valor_total -= mesa[etapa].costo;

            }
            bolso.stack[etapa] = -1;
        
        }//en if
        /* code */
    }//end while
    
}


int main(){
    srand(time(NULL));
    
    // {{12,4},{1,2},{4,10},{1,1},{2,2}};
    // {{8,5},{3,7},{5,10},{7,1},{4,14}};
    // 
    objeto mesa[total_objetos] = {{7,8},{9,2},{3,10},{5,5},{1,12}};
    mochila bolso, salida = {.peso_max = total_peso, .peso_actual=0, .valor_total=0, .stack={-1,-1,-1,-1,-1}};
    for(int i = 0; i < total_objetos; i++){
        bolso.stack[i] = -1;
    }
    
    bolso.peso_max = total_peso;
    bolso.peso_actual = 0;
    bolso.valor_total = 0;
    int sol_op = 0;
    int etapa = 0;
    llenar_con_mayor_costo(mesa,bolso,&salida,etapa,&sol_op);
    printf("precio: %d\npeso: %d\n",sol_op,salida.peso_actual);
    mostrar_bolso(salida,mesa);
    return 0;
}