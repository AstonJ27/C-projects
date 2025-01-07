/*******************************************************************************|
|    esta libreria tiene como finalidad utilizar las salidas de escape ANSI     |
|    para darle un toque de color a la terminal y a los strings impresos en     |
|    futuros programas...                                                       |
|*******************************************************************************/
#ifndef _COLORES_H
#define _COLORES_H
//*******************************|    LIBRERIAS NECESARIAS    |*********************************//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
//*******************************|    REGRESAR TERMINAL (QUITAR COLORES)    |*********************************//
#define RESET "\e[0m"
#define RESET_FONDO "\e[49m"
#define RESET_TEXTO "\e[39m"




//*******************************|    COLORES PARA STRINGS    |*********************************//
#define ROJO "\e[38;5;196m"
#define VERDE "\e[38;5;40m" //34 40 76
#define AZUL "\e[38;5;33m" //o 32 12 26 27
#define AMARILLO "\e[38;5;226m" // o "\e[38;5;184m" o 220
#define CIAN "\e[38;5;51m" //45 
#define MAGENTA "\e[38;5;201m"//  165
#define ROSA "\e[38;5;213m"
#define PURPURA "\e[38;5;135m"
#define NARANJA "\e[38;5;208m" // o 202
#define BLANCO "\e[38;5;255m" // o 7
#define GRIS "\e[38;5;239m"
#define NEGRO "\e[38;5;16m"

//*******************************|    COLORES CON EFECTO NEGRITA    |*********************************//

#define N_ROJO "\e[38;5;196;1m"
#define N_VERDE "\e[38;5;40;1m"
#define N_AZUL "\e[38;5;33;1m"
#define N_AMARILLO "\e[38;5;226;1m" // o "\e[38;5;184;1m"
#define N_CIAN "\e[38;5;51;1m" //45 
#define N_MAGENTA "\e[38;5;201;1m"//  165
#define N_ROSA "\e[38;5;213;1m"
#define N_PURPURA "\e[38;5;135;1m"
#define N_NARANJA "\e[38;5;208;1m"
#define N_BLANCO "\e[38;5;255;1m"
#define N_GRIS "\e[38;5;239;1m"
#define N_NEGRO "\e[38;5;16;1m"

//*******************************|    COLORES PASTEL    |*********************************//

#define ROJO_PASTEL "\e[38;5;9m"
#define VERDE_PASTEL "\e[38;5;83m" 
#define AZUL_PASTEL "\e[38;5;45m" //o 32 12 26 27
#define AMARILLO_PASTEL "\e[38;5;227m" // o "\e[38;5;184m" o 220
#define CIAN_PASTEL "\e[38;5;87m" //45 CHECK 
#define MAGENTA_PASTEL "\e[38;5;171m"//  165
#define ROSA_PASTEL "\e[38;5;225m"
#define PURPURA_PASTEL "\e[38;5;171m"
#define NARANJA_PASTEL "\e[38;5;209m" // o 202

//*******************************|    COLORES PARA STRINGS    |*********************************//
#define FONDO_ROJO "\e[48;5;196m"
#define FONDO_VERDE "\e[48;5;40m" //34 40 76
#define FONDO_AZUL "\e[48;5;33m" //o 32 12 26 27
#define FONDO_AMARILLO "\e[48;5;226m" // o "\e[48;5;184m" o 220
#define FONDO_CIAN "\e[48;5;51m" //45 
#define FONDO_MAGENTA "\e[48;5;201m"//  165
#define FONDO_ROSA "\e[48;5;213m"
#define FONDO_PURPURA "\e[48;5;135m"
#define FONDO_NARANJA "\e[48;5;208m" // o 202
#define FONDO_BLANCO "\e[48;5;255m" // o 7
#define FONDO_GRIS "\e[48;5;239m"
#define FONDO_NEGRO "\e[48;5;16m"


//*******************************|    ESTILOS DE TEXTOS    |*********************************//
#define NEGRITA "\e[1m"
#define CURSIVA "\e[3m"
#define SUBRAYADO "\e[4m"
#define DOBLE_SUBRAYADO "\e[21m"
#define INVERSO "\e[7m"
#define TACHADO  "\e[9m"

//*******************************|    DELIMITADORES   |*********************************//

#define INICIO '\10'       // caracter ascii no imprimible que se usara como delimitador de colores BELL

#define FIN '\5'      // caracter ascii no imprimible que se usara como delimitador de reset STX


//*******************************|    APLICAR FORMATOS A UN STRING   |*********************************//

#define MAX_ARREGLO 420  // los arreglos no deben tener mas de 420 caracteres

#define MAX_ARREGLO_USABLE 400  // los arreglos de entrada no deben tener mas de 400 caracteres

#define MIN_ARREGLO 42  // los arreglos no deben tener menos de 42 caracteres


/*******************************************************|
|   Reestablece los colores por default de los strings  |
|*******************************************************/
void reestablecer(char string[MAX_ARREGLO_USABLE], size_t tam); //check

/*******************************************************|
|   le da a un string los estilos de texto disponibles  |
|*******************************************************/
void dar_estilo(char string[MAX_ARREGLO_USABLE], char estilo[20], size_t tam); //check

/*******************************************************|
|   le da a un string los colores de texto disponibles  |
|*******************************************************/

void cambio_color(char string[MAX_ARREGLO_USABLE],char color[20], size_t tam);

/****************************************************************|
|   le da a un string los colores de fondo de texto disponibles  |
|****************************************************************/

void cambio_fondo(char string[MAX_ARREGLO_USABLE],char fondo[20], size_t tam);

/****************************************************************|
|  le da formato a un string de la forma (color, fondo, estilo)  |
|****************************************************************/

void formatear(char string[MAX_ARREGLO_USABLE], size_t tam, char color[20], char fondo[20], char estilo[20]);

#endif

