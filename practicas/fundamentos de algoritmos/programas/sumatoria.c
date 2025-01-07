#include <stdio.h>
#include <math.h>
int main(){
int n,k=1,fact=1,i=1;
float sol=0;
printf("ingrese un numero a evaluar en la operacion: ");
scanf("%i",&n);

for(i=1;i<=n;i++);{
fact=fact*i;
}
for(k=1;k<=n;k++);{
sol= (float) sol+2/k;
}
sol = (float) sol + fact/2;
sol = pow(sol,3);
printf("la solucion es: %.2f\n",sol);
return 0;
}
