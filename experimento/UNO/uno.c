#include "uno.h"

/***************************
/       Functions          /
/**************************/

/******************************LISTAS**************************************/

nodo *crearNodo(dato x){
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->card = x;
    nuevo->siguiente = NULL;
    return nuevo;
}

lista crearLista(){
    lista l;
    l.primero = NULL;
    l.total = 0;
    return l;
}
void agregarLista(lista *l, dato card){
    //crear y agregar el nodo
    nodo *nuevo = crearNodo(card);
    if(nuevo == NULL){
        printf("Error al asignar memoria");
        return;
    }
    else{
        if(l->primero == NULL){
            l->primero = nuevo;
        }else{
            //crear un puntero auxiliar al primer nodo
            nodo *aux = l->primero;
            while (strcmp(aux->card.color,nuevo->card.color) != 0 && aux->siguiente != NULL){
                aux = aux->siguiente;
            }
            
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
            
        }
        l->total = l->total + 1;
        return;
    }

}

void eliminarLista(lista *l){
    nodo *aux;
    while (l->primero != NULL){
        aux = l->primero;
        l->primero = l->primero->siguiente;
        free(aux);
        l->total = l->total -1;
    }
    //l->total = 0;
   // printf("%d\n",l->total);
    if(l->total != 0){
        printf("error de vaciado de lista\n");
        exit(EXIT_FAILURE);
    }
}

void mostrarLista(lista l){ // cambio
    nodo *aux = l.primero;
    //printf("baraja: ");
    while (aux != NULL){
        printf("%s%s ", aux->card.color, aux->card.valor);
        aux = aux->siguiente;
    }
    printf(reset"\n");
}
void seleccionar(lista l, int count){
    nodo *aux = l.primero;
    int i = 1;
    while(aux != NULL){
        if(i == count){
            printf("\033[32m>\033[0m%s%s%s ", aux->card.color, aux->card.valor,reset);
            //printf("%s%s ", aux->card.color, aux->card.valor);
            aux = aux->siguiente;
            i++;
        }else{
            printf("%s%s%s ", aux->card.color, aux->card.valor,reset);
            aux = aux->siguiente;
            i++;
        }
        
    }
    printf("\n[q para agarrar carta]\n");
        
}

dato *buscar(lista l,int posicion){
    nodo *aux = l.primero;
    int i = 1;
    while(aux->siguiente != NULL && i < posicion){
        aux = aux->siguiente;
        i++;
    }
    if(posicion == i){
        return &(aux->card);
    }else{
        return NULL;
    }
    
}

dato quitar(lista *l, int posicion){
    nodo *aux = l->primero;
    nodo *aux2;
    int i = 1;
    dato B;

    if(posicion == 1){
        B = aux->card;
        l->primero = l->primero->siguiente;
        free(aux);
        l->total = l->total - 1;
    }else{
        while(aux->siguiente != NULL && i < posicion-1){
            aux = aux->siguiente;
            i++;
        }

        if(posicion == i+1){
            aux2 = aux->siguiente;
            B = aux2->card;
            aux->siguiente = aux2->siguiente;
            free(aux2);
            l->total = l->total - 1;
            
        }else{
            printf("posicion invalida\n");
            exit(EXIT_FAILURE);
        }

    }
    
    return B;    
}


/*****************************PILAS***************************************/

pila crearPila(){
    pila p;
    p.primero = NULL;
    p.total = 0;
    return p;
}

void apilar(pila *p, dato x, logic comp){
    nodo *nuevo = crearNodo(x);
    if(nuevo ==  NULL){
        printf("error al asignar memoria a nodo pila\n");
    }else{
        if(p->total == 0){
            p->primero = nuevo;
            p->total = p->total + 1;
        }else if(comp){
            if(strcmp(nuevo->card.color,p->primero->card.color) == 0 || strcmp(nuevo->card.valor,p->primero->card.valor) == 0){
                nuevo->siguiente = p->primero;
                p->primero = nuevo;
                p->total = p->total + 1;
            }else{
                printf("carta no admitida\n");
            }    
        }else{
            nuevo->siguiente = p->primero;
            p->primero = nuevo;
            p->total = p->total + 1;
        }
    }
}

dato cima(pila p){
    if(p.primero == NULL){
        printf("pila vacia\n");
    }/*else{
        printf("%s%s\n", p.primero->card.color, p.primero->card.valor); 
    }*/
    return p.primero->card;
}

