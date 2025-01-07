#include <stdio.h>
//serie de taylor e^x = 1 + x + (x²/2!)+...+(x^n)/n!
int main(){
	int x,i=0,n,k,p=1;
	float sol=0,fact=1;
	printf("ingrese el exponente de e^x y el numero de terminos de la serie a calcular: ");
	scanf("%i%i",&x,&n);
	
		for(i = 1;i <=n ;i++)
		{
			for(k = 1;k <= i;k++)   //2432.121338 2432.121270
			{
			p=p*x;
			}
			fact = fact * i; 
			sol = (float)sol + (( p ) / fact);
			p = 1;
		}
	
	sol += 1;
	
	printf("e^%i es aproximadamente: %f\ncon %i terminos en la serie",x,sol,n);
	
	return 0;
	}
