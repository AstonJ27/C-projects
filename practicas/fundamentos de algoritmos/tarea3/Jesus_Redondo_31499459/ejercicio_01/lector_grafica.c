#include <stdio.h>
#define MAX 100
#define MAXP 3
typedef struct
{
 char pixR[MAXP],pixG[MAXP],pixB[MAXP],pixA[MAXP];
}pixel;

int main(int argc, char *argv[])
{
    FILE *ent;
    pixel p[MAX][MAX];
    int g=1,fila,columna;
    while(ent==NULL)
    {
        ent = fopen(argv[g],"r");
        g++;
        if(g == argc+1)
        {
            printf("File not found\n");
            return 1;
        }
    }
    
    fscanf(ent,"%d",&fila);
    fscanf(ent,"%d",&columna);
    
    for(int i=0;i<fila;i++)
    {
        for(int j=0;j<columna;j++)
        {
            fscanf(ent,"%2s%2s%2s%2s",p[i][j].pixR,p[i][j].pixG,p[i][j].pixB,p[i][j].pixA);
        }
    }
    printf("\nlisto\n");
    fclose(ent);
    
    
    return 0;
}
