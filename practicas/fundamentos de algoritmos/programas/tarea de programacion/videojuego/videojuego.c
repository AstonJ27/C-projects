/*
sea un videojuego, se tiene la posicion del jugador P(x,y), y la region jugable segura R(a,b,h,w)
el jugador comenzara en una posicion segura aleatoria, el jugador se mueve con las teclas A W S D (cambia su posicion).
Si el jugador se mueve a una posicion no segura pierde vida (1pto) solo se puede mover una posicion por turno
-leer direccion para moverse
-mover jugador
-mostrar posicion
-restar puntos de vida
-esta en posicion segura?
Definamos la zona segura con los valores R(50,40,80,10)

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define rojo     "\x1b[31m"
#define verde   "\x1b[32m"
#define amarillo  "\x1b[33m"
#define azul   "\x1b[34m"
#define magenta "\x1b[35m"
#define cyan    "\x1b[36m"
#define blanco   "\x1b[37m"
#define reinicio   "\x1b[0m"
int x,y;
char tec;
void mover_posicion();
void spawn();
void limpiar();
int main(){
    int a=50,b=10,c=80,d=40,salud=10,puntos=0,turnos=0;
    //char sal;
    printf("Bienvenido jugador\n");
    printf("El juego consiste en moverse dentro de la zona segura (la cual ya inicia directamente en ella) para mantenerse con vida la mayor cantidad de tiempo\n");    
    printf("Presione A para moverse a la izquierda\nPresione W para moverse hacia arriba\nPresione S para moverse hacia abajo\nPresione D para moverse a la derecha\n");
    spawn();
    
    do{
       limpiar();
        
        printf("la zona segura esta delimitada por un rectangulo con esquinas (x,y), (%d,%d) (%d,%d)\n",a,d,c,b);
        printf(verde "su salud es: %d",salud);
        printf(magenta "\nsu puntuacion es: %d",puntos);        
        printf(blanco "\nSu coordenada actual es (%d,%d) presione la tecla a donde se va a mover\n",x,y);
        mover_posicion();
        if((x < a)||(x > c)||(y<b)||(y>d)){
            salud -=1;
            printf("la zona segura esta delimitada por un rectangulo con esquinas (x,y), (%d,%d) (%d,%d)\n",a,d,c,b);
            printf("Usted esta fuera de la zona segura:" rojo "-1 de salud\n");
            printf("\nSu salud es: %d",salud);
            printf(magenta "\nSu puntaje es: %d\n",puntos);
        }
        else{
            puntos +=1;
            printf("la zona segura esta delimitada por un rectangulo con esquinas (x,y), (%d,%d) (%d,%d)\n",a,d,c,b);
            printf("Usted se encuentra dentro de la zona segura:" verde "+1 punto");
            printf("\nSu salud es: %d",salud);
            printf(magenta "\nSu puntaje es: %d\n",puntos);
        }
        turnos +=1;        

    } while ((salud != 0));
  
    printf(blanco "\nfin del juego, su puntaje fue: %d\n",puntos);
    printf("turnos transcurridos: %d\n",turnos);       
    return 0;
}

void spawn(){
    
    srand(time(0));     //posicion ramdom del jugador dentro de la zona segura
    x = rand()%31 + 50;
    y = rand()%31 +10;

}

void mover_posicion(){

    scanf("%c",&tec);
    switch (tec){
        case 'a': x = x - 1;break;
        case 'w': y = y + 1;break;
        case 's': y = y - 1;break;
        case 'd': x = x + 1;break;
        default:mover_posicion();break;
    }
}

void limpiar(){
    printf(blanco "\n");
    system("read -p 'Presione Enter para continuar' var");
    system("clear");
}