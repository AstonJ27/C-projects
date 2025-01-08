#include <stdio.h>

int main(){

	int n = 5, m;
	printf("m = ");
	scanf("%d",&m);
	printf("%3d\n",n);
	printf("%03d\n",n);
	printf("%0*d\n",m,n);
	return 0;
}
