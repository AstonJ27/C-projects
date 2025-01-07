#include <stdio.h>
int main(){
int opcion,num,cubo;

printf("\tBienvenido nuestro menú");
printf("\n1. elevar al cubo");
printf("\n2. par o impar");
printf("\n3. salir");
printf("\nopcion: ");
scanf("%d",&opcion);

switch(opcion){
case 1:
    printf("ingrese un numero: ");scanf("%d",&num);
    cubo=num*num*num;
printf("el numero %d elevado al cubo es: %d\n",num,cubo);
break;
case 2:
    printf("ingrese un numero: ");scanf("%d",&num);
    if(num%2 == 0){
	 printf("el numero %d es par\n",num);
}
else{printf("el numero %d es impar\n",num);}

break;
case 3: break;

default: printf("opcion invalida\n");
}


return 0;
}
