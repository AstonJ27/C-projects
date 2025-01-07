#include <stdio.h>

int main() {

int a,b,suma,resta,producto,resto ;
float cociente;
printf("dame un numero a: ");
scanf("%i", &a);
printf("dame un numero b: ");
scanf("%d", &b);
suma=a+b;
resta=a-b;
producto=a*b;
resto=b%a; 
if(a==0)
	printf("la division en cero no esta definida");
	
else {cociente=(float)b/a;
	}
printf(" suma= %d\n resta= %d\n producto= %d\n modulo o resto= %d\n cociente= %f\n ", suma, resta, producto, resto, cociente);

}
