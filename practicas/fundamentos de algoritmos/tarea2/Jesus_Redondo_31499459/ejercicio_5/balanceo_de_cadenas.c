/*
-EL arreglo solo acepta una cadena de maximo 8000000 caracteres
-El programa recibira una cadena de caracteres (incluyendo espacios) y lo balanceara de la siguiente forma:
Si el ultimo caracter es menor al primero entonces se intercambian sus valores, asi el segundo con el penultimo, el tercero con el antepenultimo y asi sucesivamente
*/
#include <stdio.h>
#include <string.h>
#define MAX 8000000

int main()
{
    char aux,cadena[MAX];
    int n;
    printf("ingrese la cadena a balancear: ");
    scanf("%[^\n]",cadena);
    n = strlen(cadena);
    for(int i=0;i<(n/2);i++)
    {
        if(cadena[i]>cadena[n-(i+1)])
        {
            aux = cadena[i];
            cadena[i]= cadena[n-(i+1)];
            cadena[n-(i+1)] = aux;
        }
    }
    printf("\n%s\n",cadena);
    return 0;
}
