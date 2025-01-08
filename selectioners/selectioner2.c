#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define MAX_OPTIONS 10

// Configura la terminal para modo no-canónico
void set_terminal_mode(int mode) {
    static struct termios oldt;
    struct termios newt;

    if (mode == 0) { // Activar modo no-canónico
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else { // Restaurar modo canónico
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}

// Imprime el selector horizontalmente
void print_selector(const char *options[], int count, int selected) {
    printf("\033[H"); // Mueve el cursor a la esquina superior izquierda
    for (int i = 0; i < count; i++) {
        if (i == selected) {
            printf("\033[1;32m[%s]\033[0m ", options[i]); // Resalta la opción seleccionada en verde
        } else {
            printf(" %s ", options[i]);
        }
    }
    fflush(stdout); // Asegura que el texto se imprima inmediatamente
}

int main() {
    const char *options[MAX_OPTIONS] = {
        "Opción1",
        "Opción2",
        "Opción3",
        "Opción4",
        "Opción5",
        "Opción6",
        "Opción7",
        "Opción8",
        "Opción9",
        "Opción10"
    };
    int count = 10;
    int selected = 0;
    int ch;

    // Configura la terminal para modo no-canónico
    set_terminal_mode(0);

    // Imprimir el selector inicial
    print_selector(options, count, selected);

    while (1) {
        // Leer la entrada del usuario
        ch = getchar();
        if (ch == 'q') { // Salir con 'q'
            break;
        } else if (ch == '\033') { // Secuencia de escape
            getchar(); // Ignorar '['
            switch (getchar()) {
                case 'D': // Flecha izquierda
                    selected = (selected - 1 + count) % count;
                    break;
                case 'C': // Flecha derecha
                    selected = (selected + 1) % count;
                    break;
            }
        } else if (ch == '\n') { // Enter
            printf("\nSeleccionaste: %s\n", options[selected]);
            break;
        }

        // Limpiar la línea actual
        printf("\033[2K"); // Borra la línea actual
        // Volver a imprimir el selector
        print_selector(options, count, selected);
    }

    // Restaurar la configuración de la terminal
    set_terminal_mode(1);

    return 0;
}