dato desapilar(pila *p){
    if(p->total == 0){
        printf("pila vacia\n");
        exit(1);
        //return DATO_NULL;
    }else{
        nodo *aux = p->primero;
        dato x = aux->card;
        p->primero = aux->siguiente;
        free(aux);
        p->total = p->total - 1;
        return x;
    }        
}

void eliminarPila(pila *p){
    nodo *temp;
    if(p->primero == NULL){
        printf("pila vacía\n");
        return;
    }
    
    while(p->primero != NULL){
        temp = p->primero;
        p->primero = p->primero->siguiente;
        free(temp);
        p->total = p->total - 1;
    }

    //posible error
    if(p->primero != NULL || p->total != 0){
        printf("\nerror de vaciado\n");
        printf("%d\n",p->total );
        exit(1);
    }
}



//solo por prueba, esto rompe la definicion de pila
//no usar
void mostrarPila(pila *p){
    nodo *aux;
    if(p->primero == NULL){
        printf("pila vacía\n");
    }else{
        printf("pila: \n");
        aux = p->primero;
        while(aux != NULL){
            mostrarCarta(aux->card);
            aux = aux->siguiente;
        }
    }
}

/***************************
/      Game Functions      /
/**************************/

int winner(lista players[MAX_PLAYERS], int n_players){

    for(int i = 0; i < n_players; i++){
        if(players[i].total == 0){
            return i;
        }
    }
    return -1;
}

logic es_jugable(dato A, dato in_mesa, int carry){
    logic validado;
    validado = false;
    
    if(carry > 0){
        if(A.valor[0] == in_mesa.valor[0] && A.valor[0] == '+'){
            validado = true;
        }
    }else{
        if(strcmp(A.color, in_mesa.color) == 0 || strcmp(A.valor, in_mesa.valor) == 0){
            validado = true;
        }
        if(strcmp(A.color, NONCOLOR)==0){
            validado = true;
        }
    }
    return validado;
}

void restaurar_baraja(pila *mesa, pila *baraja){
    dato A = desapilar(mesa);
    dato B;
    mostrarCarta(A);
    while (mesa->total != 0){
        B = desapilar(mesa);
        apilar(baraja,B,false);
    }
    if(mesa->primero == NULL){
        printf("tarea completada");
        apilar(mesa,A, false);
    }
}





/*****************************CARTAS***************************************/

//0-non_color, 1-rojo, 2-azul, 3-verde, 4-amarillo
carta crearCarta(int x, int color, logic a){
    carta c; 
    c.especial = a;
    if(x >= 0 && x <= 9){
        if(c.especial && (x == 2 || x == 4)){
            snprintf(c.valor,sizeof(c.valor),"+%d",x);
        }else{
            snprintf(c.valor,sizeof(c.valor),"%d",x);
        }
    }else{
        if(c.especial){
            snprintf(c.valor,sizeof(c.valor),"%c",x);
        }
    }

    if(color == 1){
        strcpy(c.color,ROJO);
        
        //c.color = ROJO;
    }else if(color == 2){
        strcpy(c.color,AZUL);
        
        //c.color = AZUL;
    }else if(color == 3){
        //c.color = VERDE;
        strcpy(c.color,VERDE);

    }else if(color == 4){
        //c.color = AMARILLO;
        strcpy(c.color,AMARILLO);

    }else if(color == 0){
        //c.color = NONCOLOR;
        strcpy(c.color,NONCOLOR);

    }
    return c;
}

void mostrarCarta(dato a){
	printf("%s%s %d%s\n",a.color,a.valor,a.especial,reset);

}
logic isCardNull(dato a){
    dato b = DATO_NULL;
    return (strcmp(a.valor,b.valor) == 0 && strcmp(a.color,b.color) == 0 && a.especial == b.especial);
}

logic cartacmp(dato a, dato b){
    return (strcmp(a.valor,b.valor) == 0 && strcmp(a.color, b.color) == 0 && a.especial == b.especial);
}

