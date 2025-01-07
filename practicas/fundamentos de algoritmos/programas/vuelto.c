#include <stdio.h>
int main(){
float costo,cantidad,cambio;	
	printf("ingrese el costo del articulo y la cantidad de dinero entregada:");
	scanf("%f %f",&costo,&cantidad);
	cambio = cantidad - costo;
	if(costo>cantidad){
		cambio*=-1;
		printf("el comprador debe %.2f\n",cambio);
		}else{
	printf("el cambio a regresar es de: %.2f\n",cambio);
	}
return 0;}
// construir un programa quye al recibir como datos el costo de un articulo vendido y la cantidad de dinero entregada por el cliente calcule e imprima el cambio
