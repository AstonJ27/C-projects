/* Programa que calcule ciertos parametros estadisticos */

#include <stdio.h>
#include <math.h>

int main()
{
    /* Declaracion de variables */
    int num, i, may, men, n, cont, cont_par, cont_imp, suma, c_izq, c_der;
    float prom;

    /* Entrada de datos */
    do
    {
        printf("Ingrese la cantidad de numeros a leer: ");
        scanf("%d", &n);

    } while (n < 2);

    i = 1;
    cont = 0;
    cont_par = 0;
    cont_imp = 0;
    may = 0;
    men = 0;
    suma = 0;
    c_der = 0;
    c_izq = 0;
    prom = 0;

    for(i=1; i<=n; i++)
    {
        do
        {
            printf("Ingrese el numero %i: ", i);
            scanf("%d", &num);
        } while (num < 1);

        if ((num % 2) == 0)
        {
            cont_par = cont_par + 1;
        }
        else
        {
            cont_imp = cont_imp + 1;
        }

        if (i == 1)
        {
            may = num;
            men = num;
        }
        else
        {
            if (num > may)
            {
                may = num;
            }
            if (num < men)
            {
                men = num;
            }
        }

        /* Seccion numeros cercanos a 100 izq y der */

          if (i == 1)
         {
             c_der = num; // 20
             c_izq = num; // 20
         }
         else
         {
             if ((num >= 100) && (num > c_der)) //aqui pusiste num<c_der y solo le cambie el < por >
             {
                 c_der = num;
             }
             else if ((num <= 100) && (num > c_izq))
             {
                 c_izq = num;
             }

             if (c_der < 100)
             {
                 c_der = 0;
             }
             if (c_izq > 100)
             {
                 c_izq = 0;
             }
         } 

        suma = suma + num;
        cont = cont + 1;
        prom = (float) suma / cont;
        //i++;
    }

    if (c_der == 0)
    {
        printf("\nNo hay cercano por la derecha");
    }
    else
    {
        printf("\nEl numero cercano derecha: %d", c_der);
    }

    if (c_izq == 0)
    {
        printf("\nNo hay cercano por la izquierda");
    }
    else
    {
        printf("\nEl numero cercano por la izquierda: %d", c_izq);
    }
    printf("\nEl total de numeros ingresados: %d ", cont);
    printf("\nEl numero mayor es: %d", may);
    printf("\nEl numero menor es: %d", men);
    printf("\nCantidad de pares: %d", cont_par);
    printf("\nCantidad de impares: %d", cont_imp);
    printf("\nLa suma de los numeros: %d", suma);
    printf("\nEl promedio es: %f", prom);

    return 0;
}
