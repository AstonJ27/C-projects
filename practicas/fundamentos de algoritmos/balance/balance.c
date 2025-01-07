#include <stdio.h>
#include <ctype.h>

int main()
{
    int i=0,j=-1;
    char n;//j
    FILE *arch1;//*arch2;
    arch1 = fopen("entrada.txt","r");
    //arch2 = fopen("salida.txt","w");
    
    while(fscanf(arch1,"%c",&n) != EOF)
    {
        if(n == '\n')
        {
            i++;
        }
    }
    i++;
    printf("%d",i);








    return 0;
}