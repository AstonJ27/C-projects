#include "uno.h"
#define MAX 108



int main(){
    int n_players;
    printf("Bienvenido al juego de uno, ¿cuantos jugadores habra en la partida?(2-8)\n");
    scanf("%d", &n_players);
    if(n_players < 2 || n_players > 8){
        printf("\ncantidad de jugadores invalida\n");
        return 1;
    }
    
    lista players[MAX_PLAYERS];
    carta inicio[MAX], *A, B;
    int a = -1, b, i ,j = 0, carry, n_turn, sentido, won;
    logic n, is_block;
    pila baraja, mesa;
    baraja = crearPila();
    mesa = crearPila();

    FILE *in = fopen("cartas.txt","r");
    srand(time(0));
    //inicio
    
    if(in == NULL){
        printf("No se pudo abrir el archivo\n");
        return 1;
    
    }else{
        while(!feof(in)){
            if(j >= MAX){
                printf("algo pasó\n");
                return 1;
               // break;
            }//end if

            fscanf(in,"%d %d %d",&a,&b,&n);
            inicio[j] = crearCarta(a,b,n);
            
            j++;
        }//end while
        fclose(in); // close file
        
        
        for(int k = 0; k < MAX; k++){
            do{
                i = rand() % MAX;
                
            }while(isCardNull(inicio[i]));

            apilar(&baraja,inicio[i], false);
            inicio[i] = DATO_NULL;
        }//end for

        do{
            barajeo(&baraja);
            B = cima(baraja);
        
        }while(B.especial);
        printf("salio del barajeo\n");
        apilar(&mesa,desapilar(&baraja),false);
        
        //repartir 7 cartas para cada uno
        for(i = 1; i <= 7; i++){
            for(b = 0; b < n_players; b++){
                agregarLista(&players[b],desapilar(&baraja));
            }//end for
        }//end for
        carry = 0;

        //game logic-------------------------------------------------------
        won = -1;
        sentido = 1;
        n_turn = 0;
        int posicion = 0;
        is_block = false;
        while(won < 0){
            Screen(players, n_turn, n_players, baraja.total, mesa.primero->card,&posicion,&A);
            if(isCardNull(*A)){
                if(baraja.total <= carry || baraja.total == 0){
                    restaurar_baraja(&mesa,&baraja);
                    barajeo(&baraja);
                }//end if

                if(carry > 0){
                    for(i = 1; i <= carry; i++){
                        agregarLista(&players[n_turn],desapilar(&baraja));
                    }
                    carry = 0;
                }else{
                
                    agregarLista(&players[n_turn],desapilar(&baraja));
                }
                // siguiente turno
                n_turn = (n_turn + sentido + n_players) % n_players;

            }else{ //carta escogida
                if(es_jugable(*A,cima(mesa),carry)){
                    if(A->valor[0] == 'B'){ //si es bloqueo
                        // siguiente turno
                        is_block = true;
                        //n_turn = (n_turn + sentido + n_players) % n_players;
                    }else if(A->valor[0] == 'R'){ //si es reversa
                        sentido = sentido * (-1);
                    }else if(strcmp(A->valor, "+2") == 0){ //si es +2
                        carry = carry + 2;
                    }else{ //a partir de aqui la carta o cambia de color o no es especial
                        
                        if(strcmp(A->valor, "+4") == 0){ //si es +4
                            carry = carry + 4;
                        }// en if +4
                        // asegurarse de que haga el cambio solo si es especial
                        if(A->especial){
                           *A = cambio_color(*A);
                        }// end if is special

                    }// end if +2
                    // poner la carta sobre la mesa:
                    apilar(&mesa, quitar(&players[n_turn], posicion), false );
                    // siguiente turno:
                    if(is_block){
                        n_turn = (n_turn + sentido + n_players) % n_players;
                    }
                    n_turn = (n_turn + sentido + n_players) % n_players;

                }// end if es jugable
            }// end carta nula (agarrar)
            won = winner(players, n_players);
        }// end while (game)
            
        printf("\n\n el jugador %d, ha ganado\n\n",won);
    
    }//end if
    // limpiar listas y pilas

    //limpiar listad e jugadores
    for(int i = 0; i < n_players; i++){
        eliminarLista(&players[i]);    
    }
    printf("listas vaciadas\n");
    
    // limpiando baraja y mesa
    printf("eliminando baraja:");
    eliminarPila(&baraja);
    printf("eliminando mesa:");
    eliminarPila(&mesa);

    
    printf("\nla mesa tiene %d\n",mesa.total);
    printf("la baraja tiene %d\n",baraja.total);



    return 0;
}// end main