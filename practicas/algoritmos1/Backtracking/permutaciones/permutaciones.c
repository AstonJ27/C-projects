#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 3
typedef struct problema{
    short conjunto[MAX];
    bool puesto[MAX];
    short solucion[MAX];
    int combinaciones;
    short etapa;
    
} problema;

void mostrar(problema *prob){
    for(int i = 0; i < MAX; i++){
        printf("%d ",prob->solucion[i]);
    }
    printf("\n");
}


void permutaciones(problema *prob){
    int i = -1;
    while(i < MAX-1){
        i++;
        //posibilidad valida
        if(!prob->puesto[i]){
            
            prob->puesto[i] = true;
            prob->solucion[prob->etapa] = prob->conjunto[i];
            prob->etapa +=1;
            if(prob->etapa == MAX){
                prob->combinaciones += 1;
                mostrar(prob);
            }else{
                permutaciones(prob);
            }
            prob->etapa--;
            prob->puesto[i] = false;

        }   
    }


}

int main(){
    //int cero = 0;
    problema prob ={
        .puesto = {0,0,0},
        .etapa = 0,
        .combinaciones = 0
    };
    for(int i =0; i < MAX ;i++){
        prob.conjunto[i] = i+1;
    }
    permutaciones(&prob);
    printf("hay %d permutaciones\n",prob.combinaciones);

    /*
        printf("tamaño entero: %ld tamaño booleano %ld, tamaño caracter %ld\n",sizeof(int),sizeof(bool), sizeof(char));
        printf("tamaño de la estructura: %ld tamaño de puntero int: %ld\n",sizeof(problema),sizeof(int*));
        printf(" short mas grande: %d\n",SHRT_MAX);
    */
    return 0;
    
}