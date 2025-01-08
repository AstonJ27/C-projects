#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

void configure_terminal() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO); // Desactivar modo canónico y eco
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void restore_terminal() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO); // Restaurar modo canónico y eco
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int main() {
    configure_terminal();

    printf("Presiona cualquier tecla (presiona 'q' para salir):\n");

    while (1) {
        int ch = getchar();
        printf("Código de tecla: %d\n", ch);
        if (ch == 'q') {
            break;
        }
    }

    restore_terminal();
    return 0;
}

