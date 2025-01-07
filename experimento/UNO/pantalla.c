#include "uno.h"

int main(){
    srand(time(NULL));
    lista players[MAX_PLAYERS];
    int n_turn = 0;
    pila baraja, mesa;
    int a=0, b=0, c=0; 
    for(int i = 0; i < MAX_PLAYERS; i++){
        players[i] = crearLista();
    }
    baraja = crearPila();
    mesa = crearPila();

    dato card1, *opcion;
    opcion = NULL;
    

    for(int i = 0; i <= 7; i++){
        a = (rand()%4) +1;
        b = (rand()%7) +1;
        card1 = crearCarta(b, a,false);
        agregarLista(&players[n_turn], card1);
        apilar(&baraja,card1, false);
        if(i == 7){
            card1 = crearCarta(4,0,true);
            agregarLista(&players[n_turn], card1);
            apilar(&baraja,card1, false);
        }
    }
    //handle_selector(players, n_turn, MAX_PLAYERS,baraja.total, card1);
    Screen(players,n_turn,MAX_PLAYERS,baraja.total,card1, &c, &opcion);
    printf("posicion:%d\ncarta:",c);
    //printf("si\n");
    if(opcion == NULL){
        printf("no\n");
        return 1;
    }
    if(strcmp(opcion->color, NONCOLOR)==0){
        printf("A que color desea cambiar\n");
        *opcion = cambio_color(*opcion);
    
    }
    

    mostrarCarta(*opcion);
    printf("\n");


    mostrarLista(players[0]);
    printf("sancando la carta:\n");
    carta Z = quitar(&players[0],c);
    mostrarLista(players[0]);
    printf("carta sacada: ");
    mostrarCarta(Z);
    
    printf("\nla mesa tiene %d\n",mesa.total);    
    printf("la baraja tiene %d\n\n",baraja.total);    
    
    restaurar_baraja(&baraja, &mesa);
    
    printf("\nla mesa tiene %d\n",mesa.total);
    printf("la baraja tiene %d\n",baraja.total);


    
    printf("eliminando baraja:");
    eliminarPila(&baraja);
    printf("eliminando mesa:");

    eliminarPila(&mesa);
    
    printf("\nla mesa tiene %d\n",mesa.total);
    printf("la baraja tiene %d\n",baraja.total);
    
    for(int i =0; i < MAX_PLAYERS; i++){
        eliminarLista(&players[i]);    
    }

    printf("listas vaciadas\n");


    
    
    
    
    return 0;
}