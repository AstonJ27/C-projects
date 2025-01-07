#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct problema{
    int conjunto[MAX];
    int etapa;
    int puesto[MAX];
    int *n_sub;
} problema;

void mostrar_conjunto(problema prob){
    printf("{");
    int alguno = 0;
    for(int i = 0; i < MAX; i++){
        if(prob.puesto[i]){
            alguno += 1;
            printf("%d,",prob.conjunto[i]);
        }
    }
    if(alguno){
        printf("\b");
    }
    printf("}\n");
}

void subconjuntos(problema prob){

    int i = -1;
    while(i < 1){
        i++;
        if(!prob.puesto[prob.etapa]){
            //dar el paso
            prob.puesto[prob.etapa] = i;
            prob.etapa += 1;
            //si es solucion
            if(prob.etapa == MAX){
                *(prob.n_sub) += 1;
                printf("%02d: ",*(prob.n_sub));
                mostrar_conjunto(prob); //el imprime el conjunto y un salto de linea
            }else{
                subconjuntos(prob);
            }
            //borrar paso
            prob.etapa -= 1;
            prob.puesto[prob.etapa] = 0;
        }
    }
    
}    

int main(){
    int cero = 0;
    problema prob = {
       .etapa = 0,
        .puesto = {0,0,0,0},
        .n_sub = &cero
    };
    for (int i = 0; i < MAX; i++){
        prob.conjunto[i] = i+1;
    }
    
    subconjuntos(prob);
    printf("subconjuntos: %d\n",*(prob.n_sub));
    return 0;

}