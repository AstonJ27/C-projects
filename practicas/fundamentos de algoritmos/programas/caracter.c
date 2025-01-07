/* crear un programa que lea caracteres  desde la entrada estandar y permita redactar las siguientes estadisticas
0-cantidad de letras mayusculas
-cantidad de letras minusculas
-total de letras 
-frecuencia de mayusculas 
-frecuencia de minusculas
formula de frecuencia : F = (# elementos del conjunto A)/(# elementos del universo)
(detener el programa si consigue un caracter que no es una letra)
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    int cma=0,cmin=0,tot=0,salida=1;
    float frecma,frecmin;
    char ent;
    do
    {
        printf("ingrese un caracter (presione * para terminar de recibir los datos):");
        scanf(" %c",&ent);
        
        if(ent == '*')
        {
            salida = 0;
        }
        else if(isalpha(ent))
        {
            if(isupper(ent))    
            {    
                cma += 1;
                tot += 1;
            }
            else if(islower(ent)) //podria ser solo un else puesto que si entró al isalpha es una letra y si no es mayuscula (isupper) es minuscula
            {
                cmin += 1;
                tot += 1;
            }
        }
        else
        {
            printf("El caracter ingresado no es una letra\n");
            return 1;
        }
    }while(salida);

    frecma = (float)cma/tot;
    frecmin = (float) cmin/tot;
    system("clear");
    
    printf("\nCantidad de mayusculas: %i\n",cma);
    printf("\nCantidad de minusculas: %i\n",cmin);
    printf("\nFrecuencia de mayusculas: %f\n",frecma);
    printf("\nFrecuencia de minusculas: %f\n",frecmin);
    printf("\nCaracteres ingresados: %i\n",tot);

    return 0;
}