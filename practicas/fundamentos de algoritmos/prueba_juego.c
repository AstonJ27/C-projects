#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rojo     "\x1b[31m"
#define verde   "\x1b[32m"
#define blanco   "\x1b[37m"
#define amarillo  "\x1b[33m"

void limpiar();

typedef struct {
    int x;
    int y;
} posicion;

posicion jugador_posicion;
posicion zona_segura;
int jugador_vida = 10;
int turnos = 0;
int terremoto;

void generar_zona_segura() {
    srand(time(NULL));
    zona_segura.x = rand() % (10 - 4 + 1);
    zona_segura.y = rand() % (10 - 4 + 1);
}

void Consola() {
    printf("\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == jugador_posicion.x && i == jugador_posicion.y) {
                printf(amarillo "ඞ " blanco );
            } else if (j >= zona_segura.x && j < zona_segura.x + 4 && i >= zona_segura.y && i < zona_segura.y + 4) {
                printf(verde "* " blanco);
            } else {
                printf(rojo ". " blanco);
            }
        }
        printf("\n");
    }
}

void mover(char direccion) {
    int prevX = jugador_posicion.x;
    int prevY = jugador_posicion.y;

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

    // Revisar si el jugador esta en la zona segura
    if (jugador_posicion.x >= zona_segura.x && jugador_posicion.x < zona_segura.x + 4 && jugador_posicion.y >= zona_segura.y && jugador_posicion.y < zona_segura.y + 4) {
        //no pierde nada
        return;
    }
    if (prevX >= zona_segura.x && prevX < zona_segura.x + 4 && prevY >= zona_segura.y && prevY < zona_segura.y + 4) {
        jugador_vida -= 1;
    } 
    else {
        jugador_vida-=1;
    }
}

int main() {
    int dificultad;

    printf("Bienvenido al juego!\n");
    printf("Por favor, selecciona la dificultad (1-Fácil, 2-Normal, 3-Difícil): ");
    scanf("%d", &dificultad);
    system("clear");
    if (dificultad == 1) {
        terremoto = 10;
    } else if (dificultad == 2) {
        terremoto = 6;
    } else {
        terremoto = 3;
    }

    generar_zona_segura();

    jugador_posicion.x = zona_segura.x + rand() % 4;
    jugador_posicion.y = zona_segura.y + rand() % 4;

    while (jugador_vida > 0) {

        Consola();

        printf("Vida del jugador: %d\n", jugador_vida);
        printf("Posición actual: (%d, %d)\n", jugador_posicion.x, jugador_posicion.y);
        printf("turnos transcurridos: %d\n",turnos);
        char cambiar_direccion;
        printf("Por favor, ingresa una dirección para mover al jugador (w/a/s/d): ");
        scanf(" %c", &cambiar_direccion);

        mover(cambiar_direccion);

        turnos++;

        if (turnos % terremoto == 0) {
            generar_zona_segura(dificultad);
            printf(rojo "TERREMOTO\n" blanco);
            printf("La zona segura cambiara de posicion!\n");
            system("read -p 'Presione Enter para continuar' var");
        }
        system("clear");
    }

    printf("Game over! El jugador ha perdido todas sus vidas.\n");

    return 0;
}

void limpiar(){
    printf(blanco "\n");
    system("read -p 'Presione Enter para continuar' var");
    system("clear");
}    