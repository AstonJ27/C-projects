#include <stdbool.h>
#include "../colores/colores.h"
#ifndef _CARTAS_H
#define _CARTAS_H

/*
    Esta libreria tiene como finalidad simular las cartas de uno como un tipo de dato
*/



//*******************************|    ESTRUCTURA CARTA   |*********************************//

typedef struct carta{
    char valor[MIN_ARREGLO+5];
    bool especial;
    char color[10];
}carta;
#define CARTA_NULA (carta){{'-'}, false, {'-'}}

//*******************************|    FUNCIONES BASICAS   |*********************************//
// crea una carta a partir de ciertos datos
carta crear_carta(char valor[3], char colores[MIN_ARREGLO], bool especial);

// se encarga de ostrar la carta
void mostrar_carta(carta A);

// si una carta es comodin cambia su color al color escogido por el usuario
void comodin(carta *A);

// verifica si una carta es nula o no
bool es_carta_nula(carta A);

// verifica si una carta puede ponerse sobre otra (si es jugable)

bool es_jugable(carta actual, carta nueva);

#endif