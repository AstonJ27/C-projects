#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define Q "\e[38;5;226m"
#define reset "\033[0m"
// este algoritmo dara una solucion al problema de las n reinas de un tablero utilizando solo un vector
void inicializar(int tablero[], int n){
    for(int i=0; i<n; i++){
        tablero[i] = -1;
    }
}
void mostrar(int tablero[], int n){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
        {
            if(i==tablero[j]){
                printf("[" Q"*"reset "]");
            }else{
                printf("[ ]");
            }
        }
        printf("\n");
    }
}

int dist(int a, int b){
    if((a-b) < 0){
        return (a-b)*-1;
    }
    return (a-b);
}
int exito = 0; //global

int validar(int tablero[], int etapa, int pos){
    for(int i = 0; i < etapa; i++){
	//si la fila es igual a la otra fila o distancia de filas es igual a distancia de columnas        
	if(tablero[i] == pos || dist(tablero[i],pos) == dist(i,etapa)){ 
            //para que una reina este en la diagonal de otra la distancia de filas debe ser igual a la de columnas
            return 0;
        }
    }
    return 1;
}
int a;
void reinas(int tablero[], int n,int etapa){
    if(etapa > n){
	printf("XD\n");        
	return;//false (llegamos mas alla de donde podemos acceder, eso significa que no se ha encontrado una solucion)
    }
    int i = -1;
    //tablero[etapa] = -1;
    while (i < n-1){
        i++;
        if(validar(tablero,etapa,i)){
            tablero[etapa] = i;
            /*printf("etapa %d",etapa);
            scanf("%d",&a);*/
            if(etapa == n-1){
                exito += 1;
            }
            else{
                reinas(tablero,n,etapa+1);
            }
		    //borrar paso
            tablero[etapa] = -1;
	    }
    }
    return;//true
}

int main(int argc, char const *argv[])
{
    //* se usa la estructura time val para declarar variables que tomen el tiempo desde el inicio de la funcion hasta el final de ella
    struct timeval start, end;
    double elapsed;
    // empieza el cronometro
    gettimeofday(&start, NULL);
    int n;
    if(argc == 1){
        n = 4;
    }else{
        n = atoi(argv[1]);
    }
    if(1){
        //int n = atoi(argv[1]);
        int tablero[n];
        
        inicializar(tablero, n);
        reinas(tablero,n,0);
        
        if(exito){
            printf("si hay solucion\n");
        
            /*for(int i = 0; i < n; i++){
                printf(" %d ",tablero[i]);
            }
            printf("\n");
            mostrar(tablero,n);*/
            printf("\nexisten %d soluciones\n",exito);
            
            //calculo del tiempo de ejecucion
            gettimeofday(&end, NULL);
            elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
            printf("Tiempo de ejecución: %f segundos\n",elapsed);
        }else{
            printf("no hay solucion\n");

            gettimeofday(&end, NULL);
            elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
            printf("Tiempo de ejecución: %f segundos\n",elapsed);

        }
    }else{
        printf("Uso: %s <numero_de_reinas>\n",argv[0]);

    }
    return 0;
}
