#include <stdio.h>
int main(){
int a,b;
printf("ingrese a y b: ");
scanf("%i %i",&a,&b);
a=a+b;
b=a-b;
a=a-b;
printf("a=%i,b=%i\n",a, b);
return 0;
}
