#include <stdio.h>
#define MAX 5 
#include <stdlib.h>
typedef struct problema{
    int denom[MAX];
    int solucion[MAX];
    int objetivo;
} problema;



void mostrar(int denom[MAX], int solucion[MAX]){
	for(int i = 0; i < MAX; i++){
		printf("%02d ",denom[i]);
	}
	printf("\n");
	for(int i =0;i<MAX;i++){
		printf("%02d ",solucion[i]);
	}
	printf("\n\n");
}

void pago(problema P){
	int i = MAX;
	
	while(i>0){
		i--;
		if(P.objetivo - P.denom[i] >= 0){
			//dar el paso
			P.objetivo -= P.denom[i];
			P.solucion[i] = P.solucion[i] +1;
			//printf("%d %d\n",P.objetivo,P.denom[i]);
			//scanf("%d");
			if(P.objetivo ==0){
			  	//printf("a");
				mostrar(P.denom,P.solucion);
			
			
			}else{
				pago(P);
		
			}
			//borrar paso
		   P.objetivo += P.denom[i];
		   P.solucion[i] -= 1;
			
		}
			
	}

}



int main(){
   
   problema P = {.denom = {1,5,20,50,100}, .solucion = {0,0,0,0,0}, .objetivo = 13};
   
   pago(P);

   return 0;
}