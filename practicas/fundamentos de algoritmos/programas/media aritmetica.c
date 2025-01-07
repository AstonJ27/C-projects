#include <stdio.h>
int main(){
float a,b,c,resultado;
printf("Digite los 3 numeros a sacar la media: "); scanf("%f %f %f", &a,&b,&c);
resultado = (a+b+c)/3;
printf("la media aritmetica es: %f\n",resultado);

return 0;
}
