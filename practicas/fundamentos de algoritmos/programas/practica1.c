#include <stdio.h>
int main(){
float min,seg,cen,dist_m,tse,vel;
	printf("ingrese la distancia recorrida:");
		scanf("%f",&dist_m);
			printf("ingrese los minutos, segundos y centesimas: ");
				scanf("%f %f %f",&min,&seg,&cen);

	tse = min*60 + seg + cen/100 ;
		vel = dist_m/tse; //velocidad m/s
			vel = vel*3600/1000; //velocidad km/h
	
	printf("la velocidad recorrida en km/h es: %f",vel);




return 0;}
