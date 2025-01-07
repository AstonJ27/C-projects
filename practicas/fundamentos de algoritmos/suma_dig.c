#include <stdio.h>
int main()
{
    int aux,acum=0,num;
    printf("Ingrese su numero: ");
    scanf("%d",&num);
    aux=num;
    while(aux>0)
    {
        acum+=aux%10;
        aux = aux/10;
    }
    printf("la suma de los digitos de %d es: %d\n",num,acum);
    return 0;
}