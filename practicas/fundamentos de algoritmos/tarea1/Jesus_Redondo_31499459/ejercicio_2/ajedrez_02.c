#include <stdio.h>
#define SALIDA "02-salida-tablero.txt"

void tabla(char matriz[8][8])
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            matriz[i][j]='*';
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *ent,*sal;
    int g=1,fila;
    char tablero[8][8],color[20];
    char columna,codigo;

    
    while(ent == NULL)
    {
        ent = fopen(argv[g],"r");
        g++;
   
        if(g == argc+1)
        {
            printf("ajedrez_02 [ARCHIVO 1] [ARCHIVO 2] ... [ARCHIVO N]\n");
            return 1;
        }
    }
    sal = fopen(SALIDA,"w");
    tabla(tablero);
    while (fscanf(ent,"%d %c %c %s",&fila,&columna,&codigo,color) != EOF)
    {
        tablero[fila-1][columna - 'A'] = codigo;
    }
    fprintf(sal,"%s\n",argv[g-1]);
    //
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            fprintf(sal,"%c ",tablero[i][j]);
        }
        fprintf(sal,"\n");
    }
    printf("Listo %s\n",argv[g-1]);
    
    fclose(ent);
    fclose(sal);
    return 0;
}