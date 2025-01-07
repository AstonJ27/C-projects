#include <stdio.h>
#include "TDA/listas.h"
#define cant_num 26
void guerra(cola *p1, cola *p2, cola *aux, int *n){ //ambas son iguales
    if(isvoidC(*p1) || isvoidC(*p2) || frenteCola(*p1) != frenteCola(*p2)){
        return;
    }
    
    for(int i=1; i < 3; i++){
        insertarACola(aux,quitarDeCola(p1));
        insertarACola(aux,quitarDeCola(p2));
        
        if(isvoidC(*p1) || isvoidC(*p2)){
            return;   
        }
    }
    
    if(frenteCola(*p1) == frenteCola(*p2)){ //llama a guerra denuevo
        *n = *n + 2;
        guerra(p1,p2,aux,n);

    } 
    if(isvoidC(*aux)){
        return;
    }
    
    if(isvoidC(*p1) || isvoidC(*p2)){
        //hubo empate
        return;
    }
    
    *n = *n+1; 
    if(frenteCola(*p1) > frenteCola(*p2)){ //p1 gana
       
        insertarACola(p1,quitarDeCola(p1));  
        insertarACola(p1,quitarDeCola(p2)); 
        while(!isvoidC(*aux)){
            
            insertarACola(p1,quitarDeCola(aux)); 
        }
        
        return;
    }else if (frenteCola(*p1) < frenteCola(*p2)){ // p2 gana
        insertarACola(p2,quitarDeCola(p1));  
        insertarACola(p2,quitarDeCola(p2)); 
        while(!isvoidC(*aux)){
            insertarACola(p2,quitarDeCola(aux)); 
        }
        return;
    }
    
    printf("final");
    return;
}



void turno(cola *p1, cola *p2, char vict[], int *n){
    cola aux;
    crearCola(&aux);
    //victoria
    if(isvoidC(*p1) && isvoidC(*p2) ){
        strcpy(vict,"empate");
 
        return;
    }
    else if(isvoidC(*p2)){
        strcpy(vict,"jugador_1");

        return;
    }else if(isvoidC(*p1)){
        strcpy(vict,"jugador_2");

        return;
    }
    
    //comprobar turno
    if(frenteCola(*p1) > frenteCola(*p2)){
        insertarACola(p1,quitarDeCola(p1)); //primero player1 
        insertarACola(p1,quitarDeCola(p2)); //luego player2
        *n = *n+1;

    }else if(frenteCola(*p1) < frenteCola(*p2)){

        insertarACola(p2,quitarDeCola(p1)); //primero player1 
        insertarACola(p2,quitarDeCola(p2)); //luego player2
        *n = *n +1;
    }else{
        
        guerra(p1,p2,&aux,n);
        *n = *n + 2;
        vaciarCola(&aux);
        if(isvoidC(*p2) || isvoidC(*p1)){
            
        }
    }

}

//--------------------------------------------------------
void asignar_cartas(cola *p){
    int carta;
    for(int i = 1; i <= cant_num; i++){

        scanf("%d",&carta);
        
        insertarACola(p, carta);
    }
}


int main(){
    int prueba;
    FILE *out = fopen("temp.txt", "w");
    if(out == NULL){
        exit(EXIT_FAILURE);
    }
    
    char lector;
    scanf("%d",&prueba);//n casos prueba    
    int a = 0;
    
    while(a < prueba){
        a++;
        cola p1, p2;
        char win[20] = "algo";
        crearCola(&p1);
        crearCola(&p2);

        asignar_cartas(&p1);

        asignar_cartas(&p2);
        
        if(isvoidC(p1)){
            printf("no agrego p2\n");
            return 1;
        }
        if(isvoidC(p2)){
            printf("no agrego p1\n");
            return 1;
        }
        
        int n=0; 
        while(!strcmp(win,"algo")){ //!isvoidC(p1) || !isvoidC(p2) || 
            turno(&p1,&p2,win,&n);
            
        }
        fprintf(out,"\n%s\n%d\n\n",win,n);
        vaciarCola(&p1);
        vaciarCola(&p2);
    
    }
    //utilizo archivos para dar el formato correcto de la salida
    fclose(out);
    out = fopen("temp.txt", "r");
    if(out == NULL){
        exit(EXIT_FAILURE);
    }

    while ((lector = getc(out)) != EOF) {
        printf("%c", lector);  // Mostrar el caracter leído
    }
    system("rm temp.txt");
    fclose(out);
    return 0;
}  