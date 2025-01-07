#include <stdio.h>
int main(){
int op1,op2,res;
float a,b;

do{

printf("\tBienvenido a nuestro convertidor de unidades de longitud ");
printf("\nPor favor escoja la medida de longitud que quiere convertir:");
printf("\n1-Kilómetro");
printf("\n2-Hectómetro");
printf("\n3-Decámetro");
printf("\n4-Metro");
printf("\n5-Decímetro");
printf("\n6-Centímetro");
printf("\n7-Milímetro\n");
printf("\nIngrese una opcion: ");
scanf("%d",&op1);

if(op1 == 1 || op1 == 2 || op1 == 3 || op1 == 4 || op1 == 5 || op1 == 6 || op1 == 7){

printf("\nPor favor escoja la medida de longitud a la que quiere convertir:");
printf("\n1-Kilómetro");
printf("\n2-Hectómetro");
printf("\n3-Decámetro");
printf("\n4-Metro");
printf("\n5-Decímetro");
printf("\n6-Centímetro");
printf("\n7-Milímetro\n");
printf("\nIngrese una opcion: ");
scanf("%d",&op2);

switch(op1){                        //a partir de aqui se hace el primer switch para la primera variable
case 1://kilometros
	switch(op2){
	case 1:printf("\ndigite los kilometros que quiere convertir a kilometros\n");scanf("%f",&a);
	b=a;
printf("%f Kilometros convertido a kilometros es igual a: %f\n",a,b);break;
//fin
	case 2:printf("\ndigite los kilometros que quiere convertir a Hectometros\n");scanf("%f",&a);
	b=10*a;
printf("%f Kilometros convertido a Hectometros es igual a: %f\n",a,b);break;
//fin
	case 3:printf("\ndigite los kilometros que quiere convertir a Decametros\n");scanf("%f",&a);
	b=100*a;
printf("%f Kilometros convertido a Decametros es igual a: %f\n",a,b);break;
//fin
	case 4:printf("\ndigite los kilometros que quiere convertir a Metros\n");scanf("%f",&a);
	b=1000*a;
printf("%f Kilometros convertido a Metros es igual a: %f\n",a,b);break;
//fin
	case 5:printf("\ndigite los kilometros que quiere convertir a Decimetros\n");scanf("%f",&a);
        b=10000*a;
printf("%f Kilometros convertido a Decimetros es igual a: %f\n",a,b);break;
//fin
	case 6:printf("\ndigite los kilometros que quiere convertir a Centimetros\n");scanf("%f",&a);
        b=100000*a;
printf("%f Kilometros convertido a Centimetros es igual a: %f\n",a,b);break;
//fin

	case 7:printf("\ndigite los kilometros que quiere convertir a Milimetros\n");scanf("%f",&a);
        b=1000000*a;
printf("%f Kilometros convertido a Milimetros es igual a: %f\n",a,b);break;
default: printf("opcion invalida");
}break;
//fin caso 1
case 2://hectometros
	switch(op2){
	case 1:printf("\ndigite los Hectometros que quiere convertir a Kilometros\n");scanf("%f",&a);
        b=a/10;
printf("%f Hectometros convertido a Kilometros es igual a: %f\n",a,b);break;
//fin

	case 2:printf("\ndigite los Hectometros que quiere convertir a Hectometros\n");scanf("%f",&a);
        b=a;
printf("%f Hectometros convertido a Hectometros es igual a: %f\n",a,b);break;
//fin

	case 3:printf("\ndigite los Hectometros que quiere convertir a Decametros\n");scanf("%f",&a);
        b=10*a;
printf("%f Hectometros convertido a Decametros es igual a: %f\n",a,b);break;
//fin

	case 4:printf("\ndigite los Hectometros que quiere convertir a Metros\n");scanf("%f",&a);
        b=100*a;
printf("%f Hectometros convertido a Metros es igual a: %f\n",a,b);break;
//fin

	case 5:printf("\ndigite los Hectometros que quiere convertir a Decimetros\n");scanf("%f",&a);
        b=1000*a;
printf("%f Hectometros convertido a Decimetros es igual a: %f\n",a,b);break;
//fin

	case 6:printf("\ndigite los Hectometros que quiere convertir a Centimetros\n");scanf("%f",&a);
        b=10000*a;
printf("%f Hectometros convertido a Decimetros es igual a: %f\n",a,b);break;
//fin

	case 7:printf("\ndigite los Hectometros que quiere convertir a Milimetros\n");scanf("%f",&a);
        b=100000*a;

printf("%f Kilometros convertido a Decimetros es igual a: %f\n",a,b);break;
default: printf("opcion invalida");
} break;
//fin caso 2

case 3://decametros
        switch(op2){
        case 1:printf("\ndigite los Decametros que quiere convertir a Kilometros\n");scanf("%f",&a);
        b=a/100;

printf("%f Decametros convertido a Kilometros es igual a: %f\n",a,b);break;
//fin1
        case 2:printf("\ndigite los Decametros que quiere convertir a Hectometros\n");scanf("%f",&a);
        b=a/10;

printf("%f Decametros convertido a Hectometros es igual a: %f\n",a,b);break;
//fin2
        case 3:printf("\ndigite los Decametros que quiere convertir a Decametros\n");scanf("%f",&a);
        b=a;

printf("%f Decametros convertido a Decametros es igual a: %f\n",a,b);break;
//fin3
        case 4:printf("\ndigite los Decametros que quiere convertir a Metros\n");scanf("%f",&a);
        b=a*10;

printf("%f Decametros convertido a Metros es igual a: %f\n",a,b);break;
//fin4
        case 5:printf("\ndigite los Decametros que quiere convertir a Decimetros\n");scanf("%f",&a);
        b=a*100;

printf("%f Decametros convertido a Decimetros es igual a: %f\n",a,b);break;
//fin5
        case 6:printf("\ndigite los Decametros que quiere convertir a Centimetros\n");scanf("%f",&a);
        b=a*1000;

printf("%f Decametros convertido a Centimetros es igual a: %f\n",a,b);break;
//fin6
        case 7:printf("\ndigite los Decametros que quiere convertir a Milimetros\n");scanf("%f",&a);
        b=a*10000;

printf("%f Decametros convertido a Milimetros es igual a: %f\n",a,b);break;
default: printf("opcion invalida");
} break;
//fin caso 3

case 4://metros
        switch(op2){
        case 1:  printf("\ndigite los Metros que quiere convertir a Kilometros\n");scanf("%f",&a);
        b=a/1000;

printf("%f Metros convertido a Kilometros es igual a: %f\n",a,b);break;
//fin1
        case 2: printf("\ndigite los Metros que quiere convertir a Hectometros\n");scanf("%f",&a);
        b=a/100;

printf("%f Metros convertido a Hectometros es igual a: %f\n",a,b);break;
//fin2
        case 3: printf("\ndigite los Metros que quiere convertir a Decametros\n");scanf("%f",&a);
        b=a/10;

printf("%f Metros convertido a Decametros es igual a: %f\n",a,b);break;
//fin3
        case 4: printf("\ndigite los Metros que quiere convertir a Metros\n");scanf("%f",&a);
        b=a;

printf("%f Metros convertido a Metros es igual a: %f\n",a,b);break;
//fin4
        case 5: printf("\ndigite los Metros que quiere convertir a Decimetros\n");scanf("%f",&a);
        b=a*10;

printf("%f Metros convertido a Decimetros es igual a: %f\n",a,b);break;
//fin5
        case 6: printf("\ndigite los Metros que quiere convertir a Centimetros\n");scanf("%f",&a);
        b=a*100;

printf("%f Metros convertido a Centimetros es igual a: %f\n",a,b);break;
//fin6
        case 7: printf("\ndigite los Metros que quiere convertir a Milimetros\n");scanf("%f",&a);
        b=a*1000;

printf("%f Metros convertido a Milimetros es igual a: %f\n",a,b);break;
default: printf("opcion invalida");
} break;
//fin caso 4

case 5://decimetros
        switch(op2){
        case 1: printf("\ndigite los Decimetros que quiere convertir a Kilometros\n");scanf("%f",&a);
        b=a/10000;

printf("%f Decimetros convertido a Kilometros es igual a: %f\n",a,b);break;
//fin1
        case 2: printf("\ndigite los Decimetros que quiere convertir a Hectometros\n");scanf("%f",&a);
        b=a/1000;

printf("%f Decimetros convertido a Hectometros es igual a: %f\n",a,b);break;
//fin2
        case 3: printf("\ndigite los Decimetros que quiere convertir a Decametros\n");scanf("%f",&a);
        b=a/100;

printf("%f Decimetros convertido a Decametros es igual a: %f\n",a,b);break;
//fin3
        case 4: printf("\ndigite los Decimetros que quiere convertir a Metros\n");scanf("%f",&a);
        b=a/10;

printf("%f Decimetros convertido a Metros es igual a: %f\n",a,b);break;
//fin4
        case 5: printf("\ndigite los Decimetros que quiere convertir a Decimetros\n");scanf("%f",&a);
        b=a;

printf("%f Decimetros convertido a Decimetros es igual a: %f\n",a,b);break;
//fin5
        case 6: printf("\ndigite los Decimetros que quiere convertir a Centimetros\n");scanf("%f",&a);
        b=a*10;

printf("%f Decimetros convertido a Centimetros es igual a: %f\n",a,b);break;
//fin6
        case 7: printf("\ndigite los Decimetros que quiere convertir a Milimetros\n");scanf("%f",&a);
        b=a*100;

printf("%f Decimetros convertido a Milimetros es igual a: %f\n",a,b);break;
default: printf("opcion invalida");

} break;
//fin caso 5

case 6://centimetros
        switch(op2){
        case 1: printf("\ndigite los Centimetros que quiere convertir a Kilometros\n");scanf("%f",&a);
        b=a/100000;
printf("%f Centimetros convertido a Kilometros es igual a: %f\n",a,b);break;
//fin1
        case 2:printf("\ndigite los Centimetros que quiere convertir a Hectometros\n");scanf("%f",&a);
        b=a/10000;

printf("%f Centimetros convertido a Hectometros es igual a: %f\n",a,b);break;
//fin2

        case 3:printf("\ndigite los Centimetros que quiere convertir a Decametros\n");scanf("%f",&a);
        b=a/1000;

printf("%f Centimetros convertido a Decametros es igual a: %f\n",a,b);break;
//fin3

        case 4:printf("\ndigite los Centimetros que quiere convertir a Metros\n");scanf("%f",&a);
        b=a/100;

printf("%f Centimetros convertido a Metros es igual a: %f\n",a,b);break;
//fin4

        case 5:printf("\ndigite los Centimetros que quiere convertir a Decimetros\n");scanf("%f",&a);
        b=a/10;

printf("%f Centimetros convertido a Decimetros es igual a: %f\n",a,b);break;
//fin5

        case 6:printf("\ndigite los Centimetros que quiere convertir a Centimetros\n");scanf("%f",&a);
        b=a;

printf("%f Centimetros convertido a Centimetros es igual a: %f\n",a,b);break;
//fin6

        case 7:printf("\ndigite los Centimetros que quiere convertir a Milimetros\n");scanf("%f",&a);
        b=a*10;

printf("%f Centimetros convertido a Milimetros es igual a: %f\n",a,b);break;
default: printf("opcion invalida");
} break;
//fin caso 6

case 7://milimetros
        switch(op2){
        case 1:printf("\ndigite los Milimetros que quiere convertir a Kilometros\n");scanf("%f",&a);
        b=a/1000000;

printf("%f Milimetros convertido a Kilometros es igual a: %f\n",a,b);break;
//fin1

        case 2:printf("\ndigite los Milimetros que quiere convertir a Hectometros\n");scanf("%f",&a);
        b=a/100000;

printf("%f Milimetros convertido a Hectometros es igual a: %f\n",a,b);break;
//fin
        case 3:printf("\ndigite los Milimetros que quiere convertir a Decametros\n");scanf("%f",&a);
        b=a/10000;

printf("%f Milimetros convertido a Decametros es igual a: %f\n",a,b);break;
//fin
        case 4:printf("\ndigite los Milimetros que quiere convertir a Metros\n");scanf("%f",&a);
        b=a/1000;

printf("%f Milimetros convertido a Metros es igual a: %f\n",a,b);break;
//fin
        case 5:printf("\ndigite los Milimetros que quiere convertir a Decimetros\n");scanf("%f",&a);
        b=a/100;

printf("%f Milimetros convertido a Decimetros es igual a: %f\n",a,b);break;
//fin
        case 6:printf("\ndigite los Milimetros que quiere convertir a Centimetros\n");scanf("%f",&a);
        b=a/10;

printf("%f Milimetros convertido a Centimetros es igual a: %f\n",a,b);break;
//fin
        case 7:printf("\ndigite los Milimetros que quiere convertir a Milimetro\n");scanf("%f",&a);
        b=a;

printf("%f Milimetros convertido a Milimetro es igual a: %f\n",a,b);break;
default: printf("opcion invalida");
} break;
//fin caso 7

} // aqui termina nuestro switch mas grande
} // fin del condicional
else{printf("\nopcion invalida\n");}

printf("\n\n¿Quieres volver a empezar?\n");
printf("1.Si\n");
printf("2.No\n");
printf("ingrese una opcion: ");
scanf("%d",&res);
printf("\n\n");

}while(res!=2);

return 0;
}//fin del programa
