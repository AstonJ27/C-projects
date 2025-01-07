#include <stdio.h>
#include <stdlib.h>
#define cantidad_colores 5
#define dimension_grafo 8



typedef struct problema problema;
//typedef struct grafo grafo;

struct problema{
    int color[dimension_grafo];
    int matriz_grafo[dimension_grafo][dimension_grafo];

    //nodo A;
    int etapa;
};

int alternativa_valida(problema prob, int color){
    int valido = 1;
    for(int i = 0; i< dimension_grafo ;i++){
        //si es adyacente
        if(prob.matriz_grafo[prob.etapa][i]){
            //si sus colores son iguales
            if(prob.color[i] == color){
                valido = 0;
                return valido;
            }        
        }
    }
    return valido;
}

void mostrar(problema prob){
    for(int i = 0; i<dimension_grafo;i++){
        printf("nodo %d: %d adyacentes (nodo,color):",i+1,prob.color[i]+1);
        for(int j=0;j<dimension_grafo;j++){
            if(prob.matriz_grafo[i][j]){
                printf("(%d,%d)",j+1,prob.color[j]+1);
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

void pintar_grafo(problema prob, int *band){
    int i = -1;
    while(i < cantidad_colores-1){
        i++;
        //si alternativa valida
        if(alternativa_valida(prob, i)){
            // dar el paso
            prob.color[prob.etapa] = i;
            prob.etapa++;
            //si solucion encontrada
            if(prob.etapa == dimension_grafo){
                //mostrar(prob);
                
                *band = *band+1;
            }else{
                pintar_grafo(prob,band);
            }
            //borrar paso
            prob.etapa--;
            prob.color[prob.etapa] = -1;

            /*if(!(*band)){
                prob.etapa--;
                prob.color[prob.etapa] = -1;

            }else{
                return;
            }*/

        }// end if
    }// end while

}// end proc



int main(){
    problema prob={.etapa = 0, .color = {-1,-1,-1,-1,-1,-1,-1,-1},
        .matriz_grafo = {
            {0,1,1,0,0,0,0,0},
            {1,0,0,1,0,0,0,0},
            {1,0,0,0,1,0,0,0},
            {0,1,0,0,1,0,0,0},
            {0,0,1,1,0,1,1,0},
            {0,0,0,0,1,0,0,1},
            {0,0,0,0,1,0,0,0},
            {0,0,0,0,0,1,0,0}
        }
    };
    int band = 0;
    pintar_grafo(prob,&band);
    printf("hay %d soluciones para el grafo dado de 8 nodos y 3 colores\n",band);


    return 0;
}
