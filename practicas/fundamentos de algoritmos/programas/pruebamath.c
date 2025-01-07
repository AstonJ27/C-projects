#include <stdio.h>
#include <math.h>
int main (){
	
int a,b,c;
	
	printf("dame una base y un exponente: ");
	scanf("%d %d",&a,&b);
	c= pow( a, b );
	printf("la potencia es: %d\n",c);
	return 0;}
