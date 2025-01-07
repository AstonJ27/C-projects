#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
#define MAXP 3
typedef struct
{
 char pixR[MAXP],pixG[MAXP],pixB[MAXP],pixA[MAXP];
}pixel;
int comparar(char a[],char b[])
{
    int num1 = strtol(a, NULL, 16);
    int num2 = strtol(b, NULL, 16);
    
    if(num1>num2)
    {
        return 1; //primera cadena es mayor
    }
    else
    {
        return 0; //la segunda es mayor
    }
}

void mayus(char *a) 
{
    int longitud = strlen(a);
    for (int i = 0; i < longitud; i++) 
    {
        if (isalpha(a[i])) 
        {  // Verifica si el carácter es una letra
            a[i] = toupper(a[i]); //convierte en mayuscula
        }
    }
}

void suma_hex(char a[], char b[], char hex[])
{
    int num1 = strtol(a, NULL, 16);
    int num2 = strtol(b, NULL, 16);
    
    int suma = num1 + num2;

    if (suma > 255) 
    {
        suma = 255;
    }

    sprintf(hex, "%02x", suma);
    mayus(hex);

}

void resta_hex(char a[],char b[], char hex[]) 
{
    int num1 = strtol(a, NULL, 16);
    int num2 = strtol(b, NULL, 16);
    int resta = num1 - num2;
    if (resta < 0) 
    {
        resta = 0;
    } 
    sprintf(hex, "%02x",resta);
    mayus(hex);
} 


int main(int argc, char *argv[])
{
    FILE *ent1, *ent2, *sal;
    pixel p1[MAX][MAX],p2[MAX][MAX],p3[MAX][MAX];
    int g=2,r=3,fila,columna,fila1,columna1;
    
    while(ent1==NULL)
    {
        if(g == argc)
        {
            printf("File1 not found\n");
            return 1;
        }
        ent1 = fopen(argv[g],"r");
        g++;
        
    }
    while(ent2==NULL)
    {
        if(g == argc)
        {
            printf("File2 not found\n");
            return 1;
        }

        ent2 = fopen(argv[g],"r");
        g++;
    }
    sal=fopen("result.txt","w");
 
    fscanf(ent1,"%d",&fila);
    fscanf(ent1,"%d",&columna);
    fscanf(ent2,"%d",&fila1);
    fscanf(ent2,"%d",&columna1);
    if(fila1<fila)
    {
        fila = fila1;
    }
    if(columna1<columna)
    {
        columna = columna1;
    }
    
    for(int i=0;i<fila;i++)
    {
        for(int j=0;j<columna;j++)
        {
            fscanf(ent1,"%2s%2s%2s%2s",p1[i][j].pixR,p1[i][j].pixG,p1[i][j].pixB,p1[i][j].pixA);
        }
    }
    for(int i=0;i<fila;i++)
    {
        for(int j=0;j<columna;j++)
        {
            fscanf(ent2,"%2s%2s%2s%2s",p2[i][j].pixR,p2[i][j].pixG,p2[i][j].pixB,p2[i][j].pixA);
        }
    }
    fprintf(sal,"%d %d\n",fila,columna);
    if (strcmp(argv[1],"sumar")==0)
    {
        for(int i = 0; i < fila; i++)
        {
            for (int j = 0; j < columna; j++)
            {
                suma_hex(p1[i][j].pixR,p2[i][j].pixR,p3[i][j].pixR);
                suma_hex(p1[i][j].pixG,p2[i][j].pixG,p3[i][j].pixG);
                suma_hex(p1[i][j].pixB,p2[i][j].pixB,p3[i][j].pixB);
                suma_hex(p1[i][j].pixA,p2[i][j].pixA,p3[i][j].pixA);
                
                fprintf(sal,"%2s%2s%2s%2s ",p3[i][j].pixR,p3[i][j].pixG,p3[i][j].pixB,p3[i][j].pixA);

            }
            fprintf(sal,"\n");
        }
    }
    else if(strcmp(argv[1],"restar")==0)
    {
        for(int i = 0; i < fila; i++)
        {
            for (int j = 0; j < columna; j++)
            {
                resta_hex(p1[i][j].pixR,p2[i][j].pixR,p3[i][j].pixR);
                resta_hex(p1[i][j].pixG,p2[i][j].pixG,p3[i][j].pixG);
                resta_hex(p1[i][j].pixB,p2[i][j].pixB,p3[i][j].pixB);
                resta_hex(p1[i][j].pixA,p2[i][j].pixA,p3[i][j].pixA);

                fprintf(sal,"%2s%2s%2s%2s ",p3[i][j].pixR,p3[i][j].pixG,p3[i][j].pixB,p3[i][j].pixA);
            }
            fprintf(sal,"\n");
        }
    }
    else if(strcmp(argv[1],"intersectar")==0)
    {
        for(int i = 0; i < fila; i++)
        {
            for (int j = 0; j < columna; j++)
            {
                strcpy(p3[i][j].pixR, p1[i][j].pixR);
                strcpy(p3[i][j].pixG, p1[i][j].pixG);
                strcpy(p3[i][j].pixB, p1[i][j].pixB);
                if(!comparar(p1[i][j].pixA,p2[i][j].pixA)) //p1 es el menor
                {
                    strcpy(p3[i][j].pixA, p1[i][j].pixA);
                }
                else //p2 es el menor
                {
                    strcpy(p3[i][j].pixA, p2[i][j].pixA);
                }
                fprintf(sal,"%2s%2s%2s%2s ",p3[i][j].pixR,p3[i][j].pixG,p3[i][j].pixB,p3[i][j].pixA);
            }
            fprintf(sal,"\n");
        }
    }
    else if(strcmp(argv[1],"unir")==0)
    {
        for(int i = 0; i < fila; i++)
        {
            for (int j = 0; j < columna; j++)
            {
                strcpy(p3[i][j].pixR, p1[i][j].pixR);
                strcpy(p3[i][j].pixG, p1[i][j].pixG);
                strcpy(p3[i][j].pixB, p1[i][j].pixB);
                if(!comparar(p1[i][j].pixA,p2[i][j].pixA)) // p2 es mayor
                {
                    strcpy(p3[i][j].pixA, p2[i][j].pixA);
                }
                else //p1 es mayor
                {
                    strcpy(p3[i][j].pixA, p1[i][j].pixA);
                }

                fprintf(sal,"%2s%2s%2s%2s ",p3[i][j].pixR,p3[i][j].pixG,p3[i][j].pixB,p3[i][j].pixA);
            }
            fprintf(sal,"\n");
        }
    } 
    printf("\nlisto\n");
    fclose(ent1);
    fclose(ent2);
    fclose(sal);
    return 0;
}