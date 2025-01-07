#include <stdio.h>

int main() {
	int x , y;
	for(x=6 ; x>=1 ; x--)
	{
		for(y=1; y<=x; y++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
