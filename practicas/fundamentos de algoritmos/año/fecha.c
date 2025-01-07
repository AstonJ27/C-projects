#include <stdio.h>

void validar_y_bisiesto(int d, int m,int a, int *b,int *v);

int main()
{
    //FILE *arch;
    int d,m,a,b,v;
    //arch = fopen("fechas.txt", "r");
    
    //while(fscanf(arch,"%d %d %d",&d,&m,&a) != EOF)    
    //{
        do
        {
            printf("ingrese una fecha DD/MM/AAAA: ");
            scanf("%d %d %d",&d,&m,&a);

            validar_y_bisiesto(d,m,a,&b,&v);

        } while (v != 1);
   // }
    if(m<=7)
    {
        if(m%2 != 0)//mes impar
        {
            if(d < 31)
            {
                d += 1;
            }
            else
            {
                d = 1;
                m += 1;
            }
        }//fin de impares
        else//(m%2 == 0) mes par
        {
            if(m == 2)//febrero
            {    
                if(b==1)//bisiesto    
                {    
                    if(d < 29)
                    {
                        d += 1;
                    }
                    else
                    {
                        d = 1;
                        m += 1;
                    }
                }
                else //no bisiesto
                {
                    if(d < 28)
                    {
                        d += 1;
                    }
                    else
                    {
                        d = 1;
                        m += 1;
                    }
                }            
            }//fin febrero
            else{//resto de meses pares
                if(d < 30)
                {
                    d += 1;
                }
                else
                {
                    d = 1;
                    m += 1;
                }
            }//fin de resto de pares
        }//fin de pares
    }
    else if(m < 12)//antes de diciembre
    {
        if(m%2 != 0)//mes impar
        {
            if(d < 30)
            {
                d += 1;
            }
            else
            {
                d = 1;
                m += 1;
            }
        }
        else //mes par
        {
            if(d < 31)
            {
                d += 1;
            }
            else
            {
                d = 1;
                m += 1;
            }
        }  
    }
    else
    {
        if(d < 31)
        {
            d += 1;
        }
        else
        {
            d = 1;
            m = 1;
            a += 1;
        }
    }
    printf(" el dia siguiente es: %d/%d/%d\n",d,m,a);
    return 0;
}

void validar_y_bisiesto(int d, int m,int a, int *b, int *v)
{
    if (m>12)
    {
        *v = 0;
    }
    else
    {   
        if(m%2 != 0  &&  m <= 7) //impar menor a 7
        {
            if(d > 31)
            {
                *v = 0;
            }
            else
            {
                *v=1;
            }
        }
        else if(m%2 == 0  &&  m <= 7)
        {
            if(m == 2)//febrero
            {
                if (a%4 == 0)//bisiesto
                {
                    *b = 1;
                    if(d > 29)
                    {
                        *v = 0;
                    }
                    else
                    {
                        *v=1;
                    }
                }
                else
                {
                    *b = 0;
                    if(d > 28)
                    {
                        *v = 0;
                    }
                    else
                    {
                        *v=1;
                    }
                }
            }//fin febrero
            
            if(d > 30)
            {
                *v = 0;
            }
            else
            {
                *v=1;
            }
        }
        else if(m%2 != 0 && m > 7)//mes impar y mayor a 7
        {
            if(d > 30)
            {
                *v = 0;
            }
            else
            {
                *v=1;
            }
        }
        else if(m%2 == 0 && m > 7)//mes par y menor a 7
        {
            if(d > 31)
            {
                *v = 0;
            }
            else
            {
                *v=1;
            }
        }
        
        if(a%4 == 0)
        {
            *b = 1;
        }
        else
        {
            *b = 0;
        }
    }
}