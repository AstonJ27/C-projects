#include <stdio.h>
#include <math.h>
int main(){
char cateto;
float a,b,c;
printf("¿que lado del triangulo rectangulo quiere obtener?\npara escoger la hipotenusa presione h\npara escoger la base presione b\npara escoger la altura presione a\n");
scanf("%c",&cateto);
switch(cateto){

case 'h': printf("digite un valor para los catetos a y b:") ;
	  scanf("%f %f",&a,&b);
	  c = sqrt(pow(a,2)+pow(b,2));
printf("la hipotenusa del triangulo es: %f\n",c);break;

case 'b': printf("digite un valor para la hipotenusa y el cateto a:") ;
          scanf("%f %f",&c,&a);
if(c > a){
 b = sqrt(pow(c,2)-pow(a,2));
printf("el cateto b del triangulo es: %f\n",b);
}
else{printf("la hipotenusa no puede ser menor a ninguno de los catetos\n");}
break;

case 'a': printf("digite un valor para la hipotenusa y el cateto b:") ;
          scanf("%f %f",&c,&b);
if(c > b){
a = sqrt(pow(c,2)-pow(b,2));
printf("el cateto a del triangulo es: %f\n",a);
}
else{printf("la hipotenusa no puede ser menor a ninguno de los catetos\n");}
break;
default: printf("caracter incorrecto :(\n");
}

return 0;
}
