#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} posicion;

posicion jugador_posicion;
posicion zona_segura;
int jugador_vida = 10;
int turnos = 0;

void generar_zona_segura(int dificultad) {
    srand(time(NULL));
    zona_segura.x = rand() % (10 - 8 + 1);
    zona_segura.y = rand() % (10 - 8 + 1);
}

void Consola() {
    printf("\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == jugador_posicion.x && i == jugador_posicion.y) {
                printf("P ");
            } else if (j >= zona_segura.x && j < zona_segura.x + 8 && i >= zona_segura.y && i < zona_segura.y + 8) {
                printf("S ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void mover(char direccion) {
    switch (direccion) {
        case 'w':
            if (jugador_posicion.y > 0) {
                jugador_posicion.y--;
            }
            break;
        case 's':
            if (jugador_posicion.y < 9) {
                jugador_posicion.y++;
            }
            break;
        case 'a':
            if (jugador_posicion.x > 0) {
                jugador_posicion.x--;
            }
            break;
        case 'd':
            if (jugador_posicion.x < 9) {
                jugador_posicion.x++;
            }
            break;
        default:
            break;
    }
}

int main() {
    int dificultad;

    printf("Bienvenido al juego!\n");
    printf("Por favor, selecciona la dificultad (1-Fácil, 2-Normal, 3-Difícil): ");
    scanf("%d", &dificultad);

    generar_zona_segura(dificultad);

    jugador_posicion.x = zona_segura.x + rand() % 8;
    jugador_posicion.y = zona_segura.y + rand() % 8;

    while (jugador_vida > 0) {
        Consola();

        char direccion;
        printf("Ingresa una dirección para mover al jugador (w/a/s/d): ");
        scanf(" %c", &direccion);

        mover(direccion);

        turnos++;

        if (turnos % (12 - dificultad * 2) == 0) {
            generar_zona_segura(dificultad);
        }

        if (jugador_posicion.x < zona_segura.x || jugador_posicion.x >= zona_segura.x + 8 || jugador_posicion.y < zona_segura.y || jugador_posicion.y >= zona_segura.y + 8) {
            jugador_vida--;
            printf("¡Fuera de la zona segura! Pierdes 1 punto de vida. Vida restante: %d\n", jugador_vida);
        } else {
            printf("Dentro de la zona segura. Vida restante: %d\n", jugador_vida);
        }
    }

    printf("¡Juego terminado! Tu vida ha llegado a cero. Gracias por jugar.\n");

    return 0;
}