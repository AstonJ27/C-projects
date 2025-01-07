#include <stdio.h>
//algoritmo Armstrong
int main()
{
//inicio
	int n,i=0,k,j,dig,pot=1,acum=0,r;

	printf("ingrese un numero: ");
	scanf("%i",&n);
	dig = n;

	while(dig != 0) //obtenemos el numero de digitos que tiene el numero
	{
		i+=1;
		dig = dig/10;
	}
	
	dig = n;	
	
	for(j = 1;j <= i;j++) // acumulamos y conseguimos los digitos necesarios
	{
		r = dig%10;
		dig = dig/10; 
		
		for(k = 1;k <= i;k++) // potenciamos cada digito a "i" por definicion de numero armstrong
		{
			pot *= r; 
		}
	
	acum += pot;		// acumulamos la suma de los valores ya potenciados
	pot = 1;  //inicializamos la variable auxiliar nuevamente
	}
	
	if(acum == n) //comparamos
	{
		printf("El numero %i es Armstrong\n",n);
	}
		else
		{
			printf("El numero %i no es Armstrong\n",n);
		}
		
return 0; //fin
}
