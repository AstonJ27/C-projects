#include <stdio.h>
#include <math.h>
int main(){
float x1,x2,y1,y2,sol;

	printf("ingrese el primer punto: ");
	scanf("%f %f",&x1,&y1);
	printf("ingrese el segundo punto: ");
	scanf("%f %f",&x2,&y2);
sol = sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
	printf("la solución es %.2f\n ",sol);

return 0;
}
