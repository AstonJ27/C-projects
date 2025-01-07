/*
-El arreglo solo acepta una cadena de maximo 8000000 caracteres
-Puede recibir cadenas con signos de puntuacion (, . ; : ? !)
-Puede recibir cadenas con letras mayusculas o minusculas
-El programa recibira una cadena de caracteres (incluye espacios) y verificara si la cadena es un palindromo o no
-Un palindromo es una palabra o frase que puede leerse de igual forma tanto al derecho como al reves
*/
#include <stdio.h>
#include <string.h>
#define MAX 8000000

int main()
{
    int n,r=0;
    char ent[MAX];
    printf("Ingrese su palabra o frase: ");
    scanf("%[^\n]",ent);
    n = strlen(ent);
    while(ent[r]!='\0')
    {
        if(ent[r]<'A' || (ent[r]>'Z' && ent[r]<'a') || ent[r]>'z')
        {
            for(int i=r;i<n;i++)
            {
                ent[i]=ent[i+1];
                
            }
            r--;
            n--;
        }
        if(ent[r]>='A' && ent[r]<='Z')
        {
            ent[r]+=32;
        }
        r++;
    }
    r=1;
    for(int i=0;i<=(n-1/2);i++)
    {
        if(ent[i] != ent[n-(i+1)])
        {
            r=0;
        }
    }
    if (r)
    {
        printf("\nEs palindromo\n");
    }else
    {
        printf("\nNo es palindromo\n");
    }
    return 0;
}
