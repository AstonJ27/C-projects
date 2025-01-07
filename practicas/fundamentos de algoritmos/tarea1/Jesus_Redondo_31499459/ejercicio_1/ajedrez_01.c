#include <stdio.h>
#define SALIDA "01-salida-tablero.txt"
#define size 500

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

int main()
{
    FILE *ent, *sal;
    char tablero[8][8],color[20],lectura[size];
    char columna,codigo;
    int fila;

    printf("ubicacion del tablero: ");
    scanf("%s",lectura);
    ent = fopen(lectura,"r");
    sal=fopen(SALIDA,"w");
    if (ent == NULL)
    {
        printf("error al abrir el archivo");
        return 1;
    }
    if (sal == NULL)
    {
        printf("error al abrir el archivo");
        return 1;
    }
    
    tabla(tablero);
    while (fscanf(ent,"%d %c %c %s",&fila,&columna,&codigo,color) != EOF)
    {
        tablero[fila-1][columna - 'A'] = codigo;
    }
    
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            fprintf(sal,"%c ",tablero[i][j]);
        }
        fprintf(sal,"\n");
    }
    printf("Listo\n");
    
    fclose(ent);
    fclose(sal);
    return 0;
}
