#include <stdio.h>
int main(){
int h,m,s;
printf("segundos: ");
scanf("%d",&s);

h=s/3600;
s=s%3600;
m=s/60;
s=s%60;

printf("horas:%d , Minutos:%d , segundos:%d\n",h,m,s);
return 0;}
