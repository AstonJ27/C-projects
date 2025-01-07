#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#define rojo "\e[38;5;196m"
#define MAX 1024
#define true 1
#define false 0
#define MAX_ARG 8
#define MAX_LIB 5
typedef int bool;

typedef struct header{
    char h[MAX];
    char c[MAX];
    char o[MAX];
    bool existe;
}header;

void split(char cad[MAX], char ref){
    char *sufix = strrchr(cad,ref);
    
    if(sufix == NULL){
        printf("Error sufijo incorrecto\n");
        return;
    }
    *sufix = '\0';
    memset(sufix + 1, 0, strlen(sufix+1));
}
void buscar(char *directory, char *file, bool *encontrado, char salida[MAX]);
void compilar(char program[MAX], header *libreria);
void compilar_lib(char program[MAX], header libreria[MAX_LIB], int tam);
void ocultar(char file[MAX]);

int main(int argc, char *argv[])
{
    //char ruta[1024];
    if(argc == 2 && (strcmp(argv[1],"help") == 0)){
        system("cat ~/.beccom/help.txt");
    }
    else if(argc < 4){
        printf("Uso: beccom <argumentos> <directorio_origen> <destino> ...\n");
        printf("para mas informacion beccom help\n");
    }else{
        
        char ruta[MAX];
        bool exito = false;

        if(strcmp(argv[1],"-b") == 0){
            for(int i = 3; i < argc; i++){    
                buscar(argv[2],argv[i],&exito, ruta);
                if(!exito){
                    printf("Archivo %s no encontrado\n",argv[i]);
                }else{
                    printf("%s\n", ruta);
                    exito = false;
                    //ruta[0] = '\0';
                }
            }

        }else if(strcmp(argv[1],"-c") == 0){
            for(int i = 3; i < argc; i++){
                buscar(argv[2],argv[i],&exito, ruta);
                if(!exito){
                    printf("Archivo %s no encontrado\n",argv[i]);
                
                }else{
                    printf("archivo %s encontrado\n",argv[i]); //eliminar
                    compilar(ruta, NULL);
                    printf("%s\n\n",ruta);
                    exito = false;
                }
            }
        
        }else if(strcmp(argv[1],"-cl") == 0){
            int tam = 0;
            header libreria[MAX_LIB];
            if(argc-1 > MAX_ARG || argc < 5){
                printf("Error: demasiados argumentos\n");
            }else{
                for(int i = 4; i < argc; i++){
                    
                    buscar(argv[2],argv[i],&exito, ruta);// buscar el .h
                    if(exito){
                        char filename[50];
                        strcpy(filename, argv[i]);
                        split(filename,'.'); //quitar extension .h
                        strcat(filename,".c"); //nombre del archivo.c

                        strcpy(libreria[i-4].h, ruta);
                                                
                        char direccion[MAX];
                        strcpy(direccion,ruta);
                        split(direccion, '/');
                        
                        exito = false;
                        ruta[0] = '\0';
                        
                        buscar(direccion,filename,&exito, ruta);// buscamos el .c
                        if(exito){
                            strcpy(libreria[i-4].c, ruta);
                            libreria[i-4].existe = true;
                            tam++;
                            exito = false;
                            ruta[0] = '\0';
                        }else{
                            printf("Error: archivo %s no encontrado\n",filename);
                        }

                    }else{
                        printf("Error: archivo %s no encontrado\n",argv[i]);
                    }
                }
                
                printf("librerias encontradas:\n");
                for(int i = 0; i < tam; i++){
                    if(libreria[i].existe){
                        printf("%d) %s\n",i+1,libreria[i].h);
                        printf("   %s\n",libreria[i].c);
                        compilar("\0", &libreria[i]);
                        printf("\n");
                    }else{
                        printf("Error de compilacion con libreria:\n" rojo "%s\n",libreria[i].h);
                    }    
                }
                exito = false;
                ruta[0] = '\0';
                buscar(argv[2],argv[3],&exito, ruta);
                if(exito){
                    compilar_lib(ruta,libreria,tam);

                }else{
                    printf("Error: archivo %s no encontrado\n",argv[3]);
                }            
                
            }
        
        }else if(strcmp(argv[1],"-h") == 0){
            
            buscar(argv[2],argv[3],&exito, ruta);
            
            if(!exito){
                printf("Archivo no encontrado\n");
            }else{
                ocultar(ruta);
            }
        }else{
            printf("Error: argumento invalido\n");
        }
    }
    
    
    return 0;
}

