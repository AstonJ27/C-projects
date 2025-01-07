#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

#define N 8
#define mov_cab 8
#define META N*N
#define mx 1
#define my 0

typedef struct caballo{
    short x;
    short y;
    short movimientos[mov_cab][2];
}caballo;

typedef struct problema{
    short tablero[N][N];
    short etapa;
    caballo cab;
    bool exito;
} problema;

void mostrar(short tablero[N][N]){
    for(int i = 0;i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%02d ",tablero[i][j]);
        }
        printf("\n\n");
    }
}

bool alternativa_valida(problema problem, int alt){
    //comprobamos que no se sale del tablero
    bool salida = true;
    short pos_x = problem.cab.x + problem.cab.movimientos[alt][mx];
    short pos_y = problem.cab.y+problem.cab.movimientos[alt][my];
    
    if(pos_x < 0 || pos_x >= N || pos_y < 0 || pos_y >= N){
        salida = false;
    }else if(problem.tablero[pos_x][pos_y] != 0){
        salida = false;
    }

    return salida;

}


void recorrido_caballo(problema *prob){
    //inicializar alternativas (movimientos)
    int i = -1;
    while(i < mov_cab - 1){
        i++;
        if(alternativa_valida(*prob,i)){
            //dar paso
            prob->cab.x += prob->cab.movimientos[i][mx];
            prob->cab.y += prob->cab.movimientos[i][my];
            prob->etapa += 1;
            prob->tablero[prob->cab.x][prob->cab.y] = prob->etapa;
            //si es solucion
            if(prob->etapa == META){
                mostrar(prob->tablero);
                prob->exito = true;
            }else{
                recorrido_caballo(prob);
            }
            if(!(prob->exito)){
                //borrar paso
                prob->tablero[prob->cab.x][prob->cab.y] = 0;
                prob->etapa -= 1;
                prob->cab.x -= prob->cab.movimientos[i][mx];
                prob->cab.y -= prob->cab.movimientos[i][my];
            }

        }
    }
}


int main(){
	struct timeval start, end;
    	double elapsed;
    	gettimeofday(&start, NULL);    

	problema prob ={
        .cab.x = 0,//(N/2)-1,
        .cab.y = 1,//(N/2)-1,
        .etapa = 1,
        .exito = false,
        .cab.movimientos={
            {2,1},{2,-1},{-2,1},{-2,-1},
            {1,2},{-1,2},{1,-2},{-1,-2}
        }
    }; 
    //inicializar tablero
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            prob.tablero[i][j] = 0;
        }
    }
    //inicializar caballo
    prob.tablero[prob.cab.x][prob.cab.y] = 1;
    recorrido_caballo(&prob);
    if(!prob.exito){
        printf("\nno hay solucion\n");
    }

	gettimeofday(&end, NULL);
	    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
	    printf("Tiempo de ejecución: %f segundos\n",elapsed);


    for(int i = 0;i < META; i++){
        printf("%c",'\7');
    }
    return 0;
}
