#include <stdio.h>
//utilizando backtrackin vamos a resolver el problema de la denominacion de monedas
typedef struct arr{
    int solucion[6];
} arr;

void Solucion(arr solucion, int n){
    //for(int i = 0; i < n; i++){
    //    printf("%dx%d ",solucion[i],monedas[i]);
    //}
    for(int i = 0; i < n; i++){
        printf("%02d ",solucion.solucion[i]);
    }
    printf("\n");
}
void todas_monedas(int monedas[], arr solucion, int n, int dinero){
    int i = n;
    while(i > 0){
        i--;
        if(dinero >= monedas[i]){
            solucion.solucion[i] = dinero / monedas[i];
            dinero = dinero % monedas[i];    
            if(dinero == 0){
                Solucion(solucion, n); //poner monedas            

            }else{
                todas_monedas(monedas,solucion,n,dinero);
            }
            //borrar paso
                if(solucion.solucion[i] == 1){
                    dinero = dinero + monedas[i] * (solucion.solucion[i]);
                }else{
                    dinero = dinero + monedas[i] * (solucion.solucion[i] - 1);
                }
                solucion.solucion[i] = solucion.solucion[i] - 1;
        } //end if
    } //end while
} //end proc

int main(){
    int monedas[6] = {1, 5, 10, 20, 50,100};
    arr solucion;
    for(int i = 0; i < 6; i++){
        solucion.solucion[i] = 0;
    }

    int n=6;
    
    for(int i = 0; i < n; i++){
        printf("%02d ",monedas[i]);
    }
    printf("\n\n");
    
    todas_monedas(monedas,solucion,n,13);
    
    return 0;
}