#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/time.h>
// este programa resolvera tableros de sudoku usando Backtracking
// el tablero sera representado por una matriz de 9x9
// los valores seran representados por enteros del 1 al 9
int esta_resuelto = 0;//false

void mostrar (int const n, char tablero[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j%3==0){
                printf("    ");
            }
            printf("%c ",tablero[i][j]);
        }
        printf("\n");
        if((i+1)%3==0){
            printf("\n");
        }
    }
    printf("\n");
}
void crear(char nombre[],int const n, char tablero[n][n]){ //*tablero[] es una matriz de numeros enteros
    FILE *archivo;
    archivo = fopen(nombre, "r");
    
    if(archivo == NULL){
        printf("No se puede crear el tablero\n");
    }else{
        printf("Tablero inicial:\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                fscanf(archivo, "%c\n",&tablero[i][j]);
            }
        }   
        fclose(archivo);
    }            
}
int validar(int const n, char tablero[n][n], int pFila, int pColumna, char candidato){
    // validamos la fila    
    for(int j =0;j<n;j++){    
        if(j != pColumna && tablero[pFila][j]!= '-' && tablero[pFila][j] == candidato){
            return 0; //false
        }
    }
    //validamos la columna
    for(int i =0;i<n;i++){
        if(i != pFila && tablero[i][pColumna] != '-' && tablero[i][pColumna] == candidato){
            return 0; //false
        }
    }
    //validamos el cuadro

    int InicioFila = pFila + 1;
    while(InicioFila % 3 != 1){
        InicioFila--;
    }
    int InicioColumna = pColumna + 1;
    while(InicioColumna % 3 != 1){
        InicioColumna--;
    }

    InicioColumna--;
    InicioFila--;
    int lim_f =InicioFila+3;
    int lim_c =InicioColumna+3;
    for(int i = InicioFila; i < lim_f; i++){
        for(int j = InicioColumna; j < lim_c; j++){
            if(i != pFila && j != pColumna && tablero[i][j] != '-' && tablero[i][j] == candidato){
                return 0;//false
            }
        }
    }
    //se cumplen todas las restricciones
    return 1; //true
}

void sudoku(int const n, char tablero [n][n]){
    int es_vacia = 0;//false
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!isdigit(tablero[i][j])){ //deberia de ser un "-"
                int es_vacia = 1;//true
                int candidato = 0;
                while (!esta_resuelto && candidato < n){
                    candidato +=1;
                    if(validar(n,tablero,i,j,candidato + '0')){
                        tablero[i][j] = candidato + '0';
                        //mostrar(n,tablero);
                        sudoku(n,tablero);
                        if(!esta_resuelto){
                            tablero[i][j] = '-';
                        }
                    }
                }
                return; //no se ha colocado ningun valor volvemos atras "backtracking"
            }
        }
    }
    if(!es_vacia){
        esta_resuelto = 1; //true
    }
}

int main(int argc, char *argv[])
{
    struct timeval start, end;
    double elapsed;
    gettimeofday(&start, NULL);
    if(argc >= 3){
        int const n = atoi(argv[2]);        
        char tablero[n][n];
        
	crear(argv[1], n, tablero); //argv[1]
        mostrar(n,tablero);

        printf("tablero resuelto:\n");
        sudoku(n,tablero);
        mostrar(n,tablero);
	
        gettimeofday(&end, NULL);
        elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
        printf("Tiempo de ejecución: %f segundos\n",elapsed);
    }else{
        printf("Uso: %s <nombre_archivo> <tamaño_tablero>\n", argv[0]);
    }
    return 0;
}