void buscar(char *directory, char *file, bool *encontrado, char salida[MAX]){
    DIR *dir = opendir(directory);
    char hidden_file[MAX] = ".";
    strcat(hidden_file,file);
    if(dir == NULL){
        printf("no se puede abrir el directorio");
        return;
    }
    char ruta[MAX];
    //pegar el directorio actual
    
    struct dirent *destiny;
    while((destiny = readdir(dir)) != NULL && !*encontrado){
        
        if(strcmp(destiny->d_name,".") != 0 && strcmp(destiny->d_name,"..") != 0){
            
            snprintf(ruta, sizeof(ruta), "%s/%s",directory,destiny->d_name);
            
            if(strcmp(destiny->d_name, file) == 0 || strcmp(destiny->d_name,hidden_file) == 0){
                *encontrado = true;
                strcpy(salida, ruta);
                //printf("%s\n",ruta);

            }else if(destiny->d_type == DT_DIR){
                buscar(ruta,file,encontrado,salida);
            }
        }
    }
    closedir(dir);
}

void compilar_lib(char program[MAX], header libreria[MAX_LIB], int tam){
    char aux[MAX];
    strcpy(aux,program);
    printf("\n");

    split(aux,'.');
    // crear el comando
    char comando[MAX];

    snprintf(comando, sizeof(comando),"gcc '%s' ",program);
    for(int i = 0; i < tam; i++){
        strcat(comando, "'");
        strcat(comando,libreria[i].o);
        strcat(comando,"' ");

    }
        strcat(comando,"-o '");
        strcat(comando,aux);
        strcat(comando,"'");
        
        printf("%s\n", comando);
        system(comando);

}


void compilar(char program[MAX], header *libreria){
    //guardar auxiliar con extension
    char aux[MAX];
    char command[MAX/2];

    if(libreria == NULL){    
        strcpy(aux, program);
        split(program,'.');
        
        if(snprintf(command, sizeof(command), "gcc '%s' -o '%s'",aux,program) >= sizeof(command)){
            perror("no se puede compilar el archivo, la ruta es muy grande\n");
            return;
        }else{
            system(command);
            printf("compilacion exitosa\n");
        }
    
    }else{
        
        strcpy(libreria->o, libreria->c);
        split(libreria->o,'.');
        strcat(libreria->o,".o");
                
        if(snprintf(command, sizeof(command), "gcc -c '%s' -o '%s'",libreria->c,libreria->o) >= sizeof(command)){
            perror("no se puede compilar el archivo");
            return;
        }else{
            system(command);
            FILE *in;
            in = fopen(libreria->o,"r");
            if(in == NULL){
                perror("no se creo correctamente el archivo ");
                return;

            }else{
                fclose(in);
                printf("   %s creado correctamente\n",libreria->o);
            }
        }
    
    }
}

void ocultar(char file[MAX]){
    //ocultar el archivo    
    char dir_file[MAX];
    char *copy = strrchr(file,'/');
    strcpy(dir_file, file); 
    split(dir_file,'/'); //obtener el directorio

    if(copy[1] != '.'){ //no esta oculto
        printf("Ocultando:\n");
        copy = copy+1;
        strcat(dir_file,"/.");
        strcat(dir_file,copy);
        
        if(rename(file,dir_file) == -1){
            printf("fallo al cambiar nombre\n");
        }else{
            printf("Archivo ocultado\n");
        }
    }else{ //esta oculto
        printf("descubriendo\n");
        copy = copy+2;
        printf("%s\n",copy);
        strcat(dir_file,"/");
        strcat(dir_file,copy);
        
        if(rename(file,dir_file) == -1){
            printf("fallo al cambiar nombre\n");
        }else{
            printf("archiivo descubierto\n");
        }
    }

}
