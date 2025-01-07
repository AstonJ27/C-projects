#include <stdio.h>
int main()
{
	int x,y,z,dif,t;
	float porc;
	
	printf("ingrese cuantos articulos compró: ");
	scanf("%i",&x);
	printf("\ningrese el precio por unidad: ");
	scanf("%i",&y);
	printf("\nen cuanto revenderas por unidad: ");
	scanf("%i",&z);
	printf("\nCuantos articulos te compraron: ");
	scanf("%i",&t);
	 if( t == x)
	 {
		dif = (x * z) - (x * y);
		porc = (float) (dif * 100)/(x * y);
		
		printf("\nel porcentaje de ganancia fue de %.2f por ciento\n",porc);
	 }
	 else if (t < x)
	 {
		dif = (t * z) - (x * y);
		porc = (float) (dif * 100)/(x * y);
		if(porc >= 0)
		{
		printf("\nel porcentaje de ganancia fue de %.2f por ciento\n",porc);
		}
			else
			{
				porc = porc * -1;
				printf("\nel porcentaje de perdida fue de %.2f por ciento\n",porc);
			}
			
	 
	 
	 
	 }
	 else
	 {
		printf("Error");
	 }	
return 0;	
}
