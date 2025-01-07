#include <stdio.h>
#define N 8
#define n (N+1)         /*Para representar el tablero en 1...n, 1...n*/
#define Ncuadrado N*N
#define true 1
#define false 0
// blanco 7 negro 16 amarillo 226
#define blanco "\e[48;5;7m"
#define negro "\e[48;5;16m"
#define tnegro "\e[38;5;16m"
#define amarillo "\e[38;5;226m"
#define reset "\033[0m"
#define freset "\033[0;m"

void caballo(int i, int Posx, int Posy, int* exito);
void PresentaResultado();
int tab[n][n];
int movimiento[8][2] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
void caballo(int i, int Posx, int Posy, int* exito){
    //esquema recursdivo de una solucion
    int Cx, Cy, Mov;
    *exito = false;
    Mov = 0;
    while ((Mov < 8) && !(*exito)){
        Cx = Posx + movimiento[Mov][0];
        Cy = Posy + movimiento[Mov][1];
        /*determina si nuevas coordenadas son aceptables*/
        if((Cx >= 1) && (Cx <= N) && (Cy >= 1) && (Cy <= N ) && tab[Cx][Cy] == 0){
            tab[Cx][Cy] = i;
            if(i < Ncuadrado){
                caballo(i+1,Cx,Cy,exito);
                if(!(*exito)){
                    /*no hay solucion*/
                    tab[Cx][Cy] = 0;
                }
            }else{
                *exito = true;
            }
        }
        Mov++;
    }
}

void PresentaResultado() {
    int i, j;
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            if ((i + j) % 2 == 0) { // Casilla blanca
                printf(blanco tnegro "%02d " reset freset, tab[i][j]);
            } else { // Casilla negra
                printf(negro "%02d " reset freset, tab[i][j]);
            }
        }
        printf("\n");
    }
    printf(reset freset);
}

int main(){
    int solucion;
    tab[N][N] = 1;
    caballo(2, N, N, &solucion);
    if(solucion){
        printf("\nEl problema tiene solucion:\n");
        PresentaResultado();
        printf(reset freset);

    }else
    {
        printf("No se ha encontrado solucion al problema\n");
    }
    return 0;
}