carta cambio_color(carta A){
    logic a;
    a = false;
    
    if(strcmp(A.color, NONCOLOR) != 0){
        printf("carta invalida\n");
        return A;
    }else{
        char color[10];
        printf("elije el color: ");
        scanf("%s", color);
        int i=0;
        while(color[i] != '\0'){
            color[i]= tolower(color[i]);
            i++;
        }
        while(!a){
            if(strcmp(color, "rojo") == 0 || strcmp(color, "r") == 0 ){
                strcpy(A.color,ROJO);
                a = true;
    
            }else if(strcmp(color, "verde") == 0 || strcmp(color, "v") == 0 ){
                strcpy(A.color, VERDE);
                a = true;
                
            }else if(strcmp(color, "azul") == 0 || strcmp(color, "az") == 0 ){
                strcpy(A.color,AZUL);
                a = true;
                
            }else if(strcmp(color, "amarillo") == 0 || strcmp(color, "a") == 0 ){
                strcpy(A.color,AMARILLO);
                a = true;
            }
            
        }        
        return A;

    }
}


/*****************************PILAS***************************************/

void barajeo(pila *p){
    pila a = crearPila(), b = crearPila();
    carta piv = DATO_NULL;
    logic impar = false;
    int tam = p->total;
    
    if(tam % 2 == 1){ // si es impar
        piv = desapilar(p);
        impar = true;
        // ahora sera par (sin perder la carta)
    }
    // dividimos la pila en 2 sub pilas dejando a p vacia
    while(p->total > tam/2){
        apilar(&a,desapilar(p),false);
    }
    
    while(p->total > 0){
        apilar(&b,desapilar(p),false);
    }
    // ahora apilamos en p lo que hay en a y b sucesivamente
    //hatsa llegar a la "mitad"
    while(p->total < tam/2){
        apilar(p,desapilar(&a), false);
        apilar(p,desapilar(&b), false);
    }
    //si la pila inicialmente era impar apilamops la carta que dejamos
    //por fuera
    if(impar){
        apilar(p,piv,false);
    }
    
    while(p->total < tam){
        apilar(p,desapilar(&a), false);
        apilar(p,desapilar(&b), false);
    }
    
    if(p->total == tam){
        printf("pila barajada\n");
    }else{
        printf("Error de barajeo\n");
    }
}

//------------------------------PRUEBA-------------------------------------------------
void configure_terminal() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void restore_terminal() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int getch() {
    return getchar();
}

// Función Screen que maneja la visualización y el selector
void Screen(lista players[MAX_PLAYERS], int n_turn, int n_players, int n_baraja, dato actual, int *posicion, dato **jugada) {
    // Configurar terminal
    configure_terminal();
    // Selector de números
    int seleccion = 1; // Índice de selección

    while (true) {
        // Limpiar la pantalla
        printf("\033[2J\033[H");

        //Imprimir la pantalla del juego
        printf("\n");
        for(int i = 1; i <= 71 - (11 * n_players / 2) + 3; i++) {
            printf(" ");
        }

        for(int i = 0; i < n_players; i++) {
            if(i == n_turn){
                //  
                printf("\033[1;32mplayer%d[%d]\033[0m ", i + 1, players[i].total);
            }else{
                printf("player%d[%d] ", i + 1, players[i].total);

            }
        }

        for(int i = 1; i <= 5; i++) {
            printf("\n");
        }

        for(int i = 1; i <= 71; i++) {
            printf(" ");
        }

        printf("%d ", n_baraja);
        mostrarCarta(actual);

        for(int i = 1; i <= 5; i++) {
            printf("\n");
        }

        // seleccionar carta
        for(int i = 1; i <= 71-((players[n_turn].total))+3; i++){
            printf(" ");
        }
        
        //mostrarLista(players[n_turn], numeros, &num_count);
        seleccionar(players[n_turn],seleccion);

        printf("\n");
        // Leer la entrada del usuario
        int ch = getch();
        switch(ch){
            case 'q':
                restore_terminal();
                **jugada = DATO_NULL;
                *posicion = -1;
                return; // Salir de la función Screen
            case 'C': // Tecla de flecha derecha
                if (seleccion < players[n_turn].total) {
                    seleccion++;
                }
                break;
            case 'D': // Tecla de flecha izquierda
                if (seleccion-1 > 0) {
                    seleccion--;
                }
                break;
            case '\n': // Enter 
                restore_terminal();
                *jugada = buscar(players[n_turn], seleccion);
                *posicion = seleccion;
            return;
        }
    }

    // Restaurar la configuración original del terminal antes de salir
    restore_terminal();
}










//-------------------------------------------------------------------------------------
