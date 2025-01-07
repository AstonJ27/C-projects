#include <stdio.h>
int main()
{
	 int n1,n2,rest,mcd,prod,mcm;
	 
	 printf("ingrese 2 numeros: ");
	 scanf("%i%i",&n1,&n2);
	 prod = n1 * n2;
	do
	{
		rest = n1 % n2;
		if(rest != 0)
		{
		n1 = n2;
		n2 = rest;
		}	else
			{
			mcd = n2;
			}
		
	} while(rest != 0);
	
	mcm = prod/mcd;
	printf("El minimo comun multiplo es: %i\n",mcm);   
		 
return 0;
}
