#include "uno.h"
#define MAX 108

int main(){
    carta inicio[MAX];
    int a = -1, b;
    int i,j = 0;
    logic n;
    FILE *in = fopen("cartas.txt","r");
    srand(time(0));

    if(in == NULL){
        printf("No se pudo abrir el archivo\n");
        return 1;
    
    }else{
        while(!feof(in)){
            if(j >= MAX){
                printf("algo pasó\n");
                return 1;
               // break;
            }

            fscanf(in,"%d %d %d",&a,&b,&n);
            inicio[j] = crearCarta(a,b,n);
            
            j++;
        }
        fclose(in);
        if(j == MAX){
            printf("si\n");
        }
        pila baraja;
        baraja = crearPila();
        //mostrar arreglo
        for(int k = 0; k < MAX;k++){
            mostrarCarta(inicio[k]);
        }
        system("read -p 'Presiona Enter para continuar...' var");
        system("clear"); // o system("cls") para windows


        for(int k = 0; k < MAX; k++){
            do{
                i = rand() % MAX;
                
            }while(isCardNull(inicio[i]));

            apilar(&baraja,inicio[i], false);
            inicio[i] = DATO_NULL;
        }
        // mostrar la pila sin barajear
        mostrarPila(&baraja);
        //pausar
        system("read -p 'Presiona Enter para continuar...' var");
        system("clear");
        
        // barajear cartas
        barajeo(&baraja);
        
        while (baraja.total != 0){
            carta A = desapilar(&baraja);
            printf("%d ",baraja.total+1);
            mostrarCarta(A);
        }
        if(baraja.total == 0 && baraja.primero == NULL){
            printf("\nPila vaciada\n");
        }else{
            printf("\nPila SIN vaciar\n");
        }

    }
    system("read -p 'Presiona Enter para continuar...' var");
    system("clear");

    return 0;
}
