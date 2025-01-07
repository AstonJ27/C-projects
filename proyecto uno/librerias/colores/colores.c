#include "colores.h"

/***********************************************************|
|   validaciones necesarias para comprobar si un string     |
|     tiene suficiente espacio en memoria para cambiar      |
|    de color o estilo o si los parametros son validos      |
|***********************************************************/

bool validar_color(char string[MAX_ARREGLO_USABLE], size_t tam, char agregar[20]){

    char *colores[] ={
        ROJO, VERDE, AZUL, AMARILLO,
        CIAN, MAGENTA, ROSA, PURPURA, 
        NARANJA, GRIS, BLANCO, NEGRO,
        ROJO_PASTEL, VERDE_PASTEL , AZUL_PASTEL, AMARILLO_PASTEL,
        CIAN_PASTEL, MAGENTA_PASTEL, ROSA_PASTEL, PURPURA_PASTEL, 
        NARANJA_PASTEL
    };
    
    bool pertenece = false;
    size_t tamanio_colores = sizeof(colores) / sizeof(colores[0]);
    int i = 0;
    while((i < tamanio_colores) && !pertenece){
        if(strcmp(colores[i],agregar)==0){
            pertenece = true;
        }
        i++;
    }

    if(pertenece){
        size_t tamanio_string = strlen(string);
        size_t tamanio_agregar = strlen(agregar)+2+sizeof(RESET);
        bool requisito = tam <= MAX_ARREGLO_USABLE && tam >= MIN_ARREGLO;
        bool comparacion = tamanio_string + tamanio_agregar < tam; 

        return(requisito && comparacion);
    }else{
        //printf("color: %s no esta definido",agregar);
        return false;
    }

}

bool validar_fondo(char string[MAX_ARREGLO_USABLE], size_t tam, char agregar[20]){

    char *fondos[] ={
        FONDO_ROJO, FONDO_VERDE, FONDO_AZUL, FONDO_AMARILLO,
        FONDO_CIAN, FONDO_MAGENTA, FONDO_ROSA, FONDO_PURPURA, 
        FONDO_NARANJA, FONDO_GRIS, FONDO_BLANCO, FONDO_NEGRO
    };
    
    bool pertenece = false;
    size_t tamanio_fondos = sizeof(fondos) / sizeof(fondos[0]);
    int i = 0;
    while((i < tamanio_fondos) && !pertenece){
        if(strcmp(fondos[i],agregar)==0){
            pertenece = true;
        }
        i++;
    }

    if(pertenece){
        size_t tamanio_string = strlen(string);
        size_t tamanio_agregar = strlen(agregar)+2+sizeof(RESET);
        bool requisito = tam <= MAX_ARREGLO_USABLE && tam >= MIN_ARREGLO;
        bool comparacion = tamanio_string + tamanio_agregar < tam; 

        return(requisito && comparacion);
    }else{
        //printf("color: %s no esta definido",agregar);
        return false;
    }

}

//tamaño no soportado o color
bool validar_estilo(char string[MAX_ARREGLO_USABLE],size_t tam, char agregar[20]){
    char *estilos[] ={
        NEGRITA, CURSIVA, SUBRAYADO,
        DOBLE_SUBRAYADO, INVERSO, TACHADO
    };
    
    size_t tamanio_estilos = sizeof(estilos) / sizeof(estilos[0]);
    int i = 0;
    bool pertenece = false;
    while((i < tamanio_estilos) && !pertenece){
        if(strcmp(estilos[i],agregar) == 0){
            pertenece = true;
        }
        i++;
    }
    if(pertenece){
        size_t tamanio_string = strlen(string);
        size_t tamanio_agregar = strlen(agregar)+2+sizeof(RESET);
        bool requisito = tam <= MAX_ARREGLO_USABLE && tam >= MIN_ARREGLO;
        bool comparacion = tamanio_string + tamanio_agregar < tam; 
        
        return(requisito && comparacion);

    }else{
        return false;
    } 
}

