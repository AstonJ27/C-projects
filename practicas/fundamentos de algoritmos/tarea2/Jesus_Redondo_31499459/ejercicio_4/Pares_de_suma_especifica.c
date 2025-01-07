/*
-El arreglo solo acepta una cadena de maximo 8000000 caracteres
-El programa recibira un numero para buscar como primer numero
-Recibira como segundo numero la cantidad de elementos que tiene el programa
-Buscara todos los pares tales que al sumarlos te den el numero buscado (el primer numero ingresado al iniciar el programa)
*/
#include <stdio.h>
#define MAX 8000000
int main()
{
    int n,busc,array[MAX];
    printf("ingrese el numero especifico: ");
    scanf("%d",&busc);
    do
    {
        printf("\ningrese el numero de elementos: ");
        scanf("%d",&n);
    } while (n>MAX);
    
    printf("ingrese los elementos:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(array[i] + array[j]==busc)
            {
                printf("%d %d\n",array[i],array[j]);
            }
        }
    }
    return 0;
}