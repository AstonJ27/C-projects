#include <stdio.h>
int main(){
int i,n;

for (i == 1; i<=99; i++){
	n = i+1;
if((n%3 == 0) && (n%15 != 0)){
	printf("fizz\n");
 } else{
	if((n%5 == 0) && (n%15 != 0)){
		printf("buzz\n");
 } else{
	if((n%15 == 0) && (n != 0)){
	printf("fizzbuzz\n");
 } else{ printf("%d\n",n);
 }// else mas interno

}//else interno

}//else

}//ciclo

return 0;
}
