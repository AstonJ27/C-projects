#include <stdio.h>
int main(){
FILE *A;
int a,b,c;
A = fopen("/home/jesus/dir1/a.txt","r"); 
	if(A == NULL){
		printf("\nEl archivo no esta en el directorio\n");
		return 1;
}
	else{
		fscanf(A,"%d%d",&a,&b);
		c = a + b;
		printf("la suma de los primeros 2 elementos de a.txt es: %d\n",c);
fclose(A);
}
return 0;}
