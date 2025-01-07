#include <stdio.h>
//Serie de fibonacci
int main(){

	int n,a=0,b=1,i=1,fi;
	
	printf("ingrese cuantos elementos de la serie de fibonacci quiere obtener: ");
	scanf("%i",&n);
	printf("1 ");	
	for(i=1;i<=n;i++)
	{
		fi = a + b;
		a = b;
		b = fi;
		printf("%i ",fi);
	}
	
	printf("\n");

	return 0;
	}
