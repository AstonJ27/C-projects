#include <stdio.h>
int main(){
int n,suma,i=1;
printf("ingrese el numero");
scanf("%i",&n);
suma = 0;
for(i=1 ; i<n ; i++);{
if(n%i == 0){
suma = suma + i;
}
}
if(suma == n){
printf("el numero es perfecto\n");
}else{
printf("el numero no es perfecto\n");
}


return 0;
}
