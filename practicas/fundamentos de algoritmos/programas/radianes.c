#include <stdio.h>
// algoritmo que convierte grados a radianes en c

#define pi 3.141592653589793238462643

int main(){

int a;
float rad;
printf("exprese una cantidad en grados: ");
scanf("%i", &a);
rad=a*pi/180;
printf("convertido a radianes es: %f\n", rad);







return 0;}
