/*
-El arreglo solo acepta numeros enteros
-El programa invertira los valores que se introduzcan en el arreglo  por ejemplo: {1,2,3,4,5} -> {5,4,3,2,1}
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    
    int n,aux;
    printf("¿de que tamaño es el arreglo?: ");
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++)
    {
        system("clear");
        
        printf("ingrese el %d° numero: ",i+1);
        scanf("%d",&array[i]);
        
        system("clear");
    }

    for(int j=0;j<n/2;j++)
    {
        aux = array[j];
        array[j]=array[n-(j+1)];
        array[n-(j+1)] = aux;
    }
    
    for(int i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}