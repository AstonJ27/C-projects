#include <stdio.h>

unsigned long long int binary(int n){

    if (n==0 || n==1){
        return n;
    } else{
        unsigned long long a = (n%2) + 10*binary(n/2); //se usa para ver los valores que va retornando en el debug
        return a;
    }
}

int main_binary()
{

    int n = 42 ; //  max 2^20 -1 = 1048575
    unsigned long long int binary_num = binary(n);
    printf("el numero %d en Binario es: %llu\n",n,binary_num);
    return 0;
}

void p(int a[], int t, int n, int *pos, int *neg, int *c){
    if(n<=t){
        if(a[n]==0){
            *c= *c+1;
            p(a,t,n+1,pos,neg,c);
        }else if (a[n]>0){
            *pos = *pos+1;
            p(a,t,n+1,pos,neg,c);
        }
        else{
            *neg = *neg+1;
            p(a,t,n+1,pos,neg,c);
        }
    }
}

int main_p(){
    int a[] = {1,-2,4,0,-6,-1};// t=6 se trabaja t-1 deben haber 3 negativos 2 positivos y un cero
    int t = sizeof(a)/ sizeof(a[0]), n=0, pos=0, neg=0, c=0;
    p(a,t-1,n,&pos,&neg,&c);
    printf("positivos: %d, negativos: %d, ceros: %d\n",pos,neg,c);
    return 0;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int identificador;
    printf("bienvenido al programa de ejercicios en c, en este programa puedes hacer varios ejercicios e identificarlos con un numero de forma que\npodras comprobarlos todos dentro de un mismo programa por favor escoja un numero:");
    scanf("%d",&identificador);
    printf("\n");
    switch (identificador)
    {
    case 1:
        main_binary();
        break;
    case 2:
        main_p();
        break;
    /*case 3:
        break;
    */
    default:
        break;
    }
    
    
    
    
    return 0;
}
