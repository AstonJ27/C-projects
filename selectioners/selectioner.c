#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>


// Función para configurar el terminal para lectura sin bloqueo
void configure_terminal() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO); // Desactivar el modo canónico y el eco
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Función para restaurar la configuración original del terminal
void restore_terminal() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO); // Restaurar el modo canónico y el eco
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Función para leer una tecla sin esperar por el Enter
int getch() {
    int ch = getchar();
    return ch;
}

int main() {
    // Configurar el terminal
    configure_terminal();

    // Números a mostrar
    const char *numeros[] = {"1", "2", "3", "4"};
    int num_count = sizeof(numeros) / sizeof(numeros[0]);

    int seleccion = 0;

    while (1) {
        // Limpiar la pantalla
        printf("\033[2J\033[H");

        // Mostrar los números con el selector en una fila
        for (int i = 0; i < num_count; ++i) {
            if (i == seleccion) {
                // Resaltar el número seleccionado
                printf("\033[32m> %s \033[0m", numeros[i]); // Verde
            } else {
                printf("  %s ", numeros[i]);
            }
        }
        printf("\n");

        // Leer la entrada del usuario
        int ch = getch();
        switch (ch) {
            case 'q':
                // Salir del programa
                restore_terminal();
                return 0;
            case 'A': // Tecla de flecha arriba (no se usa)
            case 'B': // Tecla de flecha abajo (no se usa)
                break;
            case 'C': // Tecla de flecha derecha
                if (seleccion < num_count - 1) {
                    ++seleccion;
                }
                break;
            case 'D': // Tecla de flecha izquierda
                if (seleccion > 0) {
                    --seleccion;
                }
                break;
            case '\n': // Enter
                printf("Seleccionaste el número: %s\n", numeros[seleccion]);
                restore_terminal();
                return 0;
        }
    }

    // Restaurar la configuración original del terminal antes de salir
    restore_terminal();
    return 0;
}