/*******************************************************|
|   Reestablece los colores por default de los strings  |
|*******************************************************/
void reestablecer(char string[MAX_ARREGLO_USABLE], size_t tam){

    if(tam <= MAX_ARREGLO_USABLE && tam >= MIN_ARREGLO){
        char* color;
        color = strrchr(string, INICIO);
        //borrar color
        if(color != NULL){
            snprintf(string, tam, "%s",++color);
            char* reinicio = strchr(string,FIN);
            if(reinicio != NULL){
                reinicio[0] = '\0';
            }
        }
        if(string[0] == INICIO){
            printf("XD");
        }
    }
}


/*******************************************************|
|   le da a un string los estilos de texto disponibles  |
|*******************************************************/

void dar_estilo(char string[MAX_ARREGLO_USABLE], char estilo[20], size_t tam){
    reestablecer(string, tam);
    if(validar_estilo(string, tam, estilo)){
        char auxiliar[tam];
        strcpy(auxiliar,string);
        char *fin = strchr(string,FIN);
        if(fin != NULL){
            snprintf(string,tam,"%s%c%s",estilo,INICIO,auxiliar);
        }else{
            snprintf(string,tam,"%s%c%s%c%s",estilo,INICIO,auxiliar,FIN,RESET);
        }
    }else{
        printf("tamaño insuficiente\n");
    }
}

/*******************************************************|
|   le da a un string los colores de texto disponibles  |
|*******************************************************/

void cambio_color(char string[MAX_ARREGLO_USABLE],char color[20], size_t tam){
    reestablecer(string, tam);

    if(validar_color(string,tam,color)){
        
        char auxiliar[tam];
        strcpy(auxiliar,string);
        snprintf(auxiliar,tam,"%s%c%s%c%s",color,INICIO, string, FIN,RESET);
        strcpy(string,auxiliar); 
    
    }else{
        printf("tamaño no soportado o color invalido");
    }
}

/****************************************************************|
|   le da a un string los colores de fondo de texto disponibles  |
|****************************************************************/
void cambio_fondo(char string[MAX_ARREGLO_USABLE],char fondo[20], size_t tam){
    reestablecer(string, tam);

    if(validar_fondo(string,tam,fondo)){
        
        char auxiliar[tam];
        strcpy(auxiliar,string);
        snprintf(auxiliar,tam,"%s%c%s%c%s",fondo,INICIO, string, FIN,RESET);
        strcpy(string,auxiliar); 
    
    }else{
        printf("tamaño no soportado o color invalido");
    }
}

/****************************************************************|
|  le da formato a un string de la forma (color, fondo, estilo)  |
|****************************************************************/

void formatear(char string[MAX_ARREGLO_USABLE], size_t tam, char color[20], char fondo[20], char estilo[20]){
    reestablecer(string, tam);
    char aux[tam];
    strcpy(aux,string);
    //agregar un reset al final, string es la cadena sin formato
    snprintf(aux, sizeof(aux), "%s%c%s",string,FIN,RESET);
    if(color != NULL){
        if(validar_color(aux, sizeof(aux), color)){
            int nuevo_tamanio = strlen(aux) + strlen(color) + 1;
            if(nuevo_tamanio < tam){ //es apto
                strcpy(string, aux);
                snprintf(aux,sizeof(aux), "%s%c%s",color,INICIO,string);
            }
        }else{
            printf("no se pudo asignar color\n");
        }
    }

    if(fondo != NULL){
        if(validar_fondo(aux, sizeof(aux), fondo)){
            int nuevo_tamanio = strlen(aux) + strlen(fondo) + 1;
            if(nuevo_tamanio < tam){ //es apto
                strcpy(string, aux);
                snprintf(aux,sizeof(aux), "%s%c%s",fondo,INICIO,string);
            }
        }else{
            printf("no se pudo asignar fondo\n");
        }
    }

    if(estilo != NULL){
        if(validar_estilo(aux, sizeof(aux), estilo)){
            int nuevo_tamanio = strlen(aux) + strlen(estilo) + 1;
            if(nuevo_tamanio < tam){ //es apto
                strcpy(string, aux);
                snprintf(aux,sizeof(aux), "%s%c%s",estilo,INICIO,string);
            }
        }else{
            printf("no se pudo asignar estilo\n");
        }
    }

    strcpy(string, aux);
    return;
}
