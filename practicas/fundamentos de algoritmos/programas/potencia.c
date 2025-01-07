#include <stdio.h>
int main(){
	
int a,b,i,c ;
c=1;
printf("escribe una base: ");
scanf("%d",&a);
printf("escribe un exponente: ");
scanf("%d",&b);
for (i=1 ; i<=b ; i++){
c*=a;
	}
	printf("el resultado es:%d\n",c);
return 0;
	}
