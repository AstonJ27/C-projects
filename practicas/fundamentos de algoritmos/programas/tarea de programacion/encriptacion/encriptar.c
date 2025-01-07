#include <stdio.h>
void encriptar(int llave);
void desencriptar(int llave);


int main(){
    int a,llave; 
    printf("Bienvenido a nuestro programa de encriptacion de archivos de texto en C\n");
    printf("ingrese una llave: ");
    scanf("%d",&llave);
    printf("\npara encriptar presione 1, para desencriptar presione 2\n");
    scanf("%d",&a);
    if(a == 1){
        encriptar(llave);
    }
    else if(a == 2){
        desencriptar(llave);
    }
    else{
        printf("Error");
    }

    return 0;
}
//1
void encriptar(int llave){
   unsigned char a;
    FILE *arch1,*arch2;
    arch2 = fopen ("archivo_encriptado.txt", "w");
    arch1 = fopen ("archivo.txt", "r");
    if(arch1 == NULL){
        printf("File not found");
    }
    else if(arch2 == NULL){
        printf("File not found");
    }
    else{
        while(!feof(arch1)){
            fscanf(arch1,"%c",&a);
            
            
            if(a == 32){
                fprintf(arch2,"%c",a);
            }   
            else if(a >= 33 && a <= 126){
                a = (a+llave)%94 + 33;
                fprintf(arch2,"%c",a);
            }
            
        }
    }
    fclose(arch1);
    fclose(arch2);
   
}
//2
void desencriptar(int llave){
   unsigned char a;
    FILE *arch1,*arch2;
    

    arch1 = fopen ("archivo_encriptado.txt", "r");
    arch2 = fopen ("archivo_recuperado.txt", "w");
 
    if(arch1 == NULL){
        printf("File not found");
    }
    else if(arch2 == NULL){
        printf("File not found");        
    }
    else{
        while(fscanf(arch1,"%c",&a) != EOF)
        {
           
            if(a == 32){
                fprintf(arch2,"%c",a);
            }         
            else{
                a = a + 61;
                if(a > 126 + llave){
                    a = a - 94;
                }
                a = a - llave;
                fprintf(arch2,"%c",a);
            }
            
        }
        
    }

    fclose(arch1);
    fclose(arch2);

}



