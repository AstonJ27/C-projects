#include <stdio.h>
int main()
{
	int n,i=1,cont=0;
	printf("ingrese un numero: ");
	scanf("%i",&n);
	for( i=1; i <= n ;i++ )
	{
		if(n%i == 0)
		{
			cont+=1;
		}
	}
	if(cont == 2)
	{
		printf("el numero es primo\n");
	}
		else if((cont == 1) || (cont == 0))
		{
			printf("el numero no es ni primo ni compuesto\n");
		}
			else
			{
				printf("el numero es compuesto\n");
			}
	
return 0;	
}
