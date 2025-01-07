#include <stdio.h>
#define MAX 50
#define true 1
#define false 0
typedef int bool;

void mostrar(int matriz[][MAX],int dim){
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void solucion(int camino[MAX], int tam){
    printf("solucion:\n");
    for(int i = 0; i < tam; i++){
        printf("%d ", camino[i]+1);
    }
    printf("\n");
}

void viaje(bool matriz[][MAX], int dim, int vi, int vf, bool visitado[MAX],int camino[MAX], bool *exito, int *i){
    int k;
    k=-1;
    while(k+1 < dim && !*exito){
        k++;// posibilidad
        if(matriz[vi][k] && !visitado[k]){
            
            visitado[k]=true;
            camino[*i]=k;
            *i= *i + 1;
            
            if(k == vf){
                *exito = true;
                solucion(camino,*i);
            
            }else{
                
                viaje(matriz, dim, k, vf, visitado, camino, exito,i);
                
                if(!*exito){
                    *i= *i - 1;
                    camino[*i] = -1;
                    visitado[k] = false;
                }
            }
        }
    }
}
int main(){

    FILE *in;
    int dim, camino[MAX], i;
    bool exito, visitado[MAX];
    in = fopen("../grafo.txt","r");
    bool grafo[MAX][MAX];
    
    if(in == NULL){
        printf("archivo no encontrado");
        return 1;
    }else{
        fscanf(in,"%d",&dim);
        if(dim > MAX){
            printf("el grafo es demasiado grande");
            return 1;
        }
    }
    exito = false;
    
    for (int i = 0; i < dim; i++){
        visitado[i] = false;
        camino[i] = -1;
    }

    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            fscanf(in,"%d",&grafo[i][j]);
        }
    }
    fclose(in);
    //mostrar(grafo,dim);
    i = 0;
    visitado[i]=true;
    camino[i] = 0;
    i++;
    viaje(grafo,dim,0,7,visitado,camino,&exito,&i);
    
        if(!exito){
            printf("no hay camino\n");
        }
    
    return 0;
}



