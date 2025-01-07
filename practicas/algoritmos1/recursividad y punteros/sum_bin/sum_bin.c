#include <stdio.h>
#define pantalla "\e[48;5;16m"
#define reset "\033[0m"
#define amarillo "\e[38;5;226m"
#define blanco "\e[38;5;15m"
typedef unsigned long long int Gint; //%llu
//suma de numeros binarios de igual longitud

void suma_Bin(int a[], int b[], int ta, int tb, int c, int s[], int *ts){//recibe 2 arreglos
    int i,j,cond;
    i=ta;
    j=tb;
    s[0] = 0;
    cond = a[i]+b[j]+c;
    if(i==0 || j==0){      			//caso base
        if(cond < 2){
            if(cond == 1){    
                s[i+1] = 1;
                *ts = *ts + 2;
            }else{
                s[i+1] = 0;
                *ts = *ts + 2;
            }
        }else{
            if(cond == 3){
                s[i+1] = 1;
                s[i] = 1; 							//s[0]
                *ts = *ts + 2;
            }else{
                s[i+1] = 0;
                s[i] = 1;
                *ts = *ts + 2;
            }
        }
    }else{
        if(cond < 2){
            if(cond == 0){    
                s[i+1] = 0;
                c = 0;
                *ts = *ts + 1;
            }else{
                s[i+1] = 1;
                c = 0;
                *ts = *ts + 1;
            }
        }else{
            if(cond == 2){
                s[i+1] = 0;
                c = 1;
                *ts = *ts + 1;
            }else{
                s[i+1] = 1;
                c = 1;
                *ts = *ts + 1;
            }
        }
        suma_Bin(a, b, i-1, j-1, c, s, ts);
    }

}

void DecToBin(Gint n,int a[],int *ta){

    if (n == 0 || n == 1){
        a[*ta] = n;

        *ta = *ta + 1;
    } else{
        a[*ta] = n % 2;
        *ta = *ta + 1;
        DecToBin(n / 2, a, ta);
        
    }
}

void ordenar(int a[],int ta,int aux){
    int aux2=0;
    if(aux >= ta-1){
        return;
    }else{
        aux2= a[aux];
        a[aux]=a[ta-1];
        a[ta-1]=aux2;
        ordenar(a,ta-1,aux+1);
    }
}
Gint BinToDec(int a[],int ta, int i){ //i debe iniciar siendo 1
    if(ta == 0){
        return a[ta]*i;
    }else{
        return a[ta]*i + BinToDec(a,ta-1,i*2);
    }
}

void nivelar(int a[], int *ta, int tb){
    if(*ta>=tb){
        return;
    }else{
        a[*ta]=0;
        *ta = *ta + 1;
        nivelar(a,ta,tb);
    }
}

int main(){
    Gint n1, n2;	
	printf(pantalla amarillo "ingrese 2 numeros enteros positivos: " blanco);
	scanf("%llu %llu",&n1,&n2);
    if(n1 + n2 > 2147483647){
        printf("desbordamiento de 32 bits\n" reset);
        return 1;
    }
	int a[33]; 
    int b[33];
    int s[33], ts=0;
    int ta = 0,tb = 0;
    //convertir
    DecToBin(n1,a,&ta);
    DecToBin(n2,b,&tb);
    //validar 
    if(ta < tb){
        nivelar(a,&ta,tb);
    }else if(tb < ta){
        nivelar(b,&tb,ta);
    }
    
    //ordenar
    ordenar(b,tb,0);
    ordenar(a,ta,0);
    //sumar
    suma_Bin(a,b,ta-1,tb-1,0,s,&ts);
   
    if(s[0] ==  0){    
        for(int i=0; i<ts; i++){
            s[i] = s[i+1];
        }
        ts = ts-1;
    }
    
    printf("%d -> ",n1);
    for(int i = 0; i < ta;i++){
        printf("%d",a[i]);
    }
    
    printf("\n%d -> ",n2);
    for(int i = 0; i < tb;i++){
        printf("%d",b[i]);
    }
    printf("\n");
    printf("Sumando:\n");
    
    //imprimir la suma
    for(int i = 0; i < ts;i++){
        printf("%d",s[i]);
    }

    printf(" -> %llu\n",BinToDec(s,ts-1,1));
    printf("el resultado fue de %d bits\n",ts +1);
    printf(reset);

    return 0;

}
