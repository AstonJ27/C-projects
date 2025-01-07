#include "uno.h"


int main(){
    lista p1;
    srand(time(0));
    int a = 0;
    int b = 0;
    p1 = crearLista();
    carta card1;
    pila bar = crearPila();

    for(int i = 0; i <= 7; i++){
        a = (rand()%4) +1;
        b = (rand()%7) +1;
        card1 = crearCarta(b, a,false);
        agregarLista(&p1, card1);
        apilar(&bar,card1, true);
        if(i == 7){
            card1 = crearCarta(i-7,a,false);
            agregarLista(&p1, card1);
            apilar(&bar,card1, true);
        }
    }
    //mostrarLista(p1);
    //eliminarLista(&p1);
    while(bar.primero != NULL){
        carta aux = desapilar(&bar);
        printf("La carta que se desapilo es: %s%s\n", aux.color, aux.valor);
        printf(reset);
        if(aux.color == NULL){
            printf("llegó a null\n");
        }
    }
    return 0;
}