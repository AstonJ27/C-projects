//todas las soluciones
#include <stdio.h>
#define MAX 4
void mostrar(char mat[][6]){
    for(int i = 0; i < 5;i++){
        for(int j = 0; j <= 5; j++){
            printf("%c",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// debe volverse local derecha abajo izquierda arriba

//mat[5][6]
void laberinto(char mat[][6],int x, int y, int pos[][2]){
    int i = 0, j = 0; // inicializar posibilidades
    
    while(x+pos[i][j] < 5 && x+pos[i][j] >= 0 && y+pos[i][j+1] < 6 && y+pos[i][j+1] >= 0 && i < MAX){ // posicion
        
        if(mat[x+pos[i][j]][y+pos[i][j+1]] == 'v' || mat[x+pos[i][j]][y+pos[i][j+1]] == '*'){ // posicion valida
            //damos el paso
                x = x+pos[i][j];
                y = y+pos[i][j+1];            

            if(mat[x][y] == 'v'){ // se encontro una solucion
                mostrar(mat);
            
            }else{ // no es solucion

                mat[x][y] = 'X';
                //mostrar(mat);

                laberinto(mat,x,y,pos);
                
                // borrar paso
                
                //mostrar(mat);

            }
	if(mat[x][y] == 'X'){
		mat[x][y] = '*';

	}
	
        x = x-pos[i][j];
        y = y-pos[i][j+1];        
}
        i++; //siguiente opcion
    }
}

int main(){
    FILE *in;
    int pos[MAX][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int x = 0, y = 0;
    char mat[5][6];
    in = fopen("../laberinto.txt","r");
    if(in == NULL){
        printf("archivo no encontrado\n");
        return 1;
    }
    
    for(int i = 0;i < 5; i++){
        for(int j = 0; j <= 5; j++){
            fscanf(in,"%c\n",&mat[i][j]);
        }
    }
    fclose(in);
    
    mat[x][y] = 'X'; //inicializar posicion de entrada
    printf("laberinto:\n");
    mostrar(mat);
    printf("\n");
    
    printf("solucion:\n");
    laberinto(mat,x,y,pos); //laberinto imprime automaticamente la solucion
    return 0;
}
