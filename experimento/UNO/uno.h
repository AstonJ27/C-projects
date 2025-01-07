// librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <math.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <ctype.h>

// colores
#define ROJO "\e[38;5;196;1m"
#define VERDE "\e[38;5;40;1m"
#define AZUL "\e[38;5;33;1m"
#define AMARILLO "\e[38;5;226;1m" // o "\e[38;5;184;1m"
#define NONCOLOR "\e[38;5;254;1m" // o "\e[38;5;184;1m"
#define reset "\033[0m"
#define backreset "\033[0;m"

#define blanco "\e[48;5;7m"
#define negro "\e[48;5;16m"

//constantes
#define MAX_PLAYERS 8
#define MAX_NUMBERS 10

/***************************
|                          |
|       data types         |
|                          |
|**************************/
//logic
typedef int logic; 
#define true 1
#define false 0

//carta
typedef struct carta{
    char valor[3];
    char color[20];
    logic especial;
}carta;
typedef carta dato;
//definicion de carta/dato nulo
#define DATO_NULL (carta){{'\0'},{'-'}, false}

//nodo
typedef struct nodo{
    dato card;
    struct nodo *siguiente;
}nodo;

//lista
typedef struct lista{
    int total;
    nodo *primero;
    //nodo *ultimo;
}lista;

//pila
typedef struct pila{
    int total;
    nodo *primero;
}pila;

/***************************
|                          |
|       Functions          |
|                          |
|**************************/

//listas
nodo *crearNodo(dato x); // check
lista crearLista(); // check
void agregarLista(lista *l, dato card); // check

void mostrarLista(lista l); // check
dato *buscar(lista l, int posicion);
void mostrarLista(lista l); // check
void eliminarLista(lista *l); // check
dato quitar(lista *l, int posicion);


//pilas
pila crearPila();
void apilar(pila *p, dato x, logic comp);
dato cima(pila p);
dato desapilar(pila *p);
//void eliminarPila(pila *p);
//solo por prueba, esto rompe la definicion de pila
void mostrarPila(pila *p);
void eliminarPila(pila *p);
/*
|**************************|
|    Game Functions        |
|**************************|
*/

logic es_jugable(dato A, dato in_mesa, int carry);

int winner(lista players[MAX_PLAYERS], int n_players);

void restaurar_baraja(pila *mesa, pila *baraja);



void seleccionar(lista l, int count);
/*****************************CARTAS***************************************/

carta crearCarta(int x, int color, logic a);
void mostrarCarta(dato a);
logic isCardNull(dato a);
logic cartacmp(dato a, dato b);

carta cambio_color(carta A);


/*****************************PILAS***************************************/

void barajeo(pila *p);
void Screen(lista players[MAX_PLAYERS], int n_turn, int n_players, int n_baraja, dato actual, int *posicion, dato **jugada);

//CONFIGURACION DE TERMINAL---------------
void configure_terminal();
void restore_terminal();
int getch();