#include <stdio.h>
int main()
{
	
	int i,e,n,may,men,ca=0,cj=0,cn=0,cont=0;
	float prom;
	
	printf("¿cuantas edades quiere evaluar?\n");
	scanf("%d", &n);
		
		i=1;
	
	while(i <= n)
	{
		printf("ingrese la edad: ");
		scanf("%d", &e);
	
	if(e >= 30)
	{
		ca+=1;
    }
	if((e>=15) && (e < 30))
	{
		cj +=1;
	}
	if((e>=0) && (e < 15))
	{
		cn +=1;
	}
	
	if ((i == 1)) 
	{
		may=e;
		men=e;
	}	
	else if (e > may)
	{
	   may = e;
	}	
	else if (e < men)
	{
		men = e;
	}
	cont = cont + e;
		
		i++;
	} //while

        prom = (float)cont/n;
        if((ca>cj) && (ca>cn))
        {
			printf("\nEn Carabobo:\n\nLa poblacion con mayor porcentaje es la adulta\nLa edad mas longeva es: %d",may);
			printf("\nLa edad mas infantil es: %d\nEl promedio de edad es: %.2f\n",men,prom);
		}
        if((cj>ca) && (cj>cn))
        {
			printf("\nEn Carabobo:\n\nLa poblacion con mayor porcentaje es la juvenil\nLa edad mas longeva es: %d",may);
			printf("\nLa edad mas infantil es: %d\nEl promedio de edad es: %.2f\n",men,prom);
		}
        if((cn>cj) && (cn>ca))
        {
			printf("\nEn Carabobo:\n\nLa poblacion con mayor porcentaje es la infantil\nLa edad mas longeva es: %d",may);
			printf("\nLa edad mas infantil es: %d\nEl promedio de edad es: %.2f\n",men,prom);
		}	
return 0;
}


