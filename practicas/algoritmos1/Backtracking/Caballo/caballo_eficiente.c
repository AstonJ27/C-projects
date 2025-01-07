#include <stdio.h>

#define N 8

// Definir colores utilizando códigos ANSI
#define blanco "\e[48;5;7m"
#define negro "\e[48;5;16m"
#define tnegro "\e[38;5;16m"
#define amarillo "\e[38;5;226m"
#define reset "\033[0m"
#define freset "\033[0;m"

int tab[N + 1][N + 1];
int movimiento[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

// Función para imprimir el resultado
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

// Función recursiva para resolver el Problema del Caballo
int caballo(int i, int Posx, int Posy) {
    int Cx, Cy, Mov;
    if (i == N * N + 1) {
        return 1; // Solución encontrada
    }

    for (Mov = 0; Mov < 8; Mov++) {
        Cx = Posx + movimiento[Mov][0];
        Cy = Posy + movimiento[Mov][1];
        if ((Cx >= 1) && (Cx <= N) && (Cy >= 1) && (Cy <= N) && (tab[Cx][Cy] == 0)) {
            tab[Cx][Cy] = i;
            if (caballo(i + 1, Cx, Cy)) {
                return 1;
            }
            tab[Cx][Cy] = 0;
        }
    }

    return 0; // No se encontró solución
}

int main() {
    int solucion;
    tab[1][2] = 1; //(y,x)
    if (caballo(2, 1, 2)) { // posicion (x,y)
        printf("El problema tiene solución:\n");
        PresentaResultado();
    } else {
        printf("No se ha encontrado solución al problema.\n");
    }
    return 0;
}
