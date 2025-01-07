/*dadas esquinas de un rectangulo y un punto en el plano hacer un programa que indique si el punto esta dentro, fuera, o en el borde del rectangulo*/
#include <stdio.h>
#include <stdlib.h>
#define rojo "\x1b[31m"
#define reset "\033[0m"
int main()
{
    float x1=0.0,x2=0.0,xp=0.0,y1=0.0,y2=0.0,yp=0.0;

    printf("ingrese las esquinas del rectangulo (x1,y1) (x2,y2): ");
    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
    printf("ingrese el punto a evaluar: ");
    scanf("%f %f",&xp,&yp);
    
    if(xp == 0.0 && yp == 0.0 && y1 == 0.0 && y2 == 0.0 && x1==0.0 && x2==0.0)
    {
        system("clear");
        printf(rojo"\nError los datos ingresados no son validos o solo ingreso ceros\n"reset);
        printf("hola");
    }
    else if(xp < x1 || xp > x2 || yp < y1 || yp > y2)
    {
        printf("El punto esta fuera\n");
    }
    else if(xp == x1 || xp == x2 || yp == y1 || yp == y2)
    {
        printf("El punto esta en el borde\n");
    }
    else
    {
        printf("El punto esta dentro\n");
    }
    
    return 0;
}