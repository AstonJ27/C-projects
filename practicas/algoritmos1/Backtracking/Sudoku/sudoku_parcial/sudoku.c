#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/time.h>
#define RUTA_ARCHIVO "tableros/ejemplo.txt"
#define MAX 9
#define LIMIT 3

typedef struct problema{
    int tablero[MAX][MAX]; //tablero de maximo 9x9
    int es_vacia; // actuara como booleano
    int n; // entrada que sera 1 2 o 3
    int ncuad; //cuadrado de n (1,4,9)
    int solucion[MAX][MAX];
    int completo; //booleano
    int completo_salida;
}problema;

void crear_problema(char archivo[], problema *prob){
    FILE *arch;
    arch = fopen(archivo,"r");
    if(arch == NULL){
        perror("no se pudo crear el tablero\n");
        exit(1);
    }else{
        
        fscanf(arch,"%d",&(prob->n));
        if(prob->n < 1 || prob->n > 3){

            perror("1 <= n <= 3\n");
            exit(EXIT_FAILURE);
        }
        
        prob->ncuad = prob->n * prob->n; //n^2
        prob->es_vacia = 0; //false
        prob->completo = 0; //false
        
        for(int i = 0; i < prob->ncuad; i++){
            for(int j = 0; j < prob->ncuad; j++){
                fscanf(arch, "%d",&(prob->tablero[i][j]));
            }
        }
        fclose(arch);
        for(int i = 0; i < prob->ncuad; i++){
            for(int j = 0; j < prob->ncuad; j++){
                prob->solucion[i][j] = 0;
            }
        }

    }
}


int validar(problema *prob,int Pfila,int Pcolumna ,int alt){
    //validamos la fila
    for(int j = 0;j < prob->ncuad;j++){    
        if(j != Pcolumna && prob->tablero[Pfila][j] != 0 && prob->tablero[Pfila][j] == alt){
            return 0; //false
        }
    }

    //validamos la columna
    for(int i = 0;i<prob->ncuad;i++){    
        if(i != Pfila && prob->tablero[i][Pcolumna] != 0 && prob->tablero[i][Pcolumna] == alt){
            return 0; //false
        }
    }

    //validar el cuadro
    int Ifila = Pfila + 1;
    while(Ifila % prob->n != 1){
        Ifila--;
    }
    
    int Icolumna = Pcolumna +1;
    while(Icolumna % prob->n != 1){
        Icolumna--;
    }
    
    Ifila--;
    Icolumna--;
    int lim_f = Ifila + prob->n;
    int lim_c = Icolumna + prob->n; 

    for(int i = Ifila; i < lim_f; i++){
        for(int j = Icolumna; j < lim_c; j++){
            if(i != Pfila && j != Pcolumna && prob->tablero[i][j] != 0 && prob->tablero[i][j] == alt){
                return 0;//false
            }
        }
    }
    //se cumplen todas las restricciones
    return 1; //true
}

void nueva_solucion(problema *prob){

    for(int i = 0; i < prob->ncuad;i++){
        for(int j = 0; j < prob->ncuad;j++){
            prob->solucion[i][j] = prob->tablero[i][j];
        }
    }

}

void mostrar(int matriz[MAX][MAX], int ncuad, int n){

    for(int i = 0; i < ncuad;i++){
        for(int j = 0; j < ncuad;j++){
            if(j % n == 0){
                printf("  ");
            }
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
        if((i+1)% n == 0){
            printf("\n");
        }
    }
    printf("\n");
}

int es_mejor(problema *prob){
    for(int i = 0; i < prob->ncuad;i++){
        for(int j = 0; j < prob->ncuad;j++){
            if(prob->tablero[i][j] < prob->solucion[i][j] || prob->solucion[i][j] == 0){
                return 1;
            }
        }
    }
    return 0;
}

void sudoku(problema *prob){
    //condiciones necesarias
    prob->es_vacia = 0;
    for(int i = 0; i < prob->ncuad; i++){
        for(int j = 0; j < prob->ncuad; j++){
            if(prob->tablero[i][j] == 0){
                //inicializar alternativas
                prob->es_vacia = 1;
                int alt = 0;
                //alternativas
                while(alt < prob->ncuad){
                    //siguiente alternativa
                    alt += 1;
                    if(validar(prob,i,j,alt) || prob->completo){
                        if(!prob->completo){
                            prob->tablero[i][j] = alt;
                        }

                        //si es solucion
                        if(prob->completo){
                           // mostrar(prob->tablero,prob->ncuad,prob->n);
                            prob->completo_salida = prob->completo;
                            prob->completo = 0;
                            if(es_mejor(prob)){
                                nueva_solucion(prob);
                            }
                        }else{
                            //seguir buscando
                            sudoku(prob);

                        }

                        if(!prob->completo){
                            //borrar paso
                            prob->tablero[i][j] = 0;
                        }

                    }

                }//end while
                
                // no encontro solucion regresa
                return;
            }
        }
    }//end for

    if(!prob->es_vacia){
        prob->completo = 1;
    }

}



int main(){
    problema prob;
    //calculo del tiempo
    struct timeval start, end;
    double elapsed;
    gettimeofday(&start, NULL);
    
    crear_problema(RUTA_ARCHIVO,&prob);

    printf("tablero inicial:\n");
    
    mostrar(prob.tablero,prob.ncuad,prob.n);

    sudoku(&prob);
    if(prob.completo_salida){
        printf("tablero final:\n");
        mostrar(prob.solucion,prob.ncuad,prob.n);
        printf("\n");
        
    }else{
        printf("NO HAY SOLUCION\n");
    }

    // terminar de contar el tiempo
    gettimeofday(&end, NULL);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Tiempo de ejecución: %f segundos\n",elapsed);

    return 0;
}