#include <stdio.h>
#include <stdlib.h>

#define rojo     "\x1b[31m"
#define verde   "\x1b[32m"
#define amarillo  "\x1b[33m"
#define azul   "\x1b[34m"
#define magenta "\x1b[35m"
#define cyan    "\x1b[36m"
#define reset   "\x1b[0m"
#define color_blanco   "\x1b[37m"
#define super_negro "\x1B[40m"
int main () {
 
  printf(rojo "This text is RED!" color_blanco "\n");
  printf(verde "This text is GREEN!" color_blanco "\n");
  printf(amarillo "This text is YELLOW!" color_blanco "\n");
  printf(azul "This text is BLUE!" color_blanco "\n");
  printf(magenta "This text is MAGENTA!" color_blanco "\n");
  printf(cyan "This text is CYAN!" color_blanco   "\n");
    system("read -p 'Presione Enter para continuar' var");
    system("clear");
  printf(super_negro "funciona\n" reset);
  return 0;
}