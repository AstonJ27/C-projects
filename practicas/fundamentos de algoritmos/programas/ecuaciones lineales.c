#include <stdio.h>
int main(){
float a,b,x;
int res;
do{
   printf("toda ecuacion lineal se puede escribir como ax+b=0");
   printf("\ningrese un valor para a:");
   scanf("%f",&a);
   printf("\ningrese un valor para b:");
   scanf("%f",&b);

if(a==0){
printf("la expresion no es una ecuacion");
}
else{
x=(-1.0*b)/a;
printf("%.1fx + %.1f = 0",a,b);
printf("\n -> x = %.3f",x);
}
printf("\n\n¿Quieres volver a empezar?\n");
printf("1.Si\n");
printf("2.No\n");
printf("ingrese una opcion: ");
scanf("%d",&res);
printf("\n\n");

}while(res!=2);
return 0;
}
