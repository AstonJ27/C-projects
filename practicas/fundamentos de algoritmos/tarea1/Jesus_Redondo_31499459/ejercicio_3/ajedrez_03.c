#include <stdio.h>
#include <string.h>
#define SALIDA "02-salida-tablero.txt"

void super_break(int *a, int*b )
{
    *a=100;
    *b=100;
}
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

struct posicion_de_pieza
{
    char codigo;
    char color[10];
    int f,c; //fila y, columna x
}pieza[32];

int main(int argc, char *argv[])
{
    FILE *ent,*sal;
    int g=1,fila;
    char tablero[8][8],turno[10];
    char columna;
    
    
    while(ent == NULL)
    {
        ent =fopen(argv[g],"r");
        g++;
   
        if(g == argc+1)
        {
            printf("ajedrez_02 [ARCHIVO 1] [ARCHIVO 2] ... [ARCHIVO N]\n");
            return 1;
        }
    }//Verificamos que el se haya puesto un archivo existente
    
    sal = fopen(SALIDA,"w");
    tabla(tablero); //llenamos la matriz de espacios vacios
    
    fscanf(ent, "%s",turno); //leemos el turno actual
    int l=0;
    while (fscanf(ent,"%d %c %c %s",&fila,&columna,&pieza[l].codigo,pieza[l].color) != EOF)
    {   
        pieza[l].f = fila-1;
        pieza[l].c = columna-'A';
        tablero[fila-1][columna - 'A'] = pieza[l].codigo;
        l++;
    }//llenamos la matriz con las posiciones definidas por el archivo de entrada
    //verificamos las posibles piezas en peligro

    fprintf(sal,"%s\n",argv[g-1]);
    // P,R,N,B,Q,K
    for(int i=0;i<=l;i++)
    {
        if(strcmp(pieza[i].color, turno)==0)
        {
            switch(pieza[i].codigo)//vemos el tipo de pieza
            {
                case 'P'://peon
                    for(int j=0;j<=l;j++)
                    {
                        if(strcmp(pieza[i].color, "WHITE") == 0)//la pieza es blanca    
                        {    
                            if((pieza[i].f +1 == pieza[j].f) && ((pieza[i].c +1 == pieza[j].c)||(pieza[i].c -1 == pieza[j].c)))
                            {
                                if(strcmp(pieza[i].color, pieza[j].color) != 0)
                                {
                                    fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                }
                            }
                        }
                        else //la pieza es negra 
                        {
                            if((pieza[i].f -1 == pieza[j].f) && ((pieza[i].c +1 == pieza[j].c)||(pieza[i].c -1 == pieza[j].c)))
                            {
                                if(strcmp(pieza[i].color, pieza[j].color) != 0)
                                {
                                    fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                }
                            }
                        }
                    }   
                break;//fin peon
                case 'R': //torre
                    for(int j=0;j<=l;j++) //para cada pieza
                    {
                        if(pieza[i].f == pieza[j].f) // comprueba si hay otra pieza en su fila
                        {
                            for(int r=1;r<=7;r++)//itera a las columnas
                            {
                                if(pieza[i].c + r == pieza[j].c) //compara si hay una pieza en la columna donde esta la torre a la derecha
                                {
                                    if(strcmp(pieza[i].color, pieza[j].color) != 0)//son colores distintos
                                    {
                                        fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                        super_break(&j,&r);
                                    }
                                    else
                                    {   
                                        super_break(&j,&r);
                                    }
                                }
                                //break
                            }
                        }
                    }    //arreglado 1
                    for(int j=0;j<=l;j++)
                    {       
                        if(pieza[i].f == pieza[j].f)
                        {       
                            for(int r=1;r<=7;r++)
                            {
                                if(pieza[i].c - r == pieza[j].c)//compara si hay una pieza en la columna donde esta la torre a la izquierda
                                {
                                    if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                                    {
                                        fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                        super_break(&j,&r);
                                    }
                                    else
                                    {
                                        super_break(&j,&r);
                                    }
                                }
                            }
                        }//fin de fila que comprueba a ambos lados
                    }//arreglado 2
                    for(int j=0;j<=l;j++) //para cada pieza
                    {
                        if(pieza[i].c == pieza[j].c) // comprueba si hay otra pieza en su columna
                        {
                            for(int r=1;r<=7;r++)//itera a las filas
                            {
                                if(pieza[i].f + r == pieza[j].f) //compara si hay una pieza en la columna donde esta la torre arriba
                                {
                                    if(strcmp(pieza[i].color, pieza[j].color) != 0)//son colores distintos
                                    {
                                        fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                        super_break(&j,&r);
                                    }
                                    else
                                    {
                                        super_break(&j,&r);
                                    }
                                }
                                
                            }
                        }
                    }
                    for(int j=0;j<=l;j++)
                    {       
                        if(pieza[i].c == pieza[j].c)
                        {       
                            for(int r=1;r<=7;r++)
                            {
                                if(pieza[i].f - r == pieza[j].f)//compara si hay una pieza en la columna donde esta la torre a abajo
                                {
                                    if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                                    {
                                        fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                        super_break(&j,&r);
                                    }
                                    else
                                    {
                                        super_break(&j,&r);
                                    }
                                }
                            }
                        }//fin de fila que comprueba a ambos lados
                    }
                break;
                case 'Q'://reina
                    for(int j=0;j<=l;j++) //para cada pieza
                    {
                        if(pieza[i].f == pieza[j].f) // comprueba si hay otra pieza en su fila
                        {
                            for(int r=1;r<=7;r++)//itera a las columnas
                            {
                                if(pieza[i].c + r == pieza[j].c) //compara si hay una pieza en la columna donde esta la torre a la derecha
                                {
                                    if(strcmp(pieza[i].color, pieza[j].color) != 0)//son colores distintos
                                    {
                                        fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                        super_break(&j,&r);
                                    }
                                    else
                                    {  
                                        super_break(&j,&r);
                                    }
                                }
                                //break
                            }
                        }
                    }    //arreglado 1
                    for(int j=0;j<=l;j++)
                    {       
                        if(pieza[i].f == pieza[j].f)
                        {       
                            for(int r=1;r<=7;r++)
                            {
                                if(pieza[i].c - r == pieza[j].c)//compara si hay una pieza en la columna donde esta la torre a la izquierda
                                {
                                    if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                                    {
                                        fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                        super_break(&j,&r);
                                    }
                                    else
                                    {  
                                        super_break(&j,&r);
                                    }
                                }
                            }
                        }//fin de fila que comprueba a ambos lados
                    }//arreglado 2
                    for(int j=0;j<=l;j++) //para cada pieza
                    {
                        if(pieza[i].c == pieza[j].c) // comprueba si hay otra pieza en su columna
                        {
                            for(int r=1;r<=7;r++)//itera a las filas
                            {
                                if(pieza[i].f + r == pieza[j].f) //compara si hay una pieza en la columna donde esta la torre a la derecha
                                {
                                    if(strcmp(pieza[i].color, pieza[j].color) != 0)//son colores distintos
                                    {
                                        fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                        super_break(&j,&r);
                                    }
                                    else
                                    {
                                        super_break(&j,&r);
                                    }
                                }
                                //break
                            }
                        }
                    }
                    for(int j=0;j<=l;j++)
                    {       
                        if(pieza[i].c == pieza[j].c)
                        {       
                            for(int r=1;r<=7;r++)
                            {
                                if(pieza[i].f - r == pieza[j].f)//compara si hay una pieza en la columna donde esta la torre a la izquierda
                                {
                                    if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                                    {
                                        fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                        super_break(&j,&r);
                                    }
                                    else
                                    {
                                        super_break(&j,&r);
                                    }
                                }
                            }
                        }//fin de fila que comprueba a ambos lados
                    }//ALFIL
                    for (int j=0;j<=l;j++)//cada pieza
                    { 
                        for(int r=1;r<=7;r++)
                        {
                            if ((pieza[i].f +r == pieza[j].f) && (pieza[i].c -r == pieza[j].c))//  <^
                            {
                                if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                                {
                                    fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                    super_break(&j,&r);
                                }
                                else
                                {
                                    super_break(&j,&r);
                                }
                            }
                            
                        }
                    }
                    for (int j=0;j<=l;j++)//cada pieza
                    { 
                        for(int r=1;r<=7;r++)
                        {
                            if ((pieza[i].f -r == pieza[j].f) && (pieza[i].c +r == pieza[j].c))//  v>
                            {
                                if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                                {
                                    fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                    super_break(&j,&r);
                                }
                                else
                                { 
                                    super_break(&j,&r);
                                }
                            }
                            
                        }
                    }
                    for (int j=0;j<=l;j++)//cada pieza
                    { 
                        for(int r=1;r<=7;r++)
                        {
                            if ((pieza[i].f -r == pieza[j].f) && (pieza[i].c -r == pieza[j].c))//  <v
                            {
                                if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                                {
                                    fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                    super_break(&j,&r);
                                }
                                else
                                {
                                    super_break(&j,&r);
                                }
                            }
                            
                        }
                    }
                    for (int j=0;j<=l;j++)//cada pieza
                    { 
                        for(int r=1;r<=7;r++)
                        {
                            if ((pieza[i].f +r == pieza[j].f) && (pieza[i].c +r == pieza[j].c))//  ^>
                            {
                                if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                                {
                                    fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                    super_break(&j,&r);
                                }
                                else
                                {
                                    super_break(&j,&r);
                                }
                            }
                            
                        }
                    }
                break;
                case 'B'://Alfil
                    for (int j=0;j<=l;j++)//cada pieza
                    { 
                        for(int r=1;r<=7;r++)
                        {
                            if ((pieza[i].f +r == pieza[j].f) && (pieza[i].c -r == pieza[j].c))//  <^
                            {
                                if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                                {
                                    fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                    super_break(&j,&r);
                                }
                                else
                                {
                                    super_break(&j,&r);
                                }
                            }
                            
                        }
                    }
                    for (int j=0;j<=l;j++)//cada pieza
                    { 
                        for(int r=1;r<=7;r++)
                        {
                            if ((pieza[i].f -r == pieza[j].f) && (pieza[i].c +r == pieza[j].c))//  v>
                            {
                                if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                                {
                                    fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                    super_break(&j,&r);
                                }
                                else
                                { 
                                    super_break(&j,&r);
                                }
                            }
                            
                        }
                    }
                    for (int j=0;j<=l;j++)//cada pieza
                    { 
                        for(int r=1;r<=7;r++)
                        {
                            if ((pieza[i].f -r == pieza[j].f) && (pieza[i].c -r == pieza[j].c))//  <v
                            {
                                if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                                {
                                    fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                    super_break(&j,&r);
                                }
                                else
                                {
                                    super_break(&j,&r);
                                }
                            }
                            
                        }
                    }
                    for (int j=0;j<=l;j++)//cada pieza
                    { 
                        for(int r=1;r<=7;r++)
                        {
                            if ((pieza[i].f +r == pieza[j].f) && (pieza[i].c +r == pieza[j].c))//  ^>
                            {
                                if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                                {
                                    fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                                    super_break(&j,&r);
                                }
                                else
                                {
                                    super_break(&j,&r);
                                }
                            }
                            
                        }
                    }
                break;
                case 'K':
                    for(int j=0;j<=l;j++)
                    {
                        if((pieza[j].c >= pieza[i].c+1)&&(pieza[j].c <= pieza[i].c+1)&&(pieza[j].f >= pieza[i].f+1)&&(pieza[j].f >= pieza[i].f+1))
                        {
                            if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                            {
                                fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                            }
                        }
                    }
                break;
                case 'N':
                    for(int j=0;j<=l;j++)
                    {
                        if((pieza[i].f +2== pieza[j].f) && ((pieza[j].c == pieza[i].c+1)||(pieza[j].c == pieza[i].c-1)))
                        {
                            if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                            {
                                fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                            }
                        }
                        if((pieza[i].f -2== pieza[j].f) && ((pieza[j].c == pieza[i].c+1)||(pieza[j].c == pieza[i].c-1)))
                        {
                            if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                            {
                                fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                            }
                        }
                        if((pieza[i].c +2== pieza[j].c) && ((pieza[j].f == pieza[i].f+1)||(pieza[j].f == pieza[i].f-1)))
                        {
                            if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                            {
                                fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                            }
                        }
                        if((pieza[i].c -2== pieza[j].c) && ((pieza[j].f == pieza[i].f+1)||(pieza[j].f == pieza[i].f-1)))
                        {
                            if(strcmp(pieza[i].color, pieza[j].color) !=0 )
                            {
                                fprintf(sal,"%d %c %c %s\n",pieza[j].f+1,pieza[j].c +'A',pieza[j].codigo,pieza[j].color);
                            }
                        }
                    }
                break;
                default:break;
            }
        }    
    }   
    
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            fprintf(sal,"%c ",tablero[i][j]);
        }
        fprintf(sal,"\n");
    }
    printf("Listo %s\n",argv[g-1]);    
    
    fclose(sal);
    fclose(ent);
    return 0;
}