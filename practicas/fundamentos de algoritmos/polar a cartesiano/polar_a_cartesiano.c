#include <stdio.h>
#include <math.h>
void cartesiano(float r, float t,float *x,float *y);

int main()
{
    float r,t,x,y;
    printf("Ingrese las coordenadas polares r y theta: ");
    scanf("%f %f",&r,&t);
    
    cartesiano(r,t,&x,&y);
    printf("sus coordenadas cartesianas son: (%.2f,%.2f)\n",x,y);

    return 0;
}

void cartesiano(float r, float t,float *x,float *y)
{
    *x= r * cos(t);
    *y= r * sin(t);
}