//2. dado un arreglo, en contrar en un arreglo cual es el mayor y cual es el menor (con funciones)
#include <stdio.h>
int menor(int array[], int tam);    //funciones para buscar el mayor y el menor
int mayor(int array[], int tam);    
int main()
{
    int ma,men,tam, arreglo[]={2,4,6,8,10,1,12,14,16};
    
    tam = sizeof(arreglo)/sizeof(int);  //definimos las variables
    ma = mayor(arreglo, tam);           //se encuentra el mayor 
    men = menor(arreglo, tam);          //se encuentra el menor
    
    printf("el numero mayor es: %d\n",ma);
    printf("el numero menor es: %d\n",men);
}

int mayor(int array[], int tam) //para encontrar el numero debemos pasar el arreglo y el tamaño real del arreglo
{
    int i, a=array[0];
    for(i=0;i<tam;i++)      //una vez empezada la funcion, la variable auxiliar "a" toma el valor del primer elemento del arreglo y se compara con el resto de variables
    {                       //para encontrar el mayor
        if(a < array[i])
        {
            a = array[i];
        }
    }
    return a;
}

int menor(int array[], int tam)
{
    int i, a=array[0];          //una vez empezada la funcion, la variable auxiliar "a" toma el valor del primer elemento del arreglo y se compara con el resto de variables
    for(i=0;i<tam;i++)          //para encontrar el menor
    {
        if(a > array[i])
        {
            a = array[i];
        }
    }
    return a;
}