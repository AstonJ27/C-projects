#include <stdio.h>
#include "colores.h"
/*#define ROJO "\e[38;5;196m"
#define VERDE "\e[38;5;76m"
#define AZUL "\e[38;5;21m"
#define AMARILLO "\e[38;5;226m"
#define CIAN "\e[38;5;51m"
#define MAGENTA "\e[38;5;201m"
#define BLANCO "\e[38;5;255m"
#define NEGRO "\e[38;5;16m"
#define RESET "\e[0m" // Para resetear el color
#define INICIO '\1'
*/

//#define ROJO "\033[38;5;196m"


int main(){

    char hola[60] = "hola mundo";
    printf("%s\n", hola);

    cambio_color(hola,ROJO,sizeof(hola));
    printf("%s\n", hola);
    
    cambio_color(hola,VERDE,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,AZUL,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,AMARILLO,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,CIAN,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,MAGENTA,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,ROSA,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,PURPURA,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,NARANJA,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,BLANCO,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,GRIS,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,NEGRO,sizeof(hola));
    printf("%s\n", hola);

    printf("colores pastel:\n");
    cambio_color(hola,ROJO_PASTEL,sizeof(hola));
    printf("%s\n", hola);
    
    cambio_color(hola,VERDE_PASTEL,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,AZUL_PASTEL,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,AMARILLO_PASTEL,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,CIAN_PASTEL,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,MAGENTA_PASTEL,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,ROSA_PASTEL,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,PURPURA_PASTEL,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,NARANJA_PASTEL,sizeof(hola));
    printf("%s\n", hola);

    cambio_color(hola,"SALMON",sizeof(hola));
    printf("\n");
    formatear(hola,sizeof(hola),ROJO,FONDO_NEGRO,DOBLE_SUBRAYADO);
    printf("%s\n", hola);
    printf("prueba\n");
    /*int i = 0;
    while(hola[i] != '\0'){
        printf("%c ",hola[i]);
        i++;
    }*/


    reestablecer(hola, sizeof(hola));
    printf("%s\n", hola);
    char a[MIN_ARREGLO];
    formatear(a,sizeof(a),ROJO,FONDO_ROJO,DOBLE_SUBRAYADO);
    int b = strlen(a);

    printf("\n%d\n",b);
    return 0;
}

